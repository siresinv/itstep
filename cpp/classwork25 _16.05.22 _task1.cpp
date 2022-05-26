// STEP _CPP _classwork25 _16.05.22 _task1
/*

СТРОКИ
homework24 _11.05.22.bmp

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>




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

	// так стремно копировать - и ссылка просто на одну область памяти и утечка памяти при удалении указателя с2?
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

void h_task1() {
	const int sizeArr = 11;
	char arrChar[sizeArr];
	std::cout << "Введите строку: ";
	std::cin >> arrChar;
	std::cout << "Занято: " << strlen(arrChar) << " Свободно: " << sizeArr - strlen(arrChar) -1 << " из: " << sizeArr - 1;

}

void h_task2() {
	const int sizeArr = 11;
	char arrChar[sizeArr]{};
	int beginId;
	int endId;

	std::cout << "Введите строку: ";
	std::cin >> arrChar;
	std::cout << "Индекс первого символа: ";
	std::cin >> beginId;
	std::cout << "Индекс последнего символа: ";
	std::cin >> endId;

	char* arrChar2 = new char[endId - beginId + 2]{};
	
	std::cout << strlen(arrChar2);

	int counter = 0;
	for (int i = beginId; i <= endId; i++) {
		*(arrChar2 + counter++) = arrChar[i];
	}
	
	//strcat(arrChar2, "\0");
	
	/*counter = 0;
	for (int i = 0; i <= strlen(arrChar2); i++) {
		std::cout << *(arrChar2 + counter++);
	}*/

	std::cout << arrChar2;

	delete[] arrChar2;
}

void h_task3() {
	const int sizeArr = 11;
	char* arrChar = new char[sizeArr] {};
	
	int beginNo;
	int endNo;

	std::cout << "Введите строку: ";
	std::cin >> arrChar;
	std::cout << "Удалить с.. по..: " << std::endl;
	std::cout << "Номер первого символа: ";
	std::cin >> beginNo;
	std::cout << "Номер последнего символа: ";
	std::cin >> endNo;

	char* arrTempChar = new char[beginNo - 1 + 1]{};
	char* arrTempChar_2 = new char[sizeArr - endNo + 1]{};

	//strcpy_s(arrTempChar, beginNo+1, arrChar);

	int counter = 0;
	for (int i = 0; i < beginNo; i++) {
		*(arrTempChar + counter++) = arrChar[i];
	}
	
	counter = 0;
	for (int i = endNo +1; i < sizeArr; i++) {
		*(arrTempChar_2 + counter++) = arrChar[i];
	}

	delete[] arrChar;

	strcpy(arrChar, arrTempChar);



}

void h_task4() {

}

void h_task5() {

}









void cw1() {
	//Заменить все буквы a на b

	char arrChar[11] = "ahakjdkaka";

	for (int i = 0; i < strlen(arrChar); i++) {
		if (arrChar[i] == 'a') {
			arrChar[i] = 'b';
		}
	}

	std::cout << arrChar;

}





void cw1_2() {
	//Заменить все буквы a на b
	char arrChar[20] = "haakjaaaaaadkaka";
	//for (int i = 0; i < strlen(arrChar); i++) {
		*strchr(arrChar, 'a') = 'b';
		*strchr(arrChar, 'a') = 'b';
		*strchr(arrChar, 'a') = 'b';
		*strchr(arrChar, 'a') = 'b';
	//}

	std::cout << arrChar;
}




void cw2() {
	/*[18:58] Трофимова Маргарита(гость)
		Создать новый массив, заменив в нем все а на ху

		[18:59] Трофимова Маргарита(гость)
		Память выделить динамически*/



	char arrChar[11] = "ahakjdkaka";
	char findLetter = 'a';
	int counter = 0;
	for (int i = 0; i < strlen(arrChar); i++) {
		if (arrChar[i] == findLetter) {
			counter++;
		}
	}

	std::cout << strlen(arrChar) + counter;

	char* arrCharNew = new char[0]; //[strlen(arrChar) + counter + 1]; // ?????????????????????????


	int count = 0;
	for (int i = 0; i <= strlen(arrChar); i++) {
		if (arrChar[i] == findLetter) {
			arrCharNew[count] = 'x';
			arrCharNew[++count] = 'y';
		}
		else {
			arrCharNew[count] = arrChar[i];
		}
		count++;
	}

	for (int i = 0; i < strlen(arrCharNew); i++) {
		std::cout << *(arrCharNew+i);
	}
	//std::cout << arrCharNew;
}



