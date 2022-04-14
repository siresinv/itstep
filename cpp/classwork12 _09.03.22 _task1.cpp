// STEP _CPP _classwork12 _09.03.22 _task1
/*
	Задание 1. В двумерном массиве целых числе посчитать:
■ Сумму всех элементов массива;
■ Среднее арифметическое всех элементов массива;
■ Минимальный элемент;
■ Максимальный элемент
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>


const int MATRIX_SIZE = 5;
int arrNum[MATRIX_SIZE][MATRIX_SIZE];
int sumNum;
float avgNum;
int minNum;
int maxNum;

int main() {

	setlocale(0, "");
	srand(time(NULL));

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			arrNum[i][j] = rand() % 10 + 1;
			
		}
	}

	sumNum = 0;
	minNum = arrNum[0][0];
	maxNum = arrNum[0][0];
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			std::cout << arrNum[i][j] << " ";
			sumNum += arrNum[i][j];
			if (minNum > arrNum[i][j]) {
				minNum = arrNum[i][j];
			}

			if (maxNum < arrNum[i][j]) {
				maxNum = arrNum[i][j];
			}

		}
		std::cout << std::endl;
	}

	avgNum = sumNum / float(MATRIX_SIZE * MATRIX_SIZE);
	std::cout << "Sum = " << sumNum << std::endl;
	std::cout << "Avg = " << avgNum << std::endl;

	std::cout << "Min = " << minNum << std::endl;
	std::cout << "Max = " << maxNum << std::endl;

	return 0;
}

