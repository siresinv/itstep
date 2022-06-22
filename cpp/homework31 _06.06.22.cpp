// STEP _CPP _homework31 _06.06.22
/*

ФАЙЛЫ



Запросить у пользователя размер массива
Создать массив, заполнить его
Открыть файл
Записать массив в файл
Закрыть файл

Открыть файл
Узнать сколько элементов в файле
Выделить память под массив, который находится в файле
Записать данные в новый массив

***Массив целых чисел


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>






int main() {

	int sizeArr;
	std::cout << "Enter array size of int number: ";
	std::cin >> sizeArr;

	int* arrNum = new int[sizeArr];

	for (int i = 0; i < sizeArr; i++) {
		*(arrNum+i) = i;
	}

	FILE* f_write;
	FILE* f_read;

	f_write = fopen("homework31 _06.06.22.txt", "w");

	if (!f_write) {
		std::cout << "Error open f_write";
	}
	else {
		for (int i = 0; i < sizeArr; i++) {
			fprintf(f_write, "%d ", arrNum[i]);
		}
	}
	fclose(f_write);
	
	f_read = fopen("homework31 _06.06.22.txt", "r");

	if (!f_read) {
		std::cout << "Error open f_read";
	}
	else {
		int nNum = 0;
		int a;
		while (!feof(f_read)) {
			if (fscanf(f_read, "%d", &a) > 0) { // ???
				nNum++;
			};
		}
		rewind(f_read);

	
		int* arrNum2 = new int[nNum];
		for (int i = 0; i < nNum; i++) {
			fscanf(f_read, "%d", &arrNum2[i]);
		}


		for (int i = 0; i < nNum; i++) {
			std::cout << arrNum2[i] << " ";
		}

	}



	return 0;
}