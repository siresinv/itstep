#include <iostream>
#include <math.h>

using namespace std;



//CW от 280122


/*
void task1_cw_280122()
{
	cout << "Введите оценку N1: ";
	int rating1;
	cin >> rating1;

	cout << "Введите оценку N2: ";
	int rating2;
	cin >> rating2;

	cout << "Введите оценку N3: ";
	int rating3;
	cin >> rating3;

	cout << "Введите оценку N4: ";
	int rating4;
	cin >> rating4;

	cout << "Введите оценку N5: ";
	int rating5;
	cin >> rating5;

	float average_rating = (rating1 + rating2 + rating3 + rating4 + rating5) / float(5);

	bool limit = (average_rating >= 4) ? true : false;

	cout << "Средний бал: " << average_rating << endl;

	if (limit)
	{
		cout << "Допуск есть";
	}
	else
	{
		cout << "Допуска нет";
	}
}*/



/*void task2_cw_280122()
{
	cout << "Введите целое число: ";
	int number;
	cin >> number;

	float result = number;
	result *= (number % 2 == 0) ? 3 : 0.5;

	cout << "Результат: " << result;

}*/



void task3_cw_280122()
{
	cout << "Введите два числа через пробел: ";
	float num1, num2, result;
	cin >> num1 >> num2;
	cout << "Выберите знак - [+] [-] [*] [/] : ";
	char operation;
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
		result = num1 / num2;
		break;
	default:
		result = 0; /////////////////////////////////////////
		break;
	}

	if (result)
	{
		cout << "Результат: " << num1 << " " << operation << " " << num2 << " = " << result;
	}
	else
	{
		cout << "Операция не выполнена";
	}
	
}



/*void task4_cw_280122()
{
	cout << "Введите вашу оценку буквами: [A] [B] [C] [D] [E] [F] : ";
	char rating_letter;
	cin >> rating_letter;

	int rating_digit;

	switch (rating_letter)
	{
	case 'A':
	case 'a':
		rating_digit = 5;
		break;
	case 'B':
	case 'b':
		rating_digit = 4;
		break;
	case 'C':
	case 'c':
		rating_digit = 3;
		break;
	case 'D':
	case 'd':
		rating_digit = 2;
		break;
	case 'E':
	case 'e':
		rating_digit = 1;
		break;
	case 'F':
	case 'f':
		rating_digit = 0;
		break;
	default:
		rating_digit = -1;
		break;
	}

	if (rating_digit == -1)
	{
		cout << "Введите верную букву";
	}
	else
	{
		cout << "Ваша оценка цифрой: " << rating_digit;
	}
	
}*/



void task5_cw_280122()
{
	cout << "Введите число : ";
	int number;
	cin >> number;

	cout << "Введите степень от 1 до 7: ";
	char number_degree;
	cin >> number_degree;

	int result;

	switch (number_degree)
	{
	case '1':
		result = pow(number, 1);
		break;
	case '2':
		result = pow(number, 2);
		break;
	case '3':
		result = pow(number, 3);
		break;
	case '4':
		result = pow(number, 4);
		break;
	case '5':
		result = pow(number, 5);
		break;
	case '6':
		result = pow(number, 6);
		break;
	case '7':
		result = pow(number, 7);
		break;
	default:
		result = -1;
		break;
	}

	if (result != -1)
	{
		cout << number << " ^ " << number_degree << " = " << result;
	}
	else
	{
		cout << "Введена неверная степень";
	}
		


}



int main()
{
	setlocale(0, "");

	//task1_cw_280122();
	//cout << endl;

	//task2_cw_280122();
	//cout << endl;

	//task3_cw_280122();
	//cout << endl;

	//task4_cw_280122();
	//cout << endl;

	task5_cw_280122();
	cout << endl;
}

//CW от 280122

