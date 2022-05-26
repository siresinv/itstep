// STEP _CPP _classwork19 _15.04.22 _task1
/*

конст указатели


ССЫЛКИ

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>







/*
int main() {
	int a = 5;
	int* const pa = &a;

	std::cout << *pa << std::endl;
	*pa = 25;

	int b = 10;
	//pa = &b; - нельзя т.к. pa-константный указатель

	//указатель на константу
	//тут наоборот - нельзя менять переменную, но можно перемещаться
	const int* p2;
	p2 = &a;
	p2 = &b;
	b = 50;
	
	std::cout << *p2 << std::endl;
	const int c = 2;
	p2 = &c;
	//*p = 50; - Нельзя изменить

	//совокупность двух первых - только для вывода
	const int* const p3 = &a;


	//ссылки

	
	int* p = &x; //указателю присвоен алрес x

	int& refX = x; //ссылка ассоциирована с x.
	int* p1 = &refX;

	std::cout << x << *p << refX << *p1;
	refX = b; // x- будет равно b
	refX++; // = 51
	refX = 555; //x = 555;
	//ссылка не может как указатель указывать на пустоту
	//нет арифметики со ссылками

	
}
*/










void swapAB(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int& refArr(int arr[][2], int id) {
	return arr[id][0];
}





int& getMax(int arr2[], int sizeArr) {
	int& max = arr2[0];
	int id = 0;
	for (int i = 0; i < sizeArr; i++) {
		if (*(arr2+i) > max) {
			id = i;
		}
	}
	return arr2[id];
}

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ДОДЕЛАТЬ С РЕКУРСИЕЙ
int& getMax2(int arr2[], int sizeArr, int max, int maxId) {
	if (sizeArr > 0 ) {
		if (*(arr2 + i) > max) {
			maxId = i;
		}
		sizeArr--;
		getMax2(arr2, sizeArr, max, maxId);
	}
	else {
		return arr2[maxId];
	}
}
*/


// ПОПРОБОВАТЬ ВОЗВРАЩАТЬ НОВЫЙ МАССИВ - НО ЭТО ЛУЧШЕ С ДИНАМИЧЕСКОЙ ПАМЯТЬЮ, а то только можно вернуть ссылку на первый элемент, а дальше - проблема типа
// Хотя бы эту и функцию ниже СДЕЛАТЬ ЕЩЁ И ССЫЛКАМИ
void join2Arr(int* arr1, int* arr2, int* arr3, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		*(arr3 + i) = *(arr1 + i);
		*(arr3 + (sizeArr) + i) = *(arr2 + i);
	}
}


void bubleSort(int *arr, int sizeArr) {
	int temp;
	for (int i = 0; i < sizeArr; i++) {
		for (int j = i+1; j < sizeArr; j++) {
			if (*(arr + i) > *(arr + j)) {
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}




void join2Arr_REF(int (&arr1)[], int& arr2, int& arr3, int sizeArr) {

	//arr1[&arr1] = 23;
	//std::cout << arr1[&arr1-1];
	//arr1 = arr2;

	for (int i = 0; i < sizeArr; i++) {
		//(arr3 + i) = (arr1 + i);
		//(arr3 + (sizeArr)+i) = (arr2 + i);
	}
}


void bubleSort_REF(int* arr, int sizeArr) {
	int temp;
	for (int i = 0; i < sizeArr; i++) {
		for (int j = i + 1; j < sizeArr; j++) {
			if (*(arr + i) > *(arr + j)) {
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}





int main() {

	setlocale(0, "");

	const int SIZE_ARR = 5;
	const int SIZE_ARR_GENERAL = SIZE_ARR * 2;

	/*int x = 5;
	int y = 10;
	int arr[5][2];*/
	int arr2[SIZE_ARR] = { 167, 2, 3, 4, 5 };
	int arr3[SIZE_ARR] = { 1, 2, 3, 4, 5 };
	int arr4[SIZE_ARR_GENERAL] = {};

	//swapAB(x, y);
	////std::cout << x << " " << y;


	//for (int i = 0; i < 5; i++) {
	//	std::cin >> arr[i][0];
	//	refArr(arr, i) = 5;
	//}


	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		//std::cout << arr[i][j] << " ";
	//		std::cout << refArr(arr, i) << " ";
	//	}
	//	std::cout << std::endl;
	//}



	//getMax(arr2, 3) = 10; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//std::cout << getMax(arr2, 3); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	
	//int max = arr2[0];
	//getMax2(arr2, 3, max, 0) = 20; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//std::cout << getMax2(arr2, 3, max, 0); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	//join2Arr(arr2, arr3, arr4, SIZE_ARR);
	//std::cout << " --- " << *arr2+32;
	//std::cout << arr2[&arr2 - 1];
	join2Arr_REF(arr2, *arr3, *arr4, SIZE_ARR);
	std::cout << "Собрали два массива в один" << std::endl;
	for (int i = 0; i < SIZE_ARR_GENERAL; i++) {
		std::cout << arr4[i];
	}
	std::cout << std::endl;

	//bubleSort(arr4, SIZE_ARR_GENERAL);
	//bubleSort_REF(arr4, SIZE_ARR_GENERAL);
	std::cout << "Отсортировали пузырьком" << std::endl;
	for (int i = 0; i < SIZE_ARR_GENERAL; i++) {
		std::cout << arr4[i];
	}
}