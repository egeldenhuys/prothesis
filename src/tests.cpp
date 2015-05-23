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

    UserData.name="John";
    UserData.surname="Bool";
    UserData.mbti="ISTJ";
    UserData.lifeKeys.push_back("Life Key 1");
    UserData.lifeKeys.push_back("Life Key 2");
    UserData.lifeKeys.push_back("Life Key 3");
    UserData.roles.push_back("Roles 1");
    UserData.roles.push_back("Roles 2");
    UserData.roles.push_back("Roles 3");
    UserData.roles.push_back("Roles 4");
    UserData.roles.push_back("Roles 5");
    UserData.roles.push_back("Roles 6");
    UserData.roles.push_back("Roles 7");

    UserData.skills.push_back("skills 1");
    UserData.skills.push_back("skills 2");
    UserData.skills.push_back("skills 3");
    UserData.skills.push_back("skills 4");
    UserData.skills.push_back("skills 5");
    UserData.skills.push_back("skills 6");
    UserData.skills.push_back("skills 7");

    UserData.passionsMovie="Passions Movie";
    UserData.passionsChange="Passions Change";
    UserData.passionsAlive="Passions Alive";
    UserData.passionsGiveUp="Passions Give Up";
    UserData.passionsSummary="Passions Summary";
    UserData.dreamsPasttime="Pastime";
    UserData.dreamsChildDreams="Child dreams";
    UserData.dreamsCurrentDreams="curr dreams";
    UserData.dreamsSummary="dreams summary";
    UserData.peopleHero="people hero";
    UserData.peopleInfluence="people influence";
    UserData.peopleIdentify="people identify";
    UserData.peopleCharacter="people character";
    UserData.peopleSummary="people summary";
    UserData.spokenWords="spoken words";
    UserData.spokenSummary="Spoken summary";

    UserData.people.push_back("KIds");
    UserData.people.push_back("Dogs");
    UserData.people.push_back("Cars");
    UserData.people.push_back("Cats");
    UserData.people.push_back("Me");

    UserData.priorities.push_back("Money");
    UserData.priorities.push_back("Animals");

    UserData.workIdeal="Ideal work";
    UserData.workCreative="work creative";
    UserData.workStructure="work struct";
    UserData.workUndefined="work undefined";
    UserData.workSummary="work summary";

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
    The amount of failed comparrisons
*/
int compare(User a, User b)
{
    int failed = 0;

    std::vector<std::string> aStrings;
    aStrings = get_strings(a);

    std::vector<std::string> bStrings;
    bStrings = get_strings(b);

    if (aStrings.size() != bStrings.size())
        return 1;

    for (unsigned int i = 0; i < aStrings.size(); i++)
    {
        if (aStrings[i] != bStrings[i])
        {
            std::cout << i << ": " << aStrings[i] << " != " << bStrings[i] << std::endl;
            failed++;
        }
    }

    std::vector<std::vector<std::string> > aVectors, bVectors;
    aVectors = get_vectors(a);
    bVectors = get_vectors(b);

    if (aVectors.size() != bVectors.size())
        return 1;

    for (unsigned int i = 0; i < aVectors.size(); i++)
    {
        for (unsigned int j = 0; j < aVectors[i].size(); j++)
        {
            if (aVectors[i][j] != bVectors[i][j])
            {
                std::cout << aVectors[i][j] << " != " << bVectors[i][j] << std::endl;
                failed++;
            }
        }
    }

    return failed;

}

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

    User UserDataSave;

    UserDataSave = set_user_data();
    UserDataSave.save();

    User UserDataLoad;
    UserDataLoad.load();

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

    failed = failed + save_and_load();
    std::cout << "save_and_load(): Fails: " << failed << std::endl;

    return failed;
}


