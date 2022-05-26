// STEP _CPP _classwork26 _18.05.22
/*

СТРОКИ


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>




void task1() {
	char* arrChar = new char[21];
	int symbDelNo;

	std::cin >> arrChar;
	std::cin >> symbDelNo;

	for (int i = symbDelNo-1; i < strlen(arrChar); i++) {
		*(arrChar + i) = *(arrChar + i + 1);
	}

	std::cout << arrChar;
}


void task2() {
	char* arrChar = new char[21];
	char symbDelChar;

	std::cin >> arrChar;
	std::cin >> symbDelChar;

	int count = 0;
	for (int i = 0; i < strlen(arrChar); i++) {
		if (*(arrChar + i) != symbDelChar) {
			arrChar[count++] = arrChar[i];
		}
	}
	arrChar[count] = '\0';

	std::cout << arrChar;
}

void task3() {
	char* arrChar = new char[20];
	std::cin >> arrChar;

	int count = 0;
	while (strchr(arrChar, '.')) {
		*strchr(arrChar, '.') = '!';
	}
	std::cout << arrChar;
}


char* insSymbToStr(char* str, char insSymb, int insPos) {
	//char* newStr = new char[strlen(str)+1];
	for (int i = strlen(str); i >= insPos; i--) {
		*(str + i + 1) = *(str + i);
	}
	*(str + insPos) = insSymb;
	return  str;
}


char* insSymbToStr_2(char* str, char insSymb, int insPos) {
	char* newStr = new char[strlen(str)+1];
	int count = 0;

	for (int i = 0; i <= strlen(str); i++) {
		if (i == insPos) {
			*(newStr + insPos) = insSymb;
			count++;
		}
		*(newStr + count++) = *(str + i);
	}
	return  newStr;
}



int my_strlen(char str[]) {
	int nSymb = 0;
	do {
		nSymb++;
	} while (str[nSymb] != '\0');
	
	return nSymb;;
}




char* my_strcpy(char* str1, char* str2) {
	int i = 0;
	for (int i = 0; i <= my_strlen(str2); i++) {
		*(str1 + i) = *(str2 + i);
	}
	return str1;;
}



int main() {
	setlocale(0, "");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	/*const int charSize = 20;
	char str[charSize];
	gets_s(str, charSize);
	// !!! ЕСЛИ МАССИВ СИМВОЛОВ УКАЗАН В СТАТИКЕ, ТО МОЖНО ПРОСТО gets_s(str)
	// А ЕСЛИ В ДИНАМИКЕ ОБЯЗАТЕЛЬНО - gets_s(str, charSize)
	std::cout << str;*/

	//task1();
	//task2();
	task3();

	
	/*
	//**************
	char* arrChar = new char[20];
	char insSymb;
	int insPos;

	std::cin >> arrChar;
	std::cin >> insSymb;
	std::cin >> insPos;

	//std::cout << insSymbToStr(arrChar, insSymb, insPos);
	std::cout << insSymbToStr_2(arrChar, insSymb, insPos);
	//*****************
	*/


	/*
	char str[10] = "qweasdzxc";

	char* str1 = new char[10];
	char* str2 = new char[10]{ "qweasdzxc" };
	

	//std::cout << my_strlen(str);
	std::cout << my_strcpy(str1, str2);
	*/

	return 0;
}