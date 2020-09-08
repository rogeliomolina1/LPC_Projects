/*
 * GameException.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: rogel
 */

#include "GameException.h"

GameException::GameException(string msg) {
	message = msg;
}

string GameException::GetMessage() const {
	return message;
}

