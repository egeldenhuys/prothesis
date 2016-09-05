#include "user.h"

#define LIFE_KEYS_MAX 7
#define ROLES_MAX 7


/*
#define SKILLS_MAX -1
#define PEOPLE_MAX -1
#define PRIORITIES_MAX -1
*/

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
int User::vector_contains(std::vector<char> vec, char findChar)
=========================
Description:
    Checks if the given vector contains the given character
    and returns its position in the vector if found, otherwise -1

Paramaters:
    vec      - The vector of characters to search in
    findChar - The character to search for in the vector

Example:
    vector<char> names {'a', 'b', 'c'};
    cout << vector_contains(names, 'c');
    // 2
    cout << vector_contains(names, 'g');
    // -1

Returns:
    If found, The position of the element in the vector.
    If not found, -1
*/
int User::vector_contains(std::vector<char> vec, char findChar)
{

    // Loop through the vector
    for (unsigned int i = 0; i < vec.size(); i++)
    {
   // std::cout << i << std::endl;

        if (vec[i] == findChar)
        {
            return i;
        }
    }

    return -1;

}

/*
std::string User::decode(std::string text)
========================
Description:
    Decode the given string to add special characters

Special Characters:
    [ <- &%1
    ] <- &%2

Paramaters:
    text - The text to encode

Example:
    cout << decode("&%1lolcat&%2");
    // [lolcat]

Returns:
    Returns the decoded string.
*/
std::string User::decode(std::string text)
{
    std::vector<std::string> specialsA;
    std::vector<std::string> specialsB;

    specialsA.push_back("[");
    specialsB.push_back("&%1");

    specialsA.push_back("]");
    specialsB.push_back("&%2");

    specialsA.push_back("\n");
    specialsB.push_back("&%3");

    std::size_t foundLoc = 0;
    // Find and replace each element from specialsB with specialsA
    // in the given string

    // Loop through each element in specialsB
    for (unsigned int i = 0; i < specialsB.size(); i++)
    {
        // Reset the found location for the next search
        foundLoc = 0;

        // Loop until all occurences have been found and replaced
        while (foundLoc != std::string::npos)
        {
            foundLoc = text.find(specialsB[i]);

            if (foundLoc != std::string::npos)
                text.replace(foundLoc, specialsB[i].length(), specialsA[i]);

        } // End while

    } // End for

    return text;

}

