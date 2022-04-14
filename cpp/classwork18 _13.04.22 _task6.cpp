// STEP _CPP _classwork18 _13.04.22 _task6
/*

УКАЗАТЕЛИ


1. Дан массив целых чисел. Воспользовавшись указателями, поменяйте местами элементы массива с четными
и нечетными индексами (т.е. те элементы массива, которые стоят на четных местах, поменяйте с элементами,
которые стоят на нечетных местах).

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>






void swapEvenOdd (int *arr, int sizeArr) {
	for (int i = 0; i < sizeArr - 1; i += 2) {
		int temp = *(arr + i);
		*(arr + i) = *(arr + i + 1);
		*(arr + i + 1) = temp;
	}
}

int main() {
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	swapEvenOdd (arr, 6);

	for (int i = 0; i < 6; i++) {
		std::cout << arr[i] << " ";
	}
}