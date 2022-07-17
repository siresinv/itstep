// STEP _CPP _selfwork43 _17.07.22 - templates
/*

*/


#include <iostream>
#include <string>


template <class T>
void getValue(std::string prompt, T& value) {

	std::cout << prompt;
	std::cin >> value;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Error... try again" << std::endl;

		std::cout << prompt;
		std::cin >> value;
	}

	std::string endLine;
	getline(std::cin, endLine);

}


int main()
{

	int number;
	getValue("Enter number: ", number);


	std::string name;
	getValue("Enter name: ", name);

	return 0;
}

