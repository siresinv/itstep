#include <iostream>
#include <math.h>

using namespace std;


//CW от 020222


void task1_сw_020222()
{
	int count = 1;
	while (count <= 7)
	{
		cout << "Чудо света " << count << endl;
		count++;
	}
	cout << "Вы увидели всё";

	//DoWhile ???
}




void task2_сw_020222()
{
	float num1, num2, result;
	char operation;
	bool operation_ok;

	do {
		operation_ok = true;
		cout << "Введите два числа через пробел: ";
		
		cin >> num1 >> num2;
		cout << "Выберите знак - [+] [-] [*] [/] [x - выход]: ";
		cout << "";
		cin >> operation;
		switch (operation)
		{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 != 0)
			{
				result = num1 / num2;
			}
			else
			{
				operation_ok = false;
			}
			break;
		case 'x':
		case 'X':
		case 'х':
		case 'Х':
			cout << "Выход" << endl;
			operation_ok = false;
			break;
		default:
			operation_ok = false; /////////////////////////////////////////
			break;
		}


		if (operation_ok)
		{
			cout << "Результат: " << num1 << " " << operation << " " << num2 << " = " << result;
			cout << endl;
		}
		else
		{
			cout << "Операция не выполнена";
			cout << endl;
		}
		cout << "---------------------------------------------" << endl;

	} while (operation != 'x' && operation != 'X' && operation != 'х' && operation != 'Х'); // буквы 'Ха' русские он не понимает

}





void task3_сw_020222()
{
	int num = 1;
	int result = 0;
	while (num <= 5)
	{
		result += num++;
	}

	cout << result;
}


void task4_сw_020222()
{
	cout << "Сколько звездочек хотите?: ";
	int stars_num;
	int count = 1;
	cin >> stars_num;

	while (count <= stars_num)
	{
		cout << "*";
		count++;
	}


}


void task5_сw_020222()
{
	char symb;
	int symb_number;
	int axis;
	int count = 1;

	cout << "Какой символ хотите?: ";
	cin >> symb;

	cout << "Сколько символов хотите?: ";
	cin >> symb_number;

	cout << "Расположить символы вертикально - 1; горизонтально - 2: ";
	cin >> axis;

		while (count <= symb_number)
		{
			cout << symb;
			(axis == 1) ? cout << endl : cout << "";
			count++;
		}

	


}



void task6_сw_020222()
{
	
	int num_begin, num_end;
	int sum = 0;

	cout << "Введите начало и конец диапазона целых чисел: ";
	cin >> num_begin >> num_end;
	int count = num_begin;
	
	while (count <= num_end)
	{
		sum += (count % 2 == 1) ? count : 0;
		count++;
	}

	cout << "Сумма нечетных чисел равна: " << sum;
	cout << endl;



}



int main()
{
	setlocale(0, "");

	//task1_сw_020222();
	//cout << endl;

	//task2_сw_020222();
	//cout << endl;

	//task3_сw_020222();
	//cout << endl;

	//task4_сw_020222();
	//cout << endl;

	//task5_сw_020222();
	//cout << endl;

	task6_сw_020222();
	cout << endl;

}

//CW от 020222

