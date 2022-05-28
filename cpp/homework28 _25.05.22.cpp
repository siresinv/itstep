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

	//std::cout << word << "!";

	char words[48][15] = {
		"ноль ",
		"один ",
		"одина ",
		"два ",
		"две ",
		"три ",
		"четыре ",
		"пять ",
		"шесть ",
		"семь ",
		"восемь ",
		"девять ",
		"десять ",
		"одиннадцать ",
		"двенадцать ",
		"тринадцать ",
		"четырнадцать ",
		"пятнадцать ",
		"шестнадцать ",
		"семнадцать ",
		"восемнадцать ",
		"девятнадцать ",
		"двадцать ",
		"тридцать ",
		"сорок ",
		"пятьдесят ",
		"шестьдесят ",
		"семдесят ",
		"восемьдесят ",
		"девяносто ",
		"сто ",
		"двести ",
		"триста ",
		"четыреста ",
		"пятьсот ",
		"шестьсот ",
		"семьсот ",
		"восемьсот ",
		"девятьсот ",
		"тысяча ",
		"тысячи ",
		"тысяч ",
		"миллион ",
		"миллиона ",
		"миллионов ",
		"миллиард ",
		"миллиарда ",
		"миллиардов "
	};

	int numbers[48] = {0,1,1,2,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
	30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000,1000,1000,
	1000000,1000000,1000000,1000000000,1000000000, 1000000000 };

	/*char month[12][10] = {
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
	};

	char* month1[122] = { //так почему-то нельзя
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
	};*/
	

	for (int i = 0; i < 48; i++) {
		if (strstr(word, words[i])) return numbers[i];
	}
	return 0;
}

int* getArrNum_OfNumber(char* str, int nWords) {
	
	int* arrNum_OfNumber = new int[nWords];
	char* word = new char[10]; //10

	int wordCounter = 0;
	int symbCounter = 0;
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] != ' ' && str[i] != '\0') {
			word[symbCounter] = str[i];
			symbCounter++;
		}
		else {
			word[symbCounter] = ' ';
			word[symbCounter+1] = '\0';
			arrNum_OfNumber[wordCounter] = getNumFromWord(word);
			wordCounter++;
			symbCounter = 0;
		}
	}
	return arrNum_OfNumber; ////////////// одинаковые названия
}

int* converStrToNum(char* str) {
	int nWords = getNWords(str);
	int* arrNum_OfNumber = getArrNum_OfNumber(str, nWords);

	for (int i = 0; i < nWords; i++) {
		std::cout << arrNum_OfNumber[i] << " ";
	}

	return arrNum_OfNumber;
}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* str = new char[200];
	std::cout << "";
	gets_s(str, 200);
	converStrToNum(str);

	return 0;
}