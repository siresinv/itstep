// STEP _CPP _classwork10 _18.02.22 _task3
/*
������� 2. �������� ���������, ���������� ��������
2-� �������� �������� 5 ��������� ������ � ���� ������ �������� 10 ��������� ��������� �������: �������
���������� ��������������� ��� ��������, ������� 0,
����� ��������������� ��� ��������, ������ 0, � �����
��������������� ��� ��������, ������� 0.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(0, "");

	const int N_NUMBERS = 5;
	int arrA[N_NUMBERS] = {-1,-2,3,4,5};
	int arrB[N_NUMBERS] = {10,-9,0,7,-6};
	int arrC[N_NUMBERS * 2];



	//������ ������� � 6 ������
	int n = 0;
	for (int i = 0; i < N_NUMBERS; i++) { if (arrA[i] > 0) { arrC[n] = arrA[i]; n++; } }
	for (int i = 0; i < N_NUMBERS; i++) { if (arrB[i] > 0) { arrC[n] = arrB[i]; n++; } }

	for (int i = 0; i < N_NUMBERS; i++) { if (arrA[i] == 0) { arrC[n] = arrA[i]; n++; } }
	for (int i = 0; i < N_NUMBERS; i++) { if (arrB[i] == 0) { arrC[n] = arrB[i]; n++; } }

	for (int i = 0; i < N_NUMBERS; i++) { if (arrA[i] < 0) { arrC[n] = arrA[i]; n++; } }
	for (int i = 0; i < N_NUMBERS; i++) { if (arrB[i] < 0) { arrC[n] = arrB[i]; n++; } }


	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrA[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrB[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < N_NUMBERS * 2; i++) {
		std::cout << arrC[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}

