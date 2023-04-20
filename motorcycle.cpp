/*
    motorcycle.cpp
    Author: M00826933
    Created: 11/01/23
    Updated: 13/01/23
*/

#include "vehicle.h"
#include "motorcycle.h"
#include <sstream>

// Motorcycle class constructor
Motorcycle::Motorcycle() : Vehicle()
{
}

Motorcycle::Motorcycle(details *array) : Vehicle(array)
{
    setEngineSizeCc(array->engineSize);
    setPassengerSeat(array->passangerSeat);
    setLuggageSpace(array->luggageSpace);
}

// Motorcycle class setter functions
void Motorcycle::setEngineSizeCc(double engineSize)
{
    this->engineSizeCc = engineSize;
}
void Motorcycle::setPassengerSeat(bool passengerSeat)
{
    this->passengerSeat = passengerSeat;
}
void Motorcycle::setLuggageSpace(bool luggageSpace)
{
    this->luggageSpace = luggageSpace;
}

// Motorcycle class getter functions
double Motorcycle::getEngineSizeCc()
{
    return engineSizeCc;
}
std::string Motorcycle::getPassengerSeat()
{
    if (passengerSeat)
        return "Passenger seat";
    else
        return "No passenger";
}
std::string Motorcycle::getLuggageSpace()
{
    if (luggageSpace)
        return "Has luggage";
    else
        return "No luggage";
}

// Return all details of a motorcycle class
std::string Motorcycle::description()
{
    std::ostringstream ss1;
    ss1 << getEngineSizeCc();
    std::string engineSizeCcString = ss1.str();

    return "Type: " + getType() +
           "\nMake: " + getMake() +
           "\nModel: " + getModel() +
           "\nPrice per day: £" + std::to_string(getPricePerDay()) +
           "\nEngine size (CC): " + engineSizeCcString +
           "cc\nPassanger seat: " + getPassengerSeat() +
           "\nLuggage space: " + getLuggageSpace() +
           "\nRegistration number: " + getregistrationNumber() +
           "\nColour: " + getColour() +
           "\nAvailable: " + getAvailability() +
           "\nDate available: " + getAvailableDate() + "\n";
}