// STEP _CPP _classwork29 _30.05.22 _task2
/*

СТРОКИ


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


struct iron{
	char mark[20];
	char model[20];
	char color[20];
	int minTemp;
	int maxTemp;
	bool steam;
	int power;
};


iron createIron() {
	iron iron1 = { "UTUG", "utug200", "black", 100, 500, true, 2000 };
	return iron1;
}





void createIron_2(char mark[], char* model, char color[], int minTemp, int maxTemp, bool steam, int power) {
	//iron iron2 = { mark, model, color, minTemp, maxTemp, steam, power };
	iron iron2;
	////////////////////////////////////////////////////////////// КАК ЧАР ЗАПИСАТЬ
	iron2.mark = mark[];
	iron2.minTemp = 100;
}





void showIron(iron iron1) {
	std::cout << iron1.mark << std::endl;
	std::cout << iron1.model << std::endl;
	std::cout << iron1.color << std::endl;
	std::cout << iron1.minTemp << std::endl;
	std::cout << iron1.maxTemp << std::endl;
	std::cout << ((iron1.steam)?"с паром":"без пара") << std::endl;
	std::cout << iron1.power << std::endl;
}

int main() {
	setlocale(0, "");
	

	//iron iron1 = createIron();
	iron iron2;
	char mark[20] = "UTUG";
	char model[20] = "utug200";
	char color[20] = "black";
	createIron_2(mark, model, color, 100, 500, true, 2000);
	showIron(iron2);

	return 0;
}