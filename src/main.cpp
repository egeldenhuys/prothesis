#include <iostream>
#include "user.h"

using namespace std;



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

User UserData;

int main()
{

    return 0;
}
