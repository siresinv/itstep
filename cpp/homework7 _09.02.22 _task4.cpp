// STEP _CPP _homework7 _09.02.22 _task4

// ����������� ��� �� ��������������� ����
// ������� ��� ��������� ����������
// ������� ������������ �����, ���� �� ���� ���������� - 3 �������


#include <iostream>



int main()
{
	setlocale(0, "");

	const int TIME_ONE_COMBINATION = 3;

	int nCombination;
	int timeSeconds;
	int timeHr;
	int timeMin;
	int timeSec;

	nCombination = 0;
	int dig1;
	for (dig1 = 0; dig1 <= 9; dig1++) {

		int dig2;
		for (dig2 = 0; dig2 <= 9; dig2++) {
			if (dig2 == dig1) {
				continue;
			}

			int dig3;
			
			for (dig3 = 0; dig3 <= 9; dig3++)
			{
				if (dig3 == dig1 || dig3 == dig2) {
					continue;
				}
				else {
					std::cout << dig1 << dig2 << dig3;
					std::cout << " ";
					nCombination++;
				}
			}
			std::cout << std::endl;
			
		}
	}

	timeSeconds = nCombination * TIME_ONE_COMBINATION;

	timeHr = timeSeconds / 3600;
	timeMin = (timeSeconds % 3600) / 60;
	timeSec = timeSeconds % 60;
	
	std::cout << std::endl;
	std::cout << "���������� ����������: " << nCombination << std::endl;
	std::cout << "������������ ����� �� ������� ���� ���������: ";
	std::cout << timeHr << "hr : " << timeMin << "min : " << timeSec << "sec" << std::endl;

	return 0;

}

