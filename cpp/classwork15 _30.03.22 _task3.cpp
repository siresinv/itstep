// STEP _CPP _classwork15 _30.03.22 _task3
/*
Написать шаблонные функции и протестировать их в основной программе:

■ Нахождения максимального значения в одномерноммассиве;

■ Нахождения максимального значения в двумерноммассиве;

■ Нахождения максимального значения в трёхмерноммассиве.
*/


#include <iostream>

template <typename T, typename T2>
T2 sumT(T a, T2 b) {
	return a + b;
}

int sum(int a, int b) {
	return a + b;
}

double sum(int a, double b, int c) {
	return a + b + c;
}



template <typename A>
A getMax(A arr[], int arrSize) {
	A max;
	max = arr[0];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > max) max = arr[i];
	}

	return max;
}

template <typename B>
B getMax(B arr[][5], int arrRows, int arrCols) {
	B max;
	max = arr[0][0];
	for (int i = 0; i < arrRows; i++) {
		for (int j = 0; j < arrCols; j++) {
			if (arr[i][j] > max) max = arr[i][j];
		}
		
	}

	return max;
}

template <typename C>
C getMax(C arr[][5][5], int arrRows, int arrCols, int arrZ) {
	C max;
	max = arr[0][0][0];
	for (int i = 0; i < arrRows; i++) {
		for (int j = 0; j < arrCols; j++) {
			for (int k = 0; k < arrZ; k++) {
				if (arr[i][j][k] > max) max = arr[i][j][k];
			}
			
		}

	}

	return max;
}

int main() {
	setlocale(0, "");

	int arr1[5] = {1, 2, 3, 4, 5};
	int arr1_2[2][5] = { {1, 2, 3, 4, 5}, {6, 7, 8, 19, 5} };
	double arr2[5] = {1.1, 2.1, 3.1, 4.1, 5.1};
	double arr2_2[2][5] = { {1.1, 2.1, 3.1, 4, 5}, {6.1, 17.1, 8.1, 9, 5} };
	int arr1_3[3][5][5] = { {1, 2, 3, 4, 5}, {6, 7, 8, 19, 5}, {16, 57, 8, 29, 15} };
	double arr2_3[3][5][5] = { {1.1, 2.1, 3.1, 4, 5}, {6.1, 17.1, 8.1, 9, 5}, {6.1, 47.1, 8.1, 29, 5} };
	

	//std::cout << sum(5, 5) << " " << sum(2, 2.2, 3) << std::endl;
	//std::cout << sumT(5, 5.5);

	std::cout << getMax(arr1, 5) << std::endl;
	std::cout << getMax(arr2, 5) << std::endl;
	std::cout << getMax(arr1_2, 2, 5) << std::endl;
	std::cout << getMax(arr2_2, 2, 5) << std::endl;
	std::cout << getMax(arr1_3, 3, 5, 5) << std::endl;
	std::cout << getMax(arr2_3, 3, 5, 15) << std::endl;

	return 0;
}

