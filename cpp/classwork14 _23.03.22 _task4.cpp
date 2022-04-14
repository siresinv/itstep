// STEP _CPP _classwork14 _23.03.22 _task4
/*
	Написать функцию, определяющую минимум и максимум
(значение и номер) элементов передаваемого ей массива
*/



#include <iostream>
#include <stdlib.h>
#include <math.h>



int getMin(int arrNum[], int arrSize);
int getMax(int arrNum[], int arrSize);



int main() {
	const int N_ARR = 10;
	srand(time(NULL));
	
	int arrNum[N_ARR];

	for (int i = 0; i < N_ARR; i++) {
		arrNum[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < 10; i++) {
		std::cout << arrNum[i] << " ";
	}
	std::cout << std::endl;
	std::cout << getMin(arrNum, N_ARR);
	std::cout << std::endl;
	std::cout << getMax(arrNum, N_ARR);
	return 0;
}


int getMin(int arrNum[], int arrSize) {
	int minNum = arrNum[0];

	for (int i = 0; i < arrSize; i++) {
		if (arrNum[i] < minNum) {
			minNum = arrNum[i];
		}
	}

	return minNum;
}

int getMax(int arrNum[], int arrSize) {
	int maxNum = arrNum[0];

	for (int i = 0; i < arrSize; i++) {
		if (arrNum[i] > maxNum) {
			maxNum = arrNum[i];
		}
	}

	return maxNum;
}