#ifndef CITYHASH_H
#define CITYHASH_H
#include <string.h>
#include "citybucket.h"
const int maxArraySize = 100;
class CityHashTable {
public:
CityHashTable() {
tableSize = 0;
}
CityHashTable(int size) {
tableSize = size;
}
// empty_since_start, empty_after_removal, filled}
CityBucket search(unsigned int pop) {
   int bucket = hash(pop);
   int bucketsProbed = 0;

   while ((table[bucket].state != empty_since_start) &&
         (bucketsProbed < maxArraySize)) {

      if (table[bucket].state != empty_since_start && table[bucket].state != empty_after_removal && table[bucket].city.getPopulation() == pop)
 {
         return table[bucket];
      }

      // Increment bucket index
      bucket = (bucket + 1) % tableSize;;

      // Increment number of buckets probed
      ++bucketsProbed;
   }
}

bool insert(City inputCity) {
  CityBucket citybucket = CityBucket();
  citybucket.city = inputCity;
  citybucket.state = filled;
  int bucket = hash(inputCity.getPopulation());
  
  if (table[bucket].state == empty_after_removal || table[bucket].state == empty_since_start) {
    table[bucket] = citybucket;
    return true;
  }
  else {
    return false;
  }
};

void remove(City city) {
  int bucket = hash(city.getPopulation());
  int end = bucket;
  if (table[bucket].city.getName() == city.getName()) {
    table[bucket] = CityBucket();
    table[bucket].state = empty_after_removal;
    return;
  }
  else {
    while (end%tableSize != bucket) {
    if (table[bucket].city.getName() == city.getName()) {
    table[bucket] = CityBucket();
    table[bucket].state = empty_after_removal;
    return;
      }
    }
  }
  
};
void printHashTable() {
  for (int i=0; i<tableSize; i++) {
    table[i].city.printInfo();
  }
};
private:
CityBucket table[maxArraySize];
int tableSize;
int hash(unsigned int pop) {
  return pop % tableSize;
};
};
#endif