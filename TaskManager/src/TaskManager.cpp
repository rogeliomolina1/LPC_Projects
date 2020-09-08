//============================================================================
// Name        : TaskManager1.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Task.h"

int main() {
	vector<Task*> taskList;
	char userChoice;
	string title;
	string location;
	int priority;
	unsigned int index;
	do {
		cout << "Welcome to Task Management System" << endl;
		cout << "====================================" << endl;
		cout << " 1. Add Item\n";
		cout << " 2. Complete Item\n";
		cout << " 3. Show All Items\n";
		cout << " 4. Show Items By Priority Number\n";
		cout << " 5. Quit\n";
		cout << "\nPlease Enter a Menu Option:\n";
		cin >> userChoice;
		cin.clear();
		cin.ignore(32768, '\n');

		switch (userChoice) {
		case ('1'): {
			cout << "Please enter a task title\n";
			getline(cin, title);
			cout << "Please enter a location\n";
			getline(cin, location);
			cout << "Please enter a priority level(1-5)\n";
			cin >> priority;
			cin.clear();
			cin.ignore(32768, '\n');
			while (priority < 1 || priority > 5) {
				cout << "Priority not between 1-5. Try Again\n";
				cin >> priority;
				cin.clear();
				cin.ignore(32768, '\n');
			}
			Task*task = new Task(title, location, priority);
			taskList.push_back(task);
			break;
		} //case1
		case ('2'): {
			if (taskList.size() == 0) {
				cout << "No tasks to complete\n\n";
			} else {
				cout
						<< "Please enter the index of the item you have completed\n";
				cin >> index;
				cin.clear();
				cin.ignore(32768, '\n');
				while (index < 0 || index > taskList.size() - 1) {
					cout << "Invalid index entered\n";
					cin >> index;
					cin.clear();
					cin.ignore(32768, '\n');
				}
				delete taskList[index];
				taskList.erase(taskList.begin() + index);
				cout << "Task completed\n\n";
			}
			break;
		}
		case ('3'): {
			if (taskList.size() == 0) {
				cout << "No tasks to show\n";
			} else {
				for (unsigned int i = 0; i < taskList.size(); i++) {
					cout << i << ") " << taskList[i]->Description() << endl;
				}
			}
			cout << endl;
			break;
		}
		case ('4'): {
			bool swap;
			Task *temp = 0;
			if (taskList.size() == 0) {
				cout << "No tasks to show\n";
			} else {
				do {
					swap = false;
					for (unsigned int ctr = 0; ctr < (taskList.size() - 1);
							ctr++) {
						if (taskList[ctr]->PriorityLevel()
								> taskList[ctr + 1]->PriorityLevel()) {
							temp = taskList[ctr];
							taskList[ctr] = taskList[ctr + 1];
							taskList[ctr + 1] = temp;
							swap = true;

						} //if
					} //for
				} while (swap);
				for (unsigned int i = 0; i < taskList.size(); i++) {
					cout << i << ") " << taskList[i]->Description() << endl;
				}
			}
			cout << endl;
			break;
		}
		case ('5'):
			cout << "Program Ending\n";
			break;
		default:
			cout << "Invalid menu option entered\n";
			break;
		} //switch
	} while (userChoice != '5');
	return 0;
}
