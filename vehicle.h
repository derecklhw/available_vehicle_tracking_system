#ifndef _VEHICLE_H_
#define _VEHICLE_H_

/*
    main.cpp
    Author: M00826933
    Created: 11/12/22
    Updated: 13/01/23
*/

#include <string>
#include "struct.h"

// Base class
class Vehicle
{
private:
    std::string type;
    std::string make;
    std::string model;
    double pricePerDay;
    std::string registrationNumber;
    std::string colour;
    bool availability;
    std::string availableDate;

public:
    //constructor
    Vehicle();

    //explicit constructor
    Vehicle(details *array);

    //deconstructor
    virtual ~Vehicle();

    //setter functions
    void setType(std::string type);
    void setMake(std::string make);
    void setModel(std::string model);
    void setPricePerDay(double pricePerDay);
    void setRegistration(std::string registration);
    void setColour(std::string colour);
    void setAvailability(bool availability, std::string availableDate);

    //getter functions
    std::string getType();
    std::string getMake();
    std::string getModel();
    int getPricePerDay();
    std::string getregistrationNumber();
    std::string getColour();
    std::string getAvailability();
    std::string getAvailableDate();

    //virtual function
    virtual std::string description() = 0;
};

#endif