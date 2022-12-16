
#include <list>
#include <map>
#include "city.h"

using namespace std;


City cityArray[]{ City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000) };
map<string, unsigned int> citymapp;


void initmap(map<string, unsigned int>& citymap, City cityArr[], int size) {
for (int i=0; i<size; i++) {
  citymap.emplace(cityArr[i].getName(), cityArr[i].getPopulation());
}
}

void PrintCityMap(map<string, unsigned int> citymap) {
for (pair<string, int>e : citymap) {
  cout << e.first << ": " << e.second << endl;
}  
}

int findPopulation(map<string, unsigned int> citymap, string city) {
  if (citymap.count(city) == true) {
    return citymap.at(city);
  }
  else {
    return 0;
  }
}

void updatePopulation(map<string, unsigned int>& citymap, string city, unsigned int pop) {
  if (citymap.count(city) == true) {
    citymap.at(city) = pop;
  }
    if (citymap.count(city) == false) {
    citymap.emplace(city, pop);
  }
}
    
void removeFromMap(map<string, unsigned int>& citymap, string city) {
    if (citymap.count(city) == true) {
        citymap.erase(city);
  }

}

int main() {
initmap(citymapp, cityArray, 5);
PrintCityMap(citymapp);
cout << "Sacramento Population: " << findPopulation(citymapp, "Sacramento") << endl;
cout << "Chicago Population: " << findPopulation(citymapp, "Chicago") << endl;
updatePopulation(citymapp, "Stockton", 350000);
  cout << "Stockton Population: " << findPopulation(citymapp, "Stockton") << endl;
  updatePopulation(citymapp, "Portland", 700000);
  cout << "Portland Population: " << findPopulation(citymapp, "Portland") << endl;
  removeFromMap(citymapp, "San Francisco");
  PrintCityMap(citymapp);


}