/*
std::string User::encode(std::string text)
========================
Description:
    Encode the given string to remove special characters

Special Characters:
    [ -> &%1
    ] -> &%2

Paramaters:
    text - The text to encode

Example:
    cout << encode("[lolcat]");
    // &%1lolcat&%2

Returns:
    Returns the encoded string.
*/
std::string User::encode(std::string text)
{
    std::vector<char> specialsA;
    std::vector<std::string> specialsB;

    specialsA.push_back('[');
    specialsB.push_back("&%1");

    specialsA.push_back(']');
    specialsB.push_back("&%2");

    specialsA.push_back('\n');
    specialsB.push_back("&%3");

    int specLoc = 0;

    // Loop through every character in the string
    for (unsigned int i = 0; i < text.length(); i++)
    {
        // Determine if the character is a special, get its location
        // in the vector
        specLoc = vector_contains(specialsA, text.at(i));

        // Check if that character is a special character
        if (specLoc != -1)
        {
            // Replace that char with the encoding
            // i - the position the character was found
            text.replace(text.begin()+i, text.begin()+i+1, specialsB[specLoc]);
        }
    }

    return text;

}
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

    std::stringstream writeBuffer;


    std::ofstream outf;

    outf.open("User_Data.dat");

    // If we could not open file for writing
    if (!outf)
    {
        std::cerr << "ERROR: Unable to create user data file!" << std::endl;
        return 1;
    }

    // START replace writeBuffer with outf

    outf << "[name]" << std::endl;
    outf << encode(name) << std::endl;
    outf << "[surname]" << std::endl;
    outf << encode(surname) << std::endl;
    outf << "[mbti]" << std::endl;
    outf << encode(mbti) << std::endl;

    outf << "[lifeKeys]" << std::endl;
    for (unsigned int i = 0; i < lifeKeys.size(); i++)
        outf << encode(lifeKeys[i]) << std::endl;

    outf << "[interests]" << std::endl;
    for (unsigned int i = 0; i < interests.size(); i++)
        outf << encode(interests[i]) << std::endl;

    outf << "[interestsPerc]" << std::endl;
    for (unsigned int i = 0; i < interestsPerc.size(); i++)
        outf << encode(interestsPerc[i]) << std::endl;

    outf << "[subInterests]" << std::endl;
    for (unsigned int i = 0; i < subInterests.size(); i++)
        outf << encode(subInterests[i]) << std::endl;

    outf << "[subInterestsPerc]" << std::endl;
    for (unsigned int i = 0; i < subInterestsPerc.size(); i++)
        outf << encode(subInterestsPerc[i]) << std::endl;

    outf << "[roles]" << std::endl;
        for (unsigned int i = 0; i < roles.size(); i++)
        outf << encode(roles[i]) << std::endl;

    outf << "[skills]" << std::endl;
    for (unsigned int i = 0; i < skills.size(); i++)
        outf << encode(skills[i]) << std::endl;

    outf << "[strengths]" << std::endl;
    for (unsigned int i = 0; i < strengths.size(); i++)
        outf << encode(strengths[i]) << std::endl;

    // Passions
    // ========
    outf << "[passionsMovie]" << std::endl;
    outf << encode(passionsMovie) << std::endl;
    outf << "[passionsChange]" << std::endl;
    outf << encode(passionsChange) << std::endl;
    outf << "[passionsOneThing]" << std::endl;
    outf << encode(passionsOneThing) << std::endl;
    outf << "[passionsAlive]" << std::endl;
    outf << encode(passionsAlive) << std::endl;
    outf << "[passionsGiveUp]" << std::endl;
    outf << encode(passionsGiveUp) << std::endl;
    outf << "[passionsSummary]" << std::endl;
    outf << encode(passionsSummary) << std::endl;

    // Dreams
    // ======
    outf << "[dreamsPasttime]" << std::endl;
    outf << encode(dreamsPasttime) << std::endl;
    outf << "[dreamsChild]" << std::endl;
    outf << encode(dreamsChild) << std::endl;
    outf << "[dreamsCurrent]" << std::endl;
    outf << encode(dreamsCurrent) << std::endl;
    outf << "[dreamsSummary]" << std::endl;
    outf << encode(dreamsSummary) << std::endl;

    // People
    // ======
    outf << "[peopleHero]" << std::endl;
    outf << encode(peopleHero) << std::endl;
    outf << "[peopleInfluence]" << std::endl;
    outf << encode(peopleInfluence) << std::endl;
    outf << "[peopleIdentify]" << std::endl;
    outf << encode(peopleIdentify) << std::endl;
    outf << "[peopleCharacter]" << std::endl;
    outf << encode(peopleCharacter) << std::endl;
    outf << "[peopleSummary]" << std::endl;
    outf << encode(peopleSummary) << std::endl;


    // Spoken Words
    // ============
    outf << "[spokenWords]" << std::endl;
    outf << encode(spokenWords) << std::endl;
    outf << "[spokenSummary]" << std::endl;
    outf << encode(spokenSummary) << std::endl;

    // Career
    // ======
    outf << "[people]" << std::endl;
    for (unsigned int i = 0; i < people.size(); i++)
        outf << encode(people[i]) << std::endl;

    outf << "[priorities]" << std::endl;
    for (unsigned int i = 0; i < priorities.size(); i++)
        outf << encode(priorities[i]) << std::endl;

    outf << "[workIdeal]" << std::endl;
    outf << encode(workIdeal) << std::endl;
    outf << "[workCreative]" << std::endl;
    outf << encode(workCreative) << std::endl;
    outf << "[workStructure]" << std::endl;
    outf << encode(workStructure) << std::endl;
    outf << "[workUndefined]" << std::endl;
    outf << encode(workUndefined) << std::endl;
    outf << "[workSummary]" << std::endl;
    outf << encode(workSummary) << std::endl;

    // Analysis
    outf << "[theme1]" << std::endl;
    outf << encode(theme1) << std::endl;

    outf << "[theme1c]" << std::endl;
    outf << encode(theme1c) << std::endl;

    outf << "[theme2]" << std::endl;
    outf << encode(theme2) << std::endl;

    outf << "[theme2c]" << std::endl;
    outf << encode(theme2c) << std::endl;

    outf << "[theme3]" << std::endl;
    outf << encode(theme3) << std::endl;

    outf << "[theme3c]" << std::endl;
    outf << encode(theme3c) << std::endl;

    outf << "[theme4]" << std::endl;
    outf << encode(theme4) << std::endl;

    outf << "[theme4c]" << std::endl;
    outf << encode(theme4c) << std::endl;

    outf << "[buttonsRoleNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsRoleNames.size(); i++)
        outf << encode(buttonsRoleNames[i]) << std::endl;

    outf << "[buttonsRoleColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsRoleColours.size(); i++)
        outf << encode(buttonsRoleColours[i]) << std::endl;

    outf << "[buttonsSkillsNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsSkillsNames.size(); i++)
        outf << encode(buttonsSkillsNames[i]) << std::endl;

    outf << "[buttonsSkillsColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsSkillsColours.size(); i++)
        outf << encode(buttonsSkillsColours[i]) << std::endl;

    outf << "[buttonsPrioritiesNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsPrioritiesNames.size(); i++)
        outf << encode(buttonsPrioritiesNames[i]) << std::endl;

    outf << "[buttonsPrioritiesColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsPrioritiesColours.size(); i++)
        outf << encode(buttonsPrioritiesColours[i]) << std::endl;

    outf << "[buttonsPeopleNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsPeopleNames.size(); i++)
        outf << encode(buttonsPeopleNames[i]) << std::endl;

    outf << "[buttonsPeopleColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsPeopleColours.size(); i++)
        outf << encode(buttonsPeopleColours[i]) << std::endl;

    outf << "[buttonsStrengthsNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsStrengthsNames.size(); i++)
        outf << encode(buttonsStrengthsNames[i]) << std::endl;

    outf << "[buttonsStrengthsColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsStrengthsColours.size(); i++)
        outf << encode(buttonsStrengthsColours[i]) << std::endl;

    outf << "[buttonsLifeKeysNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsLifeKeysNames.size(); i++)
        outf << encode(buttonsLifeKeysNames[i]) << std::endl;

    outf << "[buttonsLifeKeysColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsLifeKeysColours.size(); i++)
        outf << encode(buttonsLifeKeysColours[i]) << std::endl;

    outf << "[recommendation]" << std::endl;
    outf << encode(recommendation) << std::endl;

    // END replace writeBuffer with outf
    //outf << writeBuffer.rdbuf();

    outf.close();

    // TODO: Why return -1?
    return -1;
}

