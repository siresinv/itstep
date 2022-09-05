// STEP _CPP _homework54 _31.08.22
/*
ООП

Vector


*/


#include <iostream>
#include <vector>



void print_vector(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\t";
    }
}

int main()
{
    std::vector<int> vNum;
    std::vector<int> vSqNum;

    for (int i = 1; i <= 10; i++) {
        vNum.push_back(i);
    }
    print_vector(vNum);
    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
        vSqNum.push_back(vNum[i] * vNum[i]);
    }
    print_vector(vSqNum);
    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}

