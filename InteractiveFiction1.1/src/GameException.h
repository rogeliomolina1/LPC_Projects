/*
 * GameException.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rogel
 */

#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <string>
using namespace std;

class GameException {
private:
	string message;
public:
	GameException(string msg);
	string GetMessage() const;
};

#endif // GAMEEXCEPTION_H
