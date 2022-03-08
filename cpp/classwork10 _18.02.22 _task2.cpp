// STEP _CPP _classwork10 _18.02.22 _task2
/*
6. ��������� ��� ������������� ������� A[10] � B[10].
������������ ������ ������ X[20], �������� �������� ����� ����� �� A � B � �������:
�) ����������� (a0, b0, a1, b1, a2, b2, �, a9, b9);
�) ���������� (a0, a1, a2,�, a9, b0, b1, b2,�, b9).
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(0, "");

	const int N_NUMBERS = 10;
	int arrA[N_NUMBERS] = {1,2,3,4,5,6,7,8,9,10};
	int arrB[N_NUMBERS] = {10,9,8,7,6,5,4,3,2,1};
	int arrC[N_NUMBERS * 2];
	int variant;

	std::cout << "�������� ������� ����������� �������� 1, 2: ";
	std::cin >> variant;

	int j = 0;
	int k = 0;
	
	for (int i = 0; i < N_NUMBERS; i++) {
		
		switch (variant) {
			case 1:
				j = i * 2;
				k = j + 1;
				arrC[j] = arrA[i];
				arrC[k] = arrB[i];
				break;
			case 2:
				arrC[i] = arrA[i];
				arrC[i+ N_NUMBERS] = arrB[i];
				break;
			default:
				break;
		}
		

	}

	std::cout << std::endl;

	for (size_t i = 0; i < N_NUMBERS * 2; i++) {
		std::cout << arrC[i] << " ";
	}

	return 0;
}

