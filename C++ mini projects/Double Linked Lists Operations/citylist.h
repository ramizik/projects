#ifndef CITYLIST_H
#define CITYLIST_H
#include<string>
#include "citynode.h"


class CityList {
public:
	CityList() {
		head = tail = nullptr;
	}

	// Lab 25

	void append(CityNode* cityNode) {
		if (head == nullptr) {
			head = cityNode;
			tail = cityNode;
		}
		else {
			tail->next = cityNode;
			cityNode->prev = tail;
			tail = cityNode;
		}
	}

	void prepend(CityNode* cityNode) {
		if (head == nullptr) {
			head = cityNode;
			tail = cityNode;
		}
		else {
			cityNode->next = head;
			head->prev = cityNode;
			head = cityNode;
		}
	}

	CityNode* search(std::string cityName) {
		CityNode* currentNode = head;
		while (currentNode != nullptr) {
			if (currentNode->data.getName() == cityName)
				return currentNode;
			currentNode = currentNode->next;
		}
		return nullptr;
	}

	void printCityList() {
		CityNode* currentNode = head;
		
		while (currentNode != nullptr){
			currentNode->data.printInfo();
			currentNode = currentNode->next;
		}
	}


	// Lab 26, 27

	void insert(CityNode* currNode, CityNode* cityNode) {
		CityNode* sucNode;
		if (head == nullptr) {
			head = cityNode;
			tail = cityNode;
		}
		else if (currNode == tail) {
			tail->next = cityNode;
			cityNode->prev = tail;
			tail = cityNode;
		}
		else {
			sucNode = currNode->next;
			cityNode->next = sucNode;
			cityNode->prev = currNode;
			currNode->next = cityNode;
			sucNode->prev = cityNode;
		}
	}

	void remove(CityNode* currNode) {
		CityNode* sucNode;
		CityNode* prevNode;
		sucNode = currNode->next;
		prevNode = currNode->prev;

		if (sucNode != nullptr)
			sucNode->prev = prevNode;
		if (prevNode != nullptr)
			prevNode->next = sucNode;
		if (currNode == head)
			head = sucNode;
		if (currNode == tail)
			tail = prevNode;
	}

private:
	CityNode* head;
	CityNode* tail;

};


#endif