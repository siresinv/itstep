// STEP _CPP _classwork7 _09.02.22 _task2


#include <iostream>

/*���� ���� ������ ���, ������� ���, ������� �������.
�������� ���������, ������� ����������, ������� ���
������� ���� �� 12 �����.*/

int main()
{
	setlocale(0, "");
	int nBells = 0;

	for (int nBell = 1; nBell <= 12; nBell++) {
		nBells += nBell;
	}

	std::cout << nBells;

}