// STEP _CPP _homework19 _15.04.22 _task2
/*
в картинке
*/



#include <iostream>

//using namespace std;

const int SIZE_ARR1 = 5;
const int SIZE_ARR2 = 3;



void showArr(int* arr, int sizeArr) {
    for (int i = 0; i < sizeArr; i++) {
        std::cout << *(arr + i) << " ";
    }
}

void join2Arr(int* arr1, int* arr2, int* arr3) {
    for (int i = 0; i < SIZE_ARR1 + SIZE_ARR2; i++) {
        if (i < SIZE_ARR1) {
            *(arr3 + i) = *(arr1 + i);
        }
        else {
            *(arr3 + i) = *(arr2 + i - SIZE_ARR1);
        }
    }
}


void Arr1AndArr2(int* arr1, int* arr2, int* arr3) {
    for (int i = 0; i < SIZE_ARR1; i++) {
        for (int j = 0; j < SIZE_ARR2; j++) {
            if (*(arr2 + j) == *(arr1 + i)) {
                *(arr3++) = *(arr2 + j);
                break;
            }
        }
    }
}


void Arr1DiffArr2(int* arr1, int* arr2, int* arr3) {
    bool isElement;
    for (int i = 0; i < SIZE_ARR1; i++) {
        isElement = false;
        for (int j = 0; j < SIZE_ARR2; j++) {
            if (*(arr1 + i) == *(arr2 + j)) {
                isElement = true;
                break;
            }
        }
        if (isElement == false) {
            *(arr3++) = *(arr1 + i);
        }
        
    }
}


void Arr2DiffArr1(int* arr1, int* arr2, int* arr3) {
    bool isElement;
    for (int i = 0; i < SIZE_ARR2; i++) {
        isElement = false;
        for (int j = 0; j < SIZE_ARR1; j++) {
            if (*(arr2 + i) == *(arr1 + j)) {
                isElement = true;
                break;
            }
        }
        if (isElement == false) {
            *(arr3++) = *(arr2 + i);
        }

    }
}


void Arr1XorArr2(int* arr1, int* arr2, int* arr3) {
    join2Arr(arr1, arr2, arr3);
}



int main()
{


    int arr1[SIZE_ARR1] = { 12,23,34,45,56 };
    int arr2[SIZE_ARR2] = { 1,2,45 };
    int arr3[SIZE_ARR1 + SIZE_ARR2];

    std::cout << "arr1: \t\t";
    showArr(arr1, SIZE_ARR1);
    std::cout << std::endl;

    std::cout << "arr2: \t\t";
    showArr(arr2, SIZE_ARR2);
    std::cout << std::endl;

    std::cout << "join2Arr: \t";
    join2Arr(arr1, arr2, arr3);
    showArr(arr3, SIZE_ARR1 + SIZE_ARR2);
    std::cout << std::endl;

    int arr4[SIZE_ARR1 + SIZE_ARR2] = {};
    std::cout << "Arr1AndArr2: \t";
    Arr1AndArr2(arr1, arr2, arr4);
    showArr(arr4, SIZE_ARR1 + SIZE_ARR2);
    std::cout << std::endl;

    int arr5[SIZE_ARR1 + SIZE_ARR2] = {};
    std::cout << "Arr1DiffArr2: \t";
    Arr1DiffArr2(arr1, arr2, arr5);
    showArr(arr5, SIZE_ARR1 + SIZE_ARR2);
    std::cout << std::endl;

    int arr6[SIZE_ARR1 + SIZE_ARR2] = {};
    std::cout << "Arr2DiffArr1: \t";
    Arr2DiffArr1(arr1, arr2, arr6);
    showArr(arr6, SIZE_ARR1 + SIZE_ARR2);
    std::cout << std::endl;

    int arr7[SIZE_ARR1 + SIZE_ARR2] = {};
    std::cout << "Arr1XorArr2: \t";
    Arr1XorArr2(arr5, arr6, arr7);
    showArr(arr7, SIZE_ARR1 + SIZE_ARR2);
    std::cout << std::endl;

    return 0;
}
