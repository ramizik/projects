// Ramis Hasanli & William Wilson

#include <iostream>
#include <vector>
#include <cmath>
#include "city.h"
using namespace std;


City cityArray[] = { {"Los Angeles", 4340174}, {"San Diego", 1591688}, {"San Francisco", 871421}, {"Sacramento", 505628}, {"Stockton", 323761}, {"Redding", 90292}, {"Las Vegas", 711926}, {"Reno", 289485}, {"Portland", 730428}, {"Seattle", 752180}, {"Eugene", 221452} };

vector<City> cityVector;

void initVector(vector<City>& userVec, City userArr[], int userNum) {
	while (userVec.size() > 0) {
		userVec.pop_back();
	}
	for (int i = 0; i < userNum; ++i) {
		userVec.push_back(userArr[i]);
	}
}

void printCityVector(const vector<City> userVec) {
	for (City city1 : userVec) {
		city1.printInfo();
	}
}

template <typename TheType>
void printVector(const vector<TheType> userVec) {
	for (auto x: userVec) {
		cout << x << " ";
	}
}

void populationProject(const vector<City> userVec, vector<unsigned int> intVec) {
	
	for (int i = 0; i < userVec.size(); i++) {
		intVec.push_back(userVec.at(i).getPopulation());
	}
}

int radixGetLength(unsigned int num) {
	if (num == 0) {
		return 1;
	}
	int digits = 0;
	while (num != 0) {
		digits = digits + 1;
		num = num / 10;
	}
	return digits;
}

int radixGetMaxLength(vector <unsigned int> userVec) {
	int maxDigits = 0;
	for (int i = 0; i < userVec.size(); ++i) {
		int digitCount = radixGetLength(userVec.at(i));
		if (digitCount > maxDigits)
			maxDigits = digitCount;
	}
	return maxDigits;
}

void populationRadixSort(vector <unsigned int>& userVec) {
	vector <unsigned int> buckets(10);

	int Digits = radixGetMaxLength(userVec);
	int pow10 = 1;

	for (int digitIndex = 0; digitIndex < Digits; digitIndex++) {
		for (int i = 0; i < userVec.size(); i++) {
			//int bucketIndex = Get
			// Did not have enough time to complete the lab bc of emergency, i'm sorry
		}
	}
		

}


void mergeCityVector(vector<City>& v, int s, int m, int e) {

	vector<City> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v.at(i).getPopulation() <= v.at(j).getPopulation()) {
			temp.push_back(v.at(i));
			++i;
		}
		else {
			temp.push_back(v.at(j));
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v.at(i));
		++i;
	}

	while (j <= e) {
		temp.push_back(v.at(j));
		++j;
	}

	for (int i = s; i <= e; ++i)
		v.at(i) = temp.at(i - s);

}

void cityMergeSort(vector<City>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		cityMergeSort(v, s, m);
		cityMergeSort(v, m + 1, e);
		mergeCityVector(v, s, m, e);
	}
}

int main() {
	cout << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);
	cout << endl;

	cout << "Radix sort on cityVector:" << endl;
	cityMergeSort(cityVector, 0, 10);
	printCityVector(cityVector);
	cout << endl;
}
