// STEP _CPP _homework9 _16.02.22 _task2
/*
������� 2
� ���������� �������, ����������� ���������� �������
� �������� ������������� ���������, ����� ����� ���������,
�������� ������� ������ ���������� �������������.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");
	srand(time(NULL));



	const int N_NUMBERS = 20;
	const int MAX_RND = 100;
	const int USER_NUMBER = 30;
	int arrNumbers[N_NUMBERS];
	int sum;


	for (int i = 0; i < N_NUMBERS; i++) {
		arrNumbers[i] = rand() % MAX_RND + 1;
	}


	sum = 0;
	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrNumbers[i] << " ";
		std::cout << std::endl;

		if (arrNumbers[i] < USER_NUMBER) {
			sum += arrNumbers[i];
		}


	}

	std::cout << std::endl;
	std::cout << "����� ��������� ������� " << USER_NUMBER << " ����� " << sum;

	std::cout << std::endl;


	return 0;
}

