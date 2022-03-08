// STEP _CPP _homework9 _16.02.22 _task4
/*
ЗАДАНИЕ 4
В одномерном массиве, состоящем из N вещественных
чисел вычислить:
■ Сумму отрицательных элементов.
■ Произведение элементов, находящихся между min и max
элементами.
■ Произведение элементов с четными номерами.
■ Сумму элементов, находящихся между первым и последним отрицательными элементами.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");
	srand(time(NULL));

	const int ARR_SIZE = 20;

	int arrNumbers[ARR_SIZE];
	int sumNegative;
	int multBetweenMinMax;
	int multNumberIdEven;
	int sumBetweenFirstLastNegative;

	int minNumberId;
	int maxNumberId;
	int firstNegativeId;
	int lastNegativeId;
	int rangeBeginId;
	int rangeEndId;

	bool findFistNegative;
	bool findLastNegative;


	for (int i = 0; i < ARR_SIZE; i++) {
		arrNumbers[i] = rand() % 21 - 10;
	}


	minNumberId = 0;
	maxNumberId = 0;
	firstNegativeId = 0;
	lastNegativeId = 0;
	sumNegative = 0;
	multNumberIdEven = 1;
	findFistNegative = false;
	findLastNegative = false;

	for (int i = 0; i < ARR_SIZE; i++) {
		std::cout << arrNumbers[i] << std::endl;

		if (arrNumbers[minNumberId] > arrNumbers[i]) { minNumberId = i; }
		if (arrNumbers[maxNumberId] < arrNumbers[i]) { maxNumberId = i; }

		if (findFistNegative == false) {
			if (arrNumbers[i] < 0) {
				firstNegativeId = i;
				findFistNegative = true;
			}
		}

		if (findLastNegative == false) {
			if (arrNumbers[ARR_SIZE - 1 - i] < 0) {
				lastNegativeId = ARR_SIZE - 1 - i;
				findLastNegative = true;
			}
		}
				
		if (arrNumbers[i] < 0) { sumNegative += arrNumbers[i]; }
		if ((i+1) % 2 == 0) { multNumberIdEven *= arrNumbers[i]; }

		
	}
	std::cout << std::endl;
	std::cout << "Сумма отрицательных элементов: " << sumNegative << std::endl;
	std::cout << "Произведение элементов с четными номерами: " << multNumberIdEven << std::endl;


	

	if (minNumberId < maxNumberId) {
		rangeBeginId = minNumberId;
		rangeEndId = maxNumberId;
	}
	else {
		rangeBeginId = maxNumberId;
		rangeEndId = minNumberId;
	}
	multBetweenMinMax = 1;
	sumBetweenFirstLastNegative = 0;
	for (int i = 0; i < ARR_SIZE; i++) {

		if ((i >= rangeBeginId) && (i <= rangeEndId)) {
			multBetweenMinMax *= arrNumbers[i];
		}

		if ((i >= firstNegativeId) && (i <= lastNegativeId)) {
			sumBetweenFirstLastNegative += arrNumbers[i];
		}

	}
	std::cout << "Произведение между первым минимальным и первым максимальным элементами " << arrNumbers[minNumberId] << " и " << arrNumbers[maxNumberId] << " включительно - равно " << multBetweenMinMax << std::endl;
	std::cout << "Сумма между первым и последним отрицательными элементами " << arrNumbers[firstNegativeId] << " и " << arrNumbers[lastNegativeId] << " включительно - равна " << sumBetweenFirstLastNegative << std::endl;

	return 0;
}

