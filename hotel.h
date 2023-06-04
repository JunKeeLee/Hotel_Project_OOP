#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"
#include <iostream>
#include <vector>

class Hotel {
private:
    std::string name;
    std::vector<Room> rooms;
    int numRooms;

public:
    Hotel(const std::string& name);
    int checkin(const std::string& guestName, int adults, int children, double credit);
    bool checkout(int roomNumber);
    bool chargeRoom(int roomNumber, double charge);
    double getTotalByBaseRate();
    void printOccupancy();
};

#endif