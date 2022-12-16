#include <iostream>
#include "coastalcity.h"

using namespace std;

//William Wilson and Ramis Haslani

int main() {

  coastalCity thecity;

  thecity.PrintInfo();
  thecity.setName("San Francisco");
  thecity.setPopulation(900000);
  thecity.setWatername("SF Bay");
  thecity.setnumBeaches(10);
  thecity.PrintInfo();



  return 0;
}