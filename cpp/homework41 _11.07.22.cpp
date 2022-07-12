// STEP _CPP _homework41 _11.07.22
/*
ООП НАЧАЛО


//String
//практика
//шаблоны
//динамические структуры стек, очередь

посмотреть КОДИРОВКИ
СТРИНГ


В ДОМАШКУ - ДОБИТЬ - БЕЗ УЧЕТА РЕГИСТРА

*/

#include <algorithm>
//#include <string>
#include <iostream>



int countAll(std::string where, std::string what) {
    int count = 0;
    int pos = where.find(what);
    while (pos != -1) {
        count++;
        pos = where.find(what, pos + 1);
    }
    return count;
}



std::string toLowerCase(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}



int* findAll(std::string where, std::string what, int& count) {

    std::transform(where.begin(), where.end(), where.begin(), tolower);
    std::transform(what.begin(), what.end(), what.begin(), tolower);

    /*where = toLowerCase(where);
    what = toLowerCase(what);*/

    count = countAll(where, what);
    if (count == 0) {
        return nullptr;
    }
    else {
        int* array = new int[count];
        int pos = -1;
        for (int i = 0; i < count; i++) {
            pos = where.find(what, pos + 1);
            array[i] = pos;
        }
        return array;
    }
}


void display(int* items, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::string word;
    std::string text{ "Jingle bells, jingle bells,\n\
            Jingle all the way.\n\
            Oh!what fun it is to ride\n\
            In a one - horse open sleigh.Hey!\n\
            Jingle bells, jingle bells,\n\
            Jingle all the way;\n\
            Oh!what fun it is to ride\n\
            In a one - horse open sleigh" };


    std::cout << "In text: \n\n" << text << std::endl;

    std::cout << "search word: ";
    std::cin >> word;

    int count;
    int* pos = findAll(text, word, count);
    display(pos, count);
    std::cout << std::endl;

    std::cout << "Original text: \n\n" << text << std::endl;

    return 0;
}



