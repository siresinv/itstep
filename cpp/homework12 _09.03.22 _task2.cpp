// STEP _CPP _homework12 _09.03.22 _task2
/*
в картинке
*/

#include <iostream>

const int ARR_ROWS = 3;
const int ARR_COLS = 4;
const int TERM = 1;

int arrNum[ARR_ROWS][ARR_COLS];
int firstNumber;


int main() {
	setlocale(0, "");
	std::cout << "Введите число: ";
	std::cin >> firstNumber;
	for (int i = 0; i < ARR_ROWS; i++) {
		for (int j = 0; j < ARR_COLS; j++) {
			arrNum[i][j] = firstNumber;
			firstNumber += TERM;
		}
	}

	for (int i = 0; i < ARR_ROWS; i++) {
		for (int j = 0; j < ARR_COLS; j++) {
			std::cout << arrNum[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}