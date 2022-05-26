// STEP _CPP _classwork24 _11.05.22 _task1
/*

СТРОКИ


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <math.h>



void test() {
	const int size = 6;
	char str[size] = { 'H','e','l','\n','o','\0' };
	char str2[] = "Hel\nlo";


	/*for (int i = 0; i < size; i++) {
		std::cout << str[i];
	}*/


	std::cout << str; // почему и так работает ???
	std::cout << std::endl;
	std::cout << str2;
	std::cout << std::endl;


	char str3[10];
	std::cin >> str3;
	std::cout << str3;
	std::cout << std::endl;


	char str4[30] = "ПРИВЕТ ПРИВЕТ";
	std::cout << strlen(str4);
	std::cout << std::endl;

	char s1[10] = "asd";
	char s2[10];
	//s2 = s1; // низя

	// так стремно - и ссылка просто на одну область памяти и утечка памяти
	/*char* c1 = new char[10]{ "123" };
	char* c2 = new char[10];
	c2 = c1;*/

	//strcpy(s2, s1); // _CRT_SECURE_NO_WARNINGS
	strcpy_s(s2, 10, s1);
	std::cout << s2;
	std::cout << std::endl;


	char str5[20] = "Test";
	strcat(str5, " one");
	strcat(strcat(str5, " two"), " three");
	std::cout << str5;
}

void task1() {
	char* name = new char[20];
	char* surname = new char[20];
	char* patronymic = new char[20];

	std::cout << "name: ";
	std::cin >> name;
	std::cout << "surname: ";
	std::cin >> surname;
	std::cout << "patronymic: ";
	std::cin >> patronymic;

	char* fio = new char[strlen(name) + strlen(surname) + strlen(patronymic) + 3];
	/*fio = strcat(name, " ");
	fio = strcat(fio, surname);
	fio = strcat(fio, " ");
	fio = strcat(fio, patronymic);*/

	strcat(strcat(strcat(strcat(strcpy(fio, name)," "),surname)," "), patronymic);

	std::cout << fio;

	delete[] name;
	delete[] surname;
	delete[] patronymic;
	delete[] fio;
}


void testt() {
	char* name = new char[20];
	char* surname = new char[20];
	char* patronymic = new char[20];

	std::cout << "surname:";
	gets_s(surname, 20);
	std::cout << "name:";
	gets_s(name, 20);
	std::cout << "patronymic:";
	gets_s(patronymic, 20);

	char* fio = new char[strlen(surname) + strlen(name) + strlen(patronymic) + 3]{};
	strcat(fio, (strcat(surname, (strcat(name, patronymic)))));
	std::cout << fio;
}


void task2() {
	char filename[50];
	std::cout << "file: ";
	std::cin >> filename;
	if (strchr(filename, '.ab')) { // тут с глюками
		std::cout << "yes" << strchr(filename, '.ab');
	}
	else {
		std::cout << "no";
	}
}


void task3() {
	char filename[50];
	std::cout << "file: ";
	std::cin >> filename;
	if (strstr(filename, ".txt")) {
		std::cout << "yes" << strchr(filename, '.');
	}
	else {
		std::cout << "no";
	}
}


int main() {
	setlocale(0, "");

	//test();

	//task1();

	//testt();

	//task2();
	task3();

	return 0;
}