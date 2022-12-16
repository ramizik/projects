// Ramis Hasanli & William Wilson
// Lab 16
#include <queue>
#include <deque>
#include <algorithm>
#include "city.h"

using namespace std;

City cityArray1[] { City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000) };
queue <City> cityQueue;
deque <City> cityStack;
vector <City> cityVector;


void initQueue(queue <City>& queueIn, City arrIn[], int numEl) {

	for (int i = 0; i < numEl; ++i) {
		queueIn.push(arrIn[i]);
	}

}

void printCityQueue(queue <City> queueIn) {

	string nameCopy;
	int popCopy;
	int size = queueIn.size();
	

	for (int i = 0; i < size; ++i){
		nameCopy = queueIn.front().getName();
		popCopy = queueIn.front().getPopulation();
		queueIn.push(City(nameCopy, popCopy));
		queueIn.front().printInfo();
		queueIn.pop();
	}
}

void initStack(deque <City>& dequeueIn, City arrIn[], int numEl) {
	for (int i = 0; i < numEl; ++i) {
		dequeueIn.push_front(arrIn[i]);
	}
}

void printCityStack(deque <City>& dequeueIn) {
	deque <City> secondStack;
	string nameCopy;
	int popCopy;
	int size = dequeueIn.size();

	for (int i = 0; i < size; ++i) {
		nameCopy = dequeueIn.front().getName();
		popCopy = dequeueIn.front().getPopulation();
		secondStack.push_front(City(nameCopy, popCopy));
		dequeueIn.front().printInfo();
		dequeueIn.pop_front();
	}

	size = secondStack.size();

	for (int i = 0; i < size; ++i) {
		nameCopy = secondStack.front().getName();
		popCopy = secondStack.front().getPopulation();
		dequeueIn.push_front(City(nameCopy, popCopy));
		secondStack.pop_front();
	}


}

void initVector(vector <City>& vecIn, City arrIn[], int numEl) {

	for (int i = 0; i < numEl; ++i) {
		vecIn.push_back(arrIn[i]);
	}
}

void printCityVector(vector <City> vecIn) {

	for (City vecCity : vecIn) {
		vecCity.printInfo();
	}
}

bool fNameLarger(City cityOne, City cityTwo) {
	return !(cityOne > cityTwo);
}

bool fPopisSmaller(City cityOne, City cityTwo) {
	return (cityOne < cityTwo);
}



int main() {
	// Step 1
	cout << "Initializing cityQueue with cityArray[]:" << endl;
	initQueue(cityQueue, cityArray1, 5);
	printCityQueue(cityQueue);
	// Step 2
	cout << endl << "Initializing cityStack with cityArray[]:" << endl;
	initStack(cityStack, cityArray1, 5);
	printCityStack(cityStack);

	// Step 3
	cout << endl << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector, cityArray1, 5);
	printCityVector(cityVector);

	// Step 4
	cout << endl << "Sorting cityVector based on names in descending order:" << endl;
	sort(cityVector.begin(), cityVector.end(), fNameLarger);
	printCityVector(cityVector);

	// Step 5
	cout << endl << "Sorting cityVector based on populations in ascending order:" << endl;
	sort(cityVector.begin(), cityVector.end(), fPopisSmaller);
	printCityVector(cityVector);


	return 0;

}