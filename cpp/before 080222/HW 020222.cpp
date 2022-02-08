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


/*void hw_020222_task1()
{
	/*Задание 1. Напишите программу, которая вычисляет сумму целых чисел от а до 500 (значение a
вводится с клавиатуры). !!!
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
*/



/*void hw_020222_task2()
{
	/*Задание 2. Напишите программу, которая запрашивает два целых числа x и y, после чего
вычисляет и выводит значение x в степени y. !!!

	int num;
	int degree;
	int result;
	int count;
	bool operation_ok;

	cout << "Программа вычисляет и выводит значение x в степени y (с помощью цикла)" << endl;

	cout << "Введите значение x: ";
	cin >> num;

	cout << "Введите НЕ отрицательное значение y: ";
	cin >> degree;
	cout << endl;

	result = num;
	operation_ok = true;
	
	//************************************************************
	//************************************************************
	//************************************************************
	if (degree < 0)
	{
		operation_ok = false;
	}
	else if (degree == 0)
	{
		result = 1;
	}
	else
	{
		count = degree;
		while (count > 1)
		{
			result *= num;
			count--;
		}
	}

	
	cout << "-------------------------------------" << endl;
	(operation_ok) ? cout << num << " в степени " << degree << " равно " << result : cout << "Операция не выполнена!";
	cout << endl;
}

*/




/*void hw_020222_task3()
{
	/*Задание 3. Найти среднее арифметическое всех целых чисел от 1 до 1000. !!!

	cout << "Найти среднее арифметическое всех целых чисел от 1 до 1000" << endl;
	
	const int num_begin = 1;
	const int num_end = 1000;
	int count;
	int sum_result;
	float average;


	count = num_begin;
	sum_result = 0;

	while (count <= num_end)
	{
		sum_result += count;
		count++;
	}

	average = sum_result / float(num_end);

	cout << "-------------------------------------" << endl;
	cout << "Среднее аифметическое от " << num_begin << " до " << num_end << " равно " << average << endl;
	cout << endl;
}

*/



