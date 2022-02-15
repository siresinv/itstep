// STEP _CPP _classwork8 _11.02.22 _task4
// Массивы

#include <iostream>
#include <stdlib.h>
#include <time.h>


int main()
{
	setlocale(0, "");
	srand(time(NULL));

	const int  arrSize = 10;
	int arr[arrSize];
	int negativeSum;

	/*
	int arr[n];
	int arr2[n] = { 1,2,3,4,5 };
	int arr3[n] = { 1,2 }; //остаток нулями
	int arr4[] = { 1,2,3,4,5,4,3,5 }; // здесь лишнее отбросит
	*/

	for (int i = 0; i < arrSize-1; i++)
	{
		arr[i] = rand() % 11 - 5; // !!! 11 - диапазон   -5 - с какого чмсла начинать !!!
	}
	
	for (int i = 0; i < arrSize - 1; i++)
	{
		std::cout << arr[i] << " ";
	}

	negativeSum = 0;
	for (int i = 0; i < arrSize - 1; i++)
	{
		/*
		if (arr[i] < 0) {
			negativeSum += arr[i];
		} 
		*/

		(arr[i] < 0) ? negativeSum += arr[i]:123; // fasle true 0 1 - пофигу тут что написать вместо 123 !!!??? )))
		//continue;

	}

	std::cout << std::endl;
	std::cout << negativeSum;

	return 0;

}

