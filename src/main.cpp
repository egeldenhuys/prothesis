#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*
User
====
Description:
    This class will be used to store and manage the user data

Example:
    User userData;
    userData.load();
    userData.Roles.push_back("analyzer");
    userData.save();
*/
class User
{
    public:

        // User info
        string name;
        string surname;
        string mbti;
        vector<string> lifeKeys;

        vector<string> roles; // The names of the checked roles
        vector<string> skills;

        // Passions
        string passionsMovie;
        string passionsOneThing;
        string passionsChange;
        string passionsAlive;
        string passionsGiveUp;
        string passionsSummary;

        // Dreams
        string dreamsPasttime;
        string dreamsChildDreams;
        string dreamsCurrentDreams;
        string dreamsSummary;

        // People ID
        string peopleHero;
        string peopleInfluence;
        string peopleIdentify;
        string peopleCharacter;
        string peopleSummary;

        // Spoken Words
        string spokenWords;
        string spokenSummary;

        // Career
        // People Orientation
        vector<string> people;
        vector<string> priorities;

        // Work environment
        string workIdeal;
        string workCreative;
        string workStructure;
        string workUndefined;
        string workSummary;

        string path; // The path for storting user data
        bool dirtyData; // Flag indicating if the data has changed and needs to be saved

        int save();
        int load();
        bool _matchesVar(string VarName);
        void _addToVar(string varName, string value);

};

User UserData;

/*
User::save()
============
Description:
    Save the user data to file
*/
int User::save()
{

    /*
    Format
   ======
    [Variable Name (String)]
    Value
    [Variable Name (Array)]
    Value 1
    Value 2
    */


    ofstream outf;
    outf.open("User_Data.dat");

    // If we could not open file for writing
    if (!outf)
    {
        cerr << "ERROR: Unable to create user data file!" << endl;
        return 1;
    }

    outf << "[name]" << endl;
    outf << UserData.name << endl;
    outf << "[surname]" << endl;
    outf << UserData.surname << endl;

    outf.close();

    return -1;
}

/*
User::_addToVar(string varName, string value)
===============
Description:
    Adds the string value to the variable represented by varName
Parameters:
    varName - The string that represents the variable
    value   - The value to set the variable to OR append to
              the array
Example:
    _addToVar("[name]", "John");
Returns:
    Nothing.
*/
void User::_addToVar(string varName, string value)
{

    if (varName == "[name]")
        name = value;
    else if (varName == "[surname]")
        surname = value;
    else if (varName == "[mbti]")
        mbti = value;
    else if (varName == "[lifeKeys]")
        lifeKeys.push_back(value);
    else if (varName == "[roles]")
        roles.push_back(value);
    else if (varName == "[skills]")
        skills.push_back(value);
    else if (varName == "[passionsMovie]")
        passionsMovie = value;
    else if (varName == "[passionsChange]")
        passionsChange = value;
    else if (varName == "[passionsAlive]")
        passionsAlive = value;
    else if (varName == "[passionsGiveUp]")
        passionsGiveUp = value;
    else if (varName == "[passionsSummary]")
        passionsSummary = value;
    else if (varName == "[dreamsPasttime]")
        dreamsPasttime = value;
    else if (varName == "[dreamsChildDreams]")
        dreamsChildDreams = value;
    else if (varName == "[dreamsCurrentDreams]")
        dreamsCurrentDreams = value;
    else if (varName == "[dreamsSummary]")
        dreamsSummary = value;
    else if (varName == "[peopleHero]")
        peopleHero = value;
    else if (varName == "[peopleInfluence]")
        peopleInfluence = value;
    else if (varName == "[peopleIdentify]")
        peopleIdentify = value;
    else if (varName == "[peopleCharacter]")
        peopleCharacter = value;
    else if (varName == "[peopleSummary]")
        peopleSummary = value;
    else if (varName == "[spokenWords]")
        spokenWords = value;
    else if (varName == "[spokenSummary ]")
        spokenSummary = value;
    else if (varName == "[people]")
        people.push_back(value);
    else if (varName == "[priorities]")
        priorities.push_back(value);
    else if (varName == "[workIdeal]")
        workIdeal = value;
    else if (varName == "[workCreative]")
        workCreative = value;
    else if (varName == "[workStructure]")
        workStructure = value;
    else if (varName == "[workUndefined]")
        workUndefined = value;
    else if (varName == "[workSummary]")
        workSummary = value;

}

