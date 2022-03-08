// STEP _CPP _homework10 _18.02.22 _task2
/*
ЗАДАНИЕ 2
Напишите программу, которая выполняет поэлементную
сумму двух массивов и результат заносит в третий массив.
Элементы массивов можно сгенерировать в произвольном
диапазоне.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(0, "");
	srand(time(NULL));

	const int N_NUMBERS = 10;

	int arrNumA[N_NUMBERS];
	int arrNumB[N_NUMBERS];
	int arrNumC[N_NUMBERS];

	for (int i = 0; i < N_NUMBERS; i++) {
		arrNumA[i] = rand() % 10 + 1;
		arrNumB[i] = rand() % 10 + 1;
		arrNumC[i] = arrNumA[i]+ arrNumB[i];
	}


	

	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrNumA[i] << " + " << arrNumB[i] << " = " << arrNumC[i];
		std::cout << std::endl;
	}

	return 0;
}

