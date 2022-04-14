// STEP _CPP _homework13 _16.03.22 _task1,2,3,5
/*
в картинке
*/

#include <iostream>


int exponentiation(int base, int exp);
int summDiapason(int num1, int num2);
void outputPerfNums(int num1, int num2);
bool isLuckyNumber(int num);


int main() {

	setlocale(0, "");

	std::cout << "3 в степени 3 = ";
	std::cout << exponentiation(3, 3);
	std::cout << std::endl;

	std::cout << "Сумма чисел в диапазоне от 5 до 10 включительно = ";
	std::cout << summDiapason(5, 10);
	std::cout << std::endl;

	std::cout << "Совершенные числа в диапазоне от 1 до 10000: ";
	outputPerfNums(1, 10000);
	std::cout << std::endl;

	std::cout << "Число 487991 счастливое?: ";
	//std::cout << isLuckyNumber(487990);
	std::cout << ((isLuckyNumber(487991)) ? "да" : "нет");
	std::cout << std::endl;

	return 0;
}


int exponentiation(int base, int exp) {
	int result;
	result = 1;
	for (int i = 0; i < exp; i++) {
		result *= base;
	}
	return result;
}

int summDiapason(int num1, int num2) {
	int sum;
	sum = 0;
	for (int i = num1; i <= num2; i++) {
		sum += i;
	}
	return sum;
}

void outputPerfNums(int num1, int num2) {
	int sumDividers;
	for (int i = num1; i < num2; i++) {
		sumDividers = 0;
		for (int j = 1; j <= i/2; j++) {
			if (i%j == 0) {
				sumDividers += j;
			}
		}
		if (sumDividers == i) {
			std::cout << i << " ";
		}
	}
}


bool isLuckyNumber(int num) {
	const int N_NUMBERS = 6;
	int numLSum;
	int numRSum;
	int arrDigits[N_NUMBERS];
	for (int i = 0; i < N_NUMBERS; i++) {
		arrDigits[N_NUMBERS - 1 - i] = num%10;
		num = num / 10;
	}

	numLSum = 1;
	numRSum = 1;
	for (int i = 0; i < N_NUMBERS / 2; i++) {
		numLSum += arrDigits[i];
		numRSum += arrDigits[N_NUMBERS / 2 + i];
	}

	if (numLSum == numRSum) {
		return true;
	}
	else {
		return false;
	}
	

}