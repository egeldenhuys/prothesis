#include "tests.h"

/*
print_vector(vector<string> vecToPrint)
============
Description:
    Print the given vector to cout
*/
void print_vector(std::vector<std::string> vecToPrint)
{
    for (unsigned int i = 0; i < vecToPrint.size(); i++)
        std::cout << "[" << i << "]: " << vecToPrint[i] << std::endl;
}

/*
get_vectors(User UserData)
===========
Description:
    Places all the string vectors in the User class into
    a vector

Paramaters:
    UserData - The User object to get the vectors from

Example:
    std::vector< std::vector<std::string> > userVectors;
    userVectors = get_vectors(UserData);
    cout << userVectors[0][2];

Returns:
    An vector of the type vector<string>
*/
std::vector<std::vector<std::string> > get_vectors(User UserData)
{
    std::vector<std::vector<std::string> > UserDataVectors;
    UserDataVectors.push_back(UserData.lifeKeys);
    UserDataVectors.push_back(UserData.roles);
    UserDataVectors.push_back(UserData.skills);
    UserDataVectors.push_back(UserData.people);
    UserDataVectors.push_back(UserData.priorities);

    return UserDataVectors;
}

/*
get_strings(User UserData)
===========
Description:
    Get a vector of strings from the given User object.

Paamaters:
    UserData - The User object to get the strings from

Example:
    std::vector<string> userStrings;
    userStrings = get_strings(UserData);
    cout << user_strings[5];

Returns:
    A vector of strings
*/
std::vector<std::string> get_strings(User UserData)
{
    std::vector<std::string> UserDataStrings;

    UserDataStrings.push_back(UserData.name);
    UserDataStrings.push_back(UserData.surname);
    UserDataStrings.push_back(UserData.mbti);
    //UserDataStrings.push_back(UserData.lifeKeys);
    //UserDataStrings.push_back(UserData.roles);
    //UserDataStrings.push_back(UserData.skills);
    UserDataStrings.push_back(UserData.passionsMovie);
    UserDataStrings.push_back(UserData.passionsChange);
    UserDataStrings.push_back(UserData.passionsAlive);
    UserDataStrings.push_back(UserData.passionsGiveUp);
    UserDataStrings.push_back(UserData.passionsSummary);
    UserDataStrings.push_back(UserData.dreamsPasttime);
    UserDataStrings.push_back(UserData.dreamsChildDreams);
    UserDataStrings.push_back(UserData.dreamsCurrentDreams);
    UserDataStrings.push_back(UserData.dreamsSummary);
    UserDataStrings.push_back(UserData.peopleHero);
    UserDataStrings.push_back(UserData.peopleInfluence);
    UserDataStrings.push_back(UserData.peopleIdentify);
    UserDataStrings.push_back(UserData.peopleCharacter);
    UserDataStrings.push_back(UserData.peopleSummary);
    UserDataStrings.push_back(UserData.spokenWords);
    UserDataStrings.push_back(UserData.spokenSummary);
    //UserDataStrings.push_back(UserData.people);
    //UserDataStrings.push_back(UserData.priorities);
    UserDataStrings.push_back(UserData.workIdeal);
    UserDataStrings.push_back(UserData.workCreative);
    UserDataStrings.push_back(UserData.workStructure);
    UserDataStrings.push_back(UserData.workUndefined);
    UserDataStrings.push_back(UserData.workSummary);

    return UserDataStrings;

}

