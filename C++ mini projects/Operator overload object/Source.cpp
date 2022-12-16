// Ramis Hasanli & William Wilson
#include <iostream>
#include "CoastalCity.h"
using namespace std;

// Outisde the scope of main we need to declare our counter
unsigned int coastalCity::coastalCityCount = 0;

int main() {
	
	coastalCity SanDiego;
	coastalCity Miami;
	
	SanDiego.setName("San Diego");
	SanDiego.setPopulation(1500000);
	SanDiego.setWaterName("Pacific Ocean");
	SanDiego.setBeachNum(5);

	Miami.setName("Miami");
	Miami.setPopulation(500000);
	Miami.setWaterName("Atlantic Ocean");
	Miami.setBeachNum(8);

	SanDiego = SanDiego * 5;
	SanDiego.printInfo();
	cout << endl;
	Miami.printInfo();

	coastalCity NewCity = SanDiego + Miami;
	NewCity.printInfo();
	cout << endl;
	cout << coastalCity::getCoastalCityCount() << endl;

	return 0;
}