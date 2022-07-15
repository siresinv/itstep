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
    Array(int sizeArr): sizeArr{ sizeArr } {
        arr = new int[this->sizeArr];
        nElem = 0;
    }

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
            arr = new int[this->sizeArr];
        }
    }

    void doEmpty() {
        nElem = 0;
    }

    int getAt(int id) {
        return arr[id];
    }

    int& setAt(int id) {
        if (id<sizeArr && id >=0) {
            return arr[id];
        }
    }

    const int operator[](int id) const {
        return arr[id];
    }


    int& operator[](int id) {
        return arr[id];
    }

    Array getData() {
        return *arr;
    }


    Array& insertAt(int elem, int id) {
        if (!isFull()) {
            for (int i = nElem; i < id; i--) {
                arr[i + 1] = arr[i];
            }
            arr[id] = elem;
        }
        nElem++;
    }

    Array& removetAt(int id) {
        if (!isFull()) {
            for (int i = id; i <= nElem; i++) {
                arr[i] = arr[i+1];
            }
            arr[nElem] = 0;
            nElem--;
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
        }
    }

    void freeExtra() {
        if (arr) {
            int* temp = new int[nElem];

            for (int i = 0; i < nElem; i++) {
                temp[i] = arr[i];
            }

            delete[]arr;
            arr = nullptr;

            int* arr = new int[nElem];

            for (int i = 0; i < nElem; i++) {
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


    Array appendArr(const Array& obj1, const Array& obj2) {
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
    }


    Array& operator=(const Array& obj2) {
        if (this != &obj2) {
            if (sizeArr != obj2.sizeArr) {
                delete[]arr;
                arr = nullptr;
            }
            sizeArr = obj2.sizeArr;
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

    Array arr3;
    appendArr(arr1, arr2);
    std::cout << std::endl;
    std::cout << std::endl;
    arr3.print();

    return 0;
}

