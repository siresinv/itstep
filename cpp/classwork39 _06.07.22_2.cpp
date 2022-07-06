// STEP _CPP _classwork39 _06.07.22_2
/*
ООП НАЧАЛО


констр перемещен
ссылки l- r - value
перегрузка квадр и кругл скобок

*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int gold = 0;
int silver = 1;
int bronze = 2;

class MedalRow {
    char country[4];
    int medals[3];

public:
    MedalRow(const char* uCountry, int* uMedals) {
        strcpy(country, uCountry);

        uCountry ? strcpy(country, uCountry) : strcpy(country, "NON");

        for (int i = 0; i < 3; i++) {
            medals[i] = uMedals ? uMedals[i] : 0;
        }
    }



    MedalRow() : MedalRow{ nullptr, nullptr } {};

    void print() const{

        for (int i = 0; i < 3; i++) {
            std::cout << medals[i] << " ";
        }
        std::cout << std::endl;
    }




    //перегрузить []

};




int main()
{

    MedalRow m1;
    m1.print();
    MedalRow m2{ "RUS", new int[3]{1,3,2} };
    m2.print();

    return 0;
}



