// STEP _CPP _homework12 _09.03.22 _task3
/*
в картинке
// можно сделать ЧИСЛО_СДВИГОВ%РАЗМЕР_МАССИВА - для сдвигов больше чем размер массива
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>

const int ARR_ROWS = 3;
const int ARR_COLS = 4;
const int MIN_NUMBER = 0;
const int MAX_NUMBER = 9;

int arrNumbers[ARR_ROWS][ARR_COLS];
char shiftDirect;
int shiftAmount;
bool isDirectCorrect;

int tempCell;

int main() {
	setlocale(0, "");
	srand(time(NULL));

	std::cout << "СДВИГ ИСХОДНОЙ МАТРИЦЫ. ВЫБЕРИТЕ НАПРАВЛЕНИЕ. ВВЕДИТЕ КОЛИЧЕСТВО СДВИГОВ" << std::endl << std::endl;

	for (int i = 0; i < ARR_ROWS; i++) {
		for (int j = 0; j < ARR_COLS; j++) {
			arrNumbers[i][j] = rand() % MAX_NUMBER + 1 + MIN_NUMBER;
		}
	}

	do {
		for (int i = 0; i < ARR_ROWS; i++) {
			for (int j = 0; j < ARR_COLS; j++) {
				std::cout << arrNumbers[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << std::endl << std::endl;

		std::cout << "a - влево, d - вправо, w - вверх, s - вниз, x - выход: ";
		std::cin >> shiftDirect;

		isDirectCorrect = true;
		switch (shiftDirect) {
			case 'a':
			case 'd':
			case 'w':
			case 's':
				break;
			default:
				isDirectCorrect = false;
				break;
		}

		if (isDirectCorrect == true) { 
			std::cout << "Количество сдвигов: ";
			std::cin >> shiftAmount;

			for (int n = 1; n <= shiftAmount; n++) {

				switch (shiftDirect) {
				case 'a':
					for (int i = 0; i < ARR_ROWS; i++) {
						tempCell = arrNumbers[i][0];
						for (int j = 0; j < ARR_COLS - 1; j++) {
							arrNumbers[i][j] = arrNumbers[i][j + 1];
						}
						arrNumbers[i][ARR_COLS - 1] = tempCell;
					}
					break;
				case 'd':
					for (int i = 0; i < ARR_ROWS; i++) {
						tempCell = arrNumbers[i][ARR_COLS - 1];
						for (int j = ARR_COLS - 1; j > 0 ; j--) {
							arrNumbers[i][j] = arrNumbers[i][j - 1];
						}
						arrNumbers[i][0] = tempCell;
					}
					break;
				case 'w':
					for (int i = 0; i < ARR_COLS; i++) {
						tempCell = arrNumbers[0][i];
						for (int j = 0; j < ARR_ROWS - 1; j++) {
							arrNumbers[j][i] = arrNumbers[j + 1][i];
						}
						arrNumbers[ARR_ROWS - 1][i] = tempCell;
					}
					break;
				case 's':
					for (int i = 0; i < ARR_COLS; i++) {
						tempCell = arrNumbers[ARR_ROWS - 1][i];
						for (int j = ARR_ROWS - 1; j > 0 ; j--) {
							arrNumbers[j][i] = arrNumbers[j - 1][i];
						}
						arrNumbers[0][i] = tempCell;
					}
					break;
				default:
					isDirectCorrect = false;
					break;
				}

				


			} 

		}
		

	} while (shiftDirect != 'x');

	return 0;
}