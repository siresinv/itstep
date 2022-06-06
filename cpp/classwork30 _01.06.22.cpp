// STEP _CPP _classwork30 _01.06.22
/*




*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>


struct book {
	int num;
	char name[10];
	char author[10];
	int year;
};


void printBook(book b) {
	std::cout << b.num << " " << b.name << " " << b.author << " " << b.year;
}


void printAll(book* arr) {
	for (int i = 0; i < 3; i++) {
		printBook(arr[i]);
		std::cout << std::endl;
	}
}

void editBook(book &b) {
	b.year = 1960;
}


book searchBook(book* lib, char* str) {
	//std::cout << sizeof(lib->author) << "----";
	for (int i = 0; i < 3; i++) {

		char copy[20];
		strcpy(copy, lib[i].author);
		//if (strstr(_strlwr(lib[i].author), str))  return lib[i];
		if (strstr(_strlwr(copy), _strlwr(str)))  return lib[i];
	}
	//return lib[1];
}


book* sortBooks(book* lib) {
	
	//int nBook = sizeof(lib) / sizeof(book);
	int nBook = 3;
	//std::cout << sizeof(lib) << " - ";
	//std::cout << sizeof(book) << " - " << "                   ";

	book tempBook;

	for (int i = 0; i < nBook; i++) {
		for (int j = i+1; j < nBook; j++) {
			//std::cout << " ++++++++++ ";
			if (strcmp(lib[i].author, lib[j].author) > 0) {
				
				tempBook = lib[j];
				lib[j]= lib[i];
				lib[i] = tempBook;
			}
		}
	}

	return lib;
}


int main() {
	setlocale(0, "");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	book lib[3] = { {1, "it", "bKing", 1980},
					{2, "He", "cStiv", 1970},
					{3, "He", "aStiv", 1970} };

	printBook(lib[1]);
	std::cout << std::endl;
	printAll(lib);
	editBook(lib[1]);
	printAll(lib);

	char sBook[] = "kIN";
	std::cout << "--------------------" << std::endl;
	printBook(searchBook(lib, sBook));
	std::cout << std::endl;
	

	std::cout << "--------------------" << std::endl;
	sortBooks(lib);
	printAll(lib);
	//std::cout << sizeof(lib);


	return 0;
}