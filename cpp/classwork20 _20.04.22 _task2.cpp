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



int* join2Arr(int* arr1, int* arr2, int sizeArr1, int sizeArr2) {

	int i;
	int* arr3 = new int[sizeArr1 + sizeArr2];
	//initArr(arr3, sizeArr1 + sizeArr2);
	for (i = 0; i < sizeArr1; i++) {
		*(arr3+i) = *(arr1+i);
	}

	for (int j = 0; j < sizeArr2; j++) {
		*(arr3+i + j) = *(arr2+j);
	}

	return arr3;
}


///////////////////
int joinSameElem2Arr(int* arr1, int* arr2, int sizeArr1, int sizeArr2) {

	//int i;
	int nSameElem = 0;
	//int sameElem;
	bool isSameElem;

	int* arr3 = new int[sizeArr1 + sizeArr2];
	
	for (int i = 0; i < sizeArr1; i++) {
		isSameElem = false;
		for (int j = 0; j < sizeArr2; j++) {
			if (*(arr1 + j) == *(arr2 + i) && isSameElem == false) {
				nSameElem++;
				isSameElem = true;
			}
		}
	}

	//int* arr3 = new int[nSameElem];
	


	//return arr3;
	return nSameElem;
}




int* deleteEvenOddElemArr(int* arr, int sizeArr, bool delNumberType) {
	// УДАЛЯТЬ: true - четные false - нечетные
	int sizeNewArr;
	int nEvenElement;

	// количество элементов нового массива - передать по ссылке & --- ???
	// или это во второй задаче
	
	nEvenElement = 0;
	for (int i = 0; i < sizeArr; i++) {
		if (*(arr + 1) / 2 == 0) {
			nEvenElement++;
		}
	}

	if (delNumberType == true) {
		sizeNewArr = sizeArr - nEvenElement;
	}
	else {
		sizeNewArr = nEvenElement;
	}

	//int* arr2 = new int [(delNumberType)? sizeArr - nEvenElement : nEvenElement]
	int* arr2 = new int[sizeNewArr];

	for (int i = 0; i < sizeNewArr; i++) {
		*(arr2 + i) = *(arr + 2 * i);
	}


	for (int i = 0; i < sizeNewArr; i++) {
		std::cout << arr2[i] << " ";
	}


	return arr2;

}


int main() {
	setlocale(0, "");
	srand(time(NULL));

	

	int sizeArr1;
	std::cout << "Размер первого массива: ";
	std::cin >> sizeArr1;;

	int sizeArr2;
	std::cout << "Размер второго массива: ";
	std::cin >> sizeArr2;

	int* arr1 = new int[sizeArr1];
	initArr(arr1, sizeArr1);

	int* arr2 = new int[sizeArr2];
	initArr(arr2, sizeArr2);

	showArr(arr1, sizeArr1);
	std::cout << std::endl;
	showArr(arr2, sizeArr2);
	std::cout << std::endl;

	//int* arr3 = join2Arr(arr1, arr2, sizeArr1, sizeArr2);
	//showArr(arr3, sizeArr1 + sizeArr2);
	//std::cout << std::endl;
	

	//int* arr3 = joinSameElem2Arr(arr1, arr2, sizeArr1, sizeArr2);
	//std::cout << joinSameElem2Arr(arr1, arr2, sizeArr1, sizeArr2);
	//showArr(arr3, sizeArr1 + sizeArr2);
	//std::cout << std::endl;

	int* arr3 = deleteEvenOddElemArr(arr2, sizeArr2, false);
	showArr(arr3, 3); // а сколько элементов на печать то выводить ???
	std::cout << std::endl;





	//ПАМЯТЬ ВЕЗДЕ ПОДЧИСТИТЬ

	return 0;
}