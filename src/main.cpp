/*
main.cpp
========

*/

#include <iostream>
#include "user.h"
#include "tests.h"
#include "globals.h"

using namespace std;

int main()
{
    int result = 0;

    result = run_tests();

    return result;
}
