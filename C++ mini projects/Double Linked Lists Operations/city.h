#ifndef CITY_H
#define CITY_H

#include<string>
#include <iostream>



class City {
public:
	City() {
		name = "N/A";
		population = 0;
	}
	City(std::string nm, unsigned int pop) {
		name = nm;
		population = pop;
	}
	void setName(std::string name) { this->name = name; }
	void setPopulation(unsigned int population)
	{
		this->population = population;
	}
	std::string getName() const { return this->name; }
	unsigned int getPopulation() const { return this->population; }
	virtual void printInfo() const {
		std::cout << getName() << ": " << getPopulation() << std::endl;
	}
protected:
	std::string name;
	unsigned int population;
};
#endif