// PA04-C
// Ramis Hasanli
// This program creates 4 arrays, fills with random int & computes statistics for it
#include <iostream> // main()
#include <stdlib.h> // rand()
#include <ctime> // Unique seed for rand()
using namespace std;

// Declaring 3 functions
// 1st for finding rand int
// 2nd to fill arrays with int
// 3rd for computing & output stats
long randomInRange(long min, long max);
long randomInRange(long min, long max) {
	return min + rand() % (max - min);
}
void randomFill(long array[], short array_size, long min, long max);
void randomFill(long array[], short array_size, long min, long max) {
	for (int i = 0; i < array_size; i++) {
		array[i] = randomInRange(min, max);
	}
}
void arrayStatistics(long array[], short array_size, long& min, long& max, double& average);
void arrayStatistics(long array[], short array_size, long& min, long& max, double& average){
    // Min & Max finder
    for (int ii = 1; ii < array_size; ii++){
    if (array[ii] < min){
        min = array[ii];
    }}
    for (int i = 1; i < array_size; i++){
        if (max < array[i]){
            max = array[i];
        }}
    // Average finder
    long sum = 0;
    for (int x = 0; x < array_size; x++)
        sum = sum + array[x];
    long delim = array_size;
    average = average + (sum / delim);
    cout << "Statistics for this array: " << endl;
    cout << "Min value: " << min << " Max value: " << max << " Average value: " << average << endl << endl;
}

// Start of the program
int main() {
// Declare & fill 4 arrays with random values in range 1000-5000
long ArrayOne[10]; long ArrayTwo[100]; long ArrayThree[1000]; long ArrayFour[10000];
randomFill(ArrayOne, 10, 1000, 5001); randomFill(ArrayTwo, 100, 1000, 5001); randomFill(ArrayThree, 1000, 1000, 5001); randomFill(ArrayFour, 10000, 1000, 5001);

// Declaring additional variables for return by reference
// and separately printing out statistics of 4 arrays
long min = 5000;
long max = 0;
double average = 0;
arrayStatistics(ArrayOne, 10, min, max, average), arrayStatistics(ArrayTwo, 100, min, max, average), arrayStatistics(ArrayThree, 1000, min, max, average), arrayStatistics(ArrayFour, 10000, min, max, average);

// End of the program
return 0;
}
    