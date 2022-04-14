// STEP _CPP _classwork18 _13.04.22 _task1-5
/*

УКАЗАТЕЛИ
в картинке

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>



int getMax(int &a, int &b) {
	//std::cout << a << " " << b << " ";
	return (a > b) ? a : b;
}

int getMax2(int *a, int *b) {
	return (*a > *b) ? *a : *b;
}


bool getSign(int *a) {
	return *a >= 0;
}


void swapVar(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void showArr(int *arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		//std::cout << *arr++ << " ";
		std::cout << *(arr + i) << " ";
	}
}


int sumNumArr (int *arr, int sizeArr) {
	int sum = 0;
	for (int i = 0; i < sizeArr; i++) {
		sum += *(arr + i);
	}
	return sum;
}


int getResult(int* a, int* b, char *op) {
	switch (*op) {
	case '+':
		return *a + *b;
	case '-':
		return *a - *b;
	case '*':
		return *a * *b;
	case '/':
		return *a / *b;
	default:
		break;
	}
}

int main() {

	int a = 5;
	int b = 10;
	char op = '*';
	//int arr[5] = {1, 2, 3, 4, 5};
	//int c = -5;
	//int *pa = &a;
	//int *pb = &b;
	//int *pc = &c;

	//std::cout << getMax(*pa, *pb);
	//std::cout << std::endl;
	//std::cout << getMax2(pa, pb);
	//std::cout << std::endl;
	//std::cout << ((getSign(&c)) ? "+" : "-");
	//std::cout << std::endl;
	//swapVar(&a, &b);
	//std::cout << a << " " << b;

	//std::cout << sumNumArr(arr, 5);

	std::cout << getResult(&a, &b, &op);

}


	
