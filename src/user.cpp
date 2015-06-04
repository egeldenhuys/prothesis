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


    std::ofstream outf;
    outf.open("User_Data.dat");

    // If we could not open file for writing
    if (!outf)
    {
        std::cerr << "ERROR: Unable to create user data file!" << std::endl;
        return 1;
    }

    outf << "[name]" << std::endl;
    outf << encode(name) << std::endl;
    outf << "[surname]" << std::endl;
    outf << encode(surname) << std::endl;
    outf << "[mbti]" << std::endl;
    outf << encode(mbti) << std::endl;

    outf << "[lifeKeys]" << std::endl;
    for (unsigned int i = 0; i < lifeKeys.size(); i++)
        outf << encode(lifeKeys[i]) << std::endl;

    outf << "[roles]" << std::endl;
        for (unsigned int i = 0; i < roles.size(); i++)
        outf << encode(roles[i]) << std::endl;

    outf << "[skills]" << std::endl;
    for (unsigned int i = 0; i < skills.size(); i++)
        outf << encode(skills[i]) << std::endl;

    // Passions
    // ========
    outf << "[passionsMovie]" << std::endl;
    outf << encode(passionsMovie) << std::endl;
    outf << "[passionsChange]" << std::endl;
    outf << encode(passionsChange) << std::endl;
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
    outf << "[dreamsChildDreams]" << std::endl;
    outf << encode(dreamsChildDreams) << std::endl;
    outf << "[dreamsCurrentDreams]" << std::endl;
    outf << encode(dreamsCurrentDreams) << std::endl;
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

    if (varName == "[name]")
        name = decode(value);
    else if (varName == "[surname]")
        surname = decode(value);
    else if (varName == "[mbti]")
        mbti = decode(value);
    else if (varName == "[lifeKeys]" && lifeKeys.size() <= LIFE_KEYS_MAX)
        lifeKeys.push_back(decode(value));
    else if (varName == "[roles]" && roles.size() <= ROLES_MAX)
        roles.push_back(decode(value));
    else if (varName == "[skills]")
        skills.push_back(decode(value));
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
    else if (varName == "[dreamsChildDreams]")
        dreamsChildDreams = decode(value);
    else if (varName == "[dreamsCurrentDreams]")
        dreamsCurrentDreams = decode(value);
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
