#ifndef CITYHEAP_H
#define CITYHEP_H
#include<string>
#include "city.h"
const int maxArraySize = 100;
class CityMaxHeap {
public:
CityMaxHeap() {
arraySize = 0;
}

CityMaxHeap(City arr[], int size) {
for(int i = 0; i < size; i++)
array[i] = arr[i];
arraySize = size;
cityHeapify();
}

void printHeap() {
  for (int i=0; i<arraySize; i++) {
    array[i].printInfo();
  };
};

void insert(City city) {
  arraySize++;
  array[arraySize-1] = city;
  percolateUp(arraySize-1);
};

void remove() {
  array[0] = array[arraySize-1];
  for (int i=0; i<arraySize; i++) {
    percolateDown(i, arraySize);
  }
  arraySize--;
};

void heapSort() {
   for (int i = arraySize / 2 - 1; i >= 0; i--) {
      percolateDown(i, arraySize);
   }

   for (int i = arraySize - 1; i > 0; i--) {
     City holder = array[0];
     array[0] = array[1];
     array[1]= holder;
     percolateDown(0, i);
   }
};
private:
City array[maxArraySize];
int arraySize;
void percolateUp(int nodeInd) {
     while (nodeInd > 0) {
      int parentInd = (nodeInd - 1)/2;
      if (array[nodeInd].getPopulation() <= array[parentInd].getPopulation())
         return;
      else {
        City holder = array[nodeInd];
        array[nodeInd] = array[parentInd];
        array[parentInd] = holder;
        nodeInd = parentInd;
      }
};
};
void percolateDown(int nodeInd, int size) {
   int childInd = 2 * nodeInd + 1;
  int value = array[nodeInd].getPopulation();

   while (childInd < arraySize) {
      int maxValue = value;
      int maxIndex = -1;
      for (int i = 0; i < 2 && i + childInd < arraySize; i++) {
         if (array[i + childInd].getPopulation() > maxValue) {
            maxValue = array[i + childInd].getPopulation();
            maxIndex = i + childInd;
         }
      }

      if (maxValue == value) {
         return;
      }
      else {
         //swap array[nodeInd] and array[maxIndex]
        City holder = array[nodeInd];
        array[nodeInd] = array[maxIndex];
        array[maxIndex] = holder;
         nodeInd = maxIndex;
         childInd = 2 * nodeInd + 1;
      }
   }
};
void cityHeapify() {
  for (int i=0; i<arraySize; i++) {
    percolateDown(i, arraySize);
  }
};
};
#endif