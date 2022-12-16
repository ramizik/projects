#ifndef CITYLIST_H
#define CITYLIST_H
#include "citynode.h"
#include <string>

class CityList {
public:
    CityList() {
        CityNode* dummy = new CityNode(City());
        head = dummy;
        tail = dummy;
    }

    void append(CityNode* cityNode) {
        tail->next = cityNode;
        cityNode->prev = tail;
        tail = cityNode;
    }

    void prepend(CityNode* cityNode) {
        CityNode* firstNode = head->next;

        cityNode->next = head->next;
        cityNode->prev = head;

        head->next = cityNode;

        if (firstNode != nullptr) {
            firstNode->prev = cityNode;
        }
    }

    void printCityList() {
        CityNode* temp = head->next;
        while (temp != nullptr) {
            temp->data.printInfo();
            temp = temp->next;
        }
    }

    CityNode* search(std::string cityName) {
        CityNode* curNode = head->next;
        while (curNode != nullptr) {
            if (curNode->data.getName() == cityName)
                return curNode;
            curNode = curNode->next;
        }
        return nullptr;
    }

    void insert(CityNode* currNode, CityNode* cityNode) {
        if (currNode == tail) {
            tail->next = cityNode;
            cityNode->prev = tail;
            tail = cityNode;
        }
        else {
            CityNode* sucNode = currNode->next;
            cityNode->next = sucNode;
            cityNode->prev = currNode;
            currNode->next = cityNode;
            sucNode->prev = cityNode;
        }
    }

    void remove(CityNode* currNode) {
        if (currNode == head) {
            return;
        }

        CityNode* sucNode = currNode->next;
        CityNode* predNode = currNode->prev;

        if (sucNode != nullptr) {
            sucNode->prev = predNode;
        }

        predNode->next = sucNode;

        if (currNode == tail) {
            tail = predNode;
        }
    }

    void insertionSortByPopulation() {
        CityNode* searchNode;
        CityNode* nextNode;
        CityNode* currNode = head->next;
        while (currNode != nullptr) {
            nextNode = currNode->next;
            searchNode = currNode->prev;
            while ((searchNode != nullptr) && (searchNode->data.getPopulation() >
                currNode->data.getPopulation()))
                searchNode = searchNode->prev;
            remove(currNode);
            if (searchNode == nullptr) {
                currNode->prev = nullptr;
                prepend(currNode);
            }
            else
                insert(searchNode, currNode);
            currNode = nextNode;
        }
    }

private:
    CityNode* head;
    CityNode* tail;
};
#endif