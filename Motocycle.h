#pragma once
#ifndef LABA1TECHNOLOGYOFPROGRAMMING_MOTOCYCLE_H
#define LABA1TECHNOLOGYOFPROGRAMMING_MOTOCYCLE_H
#include "Garage.h"
class Motorcycle : public Garage {
private:
	string brand;
	string model;
	int engineCapacity;
	int enginePower;
	string terrainType;
public:
	Motorcycle(string brand, string model, int engineCapacity, int enginePower,
		string terrainType);
	~Motorcycle();
	void print();
	string getDetails();
};
#endif