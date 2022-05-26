// STEP _CPP _classwork20 _20.04.22 _task1
/*

Динамическая память


ССЫЛКИ

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


void initArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		*(arr + i) = rand() % 10;
	}
}


void showArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << *arr++ << " ";
	}
}





int main() {
	setlocale(0, "");
	srand(time(NULL));

	/*
	int a = 5;
	int* p = new int(7);
	//*p = 50;

	std::cout << *p;
	std::cout << std::endl;

	//int* p2 = p;
	int* p2 = &a;

	 //ВСЕГДА ВМЕСТЕ(Т.Е. ПОСЛЕ) С NEW ПИСАТЬ
	delete p;
	p = p2; // связь с 7 теряется
	//delete p; // а тут уже ошибка !!!

	std::cout << a;

	*/

	/*
	int n;
	std::cin >> n;

	int* arr = new int[10];
	initArr(arr, n);
	showArr(arr, n);

	delete[] arr;
	*/


	return 0;
}