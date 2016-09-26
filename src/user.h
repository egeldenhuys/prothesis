/*
User.h
====
Description:
    This class will be used to store and manage the user data

Example:
    User userData;
    userData.load();
    userData.Roles.push_back("analyzer");
    userData.save();
*/

//=================================
// include guard
#ifndef __USER_H_INCLUDED__
#define __USER_H_INCLUDED__

//=================================
// included dependencies
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

//=================================
// the actual class
class User
{
    public:

    /* Adding a new Variable
     * 1. Add declaration to header
     * 2. Add code to Saving function
     * 3. Add code to AddToVar
     * 4. Add code to MatchesVar
     * 5. Add code to tests.cpp, get_strings or get_vectors
     * 6. Add code to tests.cpp, set_user_data
    */

    std::string recommendation;

    std::vector<std::string> buttonsRoleNames;
    std::vector<std::string> buttonsRoleColours;

    std::vector<std::string> buttonsSkillsNames;
    std::vector<std::string> buttonsSkillsColours;

    std::vector<std::string> buttonsPrioritiesNames;
    std::vector<std::string> buttonsPrioritiesColours;

    std::vector<std::string> buttonsPeopleNames;
    std::vector<std::string> buttonsPeopleColours;

    std::vector<std::string> buttonsStrengthsNames;
    std::vector<std::string> buttonsStrengthsColours;

    std::vector<std::string> buttonsLifeKeysNames;
    std::vector<std::string> buttonsLifeKeysColours;

    // Analysis
    // c - Colour
    std::string theme1;
    std::string theme1c;
    std::string theme2;
    std::string theme2c;
    std::string theme3;
    std::string theme3c;
    std::string theme4;
    std::string theme4c;

        // User info
        std::string name;
        std::string surname;
        std::string mbti;
        std::vector<std::string> lifeKeys;

        std::vector<std::string> interests;
        std::vector<std::string> interestsPerc;

        std::vector<std::string> subInterests;
        std::vector<std::string> subInterestsPerc;

        std::vector<std::string> roles; // The names of the checked roles
        std::vector<std::string> skills;

        std::vector<std::string> strengths;

        // Passions
        std::string passionsMovie;
        std::string passionsOneThing;
        std::string passionsChange;
        std::string passionsAlive;
        std::string passionsGiveUp;
        std::string passionsSummary;

        // Dreams
        std::string dreamsPasttime;
        std::string dreamsChild;
        std::string dreamsCurrent;
        std::string dreamsSummary;

        // People ID
        std::string peopleHero;
        std::string peopleInfluence;
        std::string peopleIdentify;
        std::string peopleCharacter;
        std::string peopleSummary;

        // Spoken Words
        std::string spokenWords;
        std::string spokenSummary;

        // Career
        // People Orientation
        std::vector<std::string> people;
        std::vector<std::string> priorities;

        // Work environment
        std::string workIdeal;
        std::string workCreative;
        std::string workStructure;
        std::string workUndefined;
        std::string workSummary;

        std::string path; // The path for storting user data
        bool dirtyData; // Flag indicating if the data has changed and needs to be saved


        int save(bool useBuffer = true);
        int load();
        bool _matchesVar(std::string VarName);
        int _addToVar(std::string varName, std::string value);
        int _remove_by_name(std::vector<std::string> &vecToSearch, std::string itemText);
        int vector_contains(std::vector<char> vec, char findChar);
        std::string encode(std::string text);
        std::string decode(std::string text);

};

#endif // __USER_H_INCLUDED__
