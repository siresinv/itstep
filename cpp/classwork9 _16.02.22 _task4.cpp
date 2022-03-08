// STEP _CPP _classwork9 _16.02.22 _task4
/*
2. � ������� �������� ���������� � ���������� �������
������ �������� ������������ ���� (4 ��������, ��
������ ����� �� 2 ��������).
1- �) �� ���������� ������ �������� ���������� ���������� �������, � ����� �� ������� �����������
�� ����� �����;
2- �) ���������� ��������� ���������� ������� ���
������� ��������;
1- �) ���������� ������ �������, ��� ����� �����������
�����. ������� ����� ������� ��������, � �������
���������� ������ ����� ��������� ���� �������.

� �������� �� 1 �� 8

� ������ �� ��������?
0-��� ������� - �������� - 1
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");

	srand(time(NULL));

	const int N_FLOOR = 5; // ���������� ������
	const int N_ENTRY = 4; // ���������� ���������
	const int N_FLOOR_FLAT = 3; // ���������� ������� �� �����
	const int N_ALL_FLAT = N_FLOOR * N_ENTRY * N_FLOOR_FLAT; // ����� ���������� �������
	const int N_ENTRY_FLAT = N_FLOOR * N_FLOOR_FLAT; // ��������� ������� � ��������
	const int N_MANY_HUMAN = 5; // ������� ������� ������ ��������� ������������


	int flatNo;
	int floorNo;
	int entryNo;
	int ManyHumanFlatId; ///// ��� ������ ���������� � �������� ???
	int selectFlatNo; // ����� ��������� ��������
	int nHumanSelectFlat; // ���������� ������� � ��������� ��������
	bool isEvenSelectFlat; // �������� ������ ��������� ��������
	int neighborFlatNo; // ����� �������� ��������
	int neighborFlatHumanAmount; // ���������� ������� � �������� ��������

	int arrFlatHumanAmount[N_ALL_FLAT]; // ������ � ����������� ������� � ���������
	int arrEntryHumanAmount[N_ENTRY] = {}; // ������ � ����������� ������� � ���������
	int arrManyHumanFlatNo[N_ALL_FLAT] = {}; // ������ ��� ����������� �������. ��� ��������������� ������ )))


	for (int i = 0; i < N_ALL_FLAT; i++) {
		arrFlatHumanAmount[i] = rand() % 8 + 1;
	}


	ManyHumanFlatId = 0;
	for (int i = 0; i < N_ALL_FLAT; i++) {
		
		flatNo = i + 1; // ����� ��������
		entryNo =  i / N_ENTRY_FLAT + 1; // ����� ��������
		
		arrEntryHumanAmount[entryNo-1] += arrFlatHumanAmount[i];

		if (arrFlatHumanAmount[i] > N_MANY_HUMAN) {
			arrManyHumanFlatNo[ManyHumanFlatId] = flatNo;
			ManyHumanFlatId++;
		}
	}


	std::cout << "��.\t" << "���." << std::endl;
	for (int i = 0; i < N_ALL_FLAT; i++) {
		flatNo = i + 1;
		std::cout << flatNo << "\t" << arrFlatHumanAmount[i] << std::endl;
	}
	std::cout << std::endl;


	std::cout << "����������� ��������: ";
	for (int i = 0; i < N_ALL_FLAT; i++) {
		if (arrManyHumanFlatNo[i] != 0) {
			std::cout << arrManyHumanFlatNo[i] << " ";
		}
		
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "�������\t" << "���." << std::endl;
	for (int i = 0; i < N_ENTRY; i++) {
		entryNo = i + 1;
		std::cout << entryNo << "\t" << arrEntryHumanAmount[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;




	selectFlatNo = rand() % N_ALL_FLAT + 1;
	entryNo = selectFlatNo / N_ENTRY_FLAT + ((selectFlatNo % N_ENTRY_FLAT == 0) ? 0 : 1); // ����� ��������
	floorNo = (selectFlatNo - (entryNo-1) * N_ENTRY_FLAT)/ N_FLOOR_FLAT + ((selectFlatNo % N_FLOOR_FLAT == 0) ? 0 : 1); // ����� �����
	nHumanSelectFlat = arrFlatHumanAmount[selectFlatNo - 1];
	isEvenSelectFlat = (selectFlatNo % 2 == 0) ? true : false;
	
	//������ ��� �������, ��� ������� �� ����� - ���
	if (isEvenSelectFlat == true) {
		neighborFlatNo = selectFlatNo - 1;
	}
	else {
		neighborFlatNo = selectFlatNo + 1;
	}
	neighborFlatHumanAmount = arrFlatHumanAmount[neighborFlatNo - 1];

	std::cout << "��������� ��������: " << selectFlatNo << std::endl;
	std::cout << "����� ��������: " << entryNo << std::endl;
	std::cout << "����� �����: " << floorNo << std::endl;
	std::cout << "���������� �������: " << nHumanSelectFlat << std::endl;
	std::cout << "����� �������� ��������: " << neighborFlatNo << std::endl;
	std::cout << "���������� ������� � �������� ��������: " << neighborFlatHumanAmount << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}

