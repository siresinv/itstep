// STEP _CPP _classwork7 _09.02.22 _task2


#include <iostream>

/*Пользователь с клавиатуры последовательно вводит
целые числа. Как только пользователь ввел 0, необходимо
показать на экран сумму всех введенных чисел.*/

int main()
{
	setlocale(0, "");
	int sum = 0;
	int num;

	for (;;) {
		std::cout << "Введите число (0 - выход): ";
		std::cin >> num;

		if (num == 0) {
			break;
		}

		sum += num;

		
	}

	std::cout << "Сумма равна: " <<sum;

}