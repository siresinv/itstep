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

	const int num_end = 20;
	//const double big_int_number = 1000000;
	int num_begin;
	bool operation_ok;
	double result;
	//double result_part1, result_part2;
	int count;
	
	


	cout << "Найти произведение всех целых чисел от a до 20" << endl;

	cout << "Введите значение a - от 1 до 20: ";
	cin >> num_begin;

	operation_ok = (num_begin >= 1 && num_begin <= 20) ? true : false;

	if (operation_ok)
	{
		count = num_begin;
		result = 1;
		while (count <= num_end)
		{
			result *= count;
			count++;
		}
	}


	cout << "-------------------------------------" << endl;
	
	if (!operation_ok)
	{
		cout << "Операция не выпонена!";
	}
	else
	{
		cout << "Произведение всех целых чисел от " << num_begin << " до " << num_end << " равно " << result;
	}

	cout << endl;
}
