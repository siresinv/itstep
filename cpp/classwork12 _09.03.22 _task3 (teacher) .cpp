// STEP _CPP _classwork12 _09.03.22 _task3 (teacher)
/*
Задание 3. Напишите программу, в которой объявляется
массив размером 5×10 и массив размером 5×5. Первый
массив заполняется случайными числами, в диапазоне
от 0 до 50. Второй массив заполняется по следующему
принципу: первый элемент второго массива равен сумме
первого и второго элемента первого массива, второй элемент второго массива равен сумму третьего и четвертого
элемента первого массива.
*/
//////// ВЕРСИЯ ПРЕПОДАВАТЕЛЯ

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main()
{
	setlocale(0, "");
	srand(time(NULL));
	const int row = 5, col = 10;
	int mas[row][col], mas2[row][row];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mas[i][j] = rand() % 51;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j += 2) {
			mas2[i][j / 2] = mas[i][j] + mas[i][j + 1];
		}
	}
	cout << "----------------------------------------------------------------------------\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cout << mas2[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			mas2[i][j] = mas[i][j * 2] + mas[i][j * 2 + 1];
		}
	}
	cout << "----------------------------------------------------------------------------\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cout << mas2[i][j] << "\t";
		}
		cout << endl;
	}
}

