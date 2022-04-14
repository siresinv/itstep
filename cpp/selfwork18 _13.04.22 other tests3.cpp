// STEP _CPP _selfwork18 _13.04.22 other tests3

#include <iostream>


void arrArr(double* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << (arr+i) << " ";
	}
}



int main() {

	double arr[5] = { 1, 2, 3, 4, 5 };

	arrArr(arr, 5);

}


