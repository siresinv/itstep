// STEP _CPP _classwork10 _18.02.22 _task4
/*
����� (�������� ��������) ������, ������ ��
���� ��� 0, � ��������� �������������� ������ ��������
���������� -1.
������ ��� �� �����!!

i++;
� �����
������ ������� ��������!

���.... �� �������� ���
�.�. ���� ������ ���� ������ �����
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

	setlocale(0, "");

	const int size = 11;
	int mas[size] = { 9,0,0,0,7,8,0,6,9,5,4 };
	for (int i = 0; i < 10; i++) {
		if (mas[i] == 0) {
			for (int j = i; j < size - 1; j++) {
				mas[j] = mas[j + 1];
			}
			mas[size - 1] = -1;
			i--;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;


	return 0;
}

