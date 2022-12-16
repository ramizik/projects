// PA04-B
// Ramis Hasanli
// This program computes weather chill factor
#include <iostream> // main()
#include <iomanip> // setw()
#include <vector> // Vector for W values
using namespace std;

// Header of the functions. double fn is for computing WindChiill
// void function declares initial variables such as air temperature and wind speed, then prints the whole table
double WindChill(double, double);
void Output();

// Declaring the functions mentioned above
double WindChill(double wind, double temp) {
	double p1 = 35.74;
	double p2 = 0.6215 * temp;
	double p3 = 35.74 * (pow(wind, 0.16));
	double p4 = 0.4275 * temp * (pow(wind, 0.16));
	return(p1 + p2 - p3 + p4);
}
void Output() {
	int tableWind[12];
	int tableTemp[11];
	double windact = 0;
	double tempact = 45;


	for (int i = 0; i < 12; i++) {
		tableWind[i] = windact + 5;
		windact = windact + 5;
	}
	for (int ii = 0; ii < 11; ii++) {
		tableTemp[ii] = tempact - 5;
		tempact = tempact - 5;
	}

	vector<double>TABLE;
	for (int i = 0; i < 12; i++) {
		for (int a = 0; a < 11; a++) {
			double wChill = WindChill(tableWind[i], tableTemp[a]);
			TABLE.push_back(wChill);
		}
	}
	cout << endl;
	cout << "calm" << setw(4) << tableTemp[0] << setw(4) << tableTemp[1] << setw(4) << tableTemp[2] << setw(4) << tableTemp[3] << setw(4) << tableTemp[4] << setw(4) << tableTemp[5] <<
		setw(4) << tableTemp[6] << setw(4) << tableTemp[7] << setw(4) << tableTemp[8] << setw(4) << tableTemp[9] << setw(4) << tableTemp[10] << endl;
	cout << setw(4) << tableWind[0] << setw(4) << int(TABLE.at(0)) << setw(4) << int(TABLE.at(1)) << setw(4) << int(TABLE.at(2)) << setw(4) << int(TABLE.at(3)) << setw(4) << int(TABLE.at(4)) << setw(4) << int(TABLE.at(5)) << setw(4) << int(TABLE.at(6))
		<< setw(4) << int(TABLE.at(7)) << setw(4) << int(TABLE.at(8)) << setw(4) << int(TABLE.at(9)) << setw(4) << int(TABLE.at(10)) << endl;
	cout << setw(4) << tableWind[1] << setw(4) << int(TABLE.at(11)) << setw(4) << int(TABLE.at(12)) << setw(4) << int(TABLE.at(13)) << setw(4) << int(TABLE.at(14)) << setw(4) << int(TABLE.at(15)) << setw(4) << int(TABLE.at(16)) << setw(4) << int(TABLE.at(17))
		<< setw(4) << int(TABLE.at(18)) << setw(4) << int(TABLE.at(19)) << setw(4) << int(TABLE.at(20)) << setw(4) << int(TABLE.at(21)) << endl;
	cout << setw(4) << tableWind[2] << setw(4) << int(TABLE.at(22)) << setw(4) << int(TABLE.at(23)) << setw(4) << int(TABLE.at(24)) << setw(4) << int(TABLE.at(25)) << setw(4) << int(TABLE.at(26)) << setw(4) << int(TABLE.at(27)) << setw(4) << int(TABLE.at(28))
		<< setw(4) << int(TABLE.at(29)) << setw(4) << int(TABLE.at(30)) << setw(4) << int(TABLE.at(31)) << setw(4) << int(TABLE.at(32)) << endl;

	cout << setw(4) << tableWind[3] << setw(4) << int(TABLE.at(33)) << setw(4) << int(TABLE.at(34)) << setw(4) << int(TABLE.at(35)) << setw(4) << int(TABLE.at(36)) << setw(4) << int(TABLE.at(37)) << setw(4) << int(TABLE.at(38)) << setw(4) << int(TABLE.at(39))
		<< setw(4) << int(TABLE.at(40)) << setw(4) << int(TABLE.at(41)) << setw(4) << int(TABLE.at(42)) << setw(4) << int(TABLE.at(43)) << endl;

	cout << setw(4) << tableWind[4] << setw(4) << int(TABLE.at(44)) << setw(4) << int(TABLE.at(45)) << setw(4) << int(TABLE.at(46)) << setw(4) << int(TABLE.at(47)) << setw(4) << int(TABLE.at(48)) << setw(4) << int(TABLE.at(49)) << setw(4) << int(TABLE.at(50))
		<< setw(4) << int(TABLE.at(51)) << setw(4) << int(TABLE.at(52)) << setw(4) << int(TABLE.at(53)) << setw(4) << int(TABLE.at(54)) << endl;

	cout << setw(4) << tableWind[5] << setw(4) << int(TABLE.at(55)) << setw(4) << int(TABLE.at(56)) << setw(4) << int(TABLE.at(7)) << setw(4) << int(TABLE.at(58)) << setw(4) << int(TABLE.at(59)) << setw(4) << int(TABLE.at(60)) << setw(4) << int(TABLE.at(61))
		<< setw(4) << int(TABLE.at(62)) << setw(4) << int(TABLE.at(63)) << setw(4) << int(TABLE.at(64)) << setw(4) << int(TABLE.at(65)) << endl;

	cout << setw(4) << tableWind[6] << setw(4) << int(TABLE.at(66)) << setw(4) << int(TABLE.at(67)) << setw(4) << int(TABLE.at(68)) << setw(4) << int(TABLE.at(69)) << setw(4) << int(TABLE.at(70)) << setw(4) << int(TABLE.at(71)) << setw(4) << int(TABLE.at(72))
		<< setw(4) << int(TABLE.at(73)) << setw(4) << int(TABLE.at(74)) << setw(4) << int(TABLE.at(75)) << setw(4) << int(TABLE.at(76)) << endl;

	cout << setw(4) << tableWind[7] << setw(4) << int(TABLE.at(77)) << setw(4) << int(TABLE.at(78)) << setw(4) << int(TABLE.at(79)) << setw(4) << int(TABLE.at(80)) << setw(4) << int(TABLE.at(81)) << setw(4) << int(TABLE.at(82)) << setw(4) << int(TABLE.at(83))
		<< setw(4) << int(TABLE.at(84)) << setw(4) << int(TABLE.at(85)) << setw(4) << int(TABLE.at(86)) << setw(4) << int(TABLE.at(87)) << endl;

	cout << setw(4) << tableWind[8] << setw(4) << int(TABLE.at(88)) << setw(4) << int(TABLE.at(89)) << setw(4) << int(TABLE.at(90)) << setw(4) << int(TABLE.at(91)) << setw(4) << int(TABLE.at(92)) << setw(4) << int(TABLE.at(93)) << setw(4) << int(TABLE.at(94))
		<< setw(4) << int(TABLE.at(95)) << setw(4) << int(TABLE.at(96)) << setw(4) << int(TABLE.at(97)) << setw(4) << int(TABLE.at(98)) << endl;

	cout << setw(4) << tableWind[9] << setw(4) << int(TABLE.at(99)) << setw(4) << int(TABLE.at(100)) << setw(4) << int(TABLE.at(101)) << setw(4) << int(TABLE.at(102)) << setw(4) << int(TABLE.at(103)) << setw(4) << int(TABLE.at(104)) << setw(4) << int(TABLE.at(105))
		<< setw(4) << int(TABLE.at(106)) << setw(4) << int(TABLE.at(107)) << setw(4) << int(TABLE.at(108)) << setw(4) << int(TABLE.at(109)) << endl;

	cout << setw(4) << tableWind[10] << setw(4) << int(TABLE.at(110)) << setw(4) << int(TABLE.at(111)) << setw(4) << int(TABLE.at(112)) << setw(4) << int(TABLE.at(113)) << setw(4) << int(TABLE.at(114)) << setw(4) << int(TABLE.at(115)) << setw(4) << int(TABLE.at(116))
		<< setw(4) << int(TABLE.at(117)) << setw(4) << int(TABLE.at(118)) << setw(4) << int(TABLE.at(119)) << setw(4) << int(TABLE.at(120)) << endl;

	cout << setw(4) << tableWind[11] << setw(4) << int(TABLE.at(121)) << setw(4) << int(TABLE.at(122)) << setw(4) << int(TABLE.at(123)) << setw(4) << int(TABLE.at(124)) << setw(4) << int(TABLE.at(125)) << setw(4) << int(TABLE.at(126)) << setw(4) << int(TABLE.at(127))
		<< setw(4) << int(TABLE.at(128)) << setw(4) << int(TABLE.at(129)) << setw(4) << int(TABLE.at(130)) << setw(4) << int(TABLE.at(131)) << endl;
}


// Start of the program
int main() {
	Output();
	// End of the program
	return 0;
}