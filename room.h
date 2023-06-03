#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
    int number;
    std::string name;
    int adults;
    int children;
    double credit;
    double charge;
    bool available;

public:
    Room();
    explicit Room(int number);
    int getNumber() const;
    bool isAvailable() const;
    void checkin(const std::string& guestName, int adults, int children, double credit);
    bool checkout();
    double getBaseRate() const;
    bool performCharge(double amount);
    std::string toString() const;
};

#endif

Room::Room() : number(0), name(""), adults(0), children(0), credit(0.0), charge(0.0), available(true) {}

Room::Room(int number) : number(number), name(""), adults(0), children(0), credit(0.0), charge(0.0), available(true) {}

int Room::getNumber() const {
    return number;
}

bool Room::isAvailable() const {
    return available;
}

void Room::checkin(const std::string& guestName, int adults, int children, double credit) {
    if (available) {
        this->name = guestName;
        this->adults = adults;
        this->children = children;
        this->credit = credit;
        this->charge = 0.0;
        this->available = false;
    }
}

bool Room::checkout() {
    if (!available) {
        name = "";
        adults = 0;
        children = 0;
        credit = 0.0;
        charge = 0.0;
        available = true;
        return true;
    }
    return false;
}

double Room::getBaseRate() const {
    return adults * 450.0 + children * 150.0;
}

bool Room::performCharge(double amount) {
    if (amount > 0 && amount <= credit) {
        charge += amount;
        credit -= amount;
        return true;
    }
    return false;
}

std::string Room::toString() const {
    return std::to_string(number) + ",Guest: " + name + ",Base Rate: " + std::to_string(getBaseRate()) +
           ",Credit: " + std::to_string(credit) + ",Charges: " + std::to_string(charge);
}