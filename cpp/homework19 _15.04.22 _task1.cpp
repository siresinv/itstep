// STEP _CPP _homework19 _15.04.22 _task1
/*
в картинке
*/



#include <iostream>

//using namespace std;

const int SIZE_ARR1 = 5;
const int SIZE_ARR2 = 3;



void showArr(int *arr, int sizeArr){
    for(int i = 0; i < sizeArr; i++){
        std::cout << *(arr + i) << " ";
    }
}

void join2Arr(int *arr1, int *arr2, int *arr3){
    for(int i = 0; i < SIZE_ARR1 + SIZE_ARR2; i++){
        if(i < SIZE_ARR1){
            *(arr3+i) = *(arr1+i);
        }
        else{
            *(arr3+i) = *(arr2+i - SIZE_ARR1);
        }
    }
}


void bubleSort (int *arr){
    int temp;
    for(int i = 0; i < SIZE_ARR1 + SIZE_ARR2; i++){
        for(int j = i+1; j < SIZE_ARR1 + SIZE_ARR2; j++){
            if(*(arr+i) > *(arr+j)){
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
}



int main()
{


    int arr1[SIZE_ARR1] = {12,23,34,45,56};
    int arr2[SIZE_ARR2] = {1,50,90};
    int arr3[SIZE_ARR1 + SIZE_ARR2];
    
    std::cout << "arr1: ";
    showArr(arr1, SIZE_ARR1);
    std::cout << std::endl;
    
    std::cout << "arr2: ";
    showArr(arr2, SIZE_ARR2);
    std::cout << std::endl;
    
    std::cout << "arr3: ";
    join2Arr(arr1, arr2, arr3);
    showArr(arr3, SIZE_ARR1+SIZE_ARR2);
    std::cout << std::endl;
    
    std::cout << "sort: ";
    bubleSort(arr3);
    showArr(arr3, SIZE_ARR1+SIZE_ARR2);
    std::cout << std::endl;
    
    return 0;
}
