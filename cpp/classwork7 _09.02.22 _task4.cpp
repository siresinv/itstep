// STEP _CPP _classwork7 _09.02.22 _task4


#include <iostream>

/*
�������� ���������, ������� ���������� ��� �����,
������� ������ �����, �������� � ����������
*/

int main()
{
	setlocale(0, "");
	int num;

	std::cout << "������� �����: ";
	std::cin >> num;

	std::cout << num << " ������ ������ ";
	for (int i = 1; i <= num/2; i++)
	{
		
		if (num % i == 0) {
			std::cout << i << " ";
		}
	}
	std::cout << num;

	return 0;

}