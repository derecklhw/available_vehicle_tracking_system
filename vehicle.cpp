/*
    vehicle.cpp
    Author: M00826933
    Created: 11/12/22
    Updated: 13/01/23
*/

#include "vehicle.h"
#include <string>

// Vehicle class constructor
Vehicle::Vehicle()
{
}

Vehicle::Vehicle(details *array)
{
    setType(array->type);
    setMake(array->make);
    setModel(array->model);
    setPricePerDay(array->pricePerDay);
    setRegistration(array->registrationNumber);
    setColour(array->colour);
    setAvailability(array->availability, array->availableDate);
}

// Vehicle class deconstructor
Vehicle::~Vehicle()
{
}

// Vehicle setter functions
void Vehicle::setType(std::string type)
{
    this->type = type;
}

void Vehicle::setMake(std::string make)
{
    this->make = make;
}

void Vehicle::setModel(std::string model)
{
    this->model = model;
}

void Vehicle::setPricePerDay(double pricePerDay)
{
    this->pricePerDay = pricePerDay;
}

void Vehicle::setRegistration(std::string registration)
{
    this->registrationNumber = registration;
}

void Vehicle::setColour(std::string colour)
{
    this->colour = colour;
}

void Vehicle::setAvailability(bool availability, std::string availableDate)
{
    this->availability = availability;
    this->availableDate = availableDate;
}

// Vehicle getter functions
std::string Vehicle::getType()
{
    return type;
}

std::string Vehicle::getMake()
{
    return make;
}
std::string Vehicle::getModel()
{
    return model;
}
int Vehicle::getPricePerDay()
{
    return pricePerDay;
}
std::string Vehicle::getregistrationNumber()
{
    return registrationNumber;
}
std::string Vehicle::getColour()
{
    return colour;
}
std::string Vehicle::getAvailability()
{
    if (availability)
        return "Yes";
    else
        return "No";
}
std::string Vehicle::getAvailableDate()
{
    return availableDate;
}
