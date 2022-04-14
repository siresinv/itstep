// STEP _CPP _classwork13 _16.03.22 _task4
/*
Написать функцию, которая проверяет, является ли переданное ей число простым? Число называется простым,
если оно делится без остатка только на себя и на единицу.
*/


#include <iostream>



bool isPrimeNum(int num);
bool isPrimeNum2(int num);
bool prime_pyataevma(int n);

int main() {
	std::cout << isPrimeNum2(2300);
}



bool isPrimeNum(int num) {
	int isPrime = true;

	for (size_t i = 2; i < num/2; i++) {
		if (num%i == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

bool isPrimeNum2(int num) {
	for (size_t i = 2; i < num / 2; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

bool prime_pyataevma(int n)
{
	for (int i = 2; i <= int(sqrt(n)) + 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}