// Ramis Hasanli & William Wilson | Lab 19
#include <iostream>
#include <vector>
#include <algorithm>
#include "city.h"



City cityArray[]{ 
	City("Los Angeles", 4000000), City("San Diego", 1500000),City("San Francisco", 900000), 
	City("Sacramento", 500000), City("Stockton", 300000), City("Redding", 90000), City("Las Vegas", 700000),
	City("Reno", 300000), City("Portland", 700000), City("Seattle", 750000), City("Eugene", 200000) };

vector <City> cityVector;
int steps = 1;

void initVector(vector<City>& vectorIn, City arrIn[], int arrSize) {
	for (int i = 0; i < arrSize; ++i)
		vectorIn.push_back(arrIn[i]);
}

void printCityVector(vector <City>& vectorIn) {
	for (City city : vectorIn)
		city.printInfo();
}

bool isSmaller(City city1, City city2) {
	return (city1.getName() < city2.getName());
}

unsigned int cityLinearSearch(vector <City> vectorIn, string cityName) {
	for (int i = 0; i < vectorIn.size(); ++i, ++steps) {
		if (vectorIn.at(i).getName() == cityName){
			return vectorIn.at(i).getPopulation();
		}
	}
	return 0;
}

unsigned int cityBinarySearch(vector <City> vectorIn, string cityName) {
	int mid = 0;
	int low = 0;
	int high = vectorIn.size() - 1;
	
	while (high >= low) {
		mid = (high + low) / 2;
		if (vectorIn[mid].getName() < cityName) {
			low = mid + 1;
			steps++;
		}
		else if (vectorIn[mid].getName() > cityName) {
			high = mid - 1;
			steps++;
		}
		else {
			return vectorIn[mid].getPopulation();
		}
	}
	return 0;
}



int main() {

	initVector(cityVector, cityArray, 11);
	std::cout << "Initializing cityVector with cityArray[]: \n";
	printCityVector(cityVector);
	std::cout << "\nSorting cityVector based on names in ascending order: \n";
	std::sort(cityVector.begin(), cityVector.end(), isSmaller);
	printCityVector(cityVector);
	std::cout << std::endl;
	std::cout << "Linear search for the population of San Francisco: " << cityLinearSearch(cityVector, "San Francisco");
	std::cout << "\nNumber of comparisons for this search: " << steps;
	std::cout << std::endl;
	steps = 0;
	std::cout << "\nLinear search for the population of Boston: " << cityLinearSearch(cityVector, "Boston");
	std::cout << "\nNumber of comparisons for this search: " << steps;
	std::cout << std::endl;
	steps = 1;
	std::cout << "\nBinary search for the population of San Francisco: " << cityBinarySearch(cityVector, "San Francisco");
	std::cout << "\nNumber of comparisons for this search: " << steps;
	std::cout << std::endl;
	steps = 0;
	std::cout << "\nBinary search for the population of Boston: " << cityBinarySearch(cityVector, "Boston");
	std::cout << "\nNumber of comparisons for this search: " << steps;
	std::cout << std::endl;

	return 0;
}