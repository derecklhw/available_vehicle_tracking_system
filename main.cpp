/*
    main.cpp
    Author: M00826933
    Created: 22/12/22
    Updated: 13/12/22
*/

#include "program.h"


int main(int argc, char *argv[])
{
    std::cout << "Vehicle-Tracker for linux using c++" << std::endl
              << "Copyright (c) 2023, M00826933" << std::endl
              << std::endl;

    const int NUMBEROFARGUMENTS = argc;

    // check number of arguments
    if (!checkNumberOfArguments(NUMBEROFARGUMENTS))
    {
        return 1;
    };

    const std::string FILENAME = argv[1];

    // check if the file exists and load the vehicle details from file
    if (checkFile(FILENAME))
    {   
        prepareFile(FILENAME);
        mainMenu(FILENAME);
        return 0;
    }
    else
    {
        return 1;
    }

    return 0;
}
