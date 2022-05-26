// STEP _CPP _homework26 _18.05.22 _task1-3.cpp
/*

������
homework26 _18.05.22.bmp

*/


#include <iostream>



char* mystrcat(char* str1, const char* str2);
char* mystrchr(char* str, char s);
char* mystrstr(char* str1, char* str2);



int main() {
	setlocale(0, "");

	char* str1 = new char[20];
	char* str2 = new char[5];
	char s;

	std::cout << "������� ������ 1: ";
	std::cin >> str1;
	
	std::cout << "������� ������ 2: ";
	std::cin >> str2;
	
	std::cout << "������� ������: ";
	std::cin >> s;


	std::cout << "������������ �����. ������ 1: " << mystrcat(str1, str2);
	std::cout << std::endl;

	if (mystrchr(str1, s)) {
		std::cout << "������� ��������� �� ������ ��������� ������� � ������1: " << mystrchr(str1, s);
	}
	else {
		std::cout << "��������� ��������� ������� � ������1 �� �������";
	}
	std::cout << std::endl;


	if (mystrstr(str1, str2)) {
		std::cout << "������� ��������� �� ������ ��������� ������2 � ������1: " << mystrstr(str1, str2);
	}
	else {
		std::cout << "��������� �� ��������� ������2 � ������1 �� �������";
	}
	std::cout << std::endl;


	delete[] str1;
	delete[] str2;

	return 0;
}




char* mystrcat(char* str1, const char* str2) {
	int lenStr1 = strlen(str1);
	for (int i = 0; i <= strlen(str2); i++) {
		*(str1 + i + lenStr1) = *(str2 + i);
	}
	return str1;
}



char* mystrchr(char* str, char s) {
	for (int i = 0; i < strlen(str); i++) {
		if (*(str + i) == s) {
			return (str + i);
		}
	}
	return nullptr;
}



char* mystrstr(char* str1, char* str2) {
	bool isFirtSymb = false;
	int countStr2 = 0;
	int firstSymbolId;

	for (int i = 0; i < strlen(str1); i++) {

		if (isFirtSymb == false) {
			if (*(str1 + i) == *(str2)) {
				isFirtSymb = true;
				firstSymbolId = i;
			}
		}
		else {
			countStr2++;
			if (*(str1 + i) != *(str2 + countStr2)) {
				isFirtSymb = false;
				countStr2 = 0;
			}
			else {
				if (countStr2 == strlen(str2) - 1) {
					return (str1 + firstSymbolId);
				}
			}
		}
	}
	return nullptr;
}