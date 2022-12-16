#ifndef CITY_H
#define CITY_H

#include <utility>
#include <string>
#include <iostream>

using namespace std;

class City {
public:
City(string nm, unsigned int pop) {
cityPair = make_pair(nm, pop);
}
void setName(string name) {cityPair.first = name;}
void setPopulation(unsigned int population)
{cityPair.second = population;}
string getName() const {return cityPair.first;}
unsigned int getPopulation() const {return cityPair.second;}
virtual void printInfo() const {
cout << getName() <<": "<< getPopulation() << endl;
}




bool operator < (const City& cityin) const { return this->cityPair.first < cityin.getName(); }


protected:
pair<string, int> cityPair;
};
#endif