/*
User::_addToVar(string varName, string value)
===============
Description:
    Adds the string value to the variable in the User class represented by varName
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
    // DEBUG
    //std::cout << varName << "=" << value << std::endl;

    if (varName == "[name]")
        name = decode(value);
    else if (varName == "[surname]")
        surname = decode(value);
    else if (varName == "[mbti]")
        mbti = decode(value);
    else if (varName == "[lifeKeys]")
        lifeKeys.push_back(decode(value));
    else if (varName == "[interests]")
        interests.push_back(decode(value));
    else if (varName == "[interestsPerc]")
        interestsPerc.push_back(decode(value));
    else if (varName == "[subInterests]")
        subInterests.push_back(decode(value));
    else if (varName == "[subInterestsPerc]")
        subInterestsPerc.push_back(decode(value));
    else if (varName == "[roles]")
        roles.push_back(decode(value));
    else if (varName == "[skills]")
        skills.push_back(decode(value));
    else if (varName == "[strengths]")
        strengths.push_back(decode(value));
    else if (varName == "[passionsMovie]")
        passionsMovie = decode(value);
    else if (varName == "[passionsOneThing]")
        passionsOneThing = decode(value);
    else if (varName == "[passionsChange]")
        passionsChange = decode(value);
    else if (varName == "[passionsAlive]")
        passionsAlive = decode(value);
    else if (varName == "[passionsGiveUp]")
        passionsGiveUp = decode(value);
    else if (varName == "[passionsSummary]")
        passionsSummary = decode(value);
    else if (varName == "[dreamsPasttime]")
        dreamsPasttime = decode(value);
    else if (varName == "[dreamsChild]")
        dreamsChild = decode(value);
    else if (varName == "[dreamsCurrent]")
        dreamsCurrent = decode(value);
    else if (varName == "[dreamsSummary]")
        dreamsSummary = decode(value);
    else if (varName == "[peopleHero]")
        peopleHero = decode(value);
    else if (varName == "[peopleInfluence]")
        peopleInfluence = decode(value);
    else if (varName == "[peopleIdentify]")
        peopleIdentify = decode(value);
    else if (varName == "[peopleCharacter]")
        peopleCharacter = decode(value);
    else if (varName == "[peopleSummary]")
        peopleSummary = decode(value);
    else if (varName == "[spokenWords]")
        spokenWords = decode(value);
    else if (varName == "[spokenSummary]")
        spokenSummary = decode(value);
    else if (varName == "[people]")
        people.push_back(decode(value));
    else if (varName == "[priorities]")
        priorities.push_back(decode(value));
    else if (varName == "[workIdeal]")
        workIdeal = decode(value);
    else if (varName == "[workCreative]")
        workCreative = decode(value);
    else if (varName == "[workStructure]")
        workStructure = decode(value);
    else if (varName == "[workUndefined]")
        workUndefined = decode(value);
    else if (varName == "[workSummary]")
        workSummary = decode(value);
    else if (varName == "[theme1]")
        theme1 = decode(value);
    else if (varName == "[theme1c]")
        theme1c = decode(value);
    else if (varName == "[theme2]")
        theme2 = decode(value);
    else if (varName == "[theme2c]")
        theme2c = decode(value);
    else if (varName == "[theme3]")
        theme3 = decode(value);
    else if (varName == "[theme3c]")
        theme3c = decode(value);
    else if (varName == "[theme4]")
        theme4 = decode(value);
    else if (varName == "[theme4c]")
        theme4c = decode(value);
    else if (varName == "[buttonsRoleNames]")
        buttonsRoleNames.push_back(decode(value));
    else if (varName == "[buttonsRoleColours]")
        buttonsRoleColours.push_back(decode(value));
    else if (varName == "[buttonsSkillsNames]")
        buttonsSkillsNames.push_back(decode(value));
    else if (varName == "[buttonsSkillsColours]")
        buttonsSkillsColours.push_back(decode(value));
    else if (varName == "[buttonsPrioritiesNames]")
        buttonsPrioritiesNames.push_back(decode(value));
    else if (varName == "[buttonsPrioritiesColours]")
        buttonsPrioritiesColours.push_back(decode(value));
    else if (varName == "[buttonsPeopleNames]")
        buttonsPeopleNames.push_back(decode(value));
    else if (varName == "[buttonsPeopleColours]")
        buttonsPeopleColours.push_back(decode(value));
    else if (varName == "[buttonsStrengthsNames]")
        buttonsStrengthsNames.push_back(decode(value));
    else if (varName == "[buttonsStrengthsColours]")
        buttonsStrengthsColours.push_back(decode(value));
    else if (varName == "[buttonsLifeKeysNames]")
        buttonsLifeKeysNames.push_back(decode(value));
    else if (varName == "[buttonsLifeKeysColours]")
        buttonsLifeKeysColours.push_back(decode(value));
    else if (varName == "[recommendation]")
        recommendation = decode(value);

    return 0;
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
    // DEBUG
    //std::cout << "Matching: " << varName << " : ";

    bool value = false;

    // Change this!
    const int COUNT = 56;

    std::string varNames [COUNT] = {
    "[name]", "[surname]", "[mbti]",
    "[lifeKeys]", "[interests]", "[interestsPerc]",
    "[subInterests]", "[subInterestsPerc]", "[roles]", "[skills]", "[passionsMovie]",
    "[passionsOneThing]", "[passionsChange]", "[passionsAlive]",
    "[passionsGiveUp]", "[passionsSummary]", "[dreamsPasttime]",
    "[dreamsChild]", "[dreamsCurrent]",
    "[dreamsSummary]", "[peopleHero]", "[peopleInfluence]",
    "[peopleIdentify]", "[peopleCharacter]", "[peopleSummary]",
    "[spokenWords]", "[spokenSummary]", "[people]", "[priorities]",
    "[workIdeal]", "[workCreative]", "[workStructure]",
    "[workUndefined]", "[workSummary]", "[strengths]",
    "[theme1]", "[theme1c]", "[theme2]", "[theme2c]",
    "[theme3]", "[theme3c]", "[theme4]", "[theme4c]",
        "[buttonsRoleColours]", "[buttonsRoleNames]", "[buttonsSkillsNames]",
        "[buttonsSkillsColours]", "[buttonsPrioritiesNames]",
        "[buttonsPrioritiesColours]", "[buttonsPeopleNames]",
        "[buttonsPeopleColours]", "[buttonsStrengthsNames]",
        "[buttonsStrengthsColours]", "[buttonsLifeKeysNames]",
        "[buttonsLifeKeysColours]", "[recommendation]"

    };

    //print_vector(varNames);

    for (int i = 0; i < COUNT; i++)
    {
        // DEBUG
        //std::cout << varNames[i] << std::endl;

        if (varNames[i] == varName)
        {
            value = true;

        }
    }
    // DEBUG
    //std::cout << value << "\n";

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
        //std::cout << "line=" << line << std::endl;
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
            // DEBUG
            // std::cout << "Loading: " << varName << " <--- " << line << "\n";
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
