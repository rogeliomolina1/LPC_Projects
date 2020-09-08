/*
 * Task.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: rogel
 */

#include "Task.h"

Task::Task(string title, string location, int priority) {
	// TODO Auto-generated constructor stub
	this->title = title;
	this->location = location;
	this->priority = priority;
}
string Task::Description() const {
	stringstream ss;
	ss << priority;
	return (title + " (priority: " + ss.str() + ", location: " + location + ")");
}

int Task::PriorityLevel() const {
	return priority;
}

