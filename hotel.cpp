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
    void printOccupation();
};

Hotel::Hotel(const std::string& name) : name(name), numRooms(50) {
    for (int i = 0; i < numRooms; i++) {
        rooms.push_back(Room(i + 100));
    }
}

int Hotel::checkin(const std::string& guestName, int adults, int children, double credit) {
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].isAvailable()) {
            rooms[i].checkin(guestName, adults, children, credit);
            return rooms[i].getNumber();
        }
    }
    return -1;
}

bool Hotel::checkout(int roomNumber) {
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].getNumber() == roomNumber) {
            return rooms[i].checkout();
        }
    }
    return false;
}

bool Hotel::chargeRoom(int roomNumber, double charge) {
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].getNumber() == roomNumber) {
            return rooms[i].performCharge(charge);
        }
    }
    return false;
}

double Hotel::getTotalByBaseRate() {
    double total = 0.0;
    for (int i = 0; i < rooms.size(); i++) {
        if (!rooms[i].isAvailable()) {
            total += rooms[i].getBaseRate();
        }
    }
    return total;
}

void Hotel::printOccupation() {
    std::cout << "Occupancy at " << name << std::endl;
    for (int i = 0; i < rooms.size(); i++) {
        if (!rooms[i].isAvailable()) {
            std::cout << rooms[i].toString() << std::endl;
        }
    }
}

#endif