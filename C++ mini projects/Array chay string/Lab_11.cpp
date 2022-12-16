// Ramis Hasanli & William Wilson - Lab 11 - V 2.0 FINAL.
#include <string>
#include <iostream>
#include <vector>
using namespace std;

///////////////////////////////////////// FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

template <typename TheType>
void reverseArray(TheType ar[], int size) {
    int j = size - 1;
    TheType temp;

    for (int i = 0; i < j; i++, j--) {
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
}

template <typename TheType>
void printArray(TheType ar[], int size) {
    for (int i = 0; i < size; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

template <typename TheType>
void initVector(vector <TheType>& vec, TheType ar[], int size) {
    for (int i = 0; i < size; ++i) {
        vec.push_back(ar[i]);
    }
}

template <typename TheType>
void replaceLastThree(vector <TheType> &vec, TheType val1, TheType val2, TheType val3) {
    vec.at(vec.size() - 3) = val1;
    vec.at(vec.size() - 2) = val2;
    vec.at(vec.size() - 1) = val3;
}

template <typename TheType>
void printVector(vector <TheType> vec) {
    cout << " PRINTING VECTOR" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << ", ";
    }
    cout << endl;
}

template <typename TheType>
class Comparable {
public:
    Comparable(TheType item1, TheType item2) {
        this->item1 = item1;
        this->item2 = item2;  
    };
    bool lt() {
        if (item1 < item2)
            return true;
        else
            return false;
    }
    bool qt() {
        if (item1 > item2)
            return true;
        else
            return false;
    }
    bool eq() {
        if (item1 == item2)
            return true;
        else
            return false;
    }
private:
    TheType item1;
    TheType item2;
};


///////////////////////////////////////// GLOBAL VAR \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


int a[]{ 6,10,-4,-11,-2 };
char str[7]{ 'H','e','l','l','o','.' };
vector <int>vec1;
vector <char>vec2;



///////////////////////////////////////// MAIN APPLICATION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main()
{
    reverseArray(a, 5);
    cout << "\nReverse of array a[]:\n";
    printArray(a, 5);
    reverseArray(str, 7);
    cout << "Reverse of array str[]:\n";
    printArray(str, 7);

    cout << "Vector 1 from array a[]:\n";
    initVector(vec1, a, 5);
    printVector(vec1);

    cout << "\nVector 2 from array str[]:";
    initVector(vec2, str, 7);
    printVector(vec2);

    cout << "\nReplace last three elements of vec1 with 9, 0 , and 2:\n";
    replaceLastThree(vec1, 2, 0, 9);
    printVector(vec1);

    cout << "\nReplace last three elements of vec2 with f, y , and o:\n";
    replaceLastThree(vec2, 'o', 'y', 'f');
    printVector(vec2);

    Comparable <int>comp1(3, 5);
    Comparable <char>comp2('r', 'b');

    cout << "\nIs 1st component of comp1 less than 2nd component of it ?\n";
    cout << comp1.lt();

    cout << "\nIs 1st component of comp2 equal to 2nd component of it?\n";
    cout << comp2.eq();

    cout << "\n \tSorry for the late submission. Thanks & have a good day <3 " << endl;




    // Enter any letter to end app or close window
    string e;
    getline(cin, e);
    return 0;
}