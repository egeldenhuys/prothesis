#include <iostream>
#include <vector>
#include <string>

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
        string lifeKey1;
        string lifeKey2;
        string lifeKey3;

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

};

/*
User::save()
============
Description:
    Save the user data to file
*/
int User::save()
{

    return -1;
}

/*
User::load()
============
Description:
    Load the user data from file
*/
int User::load()
{

    return -1;
}

User UserData;

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

    return 0;
}