void cw3() {
	/*Заменить удвоенные символы на один (bb на b)и*/



	char arrChar[30] = "kbbklkjbkkljbblkjkjlljbklj";
	int lenArrChar = strlen(arrChar);
	int lenArrCharNew = lenArrChar;
	
	char findLetter = 'b';

	for (int i = 0; i < strlen(arrChar) - 1; i++) {
		if (arrChar[i] == findLetter) {
			if (arrChar[i+1] == findLetter) {
				lenArrCharNew--;
			}
		}
	}



	char* arrCharNew = new char[lenArrCharNew + 1];

	int count = 0;
	for (int i = 0; i <= strlen(arrChar); i++) {
		if (arrChar[i] == findLetter) {
			if (arrChar[i + 1] == findLetter) {
				arrCharNew[count] = findLetter;
				i++;
			}
			else {
				arrCharNew[count] = findLetter;
			}
		}
		else {
			arrCharNew[count] = arrChar[i];
		}
		count++;
	}

	std::cout << arrCharNew;
}











































/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void cw3_2() {
	/*Заменить удвоенные символы на один (bb на b)и*/



	char arrChar[30] = "aajddjjvndooofkddkddd";
	int lenArrChar = strlen(arrChar);
	int lenArrCharNew = lenArrChar;

	char findLetter = 'b';

	for (int i = 0; i < strlen(arrChar); i++) {
		if (arrChar[i] == arrChar[i+1]) {
			lenArrCharNew--;
		}
	}



	char* arrCharNew = new char[lenArrCharNew + 1];

	int count = 0;
	for (int i = 0; i <= strlen(arrChar); i++) {
		if (arrChar[i] == arrChar[i + 1]) {
			arrCharNew[count] = arrChar[i];
			i++;
		}
		else {
			arrCharNew[count] = arrChar[i];
		}
		count++;
	}

	std::cout << arrCharNew;
}









void cw4() {
	//Заменить все пробелы на табуляцию
	char arrChar[20] = "haa kjaa aaa adk ka";
	char findChar = ' ';
	char replaceChar = '\t';

	while (strchr(arrChar, findChar)) {
			*strchr(arrChar, findChar) = replaceChar;
		
	}

	std::cout << arrChar;
}


void cw5() {
	//
	char arrChar[30] = "qweASDйцуФЫВ123!@#";
	int countL = 0;
	int countD = 0;
	int countS = 0;


	for (int i = 0; i < strlen(arrChar); i++) {
		if (arrChar[i] >= 'a' && arrChar[i] <= 'z') {
			countL++;
		}
		else if (arrChar[i] >= 'A' && arrChar[i] <= 'Z') {
			countL++;
		}
		else if (arrChar[i] >= 'а' && arrChar[i] <= 'я') {
			countL++;
		}
		else if (arrChar[i] >= 'А' && arrChar[i] <= 'Я') {
			countL++;
		}
		else if (arrChar[i] >= '0' && arrChar[i] <= '9') {
			countD++;
		}
		else {
			countS++;
		}


	}

	std::cout << arrChar << std::endl;

	std::cout << "Letter amount: " << countL << std::endl;
	std::cout << "Digits amount: " << countD << std::endl;
	std::cout << "Symbols amount: " << countS << std::endl;

}


int main() {
	setlocale(0, "");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);


	//test();

	//task1();

	//testt();

	//task2();
	//task3();






	//h_task1();
	//h_task2();
	//h_task3();
	//h_task4();
	//h_task5();


	//cw1();
	//cw1_2();

	//cw2();
	//cw3();
	//cw3_2();
	//cw4();
	cw5();

	return 0;
}