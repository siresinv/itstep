// STEP _CPP _homework7 _09.02.22 _task3
// ����� ������������ ���������
// ������� � ������������� ������ // int ratio = width / height;
// ��� ������� - � ����������� �� '������ ���������'
// 

#include <iostream>


int main()
{
	setlocale(0, "");



	const char MARK = 'O';
	const char NOT_MARK = ' ';
	const char WALL = '|';
	const char LINE = '-';
	const int ORIGIN = 0; // ������ ���������. ���������� ������������ ������ � ������� � ������ ���������

	int width = 15;
	int height = 17;
	int ratio = width / height;
	
	int maxWidth = width / 2;
	int minWidth = -maxWidth;
	int maxHeight = height / 2;
	int minHeight = -maxHeight;
	
	char symb;


	// ��� ������� �������
	
	for (int j = maxHeight; j >= minHeight; j--)
	{
		for (int i = minWidth; i <= maxWidth; i++)
		{
			symb = NOT_MARK;
			//if (j == -i || j == i || j == 0 || i == 0) {
			//abs(i)==abs(j) ||
			if (abs(i)/ratio == abs(j) || i*j == 0) { ///
				// ������� � ������� � ������ ��������� - ������ ��� �������� ������� � ������ If
				symb = MARK;
			}

			std::cout << WALL << " " << symb << " ";
			//std::cout << WALL << " " << i << "; " << j << " ";

		}

		std::cout << WALL << std::endl;
		for (int k = 1; k <= width; k++)
		{
			std::cout << LINE << LINE << LINE << LINE;
		}
		std::cout << std::endl;
	}

	


	// ��� ������� �������
	/*
	for (int i = 1; i <= height; i++)
	{
		
		for (int j = 1; j <= width; j++)
		{
			symb = NOT_MARK;
			if (j == i || width-j+1 == i || j == width/2 + 1 || i == height/2 + 1){
				symb = MARK;
			}

			std::cout << WALL << " " << symb << " ";

		}
		
		std::cout << WALL << std::endl;
		for (int k = 1; k <= height; k++)
		{
			std::cout << LINE << LINE << LINE << LINE;
		}
		std::cout << std::endl;
	}
	*/

	return 0;

}

