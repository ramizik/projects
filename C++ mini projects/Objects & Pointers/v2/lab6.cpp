// Ramis Hasanli & William Wilson
#include <iostream>
#include "CoastalCity.h"
using namespace std;
 
// Outisde the scope of main we need to declare our counter
unsigned int coastalCity::coastalCityCount = 0;
 
int main() {
    
    coastalCity ccity1("Pacific Ocean", 5, "San Diego", 1500000);
    cout << "The address of ccity1: " << & ccity1 << endl;
    // This is Stack memory
 
    coastalCity* ccityPtr1 = nullptr;
    // Outputs 0000000000. I think it's same as 0 :)
    cout << "The address stored in ccityPtr1: " << ccityPtr1 << endl;
 
    ccityPtr1 = &ccity1;
    cout << "The address stored in ccityPtr1: " << ccityPtr1 << endl;
 
    cout << endl << "cityPtr1 used to call printInfo()" << endl;
 
    cout << "Using -> syntax:" << endl;
    ccityPtr1->printInfo();
    cout << endl;
    cout << "Using * syntax:" << endl;
    (*ccityPtr1).printInfo();
    cout << endl;
 
    coastalCity* ccityPtr2 = nullptr;
    ccityPtr2 = new coastalCity("Atlantic Ocean", 8, "Miami", 500000);
 
    cout << "The address stored in ccityPtr2: " << ccityPtr2 << endl;
    // This is Heap memory now
 
    cout << endl << "cityPtr2 used to call printInfo()" << endl;
 
    cout << "Using -> syntax:" << endl;
    ccityPtr2->printInfo();
    cout << endl;
    cout << "Using * syntax:" << endl;
    (*ccityPtr2).printInfo();
    cout << endl;
 
    // Is this how you guys did step 12 for lab?
    // I'm getting erros while tryting to deallocate the memory for ccitytPtr2. 
    // I'm using delete ccityPtr2
    // and i get errors
 
    // delete ccityPtr2
    cout << "ccityPtr1 memory has been deallocated. Can't access content :( " << endl;
    cout << "The address stored in ccityPtr2: " << ccityPtr2 << endl;
 
 
 
    return 0;
}