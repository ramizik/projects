#include <string>
#include <iostream>

#ifndef CITY_H
#define CITY_H

class City {
	// Access to sub-classes only
protected:
	std::string name;
	unsigned int population;
	// Public access
public:
	// Default & General constructors
	City() {
		name = "N/A";
		population = 0;
	}
	City(std::string name, int population) {
		this->name = name;
		this->population = population;
	}
	// Setters
	void setName(std::string name) { this->name = name; }
	void setPopulation(unsigned int population) {
		this->population = population;
	}
	// Getters
	std::string getName() const { return this->name; }
	unsigned int getPopulation() const { return this->population; }
	// Print
	virtual void printInfo() {
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Population: " << getPopulation() << std::endl;
	}
};


#endif