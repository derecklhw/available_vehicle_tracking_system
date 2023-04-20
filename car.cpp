/*
    car.cpp
    Author: M00826933
    Created: 11/01/23
    Updated: 13/12/22
*/

#include "vehicle.h"
#include "car.h"
#include <sstream>

// Car class constructor
Car::Car() : Vehicle()
{
}

Car::Car(details *array) : Vehicle(array)
{
    setEngineSizeLitres(array->engineSize);
    setNumberOfSeats(array->numberOfSeats);
    setNumberOfDoors(array->numberOfDoor);
}

// Car class setter functions
void Car::setEngineSizeLitres(double engineSize)
{
    this->engineSizeLitres = engineSize;
}
void Car::setNumberOfSeats(int numberOfSeats)
{
    this->numberOfSeats = numberOfSeats;
}
void Car::setNumberOfDoors(int numberOfDoors)
{
    this->numberOfDoors = numberOfDoors;
}

// Car class getter functions
double Car::getEngineSizeLitres()
{
    return engineSizeLitres;
}
int Car::getNumberOfSeats()
{
    return numberOfSeats;
}
int Car::getNumberOfDoors()
{
    return numberOfDoors;
}

// Return all details of a car class
std::string Car::description()
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
           " seats\nNumber of doors: " + std::to_string(getNumberOfDoors()) +
           " doors\nRegistration number: " + getregistrationNumber() +
           "\nColour: " + getColour() +
           "\nAvailable: " + getAvailability() +
           "\nDate available: " + getAvailableDate() + "\n";
}
