//CW от 040222

/*

*/

#include <iostream>
#include <math.h>

using namespace std;


void cw_040222_task1()
{
	int number;
	int count;
	int number_factorial;
	bool input_ok;


	cout << "Введите целое неотрицательное число: ";
	cin >> number;

	input_ok = (number > 0) ? true : false;

	cout << "------------------------------------" << endl;
	if (!input_ok)
	{	
		cout << "Введено не верное число!";
	}
	else
	{
		count = 1;
		number_factorial = 1;
		while (count <= number)
		{
			number_factorial *= count;
			count++;
		}

		cout << "Факториал числа " << number << " равен " << number_factorial;
	}

	cout << endl;
}


void cw_040222_task2()
{
	int fabric_length;
	int pillow_lenght;
	int pillow_amount;
	bool input_ok;


	cout << "Введите длину имеющейся ткани: ";
	cin >> fabric_length;

	cout << "Введите длину ткани необходимой для одной подушки: ";
	cin >> pillow_lenght;

	input_ok = (fabric_length > 0 && pillow_lenght > 0 ) ? true : false;

	cout << "------------------------------------" << endl;
	if (!input_ok)
	{
		cout << "Введены не верные данный!";
	}
	else
	{
		pillow_amount = 0;
		while (fabric_length > pillow_lenght)
		{
			pillow_amount++;
			fabric_length -= pillow_lenght;
		}


		cout << "Ткани хватит на " << pillow_amount << " подушек ";
	}

	cout << endl;
	
}




void cw_040222_task3()
{
	int box_amount;
	int box_in_car_amount;
	int car_amount;
	bool input_ok;


	cout << "Количество ящиков с яблоками: ";
	cin >> box_amount;

	cout << "Сколько ящиков вмещает одна машина: ";
	cin >> 	box_in_car_amount;

	input_ok = (box_amount > 0 && box_in_car_amount > 0) ? true : false;

	cout << "------------------------------------" << endl;

	if (!input_ok)
	{
		cout << "Введены не верные данный!";
	}
	else
	{
		car_amount = 0;
		do
		{
			car_amount++;
			box_amount -= box_in_car_amount;
		} while (box_amount > 0);


		cout << "К складу подъехало " << car_amount << " машин";
	}

	cout << endl;

}



void cw_040222_task_prev4()
{

	const int num_end = 20;
	//const double big_int_number = 1000000;
	int num_begin;
	bool operation_ok;
	long long result; //тоже не обеспечивает точность при умножении всех чисел, например от 1 до 20
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


void cw_040222_task4()
{
	int number;
	int sum;

	sum = 0;
	do
	{
		cout << "Введите число. Для завершения - 0: ";
		cin >> number;
		sum += number;
	} while (number != 0);

	cout << "-------------------------------------" << endl;
	cout << "Сумма введенных чисел равна " << sum << endl;

}


void cw_040222_task5()
{
	int number_amount;
	number_amount = 10;

	for (int i = 0; i <= number_amount; i++)
	{
		cout << "Число " << i << endl;
		i++;
	}
}


void cw_040222_task6()
{
	int number_amount;
	number_amount = 10;

	for (int i = 0; i <= number_amount;)
	{
		cout << "Число " << i << endl;
		i += 2;
	}
}


void cw_040222_task7()
{
	int number_amount;
	number_amount = 10;

	for (int i = 1; i <= 10; i++)
	{
		if (i==5)
		{
			//break;
			continue;
			
		}
		cout << i << " ";
	}
}


void cw_040222_task8()
{
	const int day1_distance = 15;
	const int day_amount = 4;
	const int everyday_distance_inc = 2;
	int distance_every_next_day = day1_distance;
	int full_distance = day1_distance;
	

	for (int i = 2; i <= day_amount; i++) // т.е. циклическое прибавление начинается со второго дня, т.к. дистанция в первый день нам уже известена
	{	
		distance_every_next_day += everyday_distance_inc;
		full_distance += distance_every_next_day;
	}

	cout << "-------------------------------------" << endl;
	cout << "Вся дистанция за " << day_amount << " дней равна " << full_distance << endl;

}

int main()
{
	setlocale(0, "");

	//cw_040222_task1();
	//cout << endl;

	//cw_040222_task2();
	//cout << endl;

	//cw_040222_task3();
	//cout << endl;

	//cw_040222_task_prev4();
	//cout << endl;

	//cw_040222_task4();
	//cout << endl;

	//cw_040222_task5();
	//cout << endl;

	//cw_040222_task6();
	//cout << endl;

	//cw_040222_task7();
	//cout << endl;

	cw_040222_task8();
	cout << endl;
}
