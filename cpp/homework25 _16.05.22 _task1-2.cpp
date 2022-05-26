// STEP _CPP _homework25 _16.05.22 _task1-2.cpp
/*

СТРОКИ
homework25 _16.05.22.bmp

*/


#include <iostream>

int getWordsAmount(char* str) {
	int nWords = 1;

	for (int i = 0; i < strlen(str); i++) {
		if (*(str + i) == ' ') {
			nWords++;
		}
	}
	return nWords;
}


bool isStrPalindrom(char* str) {

	for (int i = 0; i < strlen(str)/2; i++) {
		if (*(str + i) != *(str + strlen(str) - i - 1)) return false;
	}

	return true;
}


int main() {
	setlocale(0, "");


	char* str = new char[20];
	gets_s(str, 20);
	std::cout << getWordsAmount(str);
	std::cout << std::endl;
	std::cout << (isStrPalindrom(str) ? "Палиндром" : "Не палиндром");
	std::cout << std::endl;


	return 0;
}