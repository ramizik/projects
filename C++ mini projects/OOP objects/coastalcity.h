#include <iostream>
#include "City.h"

using namespace std;
// I recognize namespace std is non-ideal practice, but for the sake of this lab I used it.

class coastalCity : public City {
  public:
  coastalCity() {
    setName("N/A");
    setPopulation(0);
    watername = "N/A";
    numBeaches = 0;
  }
//Ye olde setters.
  void setWatername(string watername) {this->watername = watername;}
  void setnumBeaches(int numBeaches) {this->numBeaches = numBeaches;}
//Ye olde getters.
string getWatername() {
  return watername;
}
int getnumBeaches() {
  return numBeaches;
}
void PrintInfo() {
  City::printInfo();
  cout<<"Name of bodies of water: "<<getWatername()<<endl;
  cout<<"Number of beaches: "<<getnumBeaches()<<endl;
}

  private:
  string watername;
  int numBeaches;
};