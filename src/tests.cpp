#include "tests.h"

/*
print_vector(vector<string> vecToPrint)
============
Description:
    Print the given vector to cout
*/
void print_vector(std::vector<std::string> vecToPrint)
{
    //NDEBUG for (unsigned int i = 0; i < vecToPrint.size(); i++)
        //NDEBUG std::cout << "[" << i << "]: " << vecToPrint[i] << std::endl;
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
    UserDataVectors.push_back(UserData.interests);
    UserDataVectors.push_back(UserData.interestsPerc);
    UserDataVectors.push_back(UserData.subInterests);
    UserDataVectors.push_back(UserData.subInterestsPerc);
    UserDataVectors.push_back(UserData.roles);
    UserDataVectors.push_back(UserData.skills);
    UserDataVectors.push_back(UserData.strengths);
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
    UserDataStrings.push_back(UserData.passionsMovie);
    UserDataStrings.push_back(UserData.passionsChange);
    UserDataStrings.push_back(UserData.passionsAlive);
    UserDataStrings.push_back(UserData.passionsGiveUp);
    UserDataStrings.push_back(UserData.passionsSummary);
    UserDataStrings.push_back(UserData.dreamsPasttime);
    UserDataStrings.push_back(UserData.dreamsChild);
    UserDataStrings.push_back(UserData.dreamsCurrent);
    UserDataStrings.push_back(UserData.dreamsSummary);
    UserDataStrings.push_back(UserData.peopleHero);
    UserDataStrings.push_back(UserData.peopleInfluence);
    UserDataStrings.push_back(UserData.peopleIdentify);
    UserDataStrings.push_back(UserData.peopleCharacter);
    UserDataStrings.push_back(UserData.peopleSummary);
    UserDataStrings.push_back(UserData.spokenWords);
    UserDataStrings.push_back(UserData.spokenSummary);
    UserDataStrings.push_back(UserData.workIdeal);
    UserDataStrings.push_back(UserData.workCreative);
    UserDataStrings.push_back(UserData.workStructure);
    UserDataStrings.push_back(UserData.workUndefined);
    UserDataStrings.push_back(UserData.workSummary);
    UserDataStrings.push_back(UserData.theme1);
    UserDataStrings.push_back(UserData.theme1c);
    UserDataStrings.push_back(UserData.theme2);
    UserDataStrings.push_back(UserData.theme2c);
    UserDataStrings.push_back(UserData.theme3);
    UserDataStrings.push_back(UserData.theme3c);
    UserDataStrings.push_back(UserData.theme4);
    UserDataStrings.push_back(UserData.theme4c);
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
    UserData.interests.push_back("Interest 1");
    UserData.interests.push_back("Interest 2");
    UserData.interests.push_back("Interest 3");
    UserData.interests.push_back("Interest 4");
    UserData.interests.push_back("Interest 5");
    UserData.interestsPerc.push_back("10");
    UserData.interestsPerc.push_back("20");
    UserData.interestsPerc.push_back("30");
    UserData.interestsPerc.push_back("40");
    UserData.interestsPerc.push_back("50");
    UserData.subInterests.push_back("Sub Interest 1");
    UserData.subInterests.push_back("Sub Interest 2");
    UserData.subInterests.push_back("Sub Interest 3");
    UserData.subInterestsPerc.push_back("60");
    UserData.subInterestsPerc.push_back("70");
    UserData.subInterestsPerc.push_back("80");
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

    UserData.strengths.push_back("Str 1");
    UserData.strengths.push_back("Str 2");
    UserData.strengths.push_back("Str 3");
    UserData.strengths.push_back("Str 4");
    UserData.strengths.push_back("Str 5");
    UserData.strengths.push_back("Str 6");
    UserData.strengths.push_back("Str 7");
    UserData.strengths.push_back("Str 8");
    UserData.strengths.push_back("Str 9");
    UserData.strengths.push_back("Str 10");
    UserData.strengths.push_back("Str 11");
    UserData.strengths.push_back("Str 12");
    UserData.strengths.push_back("Str 13");
    UserData.strengths.push_back("Str 14");
    UserData.strengths.push_back("Str 15");
    UserData.strengths.push_back("Str 16");


    UserData.passionsMovie="Passions Movie";
    UserData.passionsChange="Passions Change";
    UserData.passionsAlive="Passions Alive";
    UserData.passionsGiveUp="Passions Give Up";
    UserData.passionsSummary="Passions Summary";
    UserData.dreamsPasttime="Pasti[me";
    UserData.dreamsChild="Child dreams";
    UserData.dreamsCurrent="curr dreams";
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

    UserData.theme1="Theme 1";
    UserData.theme1c="255, 255, 0";

    UserData.theme2="theme 2";
    UserData.theme2c="255, 0, 0";

    UserData.theme3="Theeme 3";
    UserData.theme3c="0, 255, 0";

    UserData.theme4="Theme 4";
    UserData.theme4c="0, 0, 255";

    return UserData;
}

