/*
    check.cpp
    Author: M00826933
    Created: 13/12/22
    Updated: 13/12/22
*/
#include "program.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>

int currentVehicleSize = 0;
int maxVehicleSize = 0;

details *vehicleDetails;
details *tmpVehicleDetails;

std::vector<Vehicle *> vehicles;

//Check the number of arguments passed from cmd and display appropriate error message
bool checkNumberOfArguments(int numberOfCommandLineArgument)
{
    if (numberOfCommandLineArgument != 2)
    {
        std::cout << "Usage: ./execute <filename>" << std::endl;
        return 0;
    }
    else
    {
        return 1;
    }
};

//Check if the file exists and display appropriate error message
bool checkFile(const std::string &FILENAME)
{
    try
    {
        std::ifstream myFile(FILENAME);
        if (myFile.fail())
        {
            throw 404;
        }
        else
        {
            myFile.close();

            return 1;
        }
    }

    catch (...)
    {
        std::cout << "Error: Such file not found in current directory" << std::endl;
        return 0;
    }
}

//Determine the size of dyanmic array to be created and load the vehicles from files
void prepareFile(const std::string &FILENAME)
{
    determineSize(FILENAME);
    vehicleDetails = new details[currentVehicleSize];
    loadFile(FILENAME);
}

// Determine the number of vehicles to be loaded from the file
int determineSize(const std::string &FILENAME)
{
    std::ifstream myFile(FILENAME);
    std::string myText;

    while (std::getline(myFile, myText))
    {
        currentVehicleSize++;
    }
    maxVehicleSize = currentVehicleSize;
    myFile.close();
    return currentVehicleSize;
};

//Loading the vehicles from the file and assign them to a dynamic array
void loadFile(const std::string &FILENAME)
{
    int vehicleIndexPosition = 0;
    int count = 0;

    std::ifstream myFile(FILENAME);
    std::string myText;
    std::string textDetail;

    // Decompose the file into lines and assign them to a dynamic array of datatype details.

    // Loop thourgh each vehicle
    while (std::getline(myFile, myText))
    {   
        // Loop through each vehicle details 
        std::stringstream ss(myText);
        while (std::getline(ss, textDetail, ':'))
        {
            count++;
            switch (count)
            {
            case 1:
                vehicleDetails[vehicleIndexPosition].type = textDetail;
                break;
            case 2:
                vehicleDetails[vehicleIndexPosition].make = textDetail;
                break;
            case 3:
                vehicleDetails[vehicleIndexPosition].model = textDetail;
                break;
            case 4:
                vehicleDetails[vehicleIndexPosition].pricePerDay = std::stoi(textDetail.substr(textDetail.find("£") + 2));
                ;
                break;
            case 5:
                if (vehicleDetails[vehicleIndexPosition].type == "bike")
                {
                    vehicleDetails[vehicleIndexPosition].engineSize = std::stod(textDetail.substr(0, textDetail.find("cc")));
                }
                else if (vehicleDetails[vehicleIndexPosition].type == "car" || vehicleDetails[vehicleIndexPosition].type == "van")
                {
                    vehicleDetails[vehicleIndexPosition].engineSize = std::stod(textDetail.substr(0, textDetail.find("L")));
                }
                break;
            case 6:
                if (vehicleDetails[vehicleIndexPosition].type == "bike")
                {
                    if (textDetail == "Passenger seat")
                    {
                        vehicleDetails[vehicleIndexPosition].passangerSeat = true;
                    }
                    else if (textDetail == "No Passenger")
                    {
                        vehicleDetails[vehicleIndexPosition].passangerSeat = false;
                    }
                }
                else if (vehicleDetails[vehicleIndexPosition].type == "car" || vehicleDetails[vehicleIndexPosition].type == "van")
                {
                    vehicleDetails[vehicleIndexPosition].numberOfSeats = std::stoi(textDetail.substr(0, textDetail.find("seats")));
                }
                break;
            case 7:
                if (vehicleDetails[vehicleIndexPosition].type == "bike" || vehicleDetails[vehicleIndexPosition].type == "van")
                {
                    if (textDetail == "Has luggage" || textDetail == "15.1 cubic meters luggage space")
                    {
                        vehicleDetails[vehicleIndexPosition].luggageSpace = true;
                    }
                    else
                    {
                        vehicleDetails[vehicleIndexPosition].luggageSpace = false;
                    }
                }
                else if (vehicleDetails[vehicleIndexPosition].type == "car")
                {
                    vehicleDetails[vehicleIndexPosition].numberOfDoor = std::stoi(textDetail.substr(0, textDetail.find("door")));
                }
                break;
            case 8:
                vehicleDetails[vehicleIndexPosition].registrationNumber = textDetail;
                break;
            case 9:
                vehicleDetails[vehicleIndexPosition].colour = textDetail;
                break;
            case 10:
                if (textDetail == "Yes")
                {
                    vehicleDetails[vehicleIndexPosition].availability = true;
                }
                else if (textDetail == "No")
                {
                    vehicleDetails[vehicleIndexPosition].availability = false;
                }
                break;
            case 11:
                vehicleDetails[vehicleIndexPosition].availableDate = textDetail;
                count = 0;
                vehicleIndexPosition++;
                break;
            }
        }
    }

    myFile.close();

    std::cout << "Load vehicles from file \"" << FILENAME << "\" successful." << std::endl
              << std::endl;
};

