// STEP _CPP _homework7 _09.02.22 _task1

// ����� ��������� � �� ���������� ��� ����� �� � �� �


#include <iostream>



int main()
{
	setlocale(0, "");

	const int NUM_A = 10;
	const int NUM_B = 115;

	int currentNum;
	for (currentNum = NUM_A; currentNum <= NUM_B; currentNum++) {
		std::cout << "�����: " << currentNum << "\t" << "��������: ";
		int div;
		int nDiv;
		nDiv = 0;
		for (div = 1; div <= currentNum / 2; div++) {
			if (currentNum % div == 0) {
				std::cout << div << " ";
				nDiv++;
			}
		}
		std::cout << currentNum;
		nDiv++;

		std::cout << " (" << nDiv << "��.)";
			std::cout << std::endl;

	}




	return 0;

}

