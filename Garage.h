#pragma once
#ifndef LABA1TECHNOLOGYOFPROGRAMMING_GARAGE_H
#define LABA1TECHNOLOGYOFPROGRAMMING_GARAGE_H
#include <iostream>
#include <fstream>
using namespace std;
class Garage {
public:
	Garage() {
		cout << "Garage default constructor called" << endl;
	}
	virtual ~Garage() {
		cout << "Garage destructor called" << endl;
	}
	virtual void print() = 0;
	virtual string getDetails() = 0;
};
#endif