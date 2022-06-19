// STEP _CPP _homework28 _25.05.22
/*

ДВУМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ
СТРОКИ

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>


int getNWords(char* str) {
	int wordCounter = 1;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			wordCounter++;
		}
	}
	return wordCounter;
}

int getNumFromWord(char* word) {
	
	char words[48][15] = {
		" ноль ",
		" один ",
		" одна ",
		" два ",
		" две ",
		" три ",
		" четыре ",
		" пять ",
		" шесть ",
		" семь ",
		" восемь ",
		" девять ",
		" десять ",
		" одиннадцать ",
		" двенадцать ",
		" тринадцать ",
		" четырнадцать ",
		" пятнадцать ",
		" шестнадцать ",
		" семнадцать ",
		" восемнадцать ",
		" девятнадцать ",
		" двадцать ",
		" тридцать ",
		" сорок ",
		" пятьдесят ",
		" шестьдесят ",
		" семдесят ",
		" восемьдесят ",
		" девяносто ",
		" сто ",
		" двести ",
		" триста ",
		" четыреста ",
		" пятьсот ",
		" шестьсот ",
		" семьсот ",
		" восемьсот ",
		" девятьсот ",
		" тысяча ",
		" тысячи ",
		" тысяч ",
		" миллион ",
		" миллиона ",
		" миллионов ",
		" миллиард ",
		" миллиарда ",
		" миллиардов "
	};

	int numbers[48] = { 
		0,
		1,
		1,
		2,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
		12,
		13,
		14,
		15,
		16,
		17,
		18,
		19,
		20,
		30,
		40,
		50,
		60,
		70,
		80,
		90,
		100,
		200,
		300,
		400,
		500,
		600,
		700,
		800,
		900,
		1000,
		1000,
		1000,
		1000000,
		1000000,
		1000000,
		1000000000,
		1000000000,
		1000000000 };

	for (int i = 0; i < 48; i++) {
		if (strstr(word, words[i])) return numbers[i];
	}
	return 0;
}

int* getArrNum_OfNumber(char* str, int nWords) {
	
	int* arrNum_OfNumber = new int[nWords];
	char* word = new char[10]; //10

	int wordCounter = 0;
	int symbCounter = 1;
	
	for (int i = 0; i <= strlen(str); i++) {
		word[0] = ' ';
		if (str[i] != ' ' && str[i] != '\0') {
			word[symbCounter] = str[i];
			symbCounter++;
		}
		else {
			word[symbCounter] = ' ';
			word[symbCounter+1] = '\0';
			arrNum_OfNumber[wordCounter] = getNumFromWord(word);
			wordCounter++;
			symbCounter = 1;
		}
	}
	return arrNum_OfNumber;
}

int converStrToNum(char* str) {
	int nWords = getNWords(str);
	int* arrNum_OfNumber = getArrNum_OfNumber(str, nWords);
	int number = 0;
	int numberPart = 0;

	for (int i = 0; i < nWords; i++) {
		
		if (arrNum_OfNumber[i]%1000000000 != 0 && arrNum_OfNumber[i] % 1000000 != 0 && arrNum_OfNumber[i] % 1000 != 0) {
			numberPart += arrNum_OfNumber[i];
		}
		else {
			numberPart *= arrNum_OfNumber[i];
			number += numberPart;
			numberPart = 0;
		}
	}
	number += numberPart;
	
	delete[]arrNum_OfNumber;
	return number;
}



char/***/ converNumToStr(int number) {
	int nBillion;
	int nMillion;
	int nThousand;
	int nHundred;
	int nDec;
	int nOne;

	nBillion = number / 1000000000;
	number %= (nBillion * 1000000000);

	nMillion = number / 1000000;
	number %= (nMillion * 1000000);

	nThousand = number / 1000;
	number %= (nThousand * 1000);

	nHundred = number / 100;
	number %= (nHundred * 100);

	nDec = number / 10;
	number %= (nDec * 10);

	nOne = number;
	

	std::cout << nBillion << " " << nMillion << " " << nThousand << " " << nHundred << " " << nDec << " " << nOne;

	return '0';
}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number;
	int str;

	//do {
	//	char* str = new char[250];
	//	std::cout << "Введите число строкой(ноль - выход): ";
	//	gets_s(str, 250);
	//	number = converStrToNum(str);
	//	std::cout << number;
	//	std::cout << std::endl;
	//	std::cout << std::endl;
	//	delete[]str;
	//} while (number > 0);
	

	/*do {
		char* str = new char[250];
		std::cout << "Введите число цифрами(ноль - выход): ";
		std::cout >> number;
		str = converNumToStr(number);
		std::cout << str;
		std::cout << std::endl;
		std::cout << std::endl;
		delete[]str;
	} while (number > 0);*/


	converNumToStr(1234567817);

	return 0;
}