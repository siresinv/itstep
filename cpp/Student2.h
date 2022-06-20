#pragma once
#include <iostream>

struct nameStud {
	char surname[20];
	char name[20];
	char patronymic[20];
};

struct bith{
	int day;
	int month;
	int year;
};


struct unviversity {
	char title[20];
	char city[20];
	char coutry[20];
};

class Student
{
private:
	char* name;
	int* marks;
	int nMarks;

	

	/*nameStud fullName;
	bith bithDay;
	char tel[12];
	char city[20];
	char country[20];
	unviversity university;
	int groupNo;*/

	void createName(const char* name_);

	//int marks[3];

public:
	Student();
	Student(const char*);
	Student(const int*, int);
	Student(const char*, int*, int);


	double getAvr();
	//void initStudent(const char* surname_, const char* name_, const char* patronimyc_, const int* marks1);
	void printStudent();
	
	//void setName(const char* surname_, const char* name_, const char* patronymic_) {
	//	strcpy_s(fullName.name, name_);
	//	strcpy_s(fullName.patronymic, patronymic_);
	//	strcpy_s(fullName.surname, surname_);
	//}

	//nameStud getName() {
	//	return fullName;
	//}

	//void setBithDay(int day, int month, int year) {
	//	bithDay.day = day;
	//	bithDay.month = month;
	//	bithDay.year = year;
	//}

	//bith getBithDay() {
	//	return bithDay;
	//}

	//void setName(const char* name_) {
	//	if (name) {
	//		delete[] name;
	//	}
	//	else {
	//		createName(name_);
	//	}
	//}

	//~Student() {
	//	std::cout << "Destructor process";


	//	// ???
	//	// ???
	//}

	/*void setMakr(int mark, int markId) {
		marks[markId] = mark;
	}*/

	/*int getMakr(int markId) {
		return marks[markId];
	}*/
};