// Display the main menu where different options will be displayed
void mainMenu(const std::string &FILENAME)
{
    std::string option;

    do
    {
        std::cout << "------------ MAIN MENU ------------" << std::endl;
        std::cout << "1. Add vehicle" << std::endl;
        std::cout << "2. Remove vehicle" << std::endl;
        std::cout << "3. List all vehicles" << std::endl;
        std::cout << "4. Display all details of a vehicle" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << std::endl
                  << "Enter your choice: ";
        std::cin >> option;

        // Add vehicle option
        if (option == "1")
        {
            printOptionHeader("Add Vehicle");
            addVehicle();
        }
        // Remove vehicle option
        else if (option == "2")
        {
            printOptionHeader("Remove Vehicle");
            removeVehicle();
        }
        // List all vehicle option
        else if (option == "3")
        {
            printOptionHeader("List All Vehicles");
            listAll();
        }
        // Display all details of a vehicle option
        else if (option == "4")
        {
            printOptionHeader("Display all details of a vehicle");
            displayDetailsOfSpecificVehicle();
        }
        // Quit option
        else if (option == "5")
        {
            quit(FILENAME);
        }
        else if (option != "5")
        {
            std::cout << std::endl
                      << "Invalid choice. Please enter 1, 2, 3, 4 or 5" << std::endl
                      << std::endl;
        };

    } while (option != "5");
};

// Clear the screen and display a header message
void printOptionHeader(std::string header)
{
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "----------- " << header << " -----------" << std::endl;
};

