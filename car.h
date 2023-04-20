#ifndef _CAR_H_
#define _CAR_H_

/*
    car.h
    Author: M00826933
    Created: 11/01/23
    Updated: 13/12/22
*/

#include "vehicle.h"

// Car class - derived from Vehicle class
class Car : public Vehicle
{
private:
    double engineSizeLitres;
    int numberOfSeats;
    int numberOfDoors;

public:
    Car();
    Car(details *array);

    void setEngineSizeLitres(double engineSize);
    void setNumberOfSeats(int numberOfSeats);
    void setNumberOfDoors(int numberOfDoors);

    double getEngineSizeLitres();
    int getNumberOfSeats();
    int getNumberOfDoors();

    std::string description();
};

#endif