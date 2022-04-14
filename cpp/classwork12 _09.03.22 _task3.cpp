// STEP _CPP _classwork12 _09.03.22 _task3
/*
Задание 3. Напишите программу, в которой объявляется
массив размером 5×10 и массив размером 5×5. Первый
массив заполняется случайными числами, в диапазоне
от 0 до 50. Второй массив заполняется по следующему
принципу: первый элемент второго массива равен сумме
первого и второго элемента первого массива, второй элемент второго массива равен сумму третьего и четвертого
элемента первого массива.
*/
//////// arr1Num[i][j] = i+j; - СДЕЛАТЬ поппробовать - заполнть от 1 до 50

#include <iostream>
#include <math.h>
#include <stdlib.h>

const int ARR1_ROW = 5;
const int ARR1_COL = 10;
const int ARR2_ROW = 5;
const int ARR2_COL = 5;
int arr1Num[ARR1_ROW][ARR1_COL];
int arr2Num[ARR2_ROW][ARR2_COL];
int sumPair;
int countPair;

int main() {

	setlocale(0, "");
	srand(time(NULL));

	for (int i = 0; i < ARR1_ROW; i++) {
		for (int j = 0; j < ARR1_COL; j++) {
			arr1Num[i][j] = rand() % 50 + 1;
			
		}
	}

	
	for (int i = 0; i < ARR1_ROW; i++) {
		for (int j = 0; j < ARR1_COL; j++) {
			
			std::cout << arr1Num[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	sumPair = 0;
	for (int i = 0; i < ARR1_ROW; i++) {
		for (int j = 0; j < ARR1_COL; j++) {
			sumPair += arr1Num[i][j];
			countPair++;

			if (countPair == 2) {
			
				arr2Num[i][j / 2] = sumPair;
				countPair = 0;
				sumPair = 0;
			}
			

		}
	}


	for (int i = 0; i < ARR2_ROW; i++) {
		for (int j = 0; j < ARR2_COL; j++) {

			std::cout << arr2Num[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	return 0;
}