void compareSafe(User a, User b){

    //NDEBUG std::cout << a.lifeKeys[0] << "\n";
    //NDEBUG std::cout << b.lifeKeys[0] << "\n";

    //NDEBUG if (a.lifeKeys[0] != b.lifeKeys[0])
    //NDEBUG     std::cout << a.lifeKeys[0] << " != " << b.lifeKeys[0] << "\n";

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
    //NDEBUG std::cout << "compare()..." << "\n";

    int failed = 0;

    // Extract the string variables from both objects
    // and place them into vectors
    std::vector<std::string> aStrings, bStrings;
    aStrings = get_strings(a);
    bStrings = get_strings(b);

    //NDEBUG std::cout << aStrings.size() << std::endl;
    // If they are not the same length there is an error
    // Disabled to give more information
    /*
    if (aStrings.size() != bStrings.size())
        return 1;
    */

    //NDEBUG std::cout << "Strings size: " << aStrings.size() << "," << bStrings.size() << std::endl;

    // Loop through all the string elements in the vector
    for (unsigned int i = 0; i < aStrings.size(); i++)
    {
        //NDEBUG std::cout << "String | - " << i << ": " << aStrings[i] << " = " << bStrings[i] << std::endl;
        if (aStrings[i] != bStrings[i])
        {
            //NDEBUG std::cout << "| - " << i << ": " << aStrings[i] << " != " << bStrings[i] << std::endl;
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

    //NDEBUG std::cout << "Vectors size= " << aVectors.size() << "," << bVectors.size() << std::endl;


    // Loop through all the elements in the vector
    for (unsigned int i = 0; i < aVectors.size(); i++)
    {
        // Loop through all the elements in the selected vector i
        for (unsigned int j = 0; j < aVectors[i].size(); j++)
        {
            //NDEBUG std::cout << aVectors.size() << "," << bVectors.size() << "\n";
            //NDEBUG std::cout << aVectors[i].size() << "," << bVectors[i].size() << "\n";

            // Same size, bot accessible
            if (j < aVectors[i].size() && j < bVectors[i].size()) {
                //NDEBUG std::cout << "Vector | - " << i << ": " << aVectors[i][j] << " = " << bVectors[i][j] << std::endl;
                if (aVectors[i][j] != bVectors[i][j])
                {
                    //NDEBUG std::cout << "| - " << i << "," << j << ": " << aVectors[i][j] << " != " << bVectors[i][j] << std::endl;
                    failed = 1;
                }
            }

            // One of them not accisible
            if (aVectors[i].size() != bVectors[i].size()) {
                //NDEBUG std::cout << "Vector Missmatch! " << aVectors[i].size() << "," << bVectors[i].size() << "\n";


                //NDEBUG if (j <= aVectors[i].size())
                    //NDEBUG std::cout << aVectors[i][j] << "\n";

                //NDEBUG if (j <= bVectors[i].size())
                    //NDEBUG std::cout << bVectors[i][j] << "\n";
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
    //UserDataLoad.name = "Fail";

    // Compare if both sets still hold the same data
    // after being saved and loaded
    failed = compare(UserDataSave, UserDataLoad);
    //compareSafe(UserDataSave, UserDataLoad);

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

    if (save_and_load() == 1) {
        std::cout << "save_and_load(): FAIL\n";
        failed = 1;
     } else
        std::cout << "save_and_load(): PASS\n";

    return failed;
}
