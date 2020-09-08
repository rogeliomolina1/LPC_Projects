//============================================================================
// Name        : FunctionAndArrayReview.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int quiz(string[5], string[5]);
string language(string[7]);
double totalRainfall(double[7]);
int largestValue(double[7]);
int smallestValue(double[7], double);
int main() {
	//Part 1
	string questions[5] = { "What color is the sky?",
			"At what temperature does water boil? (Celsius)",
			"Who is the first president of the US?(last name only)",
			"What does H20 stand for?",
			"Who wrote the Harry Potter books?(last name only)" };
	string answers[5] = { "blue", "100", "washington", "water", "rowling" };
	double score = 0;
	cout << "Answer the following questions using lowercase\n";
	score = quiz(questions, answers);
	cout << "You answered " << score << "% of the questions correctly\n";

	//Part 2
	string days[7];
	double rainfall[7] = { 0 };
	double total = 0;
	double average = 0;
	string largest;
	string smallest;
	string lang;

	lang = language(days);
	for (int i = 0; i < 7; i++) {
		if (lang == "English" || lang == "english") {
			cout << "Please enter the amount of rainfall for " << days[i]
					<< " (in inches)\n";
			cin >> rainfall[i];
			cin.clear();
			cin.ignore(32768, '\n');
		} else {
			cout << "Por favor ingresa la cantidad de lluvia en " << days[i]
					<< " (en pulgadas)\n";
			cin >> rainfall[i];
			cin.clear();
			cin.ignore(32768, '\n');
		}
	}
	//Total rainfall for the week
	total = totalRainfall(rainfall);
	//average rainfall
	average = total / 7;

	//Find largest value
	largest = days[largestValue(rainfall)];
	//Find smallest value
	smallest = days[smallestValue(rainfall, rainfall[largestValue(rainfall)])];
//Print results
	cout << "Total: " << total << endl;
	if (lang == "English" || lang == "english") {
		cout << "Average: " << average << endl;
		cout << "The day with the least rain was " << smallest << endl;
		cout << "The day with the most rain was " << largest << endl;
	} else {
		cout << "Promedio: " << average << endl;
		cout << "El dia con menos lluvia fue " << smallest << endl;
		cout << "El dia con mas lluvia fue " << largest << endl;

	}

	return 0;
}
//Starts quiz
int quiz(string q[5], string a[5]) {
	double counter = 0;
	string response;
	for (int i = 0; i < 5; i++) {
		cout << q[i];
		getline(cin, response);
		if (response == a[i]) {
			cout << "You are correct\n";
			counter++;
		} else {
			cout << "You are incorrect\n";
		}
	}
	counter = (counter / 5) * 100;
	return counter;
}
//Sets language
string language(string array[7]) {
	string reply;
	while (true) {
		cout << "\n\nEnglish or Spanish? (Type one)\n";
		getline(cin, reply);
		if (reply == "English" || reply == "english") {
			string day[7] = { "Monday", "Tuesday", "Wednesday", "Thursday",
					"Friday", "Saturday", "Sunday" };
			for (int i = 0; i < 7; i++) {
				array[i] = day[i];
			}

			break;
		} else if (reply == "Spanish" || reply == "spanish") {
			string day[7] = { "Lunes", "Martes", "Miercoles", "Jueves",
					"Viernes", "Sabado", "Domingo" };
			for (int i = 0; i < 7; i++) {
				array[i] = day[i];
			}
			break;
		} else {
			continue;
		}
	}
	return reply;
}
//Total rainfall for the week
double totalRainfall(double array[7]) {
	double sum = 0;
	for (int i = 0; i < 7; i++) {
		sum += array[i];
	}
	return sum;
}
//Find largest value
int largestValue(double array[7]) {
	int counter = 0;
	double temp = 0;
	for (int i = 0; i < 7; i++) {
		if (array[i] > temp) {
			temp = array[i];
			counter = i;
		} else {
		}
	}
	return counter;
}
//Find smallest value
int smallestValue(double array[7], double large) {
	int counter = 0;
	double tempSmall = large;
	for (int i = 0; i < 7; i++) {
		if (array[i] < tempSmall) {
			tempSmall = array[i];
			counter = i;
		} else {
		}
	}
	return counter;
}
