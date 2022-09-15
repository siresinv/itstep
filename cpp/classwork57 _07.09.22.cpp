// STEP _CPP _classwork57 _07.09.22
/*
ООП

map
multimap


*/


/*
СКРИНШОТЫ НА ТЕЛЕФОНЕ
ДИСКОРД
*/


#include <iostream>
#include <fstream>
#include <map>

int main()
{

    std::ifstream inf("cw57.txt", std::ios::in);
    std::string word;

    if (inf.is_open()) {
        std::cout << "Open";
    }
    else {
        std::cout << "NOT Open";
    }

    int num;

    while (!inf.eof()) {
        inf >> num;
        std::cout << num;
    }

    return 0;
}


