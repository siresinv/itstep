// STEP _CPP _homework9 _16.02.22 _task1
/*
ЗАДАНИЕ 1
В одномерном массиве, заполненном случайными числами,
определить минимальный и максимальный элементы.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");
	srand(time(NULL));

	const int N_NUMBERS = 20;

	int arrNumbers[N_NUMBERS];
	int minElementId;
	int maxElementId;

	for (int i = 0; i < N_NUMBERS; i++) {
		arrNumbers[i] = rand() % 100 + 1;
	}

	minElementId = 0;
	maxElementId = 0;
	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrNumbers[i] << " ";
		std::cout << std::endl;

		minElementId = (arrNumbers[minElementId] > arrNumbers[i]) ? i : minElementId;
		maxElementId = (arrNumbers[maxElementId] < arrNumbers[i]) ? i : maxElementId;
	}

	std::cout << std::endl;
	std::cout << "Минимальный элемент: " << arrNumbers[minElementId] << "\nМаксимальный элемент: " << arrNumbers[maxElementId];

	std::cout << std::endl;
	std::cout << std::endl;


	return 0;
}

