// STEP _CPP _classwork17 _08.04.22 _task3
/*

УКАЗАТЕЛИ

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


void showArr(int *arr, int sizeArr) {
	//WTF
	for (int i = 0; i < sizeArr; i++) {
		std::cout << "arr[" << i << "]=" << arr[i] << " ";
 		std::cout << *arr++ << "* ";
	}
}


void swap_my (int &a, int &b) {
	int temp = a;
	std::cout << temp << "---";
	a = b;
	b = temp;
}

int main() {

	int x = 5, y = 10;
	int* p1, * p2;
	std::cout << x << " " << &x << std::endl;
	p1 = &x;
	std::cout << *p1 << " " << p1 << std::endl;
	x = 15;
	std::cout << x << " " << &x << std::endl;
	std::cout << *p1 << " " << p1 << std::endl;
	*p1 = 50;
	std::cout << x << " " << &x << std::endl;
	std::cout << *p1 << " " << p1 << std::endl;


	p2 = &y;
	std::cout << *p2 << " " << p2 << std::endl;

	p1 = p2; //// p1 ссылается на p2 и соответственно уже на y
	std::cout << std::endl;

	int arr[5] = {10, 30, 50, 70, 90};
	int* pArr;
	int* pArr2;

	pArr = &arr[0];
	pArr2 = &arr[4];
	std::cout << *pArr << std::endl;
	std::cout << *(pArr + 1) << std::endl;
	//std::cout << *(++pArr) << std::endl;
	std::cout << *pArr + 1 << std::endl;

	//std::cout << 


	for (int i = 0; i < 5; i++) {
		std::cout << *pArr++ << " ";
	}
	std::cout << std::endl;
		
	pArr = &arr[0];
	for (int i = 0; i < 5; i++) {
		std::cout << *(pArr + i) << " ";
	}
	std::cout << std::endl;



	for (int i = 0; i < 5; i++) {
		std::cout << pArr[i] << " ";
	}
	std::cout << std::endl;

	pArr = &arr[0];
	for (int i = 0; i < 5; i++) {
		std::cout << *(pArr + i) << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	showArr(arr, 5);
	std::cout << std::endl;
	std::cout << std::endl;
	int a = 5;
	int b = 10;
	swap_my (a, b);

	std::cout << a << " " << b;

	int* p = nullptr; //когда пока ничего не присвоено
	if (p) { // (p != nullptr)
		std::cout << *p;
	}


}


	
