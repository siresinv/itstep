// STEP _CPP _homework9 _16.02.22 _task3
/*
������� 3
������������ ������ ������� ����� �� ��� (12 �������).
����� ������������ ������ �������� (��������, 3 � 6 � �����
����� 3-� � 6-� �������). ���������� ���������� �����,
� ������� ������� ���� ����������� � �����, � �������
������� ���� ���������� � ������ ���������� ���������.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");
	srand(time(NULL));

	const int MONTH_PERIOD = 12;
	const int MONTH_BEGIN = 5;
	const int MONTH_END = 7;

	int arrMonthProfit[MONTH_PERIOD];
	int monthIdMinProfit;
	int monthIdMaxProfit;


	for (int i = 0; i < MONTH_PERIOD; i++) {
		arrMonthProfit[i] = rand() % 100001 + 100000;
	}

	monthIdMinProfit = MONTH_BEGIN-1;
	monthIdMaxProfit = MONTH_BEGIN-1;

	for (int i = MONTH_BEGIN-1; i < MONTH_END; i++) {
		if (arrMonthProfit[monthIdMinProfit] > arrMonthProfit[i]) {
			monthIdMinProfit = i;
		}

		if (arrMonthProfit[monthIdMaxProfit] < arrMonthProfit[i]) {
			monthIdMaxProfit = i;
		}

	}

	std::cout << "�����\t" << "�������" << std::endl;
	for (int i = 0; i < MONTH_PERIOD; i++) {
		std::cout << i+1 << "\t" << arrMonthProfit[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "�������� �������: " << MONTH_BEGIN << " - " << MONTH_END << std::endl;
	std::cout << "� " << monthIdMinProfit + 1 << " ������ ������� ���� ����������� -  " << arrMonthProfit[monthIdMinProfit] << std::endl;
	std::cout << "� " << monthIdMaxProfit + 1 << " ������ ������� ���� ������������ -  " << arrMonthProfit[monthIdMaxProfit] << std::endl;

	return 0;
}

