// STEP _CPP _classwork13 _16.03.22 _task1
/*
ФУУУНКЦИИ. НАЧАЛО
*/


#include <iostream>
#include <stdlib.h>
#include <math.h>



void hello() {
	std::cout << "Hello, World! Привет, мир!" << std::endl;
}

void stars(char symb, int nSymb) {
	for (int i = 0; i < nSymb; i++) {
		std::cout << symb;
	}
}

int calcSum(int a, int b) {
	return a + b;
}

int maxNum(int a, int b) {
	return (a > b) ? a : b;
}

void first() {
	std::cout << "first\n";
}

void second() {
	std::cout << "strat second\n";
	first();
	std::cout << "end second\n";
}

void third() {
	std::cout << "strat third\n";
	second();
	std::cout << "end third\n";
}

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << a << " " << b;
}




void arrInput(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

void arrOutput(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

void arrIO(int arr[], int size) {
	arrInput(arr, size);
	arrOutput(arr, size);
}

int main() {
	setlocale(0, "");
	srand(time(NULL));

	/*for (int i = 0; i < 5; i++) {
		hello();
	}*/

	/*int a;
	std::cin >> a;*/


	//stars('-', 15);

	//std::cout << calcSum(12, 22);

	//std::cout << maxNum(12, 22);

	//third();

	/*int a = 5;
	int b = 10;
	swap(a, b);
	std::cout << std::endl;
	std::cout << a << " " << b;*/

	
	const int arrSize = 5;
	int arr[arrSize];
	/*arrInput(arr, arrSize);
	arrOutput(arr, arrSize);*/
	arrIO(arr, arrSize);
}
