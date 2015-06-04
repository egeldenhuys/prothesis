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

//=================================
// the actual class
class User
{
    public:

        // User info
        std::string name;
        std::string surname;
        std::string mbti;
        std::vector<std::string> lifeKeys;

        std::vector<std::string> roles; // The names of the checked roles
        std::vector<std::string> skills;

        // Passions
        std::string passionsMovie;
        std::string passionsOneThing;
        std::string passionsChange;
        std::string passionsAlive;
        std::string passionsGiveUp;
        std::string passionsSummary;

        // Dreams
        std::string dreamsPasttime;
        std::string dreamsChildDreams;
        std::string dreamsCurrentDreams;
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

        int save();
        int load();
        bool _matchesVar(std::string VarName);
        int _addToVar(std::string varName, std::string value);
        int _remove_by_name(std::vector<std::string> &vecToSearch, std::string itemText);
        int vector_contains(std::vector<char> vec, char findChar);
        std::string encode(std::string text);
        std::string decode(std::string text);

};

#endif // __USER_H_INCLUDED__
