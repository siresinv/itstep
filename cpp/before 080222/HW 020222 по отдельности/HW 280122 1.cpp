//HW от 020222

/*
Встреча №10
Тема: Циклы
Домашнее задание
Задание 1. Напишите программу, которая вычисляет сумму целых чисел от а до 500 (значение a
вводится с клавиатуры).
Задание 2. Напишите программу, которая запрашивает два целых числа x и y, после чего
вычисляет и выводит значение x в степени y.
Задание 3. Найти среднее арифметическое всех целых чисел от 1 до 1000.
Задание 4. Найти произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры:
1 <=a <= 20).
Задание 5. Написать программу, которая выводит на экран таблицу умножения на k, где k –
номер варианта. Например, для 7-го варианта:
7 x 2 = 14
7 x 3 = 21
*/

#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	setlocale(0, "");

	const int num_end = 500;

	int num_begin;
	int count;
	int sum_result;
	bool operation_ok;

	cout << "Программа вычисляет сумму целых чисел от а до " << num_end << endl;
	

	cout << "Введите значение a: ";
	cin >> num_begin;

	
	count = num_begin;
	sum_result = 0;
	operation_ok = true;

	if (num_begin > num_end)
	{
		cout << "a - не должно быть больше " << num_end << endl;
		operation_ok = false;
	}
	else
	{

		while (count <= num_end)
		{
			sum_result += count;
			count++;
		}
		
	}

	cout << "-------------------------------------" << endl;
	(operation_ok) ? cout << "Сумма целых чисел от " << num_begin << " до " << num_end << " равна " << sum_result : cout << "Операция не выполнена!";

	cout << endl;
}