// Check if the user inputted Y/N and display appropriate error message
bool checkUserConfirmation(std::string &choice)
{
    if (choice != "N" && choice != "Y")
    {
        std::cout << "Wrong input. Enter Y (YES) or N (NO)." << std::endl
                  << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

// Add vehicle option
void addVehicle()
{
    // initialise a user defined struct to store the different details of a vehicle 
    addVehicleDetailsStruct addVehicleDetailsObject;

    checkAddVehicleDetails(addVehicleDetailsObject);

    printOptionHeader("SUMMARY");

    // conversion from double to string 
    std::ostringstream engineSizeStream;
    engineSizeStream << addVehicleDetailsObject.addEngineSize;
    std::string engineSizeString = engineSizeStream.str();

    displaySummary(addVehicleDetailsObject, engineSizeString);

    std::string choice;
    bool choiceCheck = true;

    do
    {
        std::cout << "Are you sure to confirm? [Y/N]: ";
        std::cin >> choice;
        choiceCheck = checkUserConfirmation(choice);
    } while (choiceCheck);

    if (choice == "Y")
    {
        resizeDynamicArray(addVehicleDetailsObject);
    }
    else
    {
        std::cout << "Add vehicle is cancelled. Return to main menu." << std::endl
                  << std::endl;
    };
};

//  Check the added vehicles details if they correspond to the proper datatypes
void checkAddVehicleDetails(addVehicleDetailsStruct &addVehicleDetailsObject)
{
    std::string vehicleTypes[3] = {"bike", "car", "van"};
    bool validType = false;
    bool validRegistration = true;

    do
    {
        std::cout << std::endl
                  << "Enter vehicle type: ";
        std::cin >> addVehicleDetailsObject.addType;
        for (std::string t : vehicleTypes)
        {
            if (t == addVehicleDetailsObject.addType)
            {
                validType = true;
                std::cout << "Valid vehicle type selected: " << addVehicleDetailsObject.addType << std::endl;
                break;
            }
        }
        if (!validType)
        {
            std::cout << "Invalid vehicle type. Valid input: bike, car, van" << std::endl;
        }
    } while (!validType);

    // input the details of the new vehicles

    std::cout << std::endl
              << "Enter make: ";
    std::cin >> addVehicleDetailsObject.addMake;
    std::cout << "Enter model: ";
    std::cin >> addVehicleDetailsObject.addModel;

    // executes loop if the input fails (e.g., no characters were read) 
    while (std::cout << "Enter price per day: " && !(std::cin >> addVehicleDetailsObject.addPricePerDay))
    {
        std::cin.clear();                                                   // clear bad input flag 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input 
        std::cout << "Invalid input; please re-enter.\n"
                  << std::endl;
    }

    while (std::cout << "Enter engine size: " && !(std::cin >> addVehicleDetailsObject.addEngineSize))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please re-enter.\n"
                  << std::endl;
    }

    if (addVehicleDetailsObject.addType == "bike")
    {
        while (std::cout << "Any passanger seat? Enter 1 (YES) or 0 (NO): " && !(std::cin >> addVehicleDetailsObject.addPassangerSeat))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input; please re-enter either 1 (YES) or 0 (NO).\n"
                      << std::endl;
        }
    }

    if (addVehicleDetailsObject.addType == "car" || addVehicleDetailsObject.addType == "van")
    {
        while (std::cout << "Enter number of seats: " && !(std::cin >> addVehicleDetailsObject.addNumberOfSeats))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input; please re-enter.\n"
                      << std::endl;
        }
    }

    if (addVehicleDetailsObject.addType == "car")
    {
        while (std::cout << "Enter number of doors: " && !(std::cin >> addVehicleDetailsObject.addNumberOfDoor))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input; please re-enter.\n"
                      << std::endl;
        }
    }

    if (addVehicleDetailsObject.addType == "bike" || addVehicleDetailsObject.addType == "van")
    {
        while (std::cout << "Any luggage space? Enter 1 (YES) or 0 (NO): " && !(std::cin >> addVehicleDetailsObject.addLuggageSpace))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input; please re-enter either 1 (YES) or 0 (NO).\n"
                      << std::endl;
        }
    }

    do
    {
        validRegistration = checkAddVehicleRegistrationNumber(addVehicleDetailsObject);
    }

    while (!validRegistration);

    std::cout << "Enter colour: ";
    std::cin >> addVehicleDetailsObject.addColour;

    while (std::cout << "Vehicle available? Enter 1 (YES) or 0 (NO): " && !(std::cin >> addVehicleDetailsObject.addAvailability))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please re-enter either 1 (YES) or 0 (NO).\n"
                  << std::endl;
    }

    if (!addVehicleDetailsObject.addAvailability)
    {
        std::cout << "Enter available date [DD/MM/YYYY]: ";
        std::cin >> addVehicleDetailsObject.addAvailableDate;
    }
    else
    {
        addVehicleDetailsObject.addAvailableDate = "N/A";
    }
    std::cout << std::endl;
}

