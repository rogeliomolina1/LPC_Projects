/*
 * RandomArtFunctions.cpp
 *
 *  Created on: Sep 29, 2016
 *      Author: rogel
 */

#include "RandomArtFunctions.h"

void Run() {
	srand(time(0));
	char userChoice = 0;
	char lastChoice = 0;
	int minDepth = 1;
	int maxDepth = 1;
	int length = 0;
	int height = 0;
	Expression *E;
	int depth = 0;
	while (true) {
		cout << "Please enter the length of the graphics window: ";
		cin >> length;
		cout << endl;
		cin.clear();
		cin.ignore(32768, '\n');
		if (length > 0) {
			break;
		} else {
			continue;
		}
	}
	while (true) {
		cout << "Please enter the height of the graphics window: ";
		cin >> height;
		cout << endl;
		cin.clear();
		cin.ignore(32768, '\n');
		if (height > 0) {
			break;
		} else {
			continue;
		}
	}

	GraphicsWindow w(length, height, "Random Artist");
	GraphicsWindow*ptr = &w;
	do {
		cout << endl << endl;
		cout << "Welcome to Random Art Generator" << endl;
		cout << "====================================" << endl;
		cout << " 1. Enter an expression\n";
		cout << " 2. Set the minimum and maximum recursion depth\n";
		cout << " 3. Generate a random greyscale image\n";
		cout << " 4. Generate for a random color image\n";
		cout << " 5. Quit\n";
		cout << "\nPlease Enter a Menu Option (1-5):\n";
		string choice;
		if (getline(cin, choice) && !choice.empty()) {
			userChoice = choice[0];
			lastChoice = userChoice;
		} else {
			userChoice = lastChoice;
		}

		switch (userChoice) {
		case ('1'): {
			string userExpression;
			cout << "Please enter a valid expression: ";
			cin >> userExpression;
			cin.clear();
			cin.ignore(32768, '\n');
			UserImage(userExpression, ptr);
			break;
		} //case 1
		case ('2'): {
			while (true) {
				cout << "Enter a minimum depth (greater than or equal to 1):";
				cin >> minDepth;
				cin.clear();
				cin.ignore(32768, '\n');
				if (minDepth >= 1)
					break;
				else
					continue;
			}
			while (true) {
				cout << "Enter a maximum depth:";
				cin >> maxDepth;
				cin.clear();
				cin.ignore(32768, '\n');
				if (maxDepth >= minDepth)
					break;
				else
					continue;
			}
			break;
		} //case 2
		case ('3'): {
			depth = RandInt(minDepth, maxDepth);
			RandomGreyscale(depth, ptr, E);
			break;
		} //case 3
		case ('4'): {
			depth = RandInt(minDepth, maxDepth);
			RandomColor(depth, ptr);
			break;
		} //case 4
		case ('5'):
			break;
		default:
			cout << "Invalid menu option entered\n";
			break;
		} //switch
	} while (userChoice != '5');

	cout << "\nProgram is Ending\nGood Bye\n";
}
string Exp(int depth) {
	if (depth == 1) {
		string var[2] = { "x", "y" };
		return var[rand() % 2];
	} else {
		int r = rand() % 4;
		switch (r) {
		case 0:
			return "sin(pi*" + Exp(depth - 1) + ")";
		case 1:
			return "cos(pi*" + Exp(depth - 1) + ")";
		case 2:
			return "avg(" + Exp(depth - 1) + "," + Exp(depth - 1) + ")";
		case 3:
			return Exp(depth - 1) + "*" + Exp(depth - 1);
		}
	}
}

int RandInt(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

void UserImage(string userExpression, GraphicsWindow*w) {
	double x = 0;
	double y = 0;
	double color;
	Expression user(userExpression);
	if (user.SyntaxIsValid()) {
		user.Show();
		cout << endl << endl;
		for (double i = 0; i < w->GetWidth(); i++) {
			for (double j = 0; j < w->GetHeight(); j++) {
				x = (i - (w->GetWidth() / 2)) / (w->GetWidth() / 2);
				y = (j - (w->GetHeight() / 2)) / (w->GetHeight() / 2);
				color = (255 / 2) * (user.Evaluate(x, y) + 1);
				Color greyscale(color, color, color);
				w->DrawRectangle(i, j, 1, 1, greyscale, true);
			}
		}
		w->Refresh();
	} else {
		cout << endl << endl;
		cout << "Expression entered is not valid";
		cout << endl << endl;
	}
}

void RandomGreyscale(int depth, GraphicsWindow*w, Expression *E) {
	double x = 0;
	double y = 0;
	double color;
	E = new Expression(Exp(depth));
	E->Show();
	cout << endl << endl;
	for (double i = 0; i < w->GetWidth(); i++) {
		for (double j = 0; j < w->GetHeight(); j++) {
			x = (i - (w->GetWidth() / 2)) / (w->GetWidth() / 2);
			y = (j - (w->GetHeight() / 2)) / (w->GetHeight() / 2);
			color = (255 / 2) * (E->Evaluate(x, y) + 1);
			Color greyscale(color, color, color);
			w->DrawRectangle(i, j, 1, 1, greyscale, true);
		}
	}
	w->Refresh();
}

void RandomColor(int depth, GraphicsWindow*w) {
	double x = 0;
	double y = 0;
	double red;
	double green;
	double blue;
	Expression*redptr = new Expression(Exp(depth));
	Expression*greenptr = new Expression(Exp(depth));
	Expression*blueptr = new Expression(Exp(depth));
	cout << "Red: ";
	redptr->Show();
	cout << endl;
	cout << "Green: ";
	greenptr->Show();
	cout << endl;
	cout << "Blue: ";
	blueptr->Show();
	cout << endl;
	for (double i = 0; i < w->GetWidth(); i++) {
		for (double j = 0; j < w->GetHeight(); j++) {
			x = (i - (w->GetWidth() / 2)) / (w->GetWidth() / 2);
			y = (j - (w->GetHeight() / 2)) / (w->GetHeight() / 2);
			red = (255 / 2) * (redptr->Evaluate(x, y) + 1);
			green = (255 / 2) * (greenptr->Evaluate(x, y) + 1);
			blue = (255 / 2) * (blueptr->Evaluate(x, y) + 1);
			Color rgb(red, green, blue);
			w->DrawRectangle(i, j, 1, 1, rgb, true);
		}
	}
	w->Refresh();
}