/*
set_user_data()
=============
Description:
    Set some satic user data and return the User obect;

Example:
    User EmptyUser;
    EmptyUser = set_user_data();

Returns:
    A User object that has it variables populated
*/
User set_user_data()
{
    User UserData;

    UserData.name="Jo[hn]";
    UserData.surname="[[[Bool[";
    UserData.mbti="IS]T[J";
    UserData.lifeKeys.push_back("Life Key 1");
    UserData.lifeKeys.push_back("Life Key 2");
    UserData.lifeKeys.push_back("Life Key 3");
    UserData.roles.push_back("Rol]es 1");
    UserData.roles.push_back("Roles 2");
    UserData.roles.push_back("Roles 3");
    UserData.roles.push_back("Roles 4");
    UserData.roles.push_back("Roles 5[");
    UserData.roles.push_back("]Ro[]les 6");
    UserData.roles.push_back("Roles 7");

    UserData.skills.push_back("[][]]][");
    UserData.skills.push_back("ski[names]lls 2");
    UserData.skills.push_back("skills 3");
    UserData.skills.push_back("skills 4");
    UserData.skills.push_back("ski[skills]lls 5");
    UserData.skills.push_back("skills 6");
    UserData.skills.push_back("skills 7");

    UserData.passionsMovie="Passions Movie";
    UserData.passionsChange="Passions Change";
    UserData.passionsAlive="Passions Alive";
    UserData.passionsGiveUp="Passions Give Up";
    UserData.passionsSummary="Passions Summary";
    UserData.dreamsPasttime="Pasti[me";
    UserData.dreamsChildDreams="Child dreams";
    UserData.dreamsCurrentDreams="curr dreams";
    UserData.dreamsSummary="dreams[ ] ] [ ] ][] summ[]ary";
    UserData.peopleHero="people hero";
    UserData.peopleInfluence="people influence";
    UserData.peopleIdentify="people identify";
    UserData.peopleCharacter="people character";
    UserData.peopleSummary="people summary";
    UserData.spokenWords="spoken words";
    UserData.spokenSummary="Spoken summary";

    UserData.people.push_back("KIds");
    UserData.people.push_back("Do]]gs");
    UserData.people.push_back("Ca][[[]rs");
    UserData.people.push_back("Ca]ts");
    UserData.people.push_back("Me");

    UserData.priorities.push_back("Money");
    UserData.priorities.push_back("A[nimals");

    UserData.workIdeal="Ideal work";
    UserData.workCreative="work cr][eative";
    UserData.workStructure="work struct";
    UserData.workUndefined="work und]efined";
    UserData.workSummary="work summa][ry";

    return UserData;
}

/*
int compare(User a, User b)
===========
Description:
    Compare the variables stored in a against b

Paramaters:
    User a - The User object to use
    User b - The user object to use

Example:
    cout << compare(UserA, UserB);

Returns:
    0 - both User objects hold the same data
    1 - Not all data matches
*/
int compare(User a, User b)
{
    std::cout << "compare()..." << "\n";

    int failed = 0;

    // Extract the string variables from both objects
    // and place them into vectors
    std::vector<std::string> aStrings, bStrings;
    aStrings = get_strings(a);
    bStrings = get_strings(b);

    // If they are not the same length there is an error
    // Disabled to give more information
    /*
    if (aStrings.size() != bStrings.size())
        return 1;
    */

    // Loop through all the string elements in the vector
    for (unsigned int i = 0; i < aStrings.size(); i++)
    {
        if (aStrings[i] != bStrings[i])
        {
            std::cout << "| - " << i << ": " << aStrings[i] << " != " << bStrings[i] << std::endl;
            failed = 1;
        }
    }

    // Extract the vectors from both objects and place them
    // into a vector
    std::vector<std::vector<std::string> > aVectors, bVectors;
    aVectors = get_vectors(a);
    bVectors = get_vectors(b);

    // Disabled to give more information on which fields do not match
    /*
    if (aVectors.size() != bVectors.size())
        return 1;
    */

    // Loop through all the elements in the vector
    for (unsigned int i = 0; i < aVectors.size(); i++)
    {
        // Loop through all the elements in the selected vector i
        for (unsigned int j = 0; j < aVectors[i].size(); j++)
        {
            if (aVectors[i][j] != bVectors[i][j])
            {
                std::cout << "| - " << i << "," << j << ": " << aVectors[i][j] << " != " << bVectors[i][j] << std::endl;
                failed = 1;
            }
        }
    }

    return failed;

}

/*
save_and_load
=============
Description:
    Test the save and load functions of the User class
Method:
    - Set the User variables to a known value in User object A
    - Call the Save function on User object A
    - Create a new User object B
    - Call the load function on User object B
    - Compare the variables from User object A against User object B

    - This will test if variables are the save after being saved and loaded.
*/

/*
int save_and_load()
=================
Description:
    Test the saving and loading of the User class

Example:
    cout << save_and_load();

Returns:
    The number of failed tests
*/
int save_and_load()
{
    int failed = 0;


    // Generate data and save it
    User UserDataSave;

    UserDataSave = set_user_data();
    UserDataSave.save();

    // Load the generated data
    User UserDataLoad;
    UserDataLoad.load();

    // Compare if both sets still hold the same data
    // after being saved and loaded
    failed = compare(UserDataSave, UserDataLoad);

    return failed;

}

/*
run_tests()
=========
Description:
    Entry point for executing all the tests for the User class

Returns:
    The number of fails
*/
int run_tests()
{
    int failed = 0;

    if (save_and_load() == 1)
        std::cout << "save_and_load(): FAIL\n";
    else
        std::cout << "save_and_load(): PASS\n";

    return failed;
}

