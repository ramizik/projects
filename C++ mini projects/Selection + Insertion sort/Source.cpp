// Ramis Hasanli & William Wilson | Lab 20
#include <iostream>
#include <vector>
#include "city.h"


City cityArray[]{
	City("Los Angeles", 4000000), City("San Diego", 1500000),City("San Francisco", 900000),
	City("Sacramento", 500000), City("Stockton", 300000), City("Redding", 90000), City("Las Vegas", 700000),
	City("Reno", 300000), City("Portland", 700000), City("Seattle", 750000), City("Eugene", 200000) };
vector <City> cityVector;

void initVector(vector<City>& vectorIn, City arrIn[], int arrSize) {
	for (int i = 0; i < arrSize; ++i)
		vectorIn.push_back(arrIn[i]);
}

void printCityVector(vector <City>& vectorIn) {
	for (City city : vectorIn)
		city.printInfo();
}

void citySelectionSort(vector <City>& vectorIn) {
	int i = 0;
	int j = 0;
	int indexSmallest = 0;
	// We could use pair here, but we did not
	int tempPop = 0;
	string tempName;
	
	for (i = 0; i < vectorIn.size(); ++i) {

		// Find index of smallest element
		indexSmallest = i;
		for (j = i + 1; j < vectorIn.size(); ++j) {
			if (vectorIn.at(j).getPopulation() < vectorIn.at(indexSmallest).getPopulation())
				indexSmallest = j;
		}
		// Swap numbers & names
		tempPop = vectorIn.at(i).getPopulation();
		tempName = vectorIn.at(i).getName();
		vectorIn.at(i).setPopulation(vectorIn.at(indexSmallest).getPopulation());
		vectorIn.at(i).setName(vectorIn.at(indexSmallest).getName());
		vectorIn.at(indexSmallest).setPopulation(tempPop);
		vectorIn.at(indexSmallest).setName(tempName);
	}
};

void cityInsertionSort(vector <City>& vectorIn) {
	int i = 0;
	int j = 0;
	int tempPop = 0;
	string tempName;

	for (i = 1; i < vectorIn.size(); ++i) {
		j = i;
		while (j > 0 && vectorIn.at(j).getPopulation() < vectorIn.at(j - 1).getPopulation()) {
			tempPop = vectorIn.at(j).getPopulation();
			tempName = vectorIn.at(j).getName();
			vectorIn.at(j).setPopulation(vectorIn.at(j - 1).getPopulation());
			vectorIn.at(j).setName(vectorIn.at(j - 1).getName());
			vectorIn.at(j - 1).setPopulation(tempPop);
			vectorIn.at(j - 1).setName(tempName);
			--j;
		}
	}
};


int main() {

	std::cout << "Initializing cityVector with cityArray[]:\n";
	initVector(cityVector, cityArray,11);
	printCityVector(cityVector);

	std::cout << "\nSelection sort on cityVector:\n";
	citySelectionSort(cityVector);
	printCityVector(cityVector);

	std::cout << "\nRe-initializing cityVector with cityArray[]:\n";
	cityVector.clear();
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);

	std::cout << "\nInsertion sort on cityVector:\n";
	cityInsertionSort(cityVector);
	printCityVector(cityVector);

	return 0;
}
