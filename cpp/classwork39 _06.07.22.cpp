// STEP _CPP _classwork39 _06.07.22
/*
ООП НАЧАЛО


констр перемещен
ссылки l- r - value
перегрузка квадр и кругл скобок

*/


#include <iostream>


class DynMas {
    int* arr;
    int size;
public:
    explicit DynMas(int usize) : arr{ new int[usize] }, size{ usize }
    {
        std::cout << "Constructor for " << this << "\n";
    };

    explicit DynMas(const DynMas& obj) : arr{ new int[obj.size] }, size{ obj.size }
        //explicit -- защита от неявных преобразований
    {
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }

        //this->arr = obj.arr;

        std::cout << "Copy constructor for " << this << "\n";
    };




    explicit DynMas(DynMas&& obj) : arr{ obj.arr }, size{ obj.size }
        //explicit -- защита от неявных преобразований
    {
        obj.arr = nullptr;
        obj.size = 0;
        std::cout << "Move constructor for " << this << "\n";
    };


    DynMas& operator=(DynMas&& obj) {
        if (this != &obj) {
            //
            if (arr) {
                delete[] arr;
                arr = nullptr;
            }
            arr = obj.arr;
            // size { obj.size }; - мы не инициализируем а просто присваиваем указатели
            size = obj.size;

            obj.arr = nullptr;
            obj.size = 0;
            std::cout << "Move constructor for " << this << "\n";
        }
        
        return *this;
    }


    ~DynMas()
    {
        if (arr) {
            delete[] arr;
        }
        std::cout << "Destructor for " << this << "\n";
    }
    int getSize() const
    {
        return size;
    }
    void randomize()
    {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 10;
        }
    }
    void print(int i) const
    {

        std::cout << arr[i] << "  ";
        //cout << "\n";

    }

    void print() const
    {
        for (int i = 0; i < size; i++) {
           std::cout << arr[i] << "  ";
        }
        std::cout << "\n";
    }


    DynMas& operator=(const DynMas& obj) {
        if (this != &obj) {
            if (size != obj.size) {
                delete[] arr;
                arr = new int[obj.size];
                size = obj.size;
            }
            for (int i = 0; i < size; i++) {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }


    int operator[] (int id) const {
        return arr[id];
    }

    int& operator[] (int id) {
        return arr[id];
    }

};



int main()
{

    /*DynMas dm{ 5 };
    dm.randomize();
    dm.print();*/


    /*
    int x = 5;
    int& rx = x;
    const int& rxx = x;
    const int& rxxx = x + 20;
    x = 50;
    std::cout << x << " " << rx << " " << rxx << " " << rxxx;

    int& rx_2 = x; // l-value - ссылка на объект у которого есть имя
    int&& ref = x + 10; // since C++ 11 r-value - ссылка на безымянный объект

    // int&& r = x; // Нельзя - т.к. x - это имя
    int&& r2 = 10; // можно
    //int&& r = ref; // Нельзя - т.к. ref - это имя
    int& r = ref; // можно

    int&& r = std::move(ref);
    */

    DynMas d1{ 10 };
    d1.randomize();
    d1.print();

    DynMas d2{ d1 };
    //d2.print();
    //d1.print();

    DynMas d3{std::move(d1)};
    //d3.print();
    //d1.print();


    DynMas d4{ 10 };
    d4.randomize();
    d4.print();
    
    d1 = std::move(d4);
    std::cout << "d1 - after move from d4: ";
    d1.print();
    std::cout << "d4 - after move to d1: ";
    d4.print();

    std::cout << std::endl;
    d4 = d1;
    std::cout << "d4 - after d4 = d1: ";
    d4.print();

    d1[1] = 10;
    d1.print();
    std::cout << std::endl;
    std::cout << d1[5];
    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}



