// STEP _CPP _homework55 _02.09.22
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
  
    std::vector<int> vect;
    std::cout << vect.capacity() << " " << vect.size() << std::endl;
    std::cout << vect.max_size() / sizeof(int) << std::endl;


    vect.push_back(5);
    print_vector(vect);
    std::cout << std::endl;
    std::cout << vect.capacity() << " " << vect.size() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 28; i++) {
        vect.push_back(rand()%10);
    }
    print_vector(vect);
    std::cout << std::endl;

    std::cout << vect.capacity() << " " << vect.size() << std::endl;
    std::cout << std::endl;


    std::cout << vect.empty();
    std::cout << std::endl;
    std::cout << vect.capacity() << " " << vect.size() << std::endl;
    std::cout << std::endl;

    //vect.clear();
    std::cout << vect.empty();
    std::cout << std::endl;
    std::cout << vect.capacity() << " " << vect.size() << std::endl;
    std::cout << std::endl;


    //
    //
    //


    std::vector<int> vect2( 5,7 );
    print_vector(vect2);
    std::cout << std::endl;
    std::cout << vect2.capacity() << " " << vect2.size() << std::endl;
    std::cout << std::endl;

    vect.swap(vect2);

    print_vector(vect);
    std::cout << std::endl;
    std::cout << vect.capacity() << " " << vect.size() << std::endl;
    std::cout << std::endl;
    print_vector(vect2);
    std::cout << std::endl;
    std::cout << vect2.capacity() << " " << vect2.size() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    try {
        std::cout << vect.at(6) << std::endl;
    }
    catch (const std::exception&) {
        std::cout << "Error";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //
    //
    //

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

    std::vector<int>::iterator iter = vect.begin();
    vect.insert(iter + 2, 111);
    print_vector(vect);

    //vect.insert

    /*
    for (riter = v.rend(); riter != v.rbegin(); riter--) {
        std::cout << *(riter - 1); // - 1 ////////////////////////////////////
    }
    */

    
    /*Заполнить двухмерный вектор таблицей умножения и вывести его*/
    // в скриншоте
    // двойным пушбэком еще сделать

    std::vector<int*> vect5;

    for (int i = 1; i <= 10; i++) {
        
        vect5.push_back();
    }



    /*
    Описать класс «студент» с полями: имя, фамилия, курс. Написать функцию заполнения вектора из класса
«студент» произвольными данными. Написать функцию
печати содержимого вектора. Отсортировать вектор
по именам студентов по возрастанию. (Отсортировать
стабильно вектор по фамилиям студентов.) После каждой операции
выводить список студентов в выходной поток.


=>
Описать класс «студент» с полями: имя, фамилия, курс. Написать функцию заполнения вектора из класса
«студент» произвольными данными. Написать функцию
печати содержимого вектора. Отсортировать вектор
по именам студентов по возрастанию.  После каждой операции
выводить список студентов в выходной поток.

*/


    return 0;
}

