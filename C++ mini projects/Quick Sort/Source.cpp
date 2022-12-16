// Ramis Hasanli & William Wilson

#include <iostream>
#include <vector>
#include "city.h"
using namespace std;


City cityArray[] = { {"Los Angeles", 4000000}, {"San Diego", 1500000}, {"San Francisco", 900000}, {"Sacramento", 500000}, {"Stockton", 300000}, {"Redding", 90000}, {"Las Vegas", 700000}, {"Reno", 300000}, {"Portland", 700000}, {"Seattle", 750000}, {"Eugene", 200000} };

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

int cityPartition(vector<City>& userVec, int lowIndex, int highIndex) {
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    int pivot = userVec.at(midpoint).getPopulation();
    City temp("N/A", 0);
    bool done = false;

    while (!done) {
        while (userVec.at(lowIndex).getPopulation() < pivot) {
            lowIndex += 1;
        }

        while (pivot < userVec.at(highIndex).getPopulation()) {
            highIndex -= 1;
        }

        if (lowIndex >= highIndex) {
            done = true;
        }
        else {
            temp = userVec.at(lowIndex);
            userVec.at(lowIndex) = userVec.at(highIndex);
            userVec.at(highIndex) = temp;

            lowIndex += 1;
            highIndex -= 1;
        }
    }
    return highIndex;
}

void cityQuicksort(vector<City>& userVec, int lowIndex, int highIndex) {
    if (lowIndex >= highIndex) {
        return;
    }

    int lowEndIndex = cityPartition(userVec, lowIndex, highIndex);
    cityQuicksort(userVec, lowIndex, lowEndIndex);
    cityQuicksort(userVec, lowEndIndex + 1, highIndex);

}

int main() {
    cout << "Initializing cityVector with cityArray[]:" << endl;
    initVector(cityVector, cityArray, 11);
    printCityVector(cityVector);
    cout << endl;

    cout << "Quick sort on CityVector: " << endl;
    cityQuicksort(cityVector, 0, 10);
    printCityVector(cityVector);
    cout << endl;

}