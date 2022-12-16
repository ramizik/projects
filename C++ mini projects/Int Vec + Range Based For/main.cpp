#include <iostream>
#include <vector>

//William Wilson and Ramis Haslani

  int a[] {5, 7, -2, 8, 11, -9, 4, 6, 12, -1};

  std::vector <int> vec1;


void initVector(std::vector <int>& vec, int ar[], int size) {
    for (int i = 0; i < size; ++i) {
        vec.push_back(ar[i]);
    }
}

void printVector(std::vector <int> intvector) {
  for (int value: intvector) {
    std::cout << value << " ";
  }
}

int minVector(std::vector <int> intvector) {
  int min = intvector.at(0);
  for (int &value: intvector) {
    if (value < min) {
      min = value;
    }
  }
  return min;
}

int productVector(std::vector <int> intvector) {
  int product = 1;
    for (int value: intvector) {
        product = product*value;
    }
    return product;
}

void doublevector(std::vector <int>& intvector) {
  for (int &value : intvector) {
    value = value*2;
  }
  }
  
void aggregationVector(std::vector <int> &intvector) {
  int aggregate=0;
  for (int &value: intvector) {
    aggregate = aggregate+value;
    value = aggregate;
    }
  }
  

int main() {


  initVector(vec1, a, 10);

  std::cout << "Initial vector values: ";
  printVector(vec1);
  std:: cout << std::endl;

  std::cout << "Lowest value: " << minVector(vec1) << std::endl;

  std::cout << "Product of all values: " << productVector(vec1) << std::endl;

  doublevector(vec1);
  std::cout << "All values doubled: ";
  printVector(vec1);
  std::cout << std::endl;

  aggregationVector(vec1);
  std::cout << "All values aggregated: ";
  printVector(vec1);

}