#pragma once
#include <iostream>

struct name {
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
	name fullName;
	bith bithDay;
	char tel[12];
	char city[20];
	char country[20];
	unviversity university;
	int groupNo;


	int marks[3];

public:
	double getAvr();
	void initStudent(const char* name_, const char* surname_, const char* patronimyc_, const int* marks1);
	void printStudent();
	
	void setName(const char* surname_, const char* name_, const char* patronymic_) {
		strcpy_s(fullName.name, name_);
		strcpy_s(fullName.patronymic, patronymic_);
		strcpy_s(fullName.surname, surname_);
	}

	name getName() {
		return fullName;
	}

	void setBithDay(int day, int month, int year) {
		bithDay.day = day;
		bithDay.month = month;
		bithDay.year = year;
	}

	bith getBithDay() {
		return bithDay;
	}


	void setMakr(int mark, int markId) {
		marks[markId] = mark;
	}

	int getMakr(int markId) {
		return marks[markId];
	}
};