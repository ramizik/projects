// Ramis Hasanli & William Wilson | Lab 13 | COMP53
#include <list>
#include "city.h"
using namespace std;

//////////////////////////// Global Variables \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Steps 1-5
int a[]{ 2,8,1,7,3 };
City cityArray[]{ City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000) };
list <int> intList;
list <City> cityList;

//////////////////////////// APP FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// Step 6
template <typename T>
void initList(list <T>& listIn, T arrayIn[], int arrayInSize) {
	for (int i = 0; i < arrayInSize; ++i) {
		listIn.push_back(arrayIn[i]);
	}
}

template <typename T>
void printList(const list <T> listIn) {

	for (int value : listIn) {
		cout << value << " ";
	}
}

const void printCityList(list <City> cityListIn) {

	for (auto cityInfo : cityListIn) {

		cityInfo.printInfo();

	}
}

template <typename T> 
void rotateListRight(list<T>& l, int n) {
	for (int i = 0; i < n; i++) {
		l.push_front(l.back());
		l.pop_back();
	}
}

template <typename T> 
void rotateListLeft(list<T>& l, int n) {
	for (int i = 0; i < n; i++) {
		l.push_back(l.front());
		l.pop_front();
	}
}

void removeFromCityList(list<City>& l, string name) {
	list<City>::iterator iter;
	for (iter = l.begin(); iter != l.end(); iter++) {
		if (iter->getName() == name) {
			l.erase(iter);
			return;
		}
	}
}

void insertToCityList(list<City>& l, City newCity, string name) {
	list<City>::iterator iter;
	for (iter = l.begin(); iter != l.end(); iter++) {
		if (iter->getName() == name)
			l.insert(iter, newCity);
	}
}

//////////////////////////// MAIN FUNCTION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main() {


	initList(intList, a, 5);
	cout << "Initializing intList with a[]:" << endl;
	printList(intList);
	initList(cityList, cityArray, 5);
	cout << endl;
	cout << "Initializing cityList with cityArray[]:" << endl;
	printCityList(cityList);
	rotateListRight(intList, 2);
	cout << "Rotating intList to right twice:" << endl;
	printList(intList);
	rotateListRight(cityList, 1);
	cout << "Rotating cityList to right once:" << endl;
	printCityList(cityList);
	rotateListLeft(intList, 1);
	cout << "Rotating intList to left once:" << endl;
	printList(intList);
	rotateListLeft(cityList, 2);
	cout << "Rotating cityList to left twice:" << endl;
	printCityList(cityList);
	removeFromCityList(cityList, "Sacramento");
	cout << "Removing Sacramento from cityList:" << endl;
	printCityList(cityList);

	City redding("Redding", 90000);
	insertToCityList(cityList,redding, "Stockton");
	cout << "Inserting Redding to cityList before Stockton:" << endl;
	printCityList(cityList);

	return 0;
}