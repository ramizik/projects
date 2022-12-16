#include <iostream>
#include "cityheap.h"
#include "city.h"

using namespace std;

CityMaxHeap cityheap;

City cityarray[] {
  City("Sacremento", 505628),
  City("Eugene", 221452),
  City("Stockton", 323761),
  City("Redding", 90292),
  City("San Diego", 1591688),
  City("Reno", 289485),
  City("Los Angeles", 4340174),
  City("Portland", 730428),
  City("Las Vegas", 711926),
  City("Seattle", 752180),
  City("San Francisco", 871421)
};

int main() {
  cityheap = CityMaxHeap(cityarray, 11);
  cityheap.printHeap();
  City Denver = City("Denver", 600150);
  cityheap.insert(Denver);
  cityheap.printHeap();
  cityheap.remove();
  cityheap.printHeap();
  cityheap.heapSort();
  cityheap.printHeap();
}