// STEP _CPP _homework11 _02.03.22 _task1
/*
	В картинке
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>


const int ROWS = 3;
const int COLS = 4;
int arrNumbers[ROWS][COLS];
int zeroCount;


int main()
{
	setlocale(0, "");
	srand(time(NULL));
	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arrNumbers[i][j] = rand() % 11 - 5;
		}
	}

	zeroCount = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			std::cout << arrNumbers[i][j] << "\t";
			if (arrNumbers[i][j] == 0) zeroCount++;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Количество нулей в массиве - " << zeroCount;
	std::cout << std::endl;



	return 0;

}

