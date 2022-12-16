#include <iostream>
#include <vector>
#include "city.h"
using namespace std;

City cityArray[] = { {"Los Angeles", 4000000}, {"San Diego", 1500000}, {"San Francisco", 900000}, {"Sacramento", 500000}, {"Stockton", 300000}, {"Redding", 90000}, {"Las Vegas", 700000}, {"Reno", 300000}, {"Portland", 700000}, {"Seattle", 750000}, {"Eugene", 200000}};

int gaps[] = {4, 2, 1};

vector<City> cityVector;

void initVector(vector<City> &userVec, City userArr[], int userNum) {
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

void cityInterleavedInsertionSort(vector<City> userVec, int startIndex, int gapSize) {
  int i;
  int j;
  City temp = userVec.at(0);

  for (i = startIndex + gapSize; i < userVec.size(); i = i + gapSize) {
    j = i;
    while (j - gapSize >= startIndex && userVec.at(j) < userVec.at(j - gapSize)) {
      temp = userVec.at(j);
      userVec.at(j)= userVec.at(j - gapSize);
      userVec.at(j - gapSize) = temp;
      j = j - gapSize;
    }
  }
}


void cityShellSort(vector<City> userVec, int gapValues[], int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    int gapVal;
    gapVal = gapValues[i];
    for (int j = 0; j < gapVal; ++j) {
      cityInterleavedInsertionSort(userVec, i, gapVal);
    }
  }
}


int main() {
  cout << "Initializing cityVector with cityArray[]:" << endl;
  initVector(cityVector, cityArray, 11);
  printCityVector(cityVector);
  cout << endl;

  cout << "Shell Sort on CityVector: " << endl;
  cityShellSort(cityVector, gaps, 11);
  printCityVector(cityVector);
  cout << endl;


  

  
}