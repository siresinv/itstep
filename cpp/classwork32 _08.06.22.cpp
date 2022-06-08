// STEP _CPP _classwork32 _08.06.22
/*

*/


/* task1
fgets(char * s, int n, FILE * f); 
fputs(char * s, FILE * f);
Задание 1. Дан текстовый файл. Необходимо создать
новый файл, в который переписать из исходного файла
все слова, состоящие не менее чем из семи букв.
*/

/* task2
Задание 4. Дан текстовый файл. Добавить в него строку
из двенадцати черточек (------------), поместив ее после
последней из строк, в которых нет пробела. 

Если таких строк нет, то новая строка должна быть добавлена после
всех строк имеющегося файла. Результат записать в другой файл.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h> //<fstream>
#include <string.h>


void task1() {
	char str[100];
	FILE* f1 = fopen("C:\\Users\\user\\source\\repos\\siresinv\\itstep\\cpp\\classwork32 _08.06.22_1.txt", "r");
	// r w a r+ w+ a+ 
	FILE* f2 = fopen("C:\\Users\\user\\source\\repos\\siresinv\\itstep\\cpp\\classwork32 _08.06.22_2.txt", "w");


	if (f1 == nullptr || f2 == nullptr) {
		std::cout << "Error";
	}
	else {
		std::cout << "OK";
		fscanf(f1, "%s", str);

		while (!feof(f1)) {
			fscanf(f1, "%s", str);
			if (strlen(str) >= 7) {
				fprintf(f2, "%s ", str);
			}
		}
		fclose(f1);
		fclose(f2);
	}
}

void task2() {
	char str[100];

	FILE* f1 = fopen("C:\\Users\\user\\source\\repos\\siresinv\\itstep\\cpp\\classwork32 _08.06.22_1.txt", "r");
	// r w a r+ w+ a+ 
	FILE* f2 = fopen("C:\\Users\\user\\source\\repos\\siresinv\\itstep\\cpp\\classwork32 _08.06.22_2.txt", "a");



	if (f1 == nullptr || f2 == nullptr) {
		std::cout << "Error";
	}
	else {
		std::cout << "OK";

		int strCounter = 0;
		int strWSCounter = 0;
		while (!feof(f1)) {
			strCounter++;
			fgets(str, 100, f1);
			if (strchr(str, ' ')) {
				strWSCounter = strCounter;
			}
		}
		
		//fclose(f1);
		//FILE* f1 = fopen("C:\\Users\\user\\source\\repos\\siresinv\\itstep\\cpp\\classwork32 _08.06.22_1.txt", "r");
		// see
		fseek(f1, 0, 0);

		if (strCounter > 0) {
			int strCounter2 = 0;
			while (!feof(f1)) {
				strCounter2++;
				fgets(str, 100, f1);
				fputs(str, f2);
				if (strCounter2 == strWSCounter) {
					fputs("---", f2);
				}
				fputs("\n", f2);
			}
		}
		else {
			while (!feof(f1)) {
				fgets(str, 100, f1);
				fputs(str, f2);
				fputs("---", f2);
				fputs("\n", f2);
			}
		}


		fclose(f1);
		fclose(f2);
	}
}

int main() {

	//task1();
	task2();


	return 0;
}