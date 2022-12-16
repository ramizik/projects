// PA03 @ 12.10.21 | Late submission
// Ramis Hasanli
// Part A
#include <iostream>
#include <iomanip> // setw()
#include <string> // getline()
using namespace std;

struct ItemInfo
{
	string item_label;
	double item_price;
	char item_taxable;
};


// test app
int main() {
	// Declare known variables, struct & counter
	const double SALES_TAX_RATE = 0.09;
	double total_all_items = 0.0;
	double total_taxable_items = 0.0;
	short num_items = 0;
	double sales_tax, final_purchase_price;
	ItemInfo info[100];
	unsigned int i = 0;
	char item_ans;

	// A do-while loop is used, since it can be assumed that
	// the user has at least one item to process.
	do {
		// Prompt user to supply info about one item
		cout << '\n';
		cout << "Enter item price: $";
		cin >> info[i].item_price;
		cout << "Enter item label: ";
		cin >> info[i].item_label;
		// Check the size of the label
		if (info[i].item_label.size() > 20) {
			cout << "Item label is too long.";
			cout << '\n';
			break;
		}
		cout << "Is this item taxable? (y/n): ";
		cin >> info[i].item_taxable;

		// add curent item's price to accumulated total
		total_all_items += info[i].item_price;
		// count the number of items
		num_items++;
		// if item is taxable, add its price to accumulated taxable total
		if ((info[i].item_taxable == 'y') || info[i].item_taxable == 'Y')
			total_taxable_items += info[i].item_price;
		// Check the number of added items to the recipe, since we allow no more 100

		if (num_items > 99) {
			cout << '\n';
			cout << "Maximum number of items is 100.";
			break;
		}

		// ask user if there are more items
		cout << "OK. Add more items? (y/n): ";
		cin >> item_ans;
		// increase i for loop variable
		i++;
	} 
	while ((item_ans != 'n') && (item_ans != 'N') && i < 100);
	
	// Compute the sales tax & add tax to the final price
	sales_tax = total_taxable_items * SALES_TAX_RATE;
	final_purchase_price = total_all_items + sales_tax;
	cout << '\n';

	// Print all the items enetered by user & total cost
	for (unsigned ii = 0; ii < num_items; ii++) {
		if (info[ii].item_taxable == 'y' || info[ii].item_taxable == 'Y')
			cout << setw(17) << info[ii].item_label << "  $ " << setw(6) << setprecision(2) << fixed << info[ii].item_price << " T" << '\n';
		else
			cout << setw(17) << info[ii].item_label << "  $ " << setw(6) << setprecision(2) << fixed << info[ii].item_price << '\n';
	}
	cout << "Total Sale: $ " << setw(6) << setprecision(2) << fixed << total_all_items << '\n';
	cout << "Tax:" << setw(11) << "$  " << setprecision(2) << fixed << sales_tax << '\n';
	cout << '\n';
	cout << "Total Cost: $ " << setw(6) << setprecision(2) << fixed << final_purchase_price << '\n';

	system("pause");
	return 0;
}