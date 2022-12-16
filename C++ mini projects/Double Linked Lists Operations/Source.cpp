// Ramis Hasanli & William Willson
#include <iostream>
#include "city.h"
#include "citynode.h"
#include "citylist.h";

using namespace std;


City cityarray[]{
	City("Los Angeles", 4340174),
	City("San Diego", 1591688),
	City("San Francisco", 871421),
	City("Sacramento", 505628),
	City("Stockton", 323761),
	City("Redding", 90292),
	City("Las Vegas", 711926),
	City("Reno", 289485),
	City("Portland", 730428),
	City("Seattle", 752180),
	City("Eugene", 221452)
};

CityList cityList1;
CityList cityList2;


void initCityListByAppend(CityList& cityListIn, City cityArrIn[], int size) {
	for (int i = 0; i <= size-1; i++) {
		CityNode* currentCity = new CityNode(cityArrIn[i]);
		cityListIn.append(currentCity);
	}
}

void initCityListByPrepend(CityList& cityListIn, City cityArrIn[], int size) {
	for (int i = 0; i <= size-1; i++) {
		CityNode* currentCity = new CityNode(cityArrIn[i]);
		cityListIn.prepend(currentCity);
	}
}


int main() {
	cout << "Initializing cityList1 with cityArray[] using appending:" << endl;
	initCityListByAppend(cityList1, cityarray, 11);
	cityList1.printCityList();
	cout << endl;

	cout << "Initializing cityList2 with cityArray[] using prepending:" << endl;
	initCityListByPrepend(cityList2, cityarray, 11);
	cityList2.printCityList();
	cout << endl;


	cout << "Searching for Stockton in cityList1, and inserting Phoenix after it:" << endl;
	City newCity("Phoenix", 1660472);
	CityNode newNode(newCity);
	CityNode* find = nullptr;
	find = cityList1.search("Stockton");
	cityList1.insert(find, &newNode);
	cityList1.printCityList();
	cout << endl;


	cout << "Searching for Reno in cityList2, and removing that node:" << endl;
	find = cityList2.search("Reno");
	cityList2.remove(find);
	cityList2.printCityList();

	return 0;
}