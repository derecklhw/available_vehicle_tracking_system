#ifndef _STRUCT_H_
#define _STRUCT_H_

/*
    struct.h
    Author: M00826933
    Created: 10/01/23
    Updated: 13/01/23
*/

#include <string>

// Store details of a vehicle loaded from file
struct details
{
    std::string type;
    std::string make;
    std::string model;
    double pricePerDay;
    double engineSize;
    bool passangerSeat;
    int numberOfSeats;
    int numberOfDoor;
    bool luggageSpace;
    std::string registrationNumber;
    std::string colour;
    bool availability;
    std::string availableDate;
};

// Store details oof a vehicle from Add vehicle functionality
 struct addVehicleDetailsStruct
    {
        std::string addType;
        std::string addMake;
        std::string addModel;
        int addPricePerDay;
        double addEngineSize;
        bool addPassangerSeat;
        int addNumberOfSeats;
        int addNumberOfDoor;
        bool addLuggageSpace;
        std::string addRegistrationNumber;
        std::string addColour;
        bool addAvailability;
        std::string addAvailableDate;
    };

#endif