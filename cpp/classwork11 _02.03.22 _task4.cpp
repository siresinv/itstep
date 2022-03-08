// STEP _CPP _classwork11 _02.03.22 _task4
/*
	многомерные двумерные массивы
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>


int main() {

	setlocale(0, "");
	srand(time(NULL));

	const int row = 3;
	const int col = 4;
	int mas[row][col];
	int mas2[row][col];

	for (int i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			mas[i][j] = rand() % 50;
		}
	}

	for (int i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			std::cout << mas[i][j] << "\t ";
		}

		std::cout << std::endl;
	}


	return 0;
}

