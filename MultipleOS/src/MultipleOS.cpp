//============================================================================
// Name        : MultipleOS.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#ifdef __MINGW32__
#include <windows.h>
#elif __APPLE__
#include "TargetConditions.h"
#endif
using namespace std;

int main() {
	unsigned long total = 2000000000;

	cout << "Gonna count to " << total << endl;
#ifdef __MINGW32__
	WORD startMillis, endMillis;
	SYSTEMTIME startTime, endTime;
	GetSystemTime(&startTime);
	startMillis = (startTime.wSecond * 1000) + startTime.wMilliseconds;
#elif __APPLE__
#if TARGET_OS_MAC
	clock_t startingTime=clock();
#endif
#endif

	for (unsigned long i = 0; i < total; i++) {
	} //for

#ifdef __MINGW32__
	GetSystemTime(&endTime);
	endMillis = (endTime.wSecond * 1000) + endTime.wMilliseconds;
	cout << "It took: " << (endMillis - startMillis)
			<< " to count to 2 billion";

#elif __APPLE__
#if TARGET_OS_MAC
	clock_t endingTime=clock();
	cout << "It took: " << (endingTime - startingTime)
	<< " to count to 2 billion";
#endif
#endif

	return 0;
}
