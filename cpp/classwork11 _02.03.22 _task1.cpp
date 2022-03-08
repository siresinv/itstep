// STEP _CPP _classwork11 _02.03.22 _task1
/*
в картинке
*/

#include <iostream>



const int ARR_SIZE = 10;
int arrNum[ARR_SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
int num;

int main() {
	setlocale(0, "");




	for (int i = 0; i < ARR_SIZE / 2; i++) {
		num = arrNum[i];
		arrNum[i] = arrNum[ARR_SIZE - i - 1];
		arrNum[ARR_SIZE - i - 1] = num;
	}

	for (int i = 0; i < ARR_SIZE; i++) {
		std::cout << arrNum[i] << " ";
	}
	
	return 0;
}

