#pragma once
#include <iostream>

class Student
{
private:
	char name[20];
	int marks[3];

public:
	double getAvr();
	void initStudent(const char* name1, const int* marks1);
	void printStudent();
	
	void setName(const char* name1) {
		strcpy_s(name, name1);
	}
	/*const*/char* getName() {
		return name;
	}

	void setMakr(int mark, int markId) {
		marks[markId] = mark;
	}

	int getMakr(int markId) {
		return marks[markId];
	}
};