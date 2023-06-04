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
