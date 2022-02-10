// STEP _CPP _classwork7 _09.02.22 _task2


#include <iostream>

/*Часы бьют каждый час, столько раз, сколько времени.
Написать программу, которая подсчитает, сколько раз
пробьют часы за 12 часов.*/

int main()
{
	setlocale(0, "");
	int nBells = 0;

	for (int nBell = 1; nBell <= 12; nBell++) {
		nBells += nBell;
	}

	std::cout << nBells;

}