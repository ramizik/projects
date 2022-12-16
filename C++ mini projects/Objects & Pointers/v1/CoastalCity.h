#include <string>
#include <iostream>
#include "City.h"

#ifndef COASTALCITY_H
#define COASTALCITY_H


class coastalCity : public City {
public:
	// Default & General Constructors
	coastalCity() {
		waterName = "N/A";
		beachNum = 0;
		name = "N/A";
		population = 0;
		City* adjCity = new City("N/A", 0);
		coastalCityCount++;
	}
	coastalCity(std::string water, int beach, std::string name, int pop, std::string adjName, int adjPop) {
		waterName = water;
		beachNum = beach;
		this->name = name;
		population = pop;
		City* adjCity = new City(adjName, adjPop);
		coastalCityCount++;
	}
	// Destructor
	~coastalCity() {
		std::cout << "Object sucessfully deleted";
		delete adjCity;
	}
	// Operator overload
	coastalCity operator*(int x);
	coastalCity operator+(coastalCity x);
	// Getters
	std::string getWaterName() const { return waterName; }
	unsigned int getBnum() const { return beachNum; }
	// Setters
	void setWaterName(std::string waterName) { this->waterName = waterName; };
	void setBeachNum(unsigned int beachNum) { this->beachNum = beachNum; };
	// Print
	void printInfo() {
		City::printInfo();
		std::cout << "Ocean Name: " << getWaterName() << std::endl;
		std::cout << "No. of beaches: " << getBnum() << std::endl;
		(*adjCity).printInfo();
	
	}
	// Pointer getter
	City* getAdjCiy() {
		return adjCity;
	}

	// Get Counter
	static unsigned int getCoastalCityCount() {
		return coastalCityCount;
	};

	// Private members
private:
	std::string waterName;
	unsigned int beachNum;
	static unsigned int coastalCityCount;
	// Pointer to City
	City* adjCity = new City("N/A", 0);
};

// Operator *
coastalCity coastalCity::operator*(int x) {
	coastalCity CityInfoResult;
	CityInfoResult.setBeachNum(x* beachNum);
	CityInfoResult.setWaterName(waterName);
	CityInfoResult.setPopulation(population);
	CityInfoResult.setName(name);
	return CityInfoResult;
}
// Operator +
coastalCity coastalCity::operator+(coastalCity x) {
	coastalCity CityInfoResult;
	CityInfoResult.setBeachNum(beachNum + x.beachNum);
	CityInfoResult.setName(name.append(x.name));
	CityInfoResult.setPopulation(population + x.population);
	CityInfoResult.setWaterName(waterName.append(x.waterName));
	return CityInfoResult;
}

#endif