/*
User::_matchesVar(string varName)
=================
Description:
    Checks if the given string is in the variable names array

Parameters:
    varName - The name of the variable to search for

Example:
    if ( _matchesVar("[user]") )

Returns:
    1 - Name was found
    0 - Name was not found
*/

bool User::_matchesVar(string varName)
{
    bool value = false;

    string varNames [30] = {
    "[name]", "[surname]", "[mbti]",
    "[lifeKeys]", "[roles]", "[skills]", "[passionsMovie]",
    "[passionsOneThing]", "[passionsChange]", "[passionsAlive]",
    "[passionsGiveUp]", "[passionsSummary]", "[dreamsPasttime]",
    "[dreamsChildDreams]", "[dreamsCurrentDreams]",
    "[dreamsSummary]", "[peopleHero]", "[peopleInfluence]",
    "[peopleIdentify]", "[peopleCharacter]", "[peopleSummary]",
    "[spokenWords]", "[spokenSummary]", "[people]", "[priorities]",
    "[workIdeal]", "[workCreative]", "[workStructure]",
    "[workUndefined]", "[workSummary]"
    };

    for (int i = 0; i < 30; i++)
        if (varNames[i] == varName)
            return true;

    return value;
}
/*
User::load()
============
Description:
    Load the user data from file
*/
int User::load()
{

/*
    Format
    ======
    [Variable Name (String)]
    Value
    [Variable Name (Array)]
    Value 1
    Value 2
    */

/*
    Loading
    =======

    - Open File
    - Read until a variable name is found.
    - Store in varName
    - Read next line, if it does not match a variable name store it in
        the the variable that represents varName
    - Continue until a variable name is found again.
    - If it does match a variable name, exit the loop
    - Set varName
    - repeat

    Open file
    Get line
    if the line matches a variable read the following lines into
    that variable, until a line matches a variable again.
*/

    ifstream inf;
    inf.open("User_Data.dat");

    if (!inf)
    {
        cerr << "User_Data.dat Does not exist" << endl;
        return 1;
    }

    string line;
    string varName = "NULL";

    // Loop for reading all lines
    while (getline(inf, line))
    {
        // Check if the line matches a variable
        if ( _matchesVar(line) )
        {
            // The next lines need to be added under that variable
            //representation
            varName = line;
        }

        // The line is a value to be added to a variable
        if (varName != "NULL" && line != varName)
        {
            _addToVar(varName, line);
        }

    }

    return -1;
}

/*
remove_by_name(vector<string> &vecToSearch, string itemText)
==============
Description:
    Search for the given string in the given vector and erase it

Paramaters:
    vecToSearch - Vector to search in and erase
    itemText    - The string to search for and delete

Example:
    remove_by_name(myVector, "Rabbits");

Returns:
    0 - String was found and erased
    1 - String was not found
*/
int remove_by_name(vector<string> &vecToSearch, string itemText)
{
    int returnVal = 1;

    // Loop through vector and find matching item
    for (unsigned int i = 0; i < vecToSearch.size(); i++)
    {
        if (vecToSearch[i] == itemText)
        {
            vecToSearch.erase(vecToSearch.begin() + i);
            returnVal = 0;
        }
    }

    return returnVal;

}

/*
print_vector(vector<string> vecToPrint)
============
Description:
    Print the given vector to cout
*/
void print_vector(vector<string> vecToPrint)
{
    for (unsigned int i = 0; i < vecToPrint.size(); i++)
        cout << "[" << i << "]: " << vecToPrint[i] << endl;
}


int main()
{

    //UserData.name = "John";
    //UserData.surname = "Bool";

    //cout << "Saving data..." << endl;
    //UserData.save();
    //cout << "Data has been saved" << endl;

    //UserData.name = "FAIL";

    /*
    UserData.surname = "FAIL";

    cout << "Loading user data..." << endl;
    UserData.load();

    cout << UserData.name << endl;
    cout << UserData.surname << endl;

    cout << "Terminating program!" << endl;

*/

    cout << UserData._matchesVar("[name]");

    return 0;
}
