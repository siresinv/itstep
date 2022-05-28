// STEP _CPP _classwork28 _25.05.22
/*

СТРОКИ


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>


void task1() {
	
	int nStudents = 5;

	char** studArr = new char* [nStudents];

	for (int i = 0; i < nStudents; i++) {
		studArr[i] = new char[20];
	}

	for (int i = 0; i < nStudents; i++) {
		std::cout << "Фамилия " << i+1 << "-го студента: ";
		std::cin >> studArr[i];
	}

	char maxLenSurname[20];
	strcpy(maxLenSurname, studArr[0]);
	for (int i = 0; i < nStudents; i++) {
		if (strlen(studArr[i]) > strlen(maxLenSurname)) {
			strcpy(maxLenSurname, studArr[i]);
		}
	}

	std::cout << "-----------" << maxLenSurname;

	
	for (int i = 0; i < nStudents; i++) {
		delete[]studArr[i];
	}
	delete[]studArr;
}

void task2() {

	char str1[]{ "sdfasdafasd" };
	char str2[]{ "sdfasdafax" };

	std::cout << strcmp(str1,str2);

}


int my_strcmp(char* str1, char* str2) {
	int lenEnd;

	if (strlen(str1) < strlen(str2)) {
		lenEnd = strlen(str1);
	}
	else {
		lenEnd = strlen(str2);
	}

	for (int i = 0; i <= lenEnd; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] < str2[i]) {
			return -1;
		}
	}
	return 0;
}


void task4() {


	char f = 'a';
	std::cout << char(toupper(f));
	std::cout << f;
}

int main() {
	setlocale(0, "");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//task1();
	//task2();

	/*char str1[20];
	char str2[20];
	std::cout << "Первая строка: ";
	std::cin >> str1;
	std::cout << "Вторая строка: ";
	std::cin >> str2;
	std::cout << my_strcmp(str1, str2);*/

	task4();

	return 0;
}