// STEP _CPP _classwork10 _18.02.22 _task1
/*
4. � ������� �������� ���������� � ��������� 10 �����
�����������. ���������� ����� �������� ��������
���������� � ������ ��� �����. ���� ����� ����������� ���������, ����������:
�) ����� ������� ������ ����������;
�) ����� ���������� ������ ����������.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(0, "");

	const int N_AUTO=10;
	int arrAutoCost[N_AUTO] = {1, 5, 3, 4, 5, 3, 5, 2, 1, 0};
	int firstMostCostId;
	int lastMostCostId;

	firstMostCostId = 0;
	lastMostCostId = 0;

	for (int i = 0; i < N_AUTO; i++) {
		std::cout << i + 1 << " - ���� " << arrAutoCost[i] << std::endl;


		if (arrAutoCost[firstMostCostId] < arrAutoCost[i]) {
			firstMostCostId = i;
		}


		if (arrAutoCost[N_AUTO - 1 - i] < arrAutoCost[i]) {
			lastMostCostId = i;
		}


	}

	std::cout << "����� ������� �������������� ����������: " << firstMostCostId +1 << std::endl;
	if (arrAutoCost[lastMostCostId] == arrAutoCost[firstMostCostId]) {
		std::cout << "����� ������� �������������� ����������: " << lastMostCostId + 1 << std::endl;
	}

	

	return 0;
}