// Check the registration number of the added vehicle with the current database
bool checkAddVehicleRegistrationNumber(addVehicleDetailsStruct &addVehicleDetailsObject)
{
    std::cout << "Enter registration number: ";
    std::cin >> addVehicleDetailsObject.addRegistrationNumber;
    for (int i = 0; i < currentVehicleSize; i++)
    {
        if (addVehicleDetailsObject.addRegistrationNumber == vehicleDetails[i].registrationNumber)
        {
            std::cout << "Registration number already exists. Input a correct one." << std::endl
                      << std::endl;
            return false;
        }
    }
    return true;
}

// Display summary of added vehicle before confirmation
void displaySummary(addVehicleDetailsStruct &addVehicleDetailsObject, std::string engineSizeString)
{
    std::cout << "\nType: " + addVehicleDetailsObject.addType +
                     "\nMake: " + addVehicleDetailsObject.addMake +
                     "\nModel: " + addVehicleDetailsObject.addModel +
                     "\nPrice per day: £" + std::to_string(addVehicleDetailsObject.addPricePerDay) +
                     "\n";

    if (addVehicleDetailsObject.addType == "bike")
    {
        std::cout << "Engine size (CC): " << engineSizeString << "cc\n";
    }
    else if (addVehicleDetailsObject.addType == "car" || addVehicleDetailsObject.addType == "van")
    {
        std::cout << "Engine size (litres): " << engineSizeString << "L\n";
    }

    if (addVehicleDetailsObject.addType == "bike")
    {
        std::cout << "Passanger seat: ";
        if (addVehicleDetailsObject.addPassangerSeat)
        {
            std::cout << "Passenger seat" << std::endl;
        }
        else
        {
            std::cout << "No Passenger" << std::endl;
        }
    }
    else if (addVehicleDetailsObject.addType == "car" || addVehicleDetailsObject.addType == "van")
    {
        std::cout << "Number of seats: " << std::to_string(addVehicleDetailsObject.addNumberOfSeats) << " seats" << std::endl;
    }

    if (addVehicleDetailsObject.addType == "bike")
    {
        std::cout << "Luggage space: ";
        if (addVehicleDetailsObject.addLuggageSpace)
        {
            std::cout << "Has luggage" << std::endl;
        }
        else
        {
            std::cout << "No luggage" << std::endl;
        }
    }
    else if (addVehicleDetailsObject.addType == "van")
    {
        std::cout << "Luggage space: ";
        if (addVehicleDetailsObject.addLuggageSpace)
        {
            std::cout << "15.1 cubic meters luggage space" << std::endl;
        }
        else
        {
            std::cout << "No luggage" << std::endl;
        }
    }
    else if (addVehicleDetailsObject.addType == "car")
    {
        std::cout << "Number of doors: " << std::to_string(addVehicleDetailsObject.addNumberOfDoor) << " door" << std::endl;
    }

    std::cout << "Registration number: " + addVehicleDetailsObject.addRegistrationNumber +
                     "\nColour: " + addVehicleDetailsObject.addColour +
                     "\n";

    if (addVehicleDetailsObject.addAvailability)
    {
        std::cout << "Available: Yes" << std::endl;
    }
    else
    {
        std::cout << "Available: No" << std::endl;
    }
    std::cout << "Date Available: " << addVehicleDetailsObject.addAvailableDate << std::endl;
    std::cout << std::endl;
}

