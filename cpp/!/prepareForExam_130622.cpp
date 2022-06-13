#define SUM(a,b) a+b
#include <iostream>
#include <stdio.h>


int main() {

	char a[5]{ "Hkju" };
	//a = {'h'};

	char* b = new char[33]{"Helldfghdfo"};

	char** b1 = new char*[33];
	b1[0] = new char[20] { "asdsadff" };

	//std::cout << sizeof(a)/sizeof(a[0]);

	//std::cout << SUM(5, 6);


	int c[2][3]{ {1,2,3},{4,5,6} };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << c[i][j] << " ";
		}
	}

	int** arr = new int*[2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new int[3];
	}

	//int** arr = new int* [2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new int[3];
	}

	




	char month[12][10] = {
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
	};

	//char** month1 = new char*[20][20]{ //так почему-то нельзя? - типа за один раз?)
	//"January", "February", "March",
	//"April", "May", "June",
	//"July", "August", "September",
	//"October", "November", "December"
	//};

	FILE* f;

	f = fopen("test", "r");



	return 0;
}