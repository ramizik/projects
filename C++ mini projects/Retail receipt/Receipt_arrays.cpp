// William Wilson & Ramis Hasanli
#include <iostream>
#include <vector>
using namespace std;

// Global Variables & Arrays
int a[] = { 5, 7, -2, 8, 11, -9, 4, 6, 12, -1 };
int b[] = { 4, 16, 9, -2, 1, 1, -2, 9, 16, 4 };
int i;
int vSize;
vector <int>vec1;
vector <int>vec2;
vector <int>vec3;
vector <int>greatest;


///////////////////////////////////////// FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// Step 4a
void initVector(vector <int>& vec, int ar[], int arSize) {
	int math;
	for (i = 0; i < arSize; i++) {
		math = ar[i];
		vec.push_back(math);
	}
}

// Step 4b
void printVector(vector <int>& const vec){
	vSize = vec.size();
	// Prints all except last
	for (i = 0; i < (vSize - 1); i++) {
		cout << vec.at(i) << ", ";
	}
	// Prints last
	cout << vec.back() << endl;
}

// Step 4c
int minVector(vector <int>& const vec) {
	vSize = vec.size();
	int minValue = vec.at(0);

	for (i = 0; i < vSize; ++i){
		if (minValue > vec.at(i)) {
			minValue = vec.at(i);
		}
	}
	return minValue;
}

// Step 4d
int productVector(vector <int>& const vec) {
	int product = 1;
	vSize = vec.size();

	for (i = 0; i < vSize; ++i) {
		product *= vec.at(i);
	}
	return product;
}

// Step 4e
void copyVector(vector <int>& const vecFr, vector<int>& vecTo) {
	vecTo = vecFr;
}

// Step 4f
void greaterVector(vector <int>& const first, vector <int>& const second, vector <int>& third) {
	int vecNum, largest;
	vSize = first.size();

	for (i = 0; i < vSize; ++i) {
		vecNum = second.at(i);
		largest = first.at(i);
			if (largest < vecNum) {
			largest = vecNum;
		}
		third.push_back(largest);
	}

}

// Step 4G
bool isPalindrome(vector <int>& const vec) {

	bool result = true;
	int vecSize = vec.size();
	for (i = 0; i < vecSize; ++i){
		if (vec.at(i) != vec.at (vecSize - (1 + i))) {
			result = false;
		}
	}
	return result;
}

// Step 4H
void updateLast(vector <int>& vec, int input) {
	vec.pop_back();
	vec.push_back(input);
}




///////////////////////////////////////// MAIN APPLICATION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main() {
	// Steps for main function
	// Step 1
	vSize = vec1.size();
	cout << "initial size of vec1: " << vSize << endl;

	// Step 2
	initVector(vec1, a, 10);

	// Step 3
	vSize = vec1.size();
	cout << "size of vec1 after initialization: " << vSize << endl;

	// Step 4
	cout << "vec1 content: "; printVector(vec1);

	// Step 5
	initVector(vec2, b, 10);

	// Step 6
	cout << "vec2 content: ";  printVector(vec2);

	// Step 7
	cout << "minimum of vec1: " << minVector(vec1);
	cout << endl;

	// Step 8
	cout << "product of vec1: " << productVector(vec1);

	// Step 9
	copyVector(vec1, vec3);
	cout << endl << "copy vec1 to vec3: ";
	printVector(vec3);

	// Step 10
	vec3.resize(0);
	greaterVector(vec1, vec2, vec3);
	cout << "collect larger elements from vec1 and vec2 to vec3: ";
	printVector(vec3);

	// Step 11
	if (isPalindrome(vec1) == false)
		cout << "vec1 is not a Palindrome";
	else
		cout << "vec1 is a Palindrome";
	cout << endl;

	// Step 12
	if (isPalindrome(vec2) == false)
		cout << "vec2 is not a Palindrome";
	else
		cout << "vec2 is a Palindrome";

	// Step 13
	updateLast(vec3, 7);
	cout << endl << "Updating the last element of vec3: ";
	printVector(vec3);

	cout << endl;

	cout << "^_^ This lab completed by William Wilson & Ramis Hasanli. Thanks & Have a Good Day! ^_^" << endl;
	return 0;
}