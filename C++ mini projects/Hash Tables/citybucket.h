#ifndef CITYBUCKET_H
#define CITYBUCKET_H
#include<string>
#include "city.h"
enum BucketState {empty_since_start, empty_after_removal, filled};
class CityBucket {
public:
City city;
BucketState state;
CityBucket() {
city = City();
state = empty_since_start;
}
};
#endif