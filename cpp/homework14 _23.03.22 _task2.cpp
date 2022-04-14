// STEP _CPP _homework14 _23.03.22 _task2
/*
	в картинке
*/



#include <iostream>
#include <stdlib.h>
#include <math.h>





float getAvg(int arrNum[], int sizeArr);

int main() {
	setlocale(0,"");
	srand(time(NULL));

	const int N_NUM = 10;
	int arrNum[N_NUM];

	for (int i = 0; i < N_NUM; i++) {
		arrNum[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < N_NUM; i++) {
		std::cout << arrNum[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Среднее арифметическое чисел массива = " << getAvg(arrNum, N_NUM);


	return 0;
}


float getAvg(int arrNum[], int sizeArr) {
	float avg;
	int sum;
	sum = 0;
	for (int i = 0; i < sizeArr; i++) {
		sum += arrNum[i];
	}

	avg = sum / float(sizeArr);
	return avg;
}

