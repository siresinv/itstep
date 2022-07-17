// STEP _CPP _classwork43 _15.07.22
/*
ООП

*/


#include <iostream>







class Array {
    int* arr;
    int sizeArr;
    int nElem;
public:
    Array(int sizeArr) : sizeArr{ sizeArr }, arr{ new int[sizeArr] }, nElem{ 0 } {};

    Array() :Array(10){};

    ~Array() {
        if (arr) {
            delete[]arr;
            arr = nullptr;
        }
    }

    int getSize() {
        return sizeArr;
    }

    int getUpperBound() {
        return nElem - 1;
    }

    bool isEmpty() {
        return !nElem;
    }

    bool isFull() {
        return nElem == sizeArr;
    }

    void removeAll() {
        if (arr) {
            delete[]arr;
            arr = nullptr;
            arr = new int[sizeArr];
            nElem = 0;
        }
    }

    void doEmpty() {
        nElem = 0;
    }

    int getAt(int id) {
        return arr[id];
    }

    void setAt(int elem, int id) {
        if (!isEmpty()) {
            if (id < sizeArr && id >= 0) {
                arr[id] = elem;
            }
        }
    }

    const int operator[](int id) const {
        return arr[id];
    }


    int& operator[](int id) {
        return arr[id];
    }

    int* getData() {
        return arr;
    }

    
    void insertAt(int elem, int id) {
        if (!isFull()) {
            if (id <= getUpperBound() + 1) {
                for (int i = getUpperBound(); i >= id; i--) {
                    arr[i + 1] = arr[i];
                }
                arr[id] = elem;
                nElem++;
            }
        }
    }

    
    void removetAt(int id) {
        if (!isEmpty()) {
            if (id <= getUpperBound()){
                for (int i = id; i < nElem; i++) {
                    arr[i] = arr[i + 1];
                }
                arr[nElem] = -1;
                nElem--;
            }
        }
    }

    
    void setSize(int sizeArr, int grow = 1) {

        if (this->sizeArr != sizeArr) {
            
            int* temp = new int[nElem];
            for (int i = 0; i < nElem; i++) {
                temp[i] = arr[i];
            }

            delete[]arr;
            arr = nullptr;
            this->sizeArr = sizeArr + grow;
            arr = new int[this->sizeArr];

            nElem = (sizeArr > nElem) ? nElem : sizeArr;
            
            for (int i = 0; i < nElem; i++) {
                arr[i] = temp[i];
            }

            // arr = temp; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // temp -то наверно удаляется при выходе из функции
        }
    }


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /*
    void setSize(int size, int grow = 1) 
    {
        if (size < sizeArr) {
            while (size < sizeArr) {
                int* temp = new int[size];
                for (int i = 0; i < size; ++i) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                // arr = temp;
                if (nElem > size) {
                    nElem = size;
                }
            }
        }
        else if (size > sizeArr) {
            while (sizeArr < size) {
                sizeArr += grow;
            }
        }
    }
    */

    void freeExtra() {
        if (arr) {
            sizeArr = getUpperBound() + 1;
            int* temp = new int[sizeArr];

            for (int i = 0; i < sizeArr; i++) {
                temp[i] = arr[i];
            }

            

            delete[]arr;
            arr = nullptr;
            
            arr = new int[sizeArr];

            for (int i = 0; i < sizeArr; i++) {
                arr[i] = temp[i];
            }
        }
    }


    void Add(int elem) {
        if (isFull()) {
            setSize(sizeArr + 1);
        }

        arr[getUpperBound() + 1] = elem;
        nElem++;
        
    }


    /*Array appendArr(const Array& obj1, const Array& obj2) {
        Array temp;
        temp.nElem = obj1.nElem + obj2.nElem;
        temp.sizeArr = obj1.sizeArr + obj2.sizeArr;

        for (int i = 0; i < obj1.nElem; i++) {
            temp.arr[i] = obj1[i];
        }

        for (int i = obj1.nElem; i < temp.nElem; i++) {
            temp.arr[i] = obj2[i];
        }

        return temp;
    }*/


    Array& appendArr(const Array& obj2) {

        sizeArr += obj2.sizeArr;
        setSize(sizeArr);

        for (int i = 0; i < (obj2.nElem); i++) {
            arr[nElem + i] = obj2[i];
        }
        nElem += obj2.nElem;
        return *this;
    }


    Array& operator=(const Array& obj2) {
        if (this != &obj2) {
            if (sizeArr != obj2.sizeArr) {
                delete[]arr;
                arr = nullptr;
            }
            
            sizeArr = obj2.sizeArr;
            arr = new int[sizeArr];
            nElem = obj2.nElem;
            for (int i = 0; i < nElem; i++) {
                arr[i] = obj2.arr[i];
            }
        }
        return *this;
    }

    void print() {

        for (int i = 0; i < nElem; i++) {
            std::cout << arr[i] << " ";
        }
        
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }


};

int main()
{

    srand(time(NULL));

    Array arr1;
    arr1.Add(10);
    arr1.Add(11);
    arr1.Add(12);
    arr1.print();

    std::cout << arr1.getSize();
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    std::cout << std::endl;

    Array arr2;
    arr2.Add(20);
    arr2.Add(21);
    arr2.Add(22);
    arr2.print();

    arr1.appendArr(arr2);
    std::cout << std::endl;
    std::cout << std::endl;
    arr1.print();

    std::cout << arr1.getSize();
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    std::cout << std::endl;

    arr1.setSize(15);
    arr1.print();
    std::cout << arr1.getSize();
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    std::cout << std::endl;

    /*arr1.setSize(4);
    arr1.print();
    std::cout << arr1.getSize();
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    std::cout << std::endl;*/

    arr1.freeExtra();
    arr1.print();
    std::cout << arr1.getSize();
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    std::cout << std::endl;


    arr1.setAt(44,3);
    std::cout << std::endl;
    std::cout << arr1.getAt(3);
    std::cout << std::endl;
    arr1.print();
    std::cout << std::endl;
    std::cout << std::endl;


    arr1[4] = 55;
    std::cout << arr1[4];
    std::cout << std::endl;
    arr1.print();
    std::cout << std::endl;
    std::cout << std::endl;


    Array arr3;
    arr3 = arr1;
    arr3.print();
    std::cout << std::endl;
    std::cout << std::endl;

    
    arr1.getData()[5] = 66;
    std::cout << arr1.getData()[5];
    std::cout << std::endl;
    arr1.print();
    std::cout << std::endl;
    std::cout << std::endl;

    arr1.setSize(arr1.getSize() + 1);
    std::cout << arr1.getSize();
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    arr1.insertAt(77,6);
    arr1.print();
    std::cout << std::endl;
    std::cout << std::endl;


    
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    arr1.removetAt(3);
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    arr1.print();
    std::cout << std::endl;
    std::cout << std::endl;
    

    arr1.removeAll();
    std::cout << arr1.getSize();
    std::cout << std::endl;
    std::cout << arr1.getUpperBound();
    std::cout << std::endl;
    arr1.print();


    return 0;

}

// arr = temp; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// temp -то наверно удаляется при выходе из функции и arr уже не понятно на что ссылается ???