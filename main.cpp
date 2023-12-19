#include "Keeper.h"
#include "Car.h"
#include "Motocycle.h"
#include "Bus.h"
#include "Exception.h"
#include <iostream>
#include <fstream>
void showMenu() {
	std::cout << "\nMenu:\n"
		"1. Add Car\n"
		"2. Add Motorcycle\n"
		"3. Add Bus\n"
		"4. Delete object from Keeper\n"
		"5. Save to File\n"
		"6. Restore from File\n"
		"7. Show Keeper\n"
		"8. Exit\n";
}
int main() {
	Keeper keeper;
	try {
		while (true) {
			showMenu();
				int choice;
			std::cout << "\nEnter your choice:\n";
			std::cin >> choice;
			switch (choice) {
			case 1: {
				string brand;
				string model;
				int engineCapacity;
				string color;
				string checkpointType;
				std::cout << "\nEnter car brand:\n";
				std::cin >> brand;
				std::cout << "\nEnter car model:\n";
				std::cin >> model;
				std::cout << "\nEnter car engine capacity (int-type):\n";
				std::cin >> engineCapacity;
				std::cout << "\nEnter car color:\n";
				std::cin >> color;
				std::cout << "\nEnter car checkpoint type:\n";
				std::cin >> checkpointType;
				Car* car = new Car(brand, model, engineCapacity, color,
					checkpointType);
				keeper.addGarage(car);
				car->print();
				break;
			}
			case 2: {
				string brand;
				string model;
				int engineCapacity;
				int enginePower;
				string terrainType;
				std::cout << "\nEnter motorcycle brand:\n";
				std::cin >> brand;
				std::cout << "\nEnter motorcycle model:\n";
				std::cin >> model;
				std::cout << "\nEnter motorcycle engine capacity (int-type):\n";
				std::cin >> engineCapacity;
				std::cout << "\nEnter motorcycle engine power (int-type):\n";
				std::cin >> enginePower;
				std::cout << "\nEnter motorcycle terrain type:\n";
					std::cin >> terrainType;
				Motorcycle* motorcycle = new Motorcycle(brand, model,
					engineCapacity, enginePower, terrainType);
				keeper.addGarage(motorcycle);
				motorcycle->print();
				break;
			}
			case 3: {
				string brand;
				string model;
				int passengerSeats;
				int totalSeats;
				string destination;
				std::cout << "\nEnter bus brand:\n";
				std::cin >> brand;
				std::cout << "\nEnter bus model:\n";
				std::cin >> model;
				std::cout << "\nEnter bus passenger seats (int-type):\n";
				std::cin >> passengerSeats;
				std::cout << "\nEnter bus total seats (int-type):\n";
				std::cin >> totalSeats;
				std::cout << "\nEnter bus destination:\n";
				std::cin >> destination;
				Bus* bus = new Bus(brand, model, passengerSeats, totalSeats,
					destination);
				keeper.addGarage(bus);
				bus->print();
				break;
			}
			case 4: {
				if (keeper.getGaragesCount() == 0) {
					std::cout << "\nGarage is empty!\n";
					break;
				}
				int index;
				std::cout << "\nEnter index of garage vehicle you want to delete:\n";
				std::cin >> index;
				if (index < 0 || index >= keeper.getGaragesCount()) {
					std::cout << "\nInvalid index!\n";
					break;
				}
				keeper.removeGarage(index);
				break;
			}
			case 5: {
					  std::cout << "\nSaving...\n";
					  keeper.save("save_test.txt");
					  std::cout << "Data saved!\n";
					  break;
				  }
			case 6: {
				std::cout << "\nRestoring...\n";
				keeper.load("save_test.txt");
				std::cout << "\nGarage size: " << keeper.getGaragesCount() <<
					std::endl;
				break;
			}
			case 7: {
				keeper.print();
				break;
			}
			case 8: {
				std::cout << "\nExiting...\n";
				return 0;
			}
			default:
				std::cout << "\nInvalid choice!\n";
				break;
			}
		}
	}
	catch (Exception e) {
		std::cout << "\nError: " << e << std::endl;
	}
	return 0;
}