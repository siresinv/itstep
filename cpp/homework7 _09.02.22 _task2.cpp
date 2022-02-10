// STEP _CPP _homework7 _09.02.22 _task2

// Вывод простых чисел от 2 до 1000


#include <iostream>



int main()
{
	setlocale(0, "");
	const int MIN_NUM = 2;
	const int MAX_NUM = 1000;
	bool isSimpleNum;

	std::cout << "Постые числа от " << MIN_NUM << " до " << MAX_NUM <<std::endl;

	int currentNum;
	for (currentNum = MIN_NUM; currentNum <= MAX_NUM; currentNum++) {
		isSimpleNum = true;
		for (int i = MIN_NUM; i <= currentNum / 2; i++) {
			if (currentNum % i == 0){
				isSimpleNum = false;
				break; //
			}
		}
		if (isSimpleNum == true) {
			std::cout << currentNum << " ";
		}
	}
	std::cout << std::endl;





	return 0;

}

