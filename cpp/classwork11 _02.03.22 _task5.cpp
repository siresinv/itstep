// STEP _CPP _classwork11 _02.03.22 _task5
/*
	многомерные двумерные массивы
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>

int minElement;
int maxElement;


int main() {

	setlocale(0, "");
	srand(time(NULL));

	const int row = 3;
	const int col = 4;
	int mas[row][col];
	

	for (int i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			mas[i][j] = rand() % 50;
		}
	}
	
	for (int i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			std::cout << mas[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	

	for (int i = 0; i < row; i++) {
		maxElement = mas[i][0];
		for (size_t j = 0; j < col; j++) {
			if (maxElement < mas[i][j]) {
				maxElement = mas[i][j];
			}
		}
		std::cout << "ћакс в " << i + 1 << " строке - " << maxElement << std::endl;
	}

	std::cout << std::endl;

	return 0;
}

