#pragma once


struct fullName{

	char* surname = new char;
	char* name = new char;
	char* patronymic = new char;

};

class hw34_student
{
private:
	fullName nameS;
	int phoneS;
	char* addInfo;


public:

	hw34_student() {
		phoneS = 123;
	}

	~hw34_student(){
		if (nameS.surname) {
			delete[] nameS.surname;
		}
		if (nameS.name) {
			delete[] nameS.name;
		}
		if (nameS.patronymic) {
			delete[] nameS.patronymic;
		}

		if (addInfo) {
			delete[] addInfo;
		}
		
	}

};

