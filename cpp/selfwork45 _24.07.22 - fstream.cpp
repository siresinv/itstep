// STEP _CPP _selfwork45 _24.07.22 - fstream
/*

*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main()
{

	string NameFile{ "My File.txt" };

	ofstream fout;
	fout.open(NameFile, ofstream::app);

	if (!fout.is_open()) {
		cout << "ERROR!!!\n";
	}
	else {
		string x;
		cout << "Enter data \n";
		cin >> x;
		fout << x;
		fout << "\n";
		cout << "REC!";
	}

	ifstream fin;

	fin.open(NameFile);
	if (!fin.is_open()) {
		cout << "ERROR!";
	}
	else {
		cout << "File Open\n";
		string str;
		while (!fin.eof()) {
			str = "";

			getline(fin,str);
			cout << str;
		}
	}
	fin.close();

	return 0;
}

