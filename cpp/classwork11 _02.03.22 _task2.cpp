// STEP _CPP _classwork11 _02.03.22 _task2
/*
в картинке
*/

#include <iostream>



const int N_SIDE = 5;
int arrSideLength[N_SIDE];
int sumSideLength;

int main() {
	setlocale(0, "");

	sumSideLength = 0;

	for (int i = 0; i < N_SIDE; i++) {
		std::cin >> arrSideLength[i];
	}

	for (int i = 0; i < N_SIDE; i++) {
		sumSideLength += arrSideLength[i];
	}

	std::cout << sumSideLength;
	
	return 0;
}

