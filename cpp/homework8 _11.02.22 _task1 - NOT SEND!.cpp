// STEP _CPP _classwork8 _11.02.22 _task3
// ������� �� ����� ������ \- ; _\  ; \/ ; /\ ; X ; >< ; > ; < ; -/ ; /_
// ������� � ������� ������� ������

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	setlocale(0, "");

	std::cout << "����� �� ����� ����� �� ������ �������" << std::endl;
	std::cout << "������ ������� ���������� �������� (�� 5 �� 19)" << std::endl;
	std::cout << "������� �� ����������� ����� ����������" << std::endl;
	
	const int nFig = 1; //char???
	const char MARK = '*';
	const char NO_MARK = ' ';
	
	//char figNo; //int???
	int wSize; // ������ ������� �� ������ 
	int hSize; // ������ ������� �� ������
	float wCoef = 1.0; // ����������� ��� ������. ��-��������� - 1 - ��� ���������� �������
	float hCoef = 1.0; // ����������� ��� ������. ��-��������� - 1 - ��� ���������� �������
	int iInt; // ����� ������ ������� ����� ���������� ������������
	int jInt; // ����� ������� ������� ����� ���������� ������������
	int minSize; // minSize = ������ ��� ������ - ������, ��� ������

	srand(time(NULL));
	do {
		// �������� ��� ��������� �������� ����� �� 9 �� 25
		
		wSize = rand() % 17 + 9;
		hSize = rand() % 17 + 9;
	} while (wSize % 2 == 0 || hSize % 2 == 0);
	
	std::cout << wSize << " " << hSize << std::endl;

	// ��� �������� ������ � ������ - ��������� ������������ ��� ������ � ������
	// � ������� ������
	minSize = wSize;
	if (wSize > hSize) {
		wCoef = wSize / float(hSize);
		hCoef = 1.0;
		minSize = hSize;
	}
	else if (wSize < hSize) {
		hCoef = hSize / float(wSize);
		wCoef = 1.0;
		minSize = wSize;
	}

	//std::cout << wCoef << " " << hCoef;

	//figNo = 0;



	for (int figNo = 0; figNo < nFig; figNo++) {

		for (int i = 0; i <= hSize - 1; i++) {
			// ����� ������
			for (int j = 0; j <= wSize - 1; j++){
				iInt = round(i / hCoef); // round ceil floor trunc
				jInt = round(j / wCoef); // round ceil floor trunc
				
				switch (figNo) {
				// ����� � ����������� �� ������ ������
				case 0:
					(iInt >= jInt && iInt + jInt <= minSize - 1) ? std::cout << MARK : std::cout << NO_MARK;
					break;
				default:
					break;
				}

			}
			std::cout << std::endl;
		
		}
		std::cout << std::endl;

	}
	

	return 0;

}

