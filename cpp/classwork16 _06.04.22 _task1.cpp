// STEP _CPP _classwork16 _06.04.22 _task1
/*
	СОРТИРОВКИ

1. Дан массив чисел размерностью 10 элементов. Написать
функцию, которая сортирует массив по возрастанию
или по убыванию, в зависимости от третьего параметра
функции. Если он равен 1, сортировка идет по убыванию, если 0, то по возрастанию. Первые 2 параметра
функции — это массив и его размер, третий параметр
по умолчанию равен 1.


*/


#include <iostream>
#include <stdlib.h>
#include <math.h>

template <class T>
void selectSort(T arr[], int sizeArr, bool directSort = true);

template <class T>
void showArr(T arr[], int sizeArr);





int main() {

	int arr[10] = { 4, 6, 3, 8, 1, 0, 2, 7, 9, 5 };
	showArr(arr, 10);
	std::cout << std::endl;
	selectSort(arr, 10, false);
	showArr(arr, 10);

	return 0;
}


template <class T>
void selectSort(T arr[], int sizeArr, bool directSort) { // true - убывание. false - возрастание
	int searchId;
	T temp;

	for (int i = 0; i < sizeArr; i++) {
		searchId = i;
		for (int j = i + 1; j < sizeArr; j++) {

				if ((directSort)? (arr[j] > arr[searchId]) : (arr[j] < arr[searchId])) {
					searchId = j;
				}
		}

		if (i != searchId) {
			temp = arr[i];
			arr[i] = arr[searchId];
			arr[searchId] = temp;
		}
	}
}


template <class T>
void showArr(T arr[], int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << arr[i] << " ";
	}
}

