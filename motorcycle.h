#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_

/*
    motorcycle.h
    Author: M00826933
    Created: 11/01/23
    Updated: 13/01/23
*/

#include "vehicle.h"

// Motorcycle class - derived from Vehicle class
class Motorcycle : public Vehicle
{
private:
    double engineSizeCc;
    bool passengerSeat;
    bool luggageSpace;

public:
    Motorcycle();
    Motorcycle(details *array);

    void setEngineSizeCc(double engineSize);
    void setPassengerSeat(bool passengerSeat);
    void setLuggageSpace(bool luggageSpace);

    double getEngineSizeCc();
    std::string getPassengerSeat();
    std::string getLuggageSpace();

    std::string description();
};

#endif