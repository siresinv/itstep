// STEP _CPP _classwork10 _18.02.22 _task4
/*
����� (�������� ��������) ������, ������ ��
���� ��� 0, � ��������� �������������� ������ ��������
���������� -1.
������ ��� �� �����!!

i++;
� �����
������ ������� ��������!
*/

#include <iostream>

int main() {

	setlocale(0, "");

	const int N_NUMBERS = 21;
	int arrNumbers[N_NUMBERS] = { 9, 0, 0, 0, 7, 8, 0, 6, 9, 5, 4, 9, 0, 0, 7, 8, 0, 6, 9, 5, 4 };
	int nullCount;
	bool  isNull;


	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrNumbers[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	nullCount = 0;
	do  {
		isNull = false;
		for (int i = 0; i < N_NUMBERS; i++) {
			if (arrNumbers[i] == 0 && i < N_NUMBERS-1) {
				arrNumbers[i] += arrNumbers[i + 1];
				arrNumbers[i + 1] = arrNumbers[i] - arrNumbers[i + 1];
				arrNumbers[i] = arrNumbers[i] - arrNumbers[i + 1];
				isNull = true;

				for (int i = 0; i < N_NUMBERS; i++) {
					std::cout << arrNumbers[i] << " ";
				}
				std::cout << std::endl;
			}
		}

		if (isNull == true) {
			nullCount++;
			std::cout << "�������� " << nullCount << "(��/��/��) ���� � �����";
			std::cout << std::endl;
			std::cout << std::endl;
		}
		

		arrNumbers[N_NUMBERS - 1] = -1;
		
	} while (isNull == true);
	for (int i = 0; i < N_NUMBERS; i++) {
		std::cout << arrNumbers[i] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;


	return 0;
}