// Assign the added vehicle details to an position in the dynamic array
void assignAddVehicle(details *&structVehicleDetails, addVehicleDetailsStruct &addVehicleDetailsObject)
{
    structVehicleDetails[currentVehicleSize].type = addVehicleDetailsObject.addType;
    structVehicleDetails[currentVehicleSize].make = addVehicleDetailsObject.addMake;
    structVehicleDetails[currentVehicleSize].model = addVehicleDetailsObject.addModel;
    structVehicleDetails[currentVehicleSize].pricePerDay = addVehicleDetailsObject.addPricePerDay;
    structVehicleDetails[currentVehicleSize].engineSize = addVehicleDetailsObject.addEngineSize;

    if (addVehicleDetailsObject.addType == "bike")
    {
        structVehicleDetails[currentVehicleSize].passangerSeat = addVehicleDetailsObject.addPassangerSeat;
    }
    if (addVehicleDetailsObject.addType == "car" || addVehicleDetailsObject.addType == "van")
    {
        structVehicleDetails[currentVehicleSize].numberOfSeats = addVehicleDetailsObject.addNumberOfSeats;
    }

    if (addVehicleDetailsObject.addType == "bike" || addVehicleDetailsObject.addType == "van")
    {
        structVehicleDetails[currentVehicleSize].luggageSpace = addVehicleDetailsObject.addLuggageSpace;
    }

    if (addVehicleDetailsObject.addType == "car")
    {
        structVehicleDetails[currentVehicleSize].numberOfDoor = addVehicleDetailsObject.addNumberOfDoor;
    }

    structVehicleDetails[currentVehicleSize].registrationNumber = addVehicleDetailsObject.addRegistrationNumber;
    structVehicleDetails[currentVehicleSize].colour = addVehicleDetailsObject.addColour;
    structVehicleDetails[currentVehicleSize].availability = addVehicleDetailsObject.addAvailability;
    structVehicleDetails[currentVehicleSize].availableDate = addVehicleDetailsObject.addAvailableDate;
}

// Resize the dynamic array if it is too small to store anymore data
bool resizeDynamicArray(addVehicleDetailsStruct &addVehicleDetailsObject)
{   
    // if there is no space in the dynamic array
    if (maxVehicleSize == currentVehicleSize)
    {
        maxVehicleSize = maxVehicleSize * 2;
        tmpVehicleDetails = new details[maxVehicleSize];

        for (int i = 0; i < currentVehicleSize; i++)
        {
            tmpVehicleDetails[i] = vehicleDetails[i];
        }

        assignAddVehicle(tmpVehicleDetails, addVehicleDetailsObject);

        vehicleDetails = tmpVehicleDetails;
        currentVehicleSize++;
        std::cout << "Add vehicle " << addVehicleDetailsObject.addRegistrationNumber << " successful" << std::endl
                  << std::endl;
        return true;
    }
    // there is a space in the dynamc array
    else
    {
        assignAddVehicle(vehicleDetails, addVehicleDetailsObject);
        currentVehicleSize++;
        std::cout << "Add vehicle " << addVehicleDetailsObject.addRegistrationNumber << " successful" << std::endl
                  << std::endl;
        return false;
    }
}

// Remove vehicle option 
void removeVehicle()
{
    std::string selectedRegistrationNumber;
    std::string vehicleCategory;
    int vehicleIndex;
    std::string choice;
    bool choiceCheck = true;

    if (checkCorrectRegistrationNumber(selectedRegistrationNumber, vehicleCategory, vehicleIndex))
    {

        do
        {
            std::cout << "Are you sure to confirm? [Y/N]: ";
            std::cin >> choice;
            choiceCheck = checkUserConfirmation(choice);
        } while (choiceCheck);

        if (choice == "Y")
        {
            for (int i = vehicleIndex; i < currentVehicleSize - 1; i++)
            {
                vehicleDetails[i] = vehicleDetails[i + 1];
            }
            currentVehicleSize--;
            std::cout << "Remove Vehicle " << selectedRegistrationNumber << " successful." << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "Remove vehicle is cancelled. Return to main menu." << std::endl
                      << std::endl;
        };
    }
    else
    {
        std::cout << "Incorrect registration number. Please check." << std::endl
                  << std::endl;
    }
}

