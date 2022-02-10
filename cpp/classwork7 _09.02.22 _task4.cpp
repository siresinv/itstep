// STEP _CPP _classwork7 _09.02.22 _task4


#include <iostream>

/*
Написать программу, которая показывает все числа,
которым кратно число, введённое с клавиатуры
*/

int main()
{
	setlocale(0, "");
	int num;

	std::cout << "Введите число: ";
	std::cin >> num;

	std::cout << num << " кратно числам ";
	for (int i = 1; i <= num/2; i++)
	{
		
		if (num % i == 0) {
			std::cout << i << " ";
		}
	}
	std::cout << num;

	return 0;

}