void hw_020222_task4()
{
	/*Задание 4. Найти произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры:
1 <=a <= 20).*/
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




/*void hw_020222_task5()
{

	/*Задание 5. Написать программу, которая выводит на экран таблицу умножения на k, где k –
номер варианта. Например, для 7-го варианта:
7 x 2 = 14
7 x 3 = 21 !!!


	cout << "Ппрограмма выводит на экран таблицу умножения на k" << endl;
	int digit;
	int count;
	bool operation_ok;

	cout << "Введите значение k  - от 2 до 9: ";
	cin >> digit;
	


	operation_ok = (digit >= 2 && digit <= 9) ? true : false;


	
	cout << "-------------------------------------" << endl;



	if (!operation_ok)
	{
		cout << "Операция не выпонена!";
	}
	else
	{
		count = 2;
		while (count <= 10)
		{
			cout << digit << " x " << count << " = " << digit * count;
			cout << endl;
			count++;
			
		}
	}
	

	cout << endl;
}

*/



//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************






/*
void hw_020222_task6()
{
	

	const int any_leap_year = 2020; //Любой известный високосный год для дальнейшего сравнения
	const int jan = 31;
	const int mar = 31;
	const int apr = 30;
	const int may = 31;
	const int jun = 30;
	const int jul = 31;
	const int avg = 31;
	const int sep = 30;
	const int okt = 31;
	const int nov = 30;
	const int dec = 31;

	int feb;
	int date_day, date_month_number, date_year;
	int date1_day, date1_month_number, date1_year;
	int date2_day, date2_month_number, date2_year;

	bool date1_is_leap_year;
	bool date2_is_leap_year;


	cout << "Пользователь вводит две даты (день, месяц, год в виде целых чисел). Необходимо определить и вывести количество дней между этими двумя датами" << endl;
	cout << "Ведите две даты (в порядке возрастания)" << endl;

	cout << "Введите через пробел День Месяц Год первой даты : ";
	cin >> date1_day >> date1_month_number >> date1_year;

	cout << "Введите через пробел День Месяц Год второй даты : ";
	cin >> date2_day >> date2_month_number >> date2_year;



	//int count = 1;
	//do
	//{
	//	date_year = (count == 1) ? date1_year : date2_year;
	//	date1_is_leap_year = ((any_leap_year - date1_year) % 4 == 0) ? true : false;
	//} while (true);


	date1_is_leap_year = ((any_leap_year - date1_year) % 4 == 0) ? true : false;
	feb = (!date1_is_leap_year) ? 28 : 29;

	date2_is_leap_year = ((any_leap_year - date2_year) % 4 == 0) ? true : false;
	feb = (!date2_is_leap_year) ? 28 : 29;


	bool date_correct = true;

	//проверка корректности дат
	if (date1_month_number > 12 || date2_month_number > 12)
	{
		date_correct = false;
	}
	else
	{
		switch (date1_month_number)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date1_day > jan) { date_correct = false; } //т.е. если фактически >31
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date1_day > apr) { date_correct = false; } //т.е. если фактически >30
			break;
		case 2:
			if (date1_day > feb) { date_correct = false; }; //т.е. если фактически >28(29)
			break;
		default:
			break;
		}


		switch (date2_month_number)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date2_day > jan) { date_correct = false; } //т.е. если фактически >31
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date2_day > apr) { date_correct = false; } //т.е. если фактически >30
			break;
		case 2:
			if (date2_day > feb) { date_correct = false; }//т.е. если фактически >28(29)
			break;
		default:
			break;
		}
	}


	//проверка на неубывание второй даты
	if (date_correct)
	{
		if (date2_year < date1_year)
		{
			date_correct = false;
		}
		else if (date2_year == date1_year)
		{
			if (date2_month_number < date1_month_number)
			{
				date_correct = false;
			}
			else if (date2_month_number == date1_month_number)
			{
				if (date2_day < date1_day)
				{
					date_correct = false;
				}
			}
		}
	}


	cout << endl << "----------------------------------------------------" << endl;

	if (!date_correct)
	{
		cout << "Некорректный ввод дат!" << endl;
	}
	else
	{
		int date1_days_in_full_months = 0;
		date1_days_in_full_months += (date1_month_number > 1) ? jan : 0;
		date1_days_in_full_months += (date1_month_number > 2) ? feb : 0;
		date1_days_in_full_months += (date1_month_number > 3) ? mar : 0;
		date1_days_in_full_months += (date1_month_number > 4) ? apr : 0;
		date1_days_in_full_months += (date1_month_number > 5) ? may : 0;
		date1_days_in_full_months += (date1_month_number > 6) ? jun : 0;
		date1_days_in_full_months += (date1_month_number > 7) ? jul : 0;
		date1_days_in_full_months += (date1_month_number > 8) ? avg : 0;
		date1_days_in_full_months += (date1_month_number > 9) ? sep : 0;
		date1_days_in_full_months += (date1_month_number > 10) ? okt : 0;
		date1_days_in_full_months += (date1_month_number > 11) ? nov : 0;
		int date1_day_number = date1_days_in_full_months + date1_day; //Получили номер дня в году1

		int date2_days_in_full_months = 0;
		date2_days_in_full_months += (date2_month_number > 1) ? jan : 0;
		date2_days_in_full_months += (date2_month_number > 2) ? feb : 0;
		date2_days_in_full_months += (date2_month_number > 3) ? mar : 0;
		date2_days_in_full_months += (date2_month_number > 4) ? apr : 0;
		date2_days_in_full_months += (date2_month_number > 5) ? may : 0;
		date2_days_in_full_months += (date2_month_number > 6) ? jun : 0;
		date2_days_in_full_months += (date2_month_number > 7) ? jul : 0;
		date2_days_in_full_months += (date2_month_number > 8) ? avg : 0;
		date2_days_in_full_months += (date2_month_number > 9) ? sep : 0;
		date2_days_in_full_months += (date2_month_number > 10) ? okt : 0;
		date2_days_in_full_months += (date2_month_number > 11) ? nov : 0;
		int date2_day_number = date2_days_in_full_months + date2_day; //Получили номер дня в году2


		//ИГРЫ РАЗУМА !!! ))))) Находим количество високосных годов между двумя  датами
		int full_years_amount = date2_year - date1_year; //количество полных лет между двумя датами. первый год тоже сичтается за полный
		int leap_in_full_years_amount = full_years_amount / 4; //количство високосных годов между двумя датами


		//дальше самая жесть ))) - выявлена закономерность, при каких условиях добавляется високосный год
		if (date1_is_leap_year)
		{
			leap_in_full_years_amount += (full_years_amount % 4 > 1) ? 1 : 0;
		}
		else
		{
			int date1_nearest_leap_year = (date1_year / 4) * 4; //Находим ближайший к году1 високосный год и меньший года1
			int year_difference = date1_year - date1_nearest_leap_year;

			switch (year_difference)
			{
			case 2:
				leap_in_full_years_amount += (full_years_amount % 4 == 3) ? 1 : 0;
				break;
			case 3:
				leap_in_full_years_amount += (full_years_amount % 4 >= 2) ? 1 : 0;
				break;
			default:
				break;
			}
		}


		int days_in_full_years = full_years_amount * 365 + leap_in_full_years_amount;
		int date_difference = days_in_full_years + date2_day_number - date1_day_number;
		cout << "Разница между датами: " << date_difference << " дн." << endl;
	}


}

*/

int main()
{
	setlocale(0, "");

	//hw_020222_task1();
	//cout << endl;

	//hw_020222_task2();
	//cout << endl;

	//hw_020222_task3();
	//cout << endl;

	hw_020222_task4();
	cout << endl;

	//hw_020222_task5();
	//cout << endl;

	//hw_020222_task6();
	//cout << endl;
	
}
