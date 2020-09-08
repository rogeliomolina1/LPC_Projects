//*****************
//Project Name: Sales Summary Program
//Project Description: Calculates average sales and total sales
//Project Author: Molina, Rogelio
//Is this an extra credit Project:  No
//Date completed: 09/24/2015
//Operating system used: Windows
//IDE Used:  Eclipse
//*****************

#include <iostream>
#include <fstream>
using namespace std;

void clearcin(void);

int main() {
	string somestr;
	double sumOfSales = 0;
	int totalSalesFigures = 0;
	const int MAXROWS = 100;
	double salesFigures[MAXROWS];
	double sales[MAXROWS];
	ofstream outputFile;
	cout << "Welcome to My Sales Program\n";
	cout << "===========================\n";

	while (true) {
		cout << "How many sales figures would you like to enter?\n";
		cin >> totalSalesFigures;
		clearcin();
		if (totalSalesFigures > 0 && totalSalesFigures <= MAXROWS) {
			break;
		} else
			cout << "Invalid entry, must be 1-100\n";
	} //while
	for (int ctr = 0; ctr < totalSalesFigures; ctr++) {
		while (true) {
			cout << "Please enter the sales figures for year #" << (ctr + 1)
					<< endl;
			cin >> salesFigures[ctr];
			clearcin();
			if (salesFigures[ctr] < 0) {
				cout << "You cannot have negative sales\n";
			} else
				break;
		} //while
		sumOfSales = sumOfSales + salesFigures[ctr];

	} //for
	cout << "Your total sales were: " << sumOfSales << endl;
	cout << "Your average sales were: " << (sumOfSales / totalSalesFigures)
			<< endl;
	cout << "Writing your sales figures to Salesfigures.txt\n";
	outputFile.open("Salesfigures.txt");
	if (!outputFile) {
		cout << "There was an error opening Salesfigures.txt for output\n";
	} else {
		for (int ctr = 0; ctr < totalSalesFigures; ctr++) {
			cout << "Writing Sales Figure #: " << ctr + 1 << endl;
			outputFile << ctr << ": " << salesFigures[ctr] << endl;
		}//for
		outputFile.close();
	} //else
	ifstream inputFile;
	inputFile.open("Salesfigures.txt");
	for (int ctr = 0; ctr < 100; ctr++) {
		inputFile >> somestr;
		inputFile >> sales[ctr];

		if (inputFile.eof()) {
			break;
		} //if
		else {
			continue;
		} //else
	} //for
	inputFile.close();
	cout << "\nReading Files\n";
	int totalRead = 0;
	for (int ctr = 0; ctr < totalSalesFigures; ctr++) {
		cout << "Record #" << totalRead++ + 1 << endl;
		cout << sales[ctr] << endl;

	}//for
	cout << "\nTotal Records Read: " << totalRead << endl;
	cout << "\nProgram Ending, have a nice day!\n";
	return 0;
}
void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
} //clearcin
