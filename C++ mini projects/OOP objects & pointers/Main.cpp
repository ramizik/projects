// Ramis Hasanli & William Wilson
#include <iostream>
#include "CoastalCity.h"
using namespace std;


unsigned int coastalCity::coastalCityCount = 0;
int main() {
	
	coastalCity* ccityPtr = nullptr;
	ccityPtr = new coastalCity ("Atlantic Ocean", 8,  "Miami", 500000,  "Coral Gables", 50000) ;
	cout << "The address stored in ccityPtr: " << ccityPtr << endl;
	cout << "The address of adj city: " << (*ccityPtr).getAdjCiy() << endl;	
	(*ccityPtr).printInfo();
	cout << endl << "... deleting Miami from database now " << endl;
	delete ccityPtr;

	return 0;
}