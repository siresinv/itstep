// STEP _CPP _classwork31 _06.06.22
/*




*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h> //<fstream>


struct elem {
	char name[20];
	int id;
	float price;
};



int main() {

	//char[20];
	// cin 

	/*int a = 5;
	int a;
	a = 5;*/

	int arr[5] = { 1,2,3,4,5 };

	//FILE* f = fopen("C:\\Users\\user\\source\\repos\\siresinv\\itstep\\cpp\\classwork31 _06.06.22.txt", "w");
	//// r w a r+ w+ a+ 

	//if (f == nullptr) {
	//	std::cout << "Error";
	//}
	//else {
	//	std::cout << "OK";

	//	for (int i = 0; i < 5; i++) {
	//		fprintf(f, "%d ", arr[i]);
	//	}
	//	fprintf(f, "\n");
	//	fclose(f);
	//}
	

	//int x;
	elem x;
	FILE* f = fopen("C:\\Users\\user\\source\\repos\\siresinv\\itstep\\cpp\\classwork31 _06.06.22.txt", "r");
	// r w a r+ w+ a+ 

	if (f == nullptr) {
		std::cout << "Error";
	}
	else {
		std::cout << "OK";

		/*for (int i = 0; i < 5; i++) {
			fscanf(f, "%d", &x);
			std::cout << x << " ";
		}
		fclose(f);*/

		//while (!feof(f)) {
		//	fscanf(f, "%d ", &x);
		//	std::cout << x << " ";
		//	//x = 0;
		//}

		fscanf(f, "%s", x.name);
		fscanf(f, "%d", &x.id);
		fscanf(f, "%f", &x.price);

		std::cout << x.name << " " << x.id << " " << x.price;

		fclose(f);

	}

	return 0;
}