// STEP _CPP _classwork7 _09.02.22 _task2


#include <iostream>

/*������������ � ���������� ��������������� ������
����� �����. ��� ������ ������������ ���� 0, ����������
�������� �� ����� ����� ���� ��������� �����.*/

int main()
{
	setlocale(0, "");
	int sum = 0;
	int num;

	for (;;) {
		std::cout << "������� ����� (0 - �����): ";
		std::cin >> num;

		if (num == 0) {
			break;
		}

		sum += num;

		
	}

	std::cout << "����� �����: " <<sum;

}