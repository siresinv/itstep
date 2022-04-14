// STEP _CPP _classwork14 _23.03.22 _task5
/*
	в картинке
*/



#include <iostream>
#include <stdlib.h>
#include <math.h>



int getNumCube(int Num);
int getNumMax(int Num1, int Num2);
bool isPositiveNum(int Num);



int main() {
	setlocale(0,"");

	int n1 = 4;
	int n2 = 2;
	int n3 = 4;
	int n4 = -5;

	std::cout << "Куб числа " << n1 <<" = " << getNumCube(4);
	std::cout << std::endl;
	std::cout << "Наибольшее из двух чисел " << n2 << " и " << n3 << " - это " << getNumMax(2, 4);
	std::cout << std::endl;
	std::cout << "Число " << n4 << " - " << ((isPositiveNum(n4) == true) ? "положительное либо = 0": "отрицательное");
	std::cout << std::endl;

	return 0;
}


int getNumCube(int Num) {
	return Num * Num * Num;
}

int getNumMax(int Num1, int Num2) {
	return (Num1 > Num2) ? Num1 : Num2;
}

bool isPositiveNum(int Num) {
	return Num > 0;
}
