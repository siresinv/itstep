// STEP _CPP _classwork12 _09.03.22 _task2 (kopnov)
/*
в рисунке
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std; int main()
{
	setlocale(0, "");
	srand(time(NULL));
	const int row = 5;
	const int col = 5;
	int mas[row][col], sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (int i = 0; i < row; i++) //строки
	{
		for (int j = 0; j < col; j++) //столбцы
		{
			mas[i][j] = rand() % 50;
			//cin >> mas[i][j];
		}
	}
	for (int i = 0; i < row; i++) //строки
	{
		for (int j = 0; j < col; j++) //столбцы
		{
			cout << mas[i][j] << "\t";
			sum1 += mas[i][j];
		}
		cout << " | " << sum1;
		cout << endl;
		sum3 += sum1;
		sum1 = 0;
	}
	cout << "-\t-\t-\t-\t-\t-------" << endl;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			sum2 += mas[j][i];
		}
		cout << sum2 << "\t";
		sum4 += sum2;
		sum2 = 0;
	}
	cout << " | " << sum3 + sum4;
}
