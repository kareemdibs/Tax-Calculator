#include <iostream>
#include <string>
using namespace std;

int main() {

	// Created variables for program to accept as input the taxpayer's name, taxable income, occupation, and number of children.

	string name;
	cout << "Name: ";
	getline(cin, name);

	double taxable_income;
	cout << "Taxable income: ";
	cin >> taxable_income;

	string occupation;
	cout << "Occupation: ";
	cin.ignore(10000, '\n');
	getline(cin, occupation);

	int children;
	cout << "Number of children: ";
	cin >> children;

	cout << "---" << endl;

	/* If string name is empty(""), double taxable_income is negative, string occupation is empty(""),
	 and/or int children is negative, then the program ends.*/

	if (name == "") {
		cout << "You must enter a name" << endl;
		return 1;
	}
	else if (taxable_income < 0) {
		cout << "The taxable income must not be negative" << endl;
		return 1;
	}
	else if (occupation == "") {
		cout << "You must enter an occupation" << endl;
		return 1;
	}
	else if (children < 0) {
		cout << "The number of children must not be negative" << endl;
		return 1;
	}

	// Calculations to specifically determine the tax based on taxable_income in different income brackets.

	double tax = 0;
	if (taxable_income <= 55000) {
		tax = 0.04 * taxable_income;
	}
	if (taxable_income > 55000 && taxable_income <= 125000) {
		if (occupation == "nurse" || occupation == "teacher") {
			tax += 0.04 * 55000;
			tax += 0.05 * (taxable_income - 55000);
		}
		else {
			tax += 0.04 * 55000;
			tax += 0.07 * (taxable_income - 55000);
		}
	}

	if (taxable_income > 125000) {
		if (occupation == "nurse" || occupation == "teacher") {
			tax += 0.04 * 55000;
			tax += 0.05 * 70000;
			tax += 0.093 * (taxable_income - 125000);
		}
		else {
			tax += 0.04 * 55000;
			tax += 0.07 * 70000;
			tax += 0.093 * (taxable_income - 125000);
		}
	}
	if (taxable_income < 125000) {
		tax -= 200 * children;
		if (tax < 0) {
			tax = 0;
		}
	}

	// Final message that states how much the user would pay in tax dollars based on their taxable_income and income bracket.

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << name << " would pay $" << tax << endl;

}