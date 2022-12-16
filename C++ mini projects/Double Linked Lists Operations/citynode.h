#ifndef CITYNODE_H
#define CITYNODE_H
#include<string>
#include "city.h"

class CityNode {
public:
	City data;
	CityNode* next;
	CityNode* prev;

	CityNode(City city) {
		data = city;
		next = nullptr;
		prev = nullptr;
	}
};
#endif

//Essentially a CityNode object is used as an element of the list for cities, which consists of a data
// component(a city), and a pointer to the next CityNode.