// Display details of a specific vehicle 
bool displayDetailsOfSpecificVehicle()
{
    std::string selectedRegistrationNumber;
    std::string vehicleCategory;
    int vehicleIndex;

    if (checkCorrectRegistrationNumber(selectedRegistrationNumber, vehicleCategory, vehicleIndex))
    {
        std::cout << "Correct registration number." << std::endl;
        std::cout << std::endl
                  << "Details for vehicle " << selectedRegistrationNumber << ": " << std::endl;
        Vehicle *vehicleClass;
        if (vehicleCategory == "bike")
        {
            vehicleClass = new Motorcycle(&vehicleDetails[vehicleIndex]);
        }
        else if (vehicleCategory == "car")
        {
            vehicleClass = new Car(&vehicleDetails[vehicleIndex]);
        }
        else if (vehicleCategory == "van")
        {
            vehicleClass = new Van(&vehicleDetails[vehicleIndex]);
        }

        std::cout << vehicleClass->description();

        drawPressAnyKey();

        delete vehicleClass;
        vehicleClass = NULL;
        return 0;
    }
    else
    {
        std::cout << "Incorrect registration number. Please check." << std::endl
                  << std::endl;
        return 1;
    }
}

// Check registration number if present in database and return to main menu if incorrect
bool checkCorrectRegistrationNumber(std::string selectedRegistrationNumber, std::string &vehicleCategory, int &vehicleIndex)
{
    std::cout << std::endl
              << "Enter selected registration number: ";
    std::cin >> selectedRegistrationNumber;
    for (int i = 0; i < currentVehicleSize; i++)
    {
        if (selectedRegistrationNumber == *(&vehicleDetails[i].registrationNumber))
        {
            vehicleCategory = *(&vehicleDetails[i].type);
            vehicleIndex = i;
            return true;
        }
    }
    return false;
}

//  List all vehicle option
void listAll()
{
    assignVehicleArrayToVector();

    int colWidth = 13;
    char topBottomBorder = '-';
    char leftRightBorder = '|';
    char intersectionBorder = '+';

    drawTopBottomBorderTable(intersectionBorder, topBottomBorder, colWidth);

    std::cout << leftRightBorder << std::setfill(' ') << std::left << std::setw(colWidth) << "Make"
              << leftRightBorder << std::setfill(' ') << std::left << std::setw(colWidth) << "Model"
              << leftRightBorder << std::setfill(' ') << std::left << std::setw(colWidth) << "Reg Num"
              << leftRightBorder << std::setfill(' ') << std::left << std::setw(colWidth) << "Availability"
              << leftRightBorder;

    drawTopBottomBorderTable(intersectionBorder, topBottomBorder, colWidth);

    for (size_t i = 0; i < vehicles.size(); i++)
    {
        std::cout << leftRightBorder
                  << std::setfill(' ') << std::left << std::setw(13) << vehicles[i]->getMake() << leftRightBorder
                  << std::setfill(' ') << std::left << std::setw(13) << vehicles[i]->getModel() << leftRightBorder
                  << std::setfill(' ') << std::left << std::setw(13) << vehicles[i]->getregistrationNumber() << leftRightBorder
                  << std::setfill(' ') << std::left << std::setw(13) << vehicles[i]->getAvailability() << leftRightBorder;
        if (i < vehicles.size() - 1)
            std::cout << std::endl;
    }

    drawTopBottomBorderTable(intersectionBorder, topBottomBorder, colWidth);

    drawPressAnyKey();
}

// Loop for the dynamic array and create a vector of vehicle class 
void assignVehicleArrayToVector()
{
    vehicles.clear();

    for (int i = 0; i < currentVehicleSize; i++)
    {
        if (vehicleDetails[i].type == "bike")
            vehicles.push_back(new Motorcycle(&vehicleDetails[i]));
        else if (vehicleDetails[i].type == "car")
            vehicles.push_back(new Car(&vehicleDetails[i]));
        else if (vehicleDetails[i].type == "van")
            vehicles.push_back(new Van(&vehicleDetails[i]));
    }
}

