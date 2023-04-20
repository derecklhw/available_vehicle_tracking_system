#ifndef _CHECK_H_
#define _CHECK_H_

/*
    check.h
    Author: M00826933
    Created: 03/01/23
    Updated: 13/12/22
*/
#include "struct.h"
#include "vehicle.h"
#include "motorcycle.h"
#include "car.h"
#include "van.h"

#include <iostream>
#include <string>

/*
    Check the number of arguments passed from cmd and display appropriate error message
    @param no parameter
    @return bool
*/
bool checkNumberOfArguments(int numberOfCommandLineArgument);

/*
    Check if the file exists and display appropriate error message
    @param std::string
    @return bool
*/
bool checkFile(const std::string &FILENAME);

/*
    Determine the number of vehicles to be loaded from the file
    @param std::string
    @return int
*/
int determineSize(const std::string &FILENAME);

/*
    Determine the size of dyanmic array to be created and load the vehicles from files
    @param std::string
    @return void
*/
void prepareFile(const std::string &FILENAME);

/*
    Loading the vehicles from the file and assign them to a dynamic array
    @param std::string
    @return void
*/
void loadFile(const std::string &FILENAME);

/*
    Display the main menu where different options will be displayed
    @param std::string
    @return void
*/
void mainMenu(const std::string &FILENAME);

/*
    Clear the screen and display a header message
    @param std::string
    @return void
*/
void printOptionHeader(std::string header);

/*
    Check if the user inputted Y/N and display appropriate error message
    @param std::string
    @return bool
*/
bool checkUserConfirmation(std::string &choice);

/*
    Add vehicle option
    @param none
    @return void
*/
void addVehicle();

/*
    Check the added vehicles details if they correspond to the proper datatypes
    @param addVehicleDetailsStruct
    @return void
*/
void checkAddVehicleDetails(addVehicleDetailsStruct &addVehicleDetailsObject);

/*
    Check the registration number of the added vehicle with the current database
    @param addVehicleDetailsStruct
    @return bool
*/
bool checkAddVehicleRegistrationNumber(addVehicleDetailsStruct &addVehicleDetailsObject);

/*
    Display summary of added vehicle before confirmation
    @param addVehicleDetailsStruct
    @param std::string
    @return void
*/
void displaySummary(addVehicleDetailsStruct &addVehicleDetailsObject, std::string engineSizeString);

/*
    Resize the dynamic array if it is too small to store anymore data
    @param addVehicleDetailsStruct
    @return bool
*/
bool resizeDynamicArray(addVehicleDetailsStruct &addVehicleDetailsObject);

/*
    Assign the added vehicle details to an position in the dynamic array
    @param details
    @param addVehicleDetailsStruct
    @return void
*/
void assignAddVehicle(details *&structVehicleDetails, addVehicleDetailsStruct &addVehicleDetailsObject);

/*
    Remove vehicle option 
    @param none
    @return void
*/
void removeVehicle();

/*
    Display details of a specific vehicle 
    @param none
    @return void
*/
bool displayDetailsOfSpecificVehicle();

/*
    Check registration number if present in database and return to main menu if incorrect
    @param std::string
    @param std::string
    @param int
    @return bool
*/
bool checkCorrectRegistrationNumber(std::string selectedRegistrationNumber, std::string &vehicleCategory, int &vehicleIndex);

/*
    List all vehicle option
    @param none
    @return void
*/
void listAll();

/*
    Loop for the dynamic array and create a vector of vehicle class 
    @param none
    @return void
*/
void assignVehicleArrayToVector();

/*
    Draw top and bottom of table
    @param char
    @param char
    @param int
    @return void
*/
void drawTopBottomBorderTable(char intersectionBorder, char topBottomBorder, int colWidth);

/*
    Display and perform the functionality of press any key to continue
    @return void
*/
void drawPressAnyKey();

/*
    Quit option
    @return void
*/
void quit(const std::string &FILENAME);

/*
    Save data option
    @param std::string
    @return void
*/
void saveData(const std::string &FILENAME);

#endif