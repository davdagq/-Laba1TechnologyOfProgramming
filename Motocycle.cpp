#include "Motocycle.h"
#include<string>
using namespace std;
Motorcycle::Motorcycle(string brand, string model, int engineCapacity, int
	enginePower, string terrainType) {
	this->brand = brand;
	this->model = model;
	this->engineCapacity = engineCapacity;
	this->enginePower = enginePower;
	this->terrainType = terrainType;
		cout << "Motorcycle constructor called" << endl;
}
Motorcycle::~Motorcycle() {
	cout << "Motorcycle destructor called" << endl;
}
void Motorcycle::print() {
	cout << "Motorcycle Details: " << endl;
	cout << "Brand: " << brand << endl;
	cout << "Model: " << model << endl;
	cout << "Engine Capacity: " << engineCapacity << endl;
	cout << "Engine Power: " << enginePower << endl;
	cout << "Terrain Type: " << terrainType << endl;
}
string Motorcycle::getDetails() {
	return "Motorcycle " + brand + " " + model + " " + to_string(engineCapacity)
		+ " " + to_string(enginePower) + " " +
		terrainType;
}