//  Draw top and bottom of table
void drawTopBottomBorderTable(char intersectionBorder, char topBottomBorder, int colWidth)
{
    std::cout << std::endl
              << intersectionBorder << std::setfill(topBottomBorder) << std::left << std::setw(colWidth) << ""
              << intersectionBorder << std::left << std::setw(colWidth) << ""
              << intersectionBorder << std::left << std::setw(colWidth) << ""
              << intersectionBorder << std::left << std::setw(colWidth) << ""
              << intersectionBorder
              << std::endl;
}

//  Display and perform the functionality of press any key to continue
void drawPressAnyKey()
{
    std::cout << std::endl
              << "Press any key to return to main menu";
    std::cin.ignore();
    std::cin.get();
    std::cout << "Back to main menu" << std::endl
              << std::endl;
}

// Quit option
void quit(const std::string &FILENAME)
{

    std::string choice;
    bool choiceCheck = true;

    // save option
    do
    {
        std::cout << "Save/Overwrite? [Y/N]: ";
        std::cin >> choice;
        choiceCheck = checkUserConfirmation(choice);
    } while (choiceCheck);

    if (choice == "Y")
    {
        saveData(FILENAME);
        std::cout << "Saving to \"" << FILENAME << "\" completed successfully." << std::endl
                  << std::endl;
    }

    std::cout << "Bye Bye !!! See you soon." << std::endl;

    // clear the memory
    for (Vehicle *v : vehicles)
    {
        delete v;
    }

    vehicles.clear();

    delete[] vehicleDetails;
    delete[] tmpVehicleDetails;

    vehicleDetails = NULL;
    tmpVehicleDetails = NULL;

    exit(0);
}

// Save data option
void saveData(const std::string &FILENAME)
{
    std::ostringstream engineSizeStream;

    std::string type;
    std::string engineSizeString;
    std::ofstream myFile(FILENAME, std::ofstream::trunc);

    for (int i = 0; i < currentVehicleSize; i++)
    {
        type = vehicleDetails[i].type;
        myFile << type << ":";
        myFile << vehicleDetails[i].make << ":";
        myFile << vehicleDetails[i].model << ":£";
        myFile << vehicleDetails[i].pricePerDay << ":";

        // reset the content of the stream
        engineSizeStream.str("");
        engineSizeStream << vehicleDetails[i].engineSize;
        engineSizeString = engineSizeStream.str();
        if (type == "bike")
        {
            myFile << engineSizeString << "cc:";
        }
        else if (type == "car" || type == "van")
        {
            myFile << engineSizeString << "L:";
        }

        if (type == "bike")
        {
            if (vehicleDetails[i].passangerSeat)
            {
                myFile << "Passenger seat:";
            }
            else if (!vehicleDetails[i].passangerSeat)
            {
                myFile << "No Passenger:";
            }
        }
        else if (type == "car" || type == "van")
        {
            myFile << std::to_string(vehicleDetails[i].numberOfSeats) << " seats:";
        }

        if (type == "bike")
        {
            if (vehicleDetails[i].luggageSpace)
            {
                myFile << "Has luggage:";
            }
            else
            {
                myFile << "No luggage:";
            }
        }
        else if (type == "van")
        {
            if (vehicleDetails[i].luggageSpace)
            {
                myFile << "15.1 cubic meters luggage space:";
            }
            else
            {
                myFile << "No luggage:";
            }
        }
        else if (type == "car")
        {
            myFile << std::to_string(vehicleDetails[i].numberOfDoor) << "door:";
        }

        myFile << vehicleDetails[i].registrationNumber << ":";
        myFile << vehicleDetails[i].colour << ":";

        if (vehicleDetails[i].availability)
        {
            myFile << "Yes:";
        }
        else
        {
            myFile << "No:";
        }

        myFile << vehicleDetails[i].availableDate;

        myFile << "\n";
    }

    myFile.close();
}