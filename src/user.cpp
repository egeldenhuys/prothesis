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

    writeBuffer << "[name]" << std::endl;
    writeBuffer << encode(name) << std::endl;
    writeBuffer << "[surname]" << std::endl;
    writeBuffer << encode(surname) << std::endl;
    writeBuffer << "[mbti]" << std::endl;
    writeBuffer << encode(mbti) << std::endl;

    writeBuffer << "[lifeKeys]" << std::endl;
    for (unsigned int i = 0; i < lifeKeys.size(); i++)
        writeBuffer << encode(lifeKeys[i]) << std::endl;

    writeBuffer << "[interests]" << std::endl;
    for (unsigned int i = 0; i < interests.size(); i++)
        writeBuffer << encode(interests[i]) << std::endl;

    writeBuffer << "[interestsPerc]" << std::endl;
    for (unsigned int i = 0; i < interestsPerc.size(); i++)
        writeBuffer << encode(interestsPerc[i]) << std::endl;

    writeBuffer << "[subInterests]" << std::endl;
    for (unsigned int i = 0; i < subInterests.size(); i++)
        writeBuffer << encode(subInterests[i]) << std::endl;

    writeBuffer << "[subInterestsPerc]" << std::endl;
    for (unsigned int i = 0; i < subInterestsPerc.size(); i++)
        writeBuffer << encode(subInterestsPerc[i]) << std::endl;

    writeBuffer << "[roles]" << std::endl;
        for (unsigned int i = 0; i < roles.size(); i++)
        writeBuffer << encode(roles[i]) << std::endl;

    writeBuffer << "[skills]" << std::endl;
    for (unsigned int i = 0; i < skills.size(); i++)
        writeBuffer << encode(skills[i]) << std::endl;

    writeBuffer << "[strengths]" << std::endl;
    for (unsigned int i = 0; i < strengths.size(); i++)
        writeBuffer << encode(strengths[i]) << std::endl;

    // Passions
    // ========
    writeBuffer << "[passionsMovie]" << std::endl;
    writeBuffer << encode(passionsMovie) << std::endl;
    writeBuffer << "[passionsChange]" << std::endl;
    writeBuffer << encode(passionsChange) << std::endl;
    writeBuffer << "[passionsAlive]" << std::endl;
    writeBuffer << encode(passionsAlive) << std::endl;
    writeBuffer << "[passionsGiveUp]" << std::endl;
    writeBuffer << encode(passionsGiveUp) << std::endl;
    writeBuffer << "[passionsSummary]" << std::endl;
    writeBuffer << encode(passionsSummary) << std::endl;

    // Dreams
    // ======
    writeBuffer << "[dreamsPasttime]" << std::endl;
    writeBuffer << encode(dreamsPasttime) << std::endl;
    writeBuffer << "[dreamsChild]" << std::endl;
    writeBuffer << encode(dreamsChild) << std::endl;
    writeBuffer << "[dreamsCurrent]" << std::endl;
    writeBuffer << encode(dreamsCurrent) << std::endl;
    writeBuffer << "[dreamsSummary]" << std::endl;
    writeBuffer << encode(dreamsSummary) << std::endl;

    // People
    // ======
    writeBuffer << "[peopleHero]" << std::endl;
    writeBuffer << encode(peopleHero) << std::endl;
    writeBuffer << "[peopleInfluence]" << std::endl;
    writeBuffer << encode(peopleInfluence) << std::endl;
    writeBuffer << "[peopleIdentify]" << std::endl;
    writeBuffer << encode(peopleIdentify) << std::endl;
    writeBuffer << "[peopleCharacter]" << std::endl;
    writeBuffer << encode(peopleCharacter) << std::endl;
    writeBuffer << "[peopleSummary]" << std::endl;
    writeBuffer << encode(peopleSummary) << std::endl;


    // Spoken Words
    // ============
    writeBuffer << "[spokenWords]" << std::endl;
    writeBuffer << encode(spokenWords) << std::endl;
    writeBuffer << "[spokenSummary]" << std::endl;
    writeBuffer << encode(spokenSummary) << std::endl;

    // Career
    // ======
    writeBuffer << "[people]" << std::endl;
    for (unsigned int i = 0; i < people.size(); i++)
        writeBuffer << encode(people[i]) << std::endl;

    writeBuffer << "[priorities]" << std::endl;
    for (unsigned int i = 0; i < priorities.size(); i++)
        writeBuffer << encode(priorities[i]) << std::endl;

    writeBuffer << "[workIdeal]" << std::endl;
    writeBuffer << encode(workIdeal) << std::endl;
    writeBuffer << "[workCreative]" << std::endl;
    writeBuffer << encode(workCreative) << std::endl;
    writeBuffer << "[workStructure]" << std::endl;
    writeBuffer << encode(workStructure) << std::endl;
    writeBuffer << "[workUndefined]" << std::endl;
    writeBuffer << encode(workUndefined) << std::endl;
    writeBuffer << "[workSummary]" << std::endl;
    writeBuffer << encode(workSummary) << std::endl;

    // Analysis
    writeBuffer << "[theme1]" << std::endl;
    writeBuffer << encode(theme1) << std::endl;

    writeBuffer << "[theme1c]" << std::endl;
    writeBuffer << encode(theme1c) << std::endl;

    writeBuffer << "[theme2]" << std::endl;
    writeBuffer << encode(theme2) << std::endl;

    writeBuffer << "[theme2c]" << std::endl;
    writeBuffer << encode(theme2c) << std::endl;

    writeBuffer << "[theme3]" << std::endl;
    writeBuffer << encode(theme3) << std::endl;

    writeBuffer << "[theme3c]" << std::endl;
    writeBuffer << encode(theme3c) << std::endl;

    writeBuffer << "[theme4]" << std::endl;
    writeBuffer << encode(theme4) << std::endl;

    writeBuffer << "[theme4c]" << std::endl;
    writeBuffer << encode(theme4c) << std::endl;

    writeBuffer << "[buttonsRoleNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsRoleNames.size(); i++)
        writeBuffer << encode(buttonsRoleNames[i]) << std::endl;

    writeBuffer << "[buttonsRoleColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsRoleColours.size(); i++)
        writeBuffer << encode(buttonsRoleColours[i]) << std::endl;

    writeBuffer << "[buttonsSkillsNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsSkillsNames.size(); i++)
        writeBuffer << encode(buttonsSkillsNames[i]) << std::endl;

    writeBuffer << "[buttonsSkillsColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsSkillsColours.size(); i++)
        writeBuffer << encode(buttonsSkillsColours[i]) << std::endl;

    writeBuffer << "[buttonsPrioritiesNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsPrioritiesNames.size(); i++)
        writeBuffer << encode(buttonsPrioritiesNames[i]) << std::endl;

    writeBuffer << "[buttonsPrioritiesColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsPrioritiesColours.size(); i++)
        writeBuffer << encode(buttonsPrioritiesColours[i]) << std::endl;

    writeBuffer << "[buttonsPeopleNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsPeopleNames.size(); i++)
        writeBuffer << encode(buttonsPeopleNames[i]) << std::endl;

    writeBuffer << "[buttonsPeopleColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsPeopleColours.size(); i++)
        writeBuffer << encode(buttonsPeopleColours[i]) << std::endl;

    writeBuffer << "[buttonsStrengthsNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsStrengthsNames.size(); i++)
        writeBuffer << encode(buttonsStrengthsNames[i]) << std::endl;

    writeBuffer << "[buttonsStrengthsColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsStrengthsColours.size(); i++)
        writeBuffer << encode(buttonsStrengthsColours[i]) << std::endl;

    writeBuffer << "[buttonsLifeKeysNames]" << std::endl;
    for (unsigned int i = 0; i < buttonsLifeKeysNames.size(); i++)
        writeBuffer << encode(buttonsLifeKeysNames[i]) << std::endl;

    writeBuffer << "[buttonsLifeKeysColours]" << std::endl;
    for (unsigned int i = 0; i < buttonsLifeKeysColours.size(); i++)
        writeBuffer << encode(buttonsLifeKeysColours[i]) << std::endl;

    writeBuffer << "[recommendation]" << std::endl;
    writeBuffer << encode(recommendation) << std::endl;

    outf << writeBuffer.rdbuf();

    outf.close();

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
