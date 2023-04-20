#ifndef _VAN_H_
#define _VAN_H_

/*
    van.h
    Author: M00826933
    Created: 11/01/23
    Updated: 13/01/23
*/

#include "vehicle.h"

// Van class - derived from Vehicle class
class Van : public Vehicle
{
private:
    double engineSizeLitres;
    int numberOfSeats;
    bool luggageSpace;

public:
    Van();
    Van(details *array);

    void setEngineSizeLitres(double engineSize);
    void setNumberOfSeats(int numberOfSeats);
    void setLuggageSpace(bool luggageSpace);

    double getEngineSizeLitres();
    int getNumberOfSeats();
    std::string getLuggageSpace();

    std::string description();
};

#endif