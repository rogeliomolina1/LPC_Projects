/*
 * Task.h
 *
 *  Created on: Feb 15, 2016
 *      Author: rogel
 */

#ifndef TASK_H_
#define TASK_H_
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Task {
public:
	Task(string, string, int);
	string Description() const;
	int PriorityLevel() const;
private:
	string title;
	string location;
	int priority;

};

#endif /* TASK_H_ */
