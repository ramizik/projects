#include <string>
#include <iostream>
#include "City.h"

#ifndef COASTALCITY_H
#define COASTALCITY_H

class coastalCity : public City {
public:
	coastalCity() {
		waterName = "N/A";
		beachNum = 0;
		name = "N/A";
		population = 0;
		coastalCityCount++;
	}

	coastalCity operator*(int x);
	coastalCity operator+(coastalCity x);

	std::string getWaterName() const { return waterName; }
	unsigned int getBnum() const { return beachNum; }

	void setWaterName(std::string waterName) { this->waterName = waterName; };
	void setBeachNum(unsigned int beachNum) { this->beachNum = beachNum; };

	void printInfo() {
		City::printInfo();		
		std::cout << "Ocean Name: " << getWaterName() << std::endl;
		std::cout << "No. of beaches: " << getBnum() << std::endl;
	}

	static unsigned int getCoastalCityCount() {
		return coastalCityCount;
	};


private:
	std::string waterName;
	unsigned int beachNum;
	static unsigned int coastalCityCount;
};


coastalCity coastalCity::operator*(int x) {
	coastalCity CityInfoResult;
	CityInfoResult.setBeachNum(x* beachNum);
	CityInfoResult.setWaterName(waterName);
	CityInfoResult.setPopulation(population);
	CityInfoResult.setName(name);
	return CityInfoResult;
}

coastalCity coastalCity::operator+(coastalCity x) {
	coastalCity CityInfoResult;
	CityInfoResult.setBeachNum(beachNum + x.beachNum);
	CityInfoResult.setName(name.append(x.name));
	CityInfoResult.setPopulation(population + x.population);
	CityInfoResult.setWaterName(waterName.append(x.waterName));
	return CityInfoResult;
}

#endif