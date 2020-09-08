//============================================================================
// Name        : MiniLab.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Task 4
//Function prototypw
int RollDice(int, int);

int main() {
	//Task number 1
	double celcius = 0;
	double farenheit = 0;
	//User input
	cout << "Enter the temperature in Celsius\n";
	cin >> celcius;
	cin.clear();
	cin.ignore(32768, '\n');
	//Calculation
	farenheit = (((celcius * 9) / 5) + 32);
	cout << "The temperature in Fahrenheit is " << farenheit << endl;

	//Task 2
	double MLength = 0;
	int FLength = 0;
	int inches = 0;
	//User input
	cout << "Enter the length in meters\n";
	cin >> MLength;
	cin.clear();
	cin.ignore(32768, '\n');
	//Finds feet
	FLength = (MLength * 39.37) / 12;
	//Finds inches
	inches = ((MLength * 39.37) - FLength * 12);
	cout << "The length is " << FLength << " feet " << inches << " inches"
			<< endl;

	//Task 3
	int numbers = 0;
	int i = 0;
	while (true) {
		//User input
		cout << "Enter an integer or 0 to exit\n";
		cin >> numbers;
		cin.clear();
		cin.ignore(32768, '\n');
		//Check for 0
		if (numbers == 0) {
			break;
		} else {
			i++;
		}
	}
	cout << "Total numbers entered: " << i << endl;

	//Task 4
	int sum = 0;
	int dieSides = 0;
	int numDie = 0;
	//User input
	cout << "Please enter the number of sides per die\n";
	cin >> dieSides;
	cout << "Please enter the number of die\n";
	cin >> numDie;
	cin.clear();
	cin.ignore(32768, '\n');
	//Function call
	sum = RollDice(dieSides, numDie);
	cout << "The sum of all rolls is " << sum << endl;

	//Task 5
	string word;
	int length[10] = { 0 };
	while (true) {
		cout << "Enter a word or END to exit\n";
		getline(cin, word);
		//Check for END
		if (word == "END" || word == "end" || word == "End") {
			break;
			//Count words of each length
		} else if (word.length() == 1) {
			length[0]++;
		} else if (word.length() == 2) {
			length[1]++;
		} else if (word.length() == 3) {
			length[2]++;
		} else if (word.length() == 4) {
			length[3]++;
		} else if (word.length() == 5) {
			length[4]++;
		} else if (word.length() == 6) {
			length[5]++;
		} else if (word.length() == 7) {
			length[6]++;
		} else if (word.length() == 8) {
			length[7]++;
		} else if (word.length() == 9) {
			length[8]++;
		} else if (word.length() == 10) {
			length[9]++;
		} else {
		}
	}
	//Print
	for (int i = 0; i < 10; i++) {
		cout << "Number of words with length " << i + 1 << ": " << length[i]
				<< endl;
	}
	return 0;
}

//Task 4
//Function definition
int RollDice(int sides, int dice) {
	//starts time
	srand(time(NULL));
	int total = 0;
	for (int i = 0; i < dice; i++) {
		total += rand() % sides + 1;
	}
	return total;
}
