#include "user.h"

/*
User.cpp
====
Description:
    This class will be used to store and manage the user data

Example:
    User userData;
    userData.load();
    userData.Roles.push_back("analyzer");
    userData.save();
*/


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


    std::ofstream outf;
    outf.open("User_Data.dat");

    // If we could not open file for writing
    if (!outf)
    {
        std::cerr << "ERROR: Unable to create user data file!" << std::endl;
        return 1;
    }

    outf << "[name]" << std::endl;
    outf << name << std::endl;
    outf << "[surname]" << std::endl;
    outf << surname << std::endl;
    outf << "[mbti]" << std::endl;
    outf << mbti << std::endl;

    outf << "[lifeKeys]" << std::endl;
    for (unsigned int i = 0; i < lifeKeys.size(); i++)
        outf << lifeKeys[i] << std::endl;

    outf << "[roles]" << std::endl;
        for (unsigned int i = 0; i < roles.size(); i++)
        outf << roles[i] << std::endl;

    outf << "[skills]" << std::endl;
    for (unsigned int i = 0; i < skills.size(); i++)
        outf << skills[i] << std::endl;

    // Passions
    // ========
    outf << "[passionsMovie]" << std::endl;
    outf << passionsMovie << std::endl;
    outf << "[passionsChange]" << std::endl;
    outf << passionsChange << std::endl;
    outf << "[passionsAlive]" << std::endl;
    outf << passionsAlive << std::endl;
    outf << "[passionsGiveUp]" << std::endl;
    outf << passionsGiveUp << std::endl;
    outf << "[passionsSummary]" << std::endl;
    outf << passionsSummary << std::endl;

    // Dreams
    // ======
    outf << "[dreamsPasttime]" << std::endl;
    outf << dreamsPasttime << std::endl;
    outf << "[dreamsChildDreams]" << std::endl;
    outf << dreamsChildDreams << std::endl;
    outf << "[dreamsCurrentDreams]" << std::endl;
    outf << dreamsCurrentDreams << std::endl;
    outf << "[dreamsSummary]" << std::endl;
    outf << dreamsSummary << std::endl;

    // People
    // ======
    outf << "[peopleHero]" << std::endl;
    outf << peopleHero << std::endl;
    outf << "[peopleInfluence]" << std::endl;
    outf << peopleInfluence << std::endl;
    outf << "[peopleIdentify]" << std::endl;
    outf << peopleIdentify << std::endl;
    outf << "[peopleCharacter]" << std::endl;
    outf << peopleCharacter << std::endl;
    outf << "[peopleSummary]" << std::endl;
    outf << peopleSummary << std::endl;


    // Spoken Words
    // ============
    outf << "[spokenWords]" << std::endl;
    outf << spokenWords << std::endl;
    outf << "[spokenSummary]" << std::endl;
    outf << spokenSummary << std::endl;

    // Career
    // ======
    outf << "[people]" << std::endl;
    for (unsigned int i = 0; i < people.size(); i++)
        outf << people[i] << std::endl;

    outf << "[priorities]" << std::endl;
    for (unsigned int i = 0; i < priorities.size(); i++)
        outf << priorities[i] << std::endl;

    outf << "[workIdeal]" << std::endl;
    outf << workIdeal << std::endl;
    outf << "[workCreative]" << std::endl;
    outf << workCreative << std::endl;
    outf << "[workStructure]" << std::endl;
    outf << workStructure << std::endl;
    outf << "[workUndefined]" << std::endl;
    outf << workUndefined << std::endl;
    outf << "[workSummary]" << std::endl;
    outf << workSummary << std::endl;


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
int User::_addToVar(std::string varName, std::string value)
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
    else if (varName == "[spokenSummary]")
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

    return -1;
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

bool User::_matchesVar(std::string varName)
{
    bool value = false;

    std::string varNames [30] = {
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

    std::ifstream inf;
    inf.open("User_Data.dat");

    if (!inf)
    {
        std::cerr << "User_Data.dat Does not exist" << std::endl;
        return 1;
    }

    std::string line;
    std::string varName = "NULL";

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
int User::_remove_by_name(std::vector<std::string> &vecToSearch, std::string itemText)
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
