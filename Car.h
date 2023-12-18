#ifndef LABA1TECHNOLOGYOFPROGRAMMING_CAR_H
#define LABA1TECHNOLOGYOFPROGRAMMING_CAR_H
#include "Garage.h"
class Car : public Garage {
private:
	string brand;
	string model;
	int engineCapacity;
	string color;
	string checkpointType;
public:
	Car(string brand, string model, int engineCapacity, string color, string
		checkpointType);
	~Car();
	void print();
	string getDetails();
};
#endif