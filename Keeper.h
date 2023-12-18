#pragma once
#ifndef LABA1TECHNOLOGYOFPROGRAMMING_KEEPER_H
#define LABA1TECHNOLOGYOFPROGRAMMING_KEEPER_H
#include "Garage.h"
class Keeper {
private:
	Garage** garages;
	int garagesCount;
	int garagesMax;
public:
	Keeper();
	void addGarage(Garage* garage);
	void removeGarage(int index);
	void save(std::string filename);
	void load(std::string filename);
	int getGaragesCount();
	void print();
};
#endif //LABA1TECHNOLOGYOFPROGRAMMING_KEEPER_H