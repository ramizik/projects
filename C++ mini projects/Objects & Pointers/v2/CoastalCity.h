#include <string>
#include "City.h"

#ifndef COASTALCITY_H
#define COASTALCITY_H


class coastalCity : public City {
public:
//Default constructor
	coastalCity() {
		waterName = "N/A";
		beachNum = 0;
		name = "N/A";
		population = 0;
    //Increment Static City counter
    coastalCityCount++;
	}

  //Input constructor
  coastalCity(std::string newname, int newpopulation, std::string newbeachname, int newbeachnum) {
    name = newname;
    population = newpopulation;
    beachNum = newbeachnum;
    waterName = newbeachname;
  }
  
  //Multiplication Operator
  coastalCity operator*(int beachMult);

  //Addition Operator
  coastalCity operator+(coastalCity atlantis);

	std::string getWaterName() const { return waterName; }
	unsigned int getBnum() const { return beachNum; }
  //Getter for coastal city total
  static int getCoastalCityCount() {std::cout << coastalCityCount;}
  //Setter for coastal city total
  void static setCoastalCityCount() {coastalCityCount = 0;}

	void setWaterName(std::string waterName) { this->waterName = waterName; };
	void setBeachNum(unsigned int beachNum) { this->beachNum = beachNum; };

	void printInfo() const override {
		City::printInfo();
		std::cout << std::endl; std::cout << "Updated Now: " << std::endl;
		std::cout << "Water Name: " << getWaterName() << std::endl;
		std::cout << "Number of beaches: " << getBnum() << std::endl;
	}
private:
	std::string waterName;
	unsigned int beachNum;
  // Static coastal city counter
  unsigned static int coastalCityCount;
};


//Multiplication Operator Definition
coastalCity coastalCity::operator*(int beachMult) {
coastalCity NewAtlantis;
NewAtlantis.setPopulation(population);
NewAtlantis.setBeachNum(beachNum*beachMult);
NewAtlantis.setName(name);
NewAtlantis.setWaterName(waterName);
return NewAtlantis;
}

//Addition Operator Definition
coastalCity coastalCity::operator+(coastalCity atlantis) {
  coastalCity NewAtlantis;
  //Append function to add names together
  NewAtlantis.setName(name.append(atlantis.name));
  NewAtlantis.setPopulation(population+atlantis.population);
  //Append function to add water names together
  NewAtlantis.setWaterName(waterName.append(atlantis.waterName));
  NewAtlantis.setBeachNum(beachNum+atlantis.beachNum);
  return NewAtlantis;
}

#endif