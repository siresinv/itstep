// STEP _CPP _homework35 _22.06.22
/*
ООП НАЧАЛО



*/


#include <iostream>

class String {
	char* str;

public:
	String(const char* uStr, int lenStr = 80) : str{ new char [lenStr]} {
		
	}

	String(const char* uStr) : String(uStr, 80) {};
};


int main()
{
	
	return 0;
}

