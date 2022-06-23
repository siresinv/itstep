#pragma once
#include <string.h>


struct fullName{
	char* surname;
	char* name;
	char* patronymic;
};

class hw34_subscribe
{
private:
	fullName nameS;
	int phoneS;
	char* addInfoS;


public:
	void printSubs();

	hw34_subscribe(const char* surnameU, const char* nameU, const char* patronymicU) {
		nameS.surname = new char[strlen(surnameU)+1];
		nameS.name = new char[strlen(nameU)+1];
		nameS.patronymic = new char[strlen(patronymicU)+1];

		strcpy_s(nameS.surname, strlen(surnameU)+1, surnameU);
		strcpy_s(nameS.name, strlen(nameU)+1, nameU);
		strcpy_s(nameS.patronymic, strlen(patronymicU)+1, patronymicU);
		phoneS = 8342;
		addInfoS = new char[10]{ "Subscribe" };
	}

	hw34_subscribe(const char* surnameU, const char* nameU, const char* patronymicU, int phoneU, const char* addInfoU) {
		nameS.surname = new char[strlen(surnameU) + 1];
		nameS.name = new char[strlen(nameU) + 1];
		nameS.patronymic = new char[strlen(patronymicU) + 1];

		strcpy_s(nameS.surname, strlen(surnameU) + 1, surnameU);
		strcpy_s(nameS.name, strlen(nameU) + 1, nameU);
		strcpy_s(nameS.patronymic, strlen(patronymicU) + 1, patronymicU);
		phoneS = phoneU;
		addInfoS = new char[strlen(addInfoU) + 1];
		strcpy_s(addInfoS, strlen(addInfoU) + 1, addInfoU);
	}

	~hw34_subscribe(){
		if (nameS.surname) {
			delete[] nameS.surname;
		}
		if (nameS.name) {
			delete[] nameS.name;
		}
		if (nameS.patronymic) {
			delete[] nameS.patronymic;
		}

		if (addInfoS) {
			delete[] addInfoS;
		}
	}

};

