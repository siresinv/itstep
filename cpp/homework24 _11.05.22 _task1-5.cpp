// STEP _CPP _homework24 _11.05.22 _task1-5
/*

СТРОКИ
homework24 _11.05.22.bmp

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



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
	
	int counter = 0;
	for (int i = beginId; i <= endId; i++) {
		*(arrChar2 + counter++) = arrChar[i];
	}
	
	std::cout << arrChar2;

	delete[] arrChar2;
}

void h_task3() {
	const int sizeArr = 11;
	char* arrChar = new char[sizeArr] {};
	
	int beginId;
	int endId;

	std::cout << "Введите строку: ";
	std::cin >> arrChar;
	std::cout << "Удалить с.. по..: " << std::endl;
	std::cout << "Индекс первого символа: ";
	std::cin >> beginId;
	std::cout << "Индекс последнего символа: ";
	std::cin >> endId;

	char* arrTempChar = new char[beginId]{}; // по факту - 1 + 1 -1подБегинАйди +подСлэшНоль
	char* arrTempChar_2 = new char[sizeArr - endId + 1]{};

	int counter = 0;
	for (int i = 0; i < beginId; i++) {
		*(arrTempChar + counter++) = arrChar[i];
	}
	arrTempChar[beginId] ='\0'; // !!!!!!  А НИЖЕ ЦИКЛ ЭТОТ НОЛЬ ИГНОРИРУЕТ - ЭТО ПРАВИЛЬНО

	counter = 0;
	for (int i = endId +1; i < sizeArr; i++) {
		*(arrTempChar_2 + counter++) = arrChar[i];
	}

	strcat(strcpy(arrChar, arrTempChar), arrTempChar_2);

	std::cout << arrChar;

	delete[] arrChar;
}

void h_task4() {
	const int sizeArr = 11;
	char* arrChar = new char[sizeArr] {};
	std::cout << "Введите строку: ";
	std::cin >> arrChar;

	char charSymb;
	std::cout << "Введите символ: ";
	std::cin >> charSymb;

	std::cout << "Номера совпадений: ";
	for (int i = 0; i < strlen(arrChar); i++) {
		if (arrChar[i] == charSymb) std::cout << i + 1 << " ";
	}
}

void h_task5() {
	const int sizeArr = 11;
	char* arrChar = new char[sizeArr] {};
	std::cout << "Введите строку: ";
	std::cin >> arrChar;

	char charSymb;
	std::cout << "Введите символ: ";
	std::cin >> charSymb;

	std::cout << "Номера последнего совпадения: ";
	for (int i = strlen(arrChar); i >= 0; i--) {
		if (arrChar[i] == charSymb) {
			std::cout << i + 1 << " ";
			break;
		}
	}
}

int main() {
	setlocale(0, "");

	//h_task1();
	//h_task2();
	//h_task3();
	//h_task4();
	h_task5();

	return 0;
}