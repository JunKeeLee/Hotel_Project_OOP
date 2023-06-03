#include <iostream>
#include "hotel.h"

int main() {
    Hotel hotel("Hotel Holiday OOP");

    char option;
    do {
        std::cout << "---- Menu ----" << std::endl;
        std::cout << "1. Check-in" << std::endl;
        std::cout << "2. Check-out" << std::endl;
        std::cout << "3. Charge for a room" << std::endl;
        std::cout << "4. Total for base fee" << std::endl;
        std::cout << "5. Print occupation" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter an option: ";
        std::cin >> option;

        switch (option) {
            case '1': {
                std::string name;
                int adults, children;
                double credit;

                std::cout << "Name of guest: ";
                std::cin >> name;
                std::cout << "Number of adults: ";
                std::cin >> adults;
                std::cout << "Number of children: ";
                std::cin >> children;
                std::cout << "Credit available: ";
                std::cin >> credit;

                int roomNumber = hotel.checkin(name, adults, children, credit);
                if (roomNumber != -1) {
                    std::cout << "Check-in successful. Room assigned: " << roomNumber << std::endl;
                } else {
                    std::cout << "There are no available rooms in the hotel." << std::endl;
                }

                break;
            }
            case '2': {
                int roomNumber;
                std::cout << "Number of rooms to check-out: ";
                std::cin >> roomNumber;

                if (hotel.checkout(roomNumber)) {
                    std::cout << "Check-out successful." << std::endl;
                } else {
                    std::cout << "The room was not occupied." << std::endl;
                }

                break;
            }
            case '3': {
                int roomNumber;
                double charge;

                std::cout << "Room number: ";
                std::cin >> roomNumber;
                std::cout << "Charge amount: ";
                std::cin >> charge;

                if (hotel.chargeRoom(roomNumber, charge)) {
                    std::cout << "Charge successful." << std::endl;
                } else {
                    std::cout << "Charge unsuccessful. The room is occupied or the charge exceedes the credit available." << std::endl;
                }

                break;
            }
            case '4': {
                double totalBaseFee = hotel.getTotalByBaseRate();
                std::cout << "Total for base fee: " << totalBaseFee << std::endl;

                break;
            }
            case '5': {
                hotel.printOccupancy();
                break;
            }
            case '6':
                std::cout << "Exiting the program." << std::endl;
                break;

            default:
                std::cout << "Invalid option. Try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (option != 6);

    return 0;
}
