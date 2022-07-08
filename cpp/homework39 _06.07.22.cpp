// STEP _CPP _homework35 _22.06.22
/*
ООП НАЧАЛО



*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stdio.h>

class String {
	char* str;
	static int strAmount;
	int nChar;

public:
	

	String(const char* uStr, int uLenStr) : str{ new char[uLenStr] } {
		strcpy_s(str, uLenStr, uStr);
		strAmount++;
		nChar = uLenStr;
	}

	String(const char* uStr) : String(uStr, strlen(uStr) + 1) {};
	String(int uLenStr) : String("\0", uLenStr + 1) {};
	String() : String("\0", 81) {};


	String(String&& obj) {
		if (this != &obj) {
			str = obj.str;
			nChar = obj.nChar;
			obj.str = nullptr;
			obj.nChar = 0;
		}
	}

	String& operator=(String&& obj) {
		if (this != &obj) {
			if (str) {
				delete[]str;
				str = nullptr;
			}
			str = obj.str;
			nChar = obj.nChar;
			obj.str = nullptr;
			obj.nChar = 0;
		}
		return *this;
	}



	~String() {
		if (str) {
			delete[] str;
			std::cout << "Worked DESTRUCTOR for string " << strAmount << std::endl;
			--strAmount;
		}
	}

	void setStr() {
		std::cout << "Enter string lenght " << nChar - 1 << ": ";
		gets_s(str, nChar);
	}

	void printStr() {
		std::cout << "\"" << str << "\"" << " - lenght of this string/char_array: " << strlen(str) << "/" << nChar;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	static int getStrAmount() {
		return strAmount;
	}
};


int String::strAmount{ 0 };

int main()
{
	std::cout << "string amount: " << String::getStrAmount();
	std::cout << std::endl;
	std::cout << std::endl;

	String str1;
	String str2("str2");
	String str3(10);
	str1.printStr();
	str2.printStr();
	str3.printStr();

	std::cout << "string amount: " << String::getStrAmount();
	std::cout << std::endl;
	std::cout << std::endl;

	str1.setStr();
	str1.printStr();
	std::cout << std::endl;

	str2.setStr();
	str2.printStr();
	std::cout << std::endl;

	str3.setStr();
	str3.printStr();
	std::cout << std::endl;

	std::cout << "string amount: " << String::getStrAmount();
	std::cout << std::endl;
	std::cout << std::endl;

	//String str4{ std::move(str1) };
	String str4; /// ВЫПОЛНЯЕТСЯ НО С ОШИБКОЙ !!!! /////////////////
	str4 = std::move(str1);
	std::cout << "str4 after move from - ";
	str4.printStr();
	std::cout << std::endl;
	std::cout << "str1 after move to str4- ";
	str1.printStr();


	return 0;
}

