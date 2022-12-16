#include <iostream>
#include "cityhash.h"

using namespace std;


City cityarray[] {
  City("Sacremento", 505628),
  City("Eugene", 221452),
  City("Stockton", 323761),
  City("Redding", 90292),
  City("San Diego", 1591688),
  City("Reno", 289485),
  City("Los Angeles", 4340174),
  City("Portland", 730428),
  City("Las Vegas", 711926),
  City("Seattle", 752180),
  City("San Francisco", 871421)
};

CityHashTable CHT1;
CityHashTable CHT2;

void initCHT(CityHashTable CHT, City cityarray[], int size) {
  for (int i=0; i<size; i++) {
    CHT.insert(cityarray[i]);
  }
}

int main() {
  initCHT(CHT1, cityarray, 15);
  CHT1.printHashTable();
  initCHT(CHT2, cityarray, 10);
  cout << CHT1.search(752180).city.getName();
  CHT2.remove(City("Seattle", 752180));
  CHT2.insert(City("Pheonix", 1660472));
  CHT2.printHashTable();
}