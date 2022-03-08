// STEP _CPP _homework10 _18.02.22 _task1
/*
ЗАДАНИЕ 1
Написать программу, копирующую последовательно элементы
одного массива размером 10 элементов в 2 массива размером
5 элементов каждый. Элементы первоначального массива можно
сгенерировать в произвольном диапазоне.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(0, "");
	srand(time(NULL));

	const int N_NUMBERS = 10;

	int arrNum[N_NUMBERS];
	int arrNumA[N_NUMBERS / 2];
	int arrNumB[N_NUMBERS / 2];

	for (int i = 0; i < N_NUMBERS; i++) {
		arrNum[i] = rand() % 10 + 1;
	}


	for (int i = 0; i < N_NUMBERS; i++) {
		if (i < N_NUMBERS / 2) {
			arrNumA[i] = arrNum[i];
		}
		else {
			arrNumB[i - N_NUMBERS/2] = arrNum[i];
		}
	}


	std::cout << std::endl;
	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrNum[i] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < N_NUMBERS / 2; i++) {
		std::cout << arrNumA[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < N_NUMBERS / 2; i++) {
		std::cout << arrNumB[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}

