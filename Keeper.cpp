#include <sstream>
#include "Keeper.h"
#include "Car.h"
#include "Bus.h"
#include "Motocycle.h"
#include <cstring>
#include <sstream>
#include <string>
Keeper::Keeper() {
	garages = nullptr;
	garagesCount = 0;
	garagesMax = 0;
}
void Keeper::addGarage(Garage* garage) {
	if (garagesCount == garagesMax) {
		Garage** newGarages = new Garage * [garagesMax + 1];
		for (int i = 0; i < garagesCount; i++) {
			newGarages[i] = garages[i];
		}
		delete[] garages;
		garages = newGarages;
		garagesMax++;
	}
	garages[garagesCount++] = garage;
}
void Keeper::removeGarage(int index = 0) {
	for (int i = 0; i < garagesCount; i++) {
		if (i == index) {
			delete garages[i];
			for (int j = i; j < garagesCount - 1; j++) {
				garages[j] = garages[j + 1];
			}
			garagesCount--;
			return;
		}
	}
}
void Keeper::save(std::string filename) {
	std::ofstream file(filename);
	file << garagesCount << std::endl;
	for (int i = 0; i < garagesCount; i++) {
		file << garages[i]->getDetails() << std::endl;
	}
	file.close();
}
void Keeper::load(std::string filename) {
	std::ifstream file(filename);
	int count;
	string line;
	file >> count;
	if (file.is_open()) {
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
			string word1, word2, word3, word4, word5, word6;
			stringstream ss(line);
			ss >> word1 >> word2 >> word3 >> word4 >> word5 >> word6;
			if (word1 == "Car") {
				Car* car = new Car(word2, word3, stoi(word4), word5, word6);
				addGarage(car);
			}
			else if (word1 == "Bus") {
				Bus* bus = new Bus(word2, word3, stoi(word4), stoi(word5), word6);
				addGarage(bus);
			}
			else if (word1 == "Motorcycle") {
				Motorcycle* motorcycle = new Motorcycle(word2, word3,
					stoi(word4), stoi(word5), word6);
				addGarage(motorcycle);
			}
		}
	}
	file.close();
	garagesCount = count;
}
int Keeper::getGaragesCount() {
	return garagesCount;
}
void Keeper::print() {
	for (int i = 0; i < garagesCount; i++) {
		garages[i]->print();
		std::cout << std::endl;
	}
}