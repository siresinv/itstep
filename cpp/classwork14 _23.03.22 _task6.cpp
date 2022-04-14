// STEP _CPP _classwork14 _23.03.22 _task6
/*
7. Написать функцию, меняющую порядок следования
элементов передаваемого ей массива на противоположный.
*/



#include <iostream>
#include <stdlib.h>
#include <math.h>




void reversArr(int arrNum[], int arrSize);


int main() {
	setlocale(0,"");
	srand(time(NULL));

	const int N_ARR = 10;
	int arrNum[N_ARR];

	for (int i = 0; i < N_ARR; i++) {
		arrNum[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < N_ARR; i++) {
		std::cout << arrNum[i] << " ";
	}

	reversArr (arrNum, N_ARR);

	std::cout << std::endl;
	for (int i = 0; i < N_ARR; i++) {
		std::cout << arrNum[i] << " ";
	}

	return 0;
}


void reversArr(int arrNum[], int arrSize) {
	int temp;

	for (int i = 0; i < arrSize / 2; i++) {
		temp = arrNum[i];
		arrNum[i] = arrNum[arrSize - 1 - i];
		arrNum[arrSize - 1 - i] = temp;
	}

}