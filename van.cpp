/*
    van.cpp
    Author: M00826933
    Created: 11/01/23
    Updated: 13/01/23
*/

#include "vehicle.h"
#include "van.h"
#include <sstream>

// Van class constructor
Van::Van() : Vehicle()
{
}

Van::Van(details *array) : Vehicle(array)
{
    setEngineSizeLitres(array->engineSize);
    setNumberOfSeats(array->numberOfSeats);
    setLuggageSpace(array->luggageSpace);
}

// Van class setter functions
void Van::setEngineSizeLitres(double engineSize)
{
    this->engineSizeLitres = engineSize;
}
void Van::setNumberOfSeats(int numberOfSeats)
{
    this->numberOfSeats = numberOfSeats;
}
void Van::setLuggageSpace(bool luggageSpace)
{
    this->luggageSpace = luggageSpace;
}

// Van class getter functions
double Van::getEngineSizeLitres()
{
    return engineSizeLitres;
}
int Van::getNumberOfSeats()
{
    return numberOfSeats;
}
std::string Van::getLuggageSpace()
{
    if (luggageSpace)
        return "15.1 cubic meters luggage space";
    else
        return "No luggage";
}

// Return all details of a van class
std::string Van::description()
{
    std::ostringstream ss1;
    ss1 << getEngineSizeLitres();
    std::string engineSizeLitresString = ss1.str();

    return "Type: " + getType() +
           "\nMake: " + getMake() +
           "\nModel: " + getModel() +
           "\nPrice per day: £" + std::to_string(getPricePerDay()) +
           "\nEngine size (Litres): " + engineSizeLitresString +
           "L\nNunmber of seats: " + std::to_string(getNumberOfSeats()) +
           " seats\nLuggage space: " + getLuggageSpace() +
           "\nRegistration number: " + getregistrationNumber() +
           "\nColour: " + getColour() +
           "\nAvailable: " + getAvailability() +
           "\nDate available: " + getAvailableDate() + "\n";
}