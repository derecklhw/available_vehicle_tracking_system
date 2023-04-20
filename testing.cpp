/*
    testing.cpp
    Author: M00826933
    Created: 10/01/23
    Updated: 13/01/23
*/

#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"
#include "vehicle.h"
#include "motorcycle.h"
#include "car.h"
#include "van.h"
#include "struct.h"
#include "program.h"

TEST_CASE("Check number of arguments passed on the commandline", "[checkNumberOfArguments]")
{
    int defaultArgumentCount = 1;
    SECTION("Number of argument is less than 1")
    {
        int numberofArguments = defaultArgumentCount - 0;
        bool result = checkNumberOfArguments(numberofArguments);
        REQUIRE(result == false);
    }
    SECTION("Number of argument is equal to 1")
    {
        int numberofArguments = defaultArgumentCount + 1;
        bool result = checkNumberOfArguments(numberofArguments);
        REQUIRE(result == true);
    }
    SECTION("Number of argument is more than 1")
    {
        int numberofArguments = defaultArgumentCount + 2;
        bool result = checkNumberOfArguments(numberofArguments);
        REQUIRE(result == false);
    }
}

TEST_CASE("Check file existance", "[checkFile]")
{
    SECTION("Correct File used")
    {
        std::string fileName = "vehicles.dat";
        bool result = checkFile(fileName);
        REQUIRE(result == true);
    }
    SECTION("Incorrect File used")
    {
        std::string fileName = "incorrect.dat";
        bool result = checkFile(fileName);
        REQUIRE(result == false);
    }
}

TEST_CASE("Determine number of vehicles in file", "[determineSize]")
{
    std::string fileName = "vehicles.dat";
    int determineVehicleSize = determineSize(fileName);

    SECTION("Correct number of vehicles")
    {
        REQUIRE(determineVehicleSize == 1000);
    }
    SECTION("Incorrect number of vehicles")
    {
        REQUIRE(determineVehicleSize != 999);
    }
}

TEST_CASE("Check user confirmation [Y/N]", "[checkUserConfirmation]")
{
    std::string choice;
    bool check;
    SECTION("User input: Y")
    {
        choice = "Y";
        check = checkUserConfirmation(choice);
        REQUIRE(check == false);
    }
    SECTION("User input: N")
    {
        choice = "N";
        check = checkUserConfirmation(choice);
        REQUIRE(check == false);
    }
    SECTION("User input: nor Y neither N")
    {
        choice = "fgvdf";
        check = checkUserConfirmation(choice);
        REQUIRE(check == true);
    }
}

TEST_CASE("Test bike", "[Bike()]")
{
    Motorcycle bike;
    bike.setType("bike");
    bike.setMake("honda");
    bike.setModel("speedy");
    bike.setPricePerDay(21);
    bike.setRegistration("M134");
    bike.setColour("red");
    bike.setAvailability(true, "N/A");

    bike.setEngineSizeCc(23);
    bike.setPassengerSeat(true);
    bike.setLuggageSpace(false);

    REQUIRE(bike.getType() == "bike");
    REQUIRE(bike.getMake() == "honda");
    REQUIRE(bike.getModel() == "speedy");
    REQUIRE(bike.getPricePerDay() == 21);
    REQUIRE(bike.getregistrationNumber() == "M134");
    REQUIRE(bike.getColour() == "red");
    REQUIRE(bike.getAvailability() == "Yes");
    REQUIRE(bike.getAvailableDate() == "N/A");
    REQUIRE(bike.getEngineSizeCc() == 23);
    REQUIRE(bike.getPassengerSeat() == "Passenger seat");
    REQUIRE(bike.getLuggageSpace() == "No luggage");

    REQUIRE(bike.description() == "Type: bike\nMake: honda\nModel: speedy\nPrice per day: £21\nEngine size (CC): 23cc\nPassanger seat: Passenger seat\nLuggage space: No luggage\nRegistration number: M134\nColour: red\nAvailable: Yes\nDate available: N/A\n");
}

TEST_CASE("Test car", "[Car()]")
{
    Car car;
    car.setType("car");
    car.setMake("toyota");
    car.setModel("road");
    car.setPricePerDay(234);
    car.setRegistration("L0923");
    car.setColour("blue");
    car.setAvailability(false, "22/01/2023");

    car.setEngineSizeLitres(13.2);
    car.setNumberOfDoors(2);
    car.setNumberOfSeats(3);

    REQUIRE(car.getType() == "car");
    REQUIRE(car.getMake() == "toyota");
    REQUIRE(car.getModel() == "road");
    REQUIRE(car.getPricePerDay() == 234);
    REQUIRE(car.getregistrationNumber() == "L0923");
    REQUIRE(car.getColour() == "blue");
    REQUIRE(car.getAvailability() == "No");
    REQUIRE(car.getAvailableDate() == "22/01/2023");
    REQUIRE(car.getEngineSizeLitres() == 13.2);
    REQUIRE(car.getNumberOfDoors() == 2);
    REQUIRE(car.getNumberOfSeats() == 3);

    REQUIRE(car.description() == "Type: car\nMake: toyota\nModel: road\nPrice per day: £234\nEngine size (Litres): 13.2L\nNunmber of seats: 3 seats\nNumber of doors: 2 doors\nRegistration number: L0923\nColour: blue\nAvailable: No\nDate available: 22/01/2023\n");
}

TEST_CASE("Test van", "[Van()]")
{
    Van van;
    van.setType("van");
    van.setMake("nissan");
    van.setModel("hilux");
    van.setPricePerDay(300);
    van.setRegistration("DL661");
    van.setColour("white");
    van.setAvailability(true, "N/A");

    van.setEngineSizeLitres(23.2);
    van.setLuggageSpace(false);
    van.setNumberOfSeats(3);

    REQUIRE(van.getType() == "van");
    REQUIRE(van.getMake() == "nissan");
    REQUIRE(van.getModel() == "hilux");
    REQUIRE(van.getPricePerDay() == 300);
    REQUIRE(van.getregistrationNumber() == "DL661");
    REQUIRE(van.getColour() == "white");
    REQUIRE(van.getAvailability() == "Yes");
    REQUIRE(van.getAvailableDate() == "N/A");
    REQUIRE(van.getEngineSizeLitres() == 23.2);
    REQUIRE(van.getLuggageSpace() == "No luggage");
    REQUIRE(van.getNumberOfSeats() == 3);

    REQUIRE(van.description() == "Type: van\nMake: nissan\nModel: hilux\nPrice per day: £300\nEngine size (Litres): 23.2L\nNunmber of seats: 3 seats\nLuggage space: No luggage\nRegistration number: DL661\nColour: white\nAvailable: Yes\nDate available: N/A\n");
}