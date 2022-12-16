// Ramis Hasanli & William Wilson
// Lab 15
#include <list>
#include <map>
#include <set>
#include "city.h"

using namespace std;


int a[]{ 2, 8, 1, 7, 3 };
City cityArray1[]{ City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000) };
City cityArray2[]{ City("Redding", 90000), City("Stockton", 300000), City("Las Vegas", 700000), City("Reno", 300000), City("Portland", 700000), City("Sacramento", 500000), City("Eugene", 200000) };
set <int> intSet;
set <City> citySet1, citySet2, citySet3;
set <string> cityNames;

template <typename T>
void initSet(set<T>& setIn, T arrIn[], int numEl) {

    for (int i = 0; i < numEl; ++i) {
        setIn.insert(arrIn[i]);
    }
}

template <typename T>
void printSet(set<T>& setIn) {
    for (const auto& e : setIn) {
        cout << e << " ";
    }
    cout << endl;
}

void printCitySet(set <City>& setIn) {
    for (const auto& e : setIn) {
        e.printInfo();
    }
}

void cityNamesSet(set <City>& setIn, set <string>& stringIn) {
    for (const auto& e : setIn) {
        stringIn.insert(e.getName());
    }
}

template <typename T>
void setIntersection(set <T>& setOne, set <T>& setTwo, set <T>& setThree) {
    for (const auto& e : setOne) {
        for (const auto& ee : setTwo) {
            if (e.getName() == ee.getName()) {
                setThree.insert(e);
            }
        }
    }
}

template <typename T>
void setUnion(set<T>& setOne, set<T>& setTwo, set<T>& setThree) {
    for (const auto& e : setOne) {
        setThree.insert(e);
    }
    for (const auto& ee: setTwo) {
        setThree.insert(ee);
    }

}

template <typename T>
bool isSubset(set<T>& setOne, set<T>& setTwo) {
    int size = setOne.size();
    int same = 0;

    for (const auto& e : setOne) {
        for (const auto& ee : setTwo) {
            if (e.getName() == ee.getName())
                same++;
        }
    }


    if (same == size)
        return true;
    else
        return false;
}


void removeFromCitySet(set<City>& setIn, const string cityIn) {
   
    for (auto e : setIn){
        if (e.getName() == cityIn) {
            setIn.erase(e);
            break;
        }
    }
}


int main() {
    // Step 1
    initSet(intSet, a, 5);
    // Step 2
    cout << "Initializing intSet with a[]:" << endl;
    printSet(intSet);
    cout << endl;
    // Step 3
    initSet(citySet1, cityArray1, 5);
    // Step 4
    cout << "Initializing citySet1 with cityArray1[]:" << endl;
    printCitySet(citySet1);
    cout << endl;
    // Step 5
    initSet(citySet2, cityArray2, 7);
    // Step 6
    cout << "Initializing citySet2 with cityArray2[]:" << endl;
    printCitySet(citySet2);
    cout << endl;
    // Step 7
    cityNamesSet(citySet1, cityNames);
    // Step 8
    cout << "Populate cityNames according to the cities in citySet1:" << endl;
    printSet(cityNames);
    cout << endl;
    // Step 9
    setIntersection(citySet1, citySet2, citySet3);
    cout << "Intersect citySet1 and citySet2, and store the result in citySet3:" << endl;
    printCitySet(citySet3);
    cout << endl;
    // Step 10
    setUnion(citySet1, citySet2, citySet3);
    cout << "Union citySet1 and citySet2, and store the result in citySet3:" << endl;
    printCitySet(citySet3);
    cout << endl;
    // Step 11
    cout << "citySet1 is a subset of citySet2?: " << isSubset(citySet1, citySet2) << endl;
    // Step 12
    cout << "citySet2 is a subset of citySet3?: " << isSubset(citySet2, citySet3) << endl;
    // Step 13
    removeFromCitySet(citySet1, "Sacramento");
    cout << endl;
    cout << "Removing Sacramento from citySet1:" << endl;
    printCitySet(citySet1);
   
    return 0;
}