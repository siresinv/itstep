// STEP _CPP _classwork42 _13.07.22
/*
СТЭК
ОЧЕРЕДЬ

*/


#include <iostream>

class Queue {
    int* q;
    int* p;
    int max;
    int real;

public:
    Queue(int size);
    ~Queue();

    void push(int x, int pr);
    void pushPrior(int x, int pr);
    int pop();
    int popPrior();
    void clear();
    bool isEmpty();
    bool isFull();
    int getCount();

    void print() {
        for (int i = 0; i < real; i++) {
            std::cout << q[i] << "-[" << p[i] << "]  ";
        }
        std::cout << std::endl;
    }

    int popRing();

};


Queue::Queue(int size = 5) : q{ new int[size] }, p{ new int[size] }, max{ size }, real{ 0 }{};


Queue::~Queue()
{
    if (q) {
        delete[] q;
        q = nullptr;
    }

    if (p) {
        delete[] p;
        p = nullptr;
    }
}


void Queue::push(int x, int pr)
{
    if (!isFull()) {
        q[real] = x;
        p[real++] = pr;
    }
}



void Queue::pushPrior(int x, int pr) {
    if (!isFull()) {
        int needId = 0;
        for (int i = 0; i < real; i++) {
            if (pr <= p[i]) needId = i + 1;
        }
        real++;
        
        for (int i = real-1; i >= needId; i--) {
            q[i] = q[i-1];
            p[i] = p[i-1];
        }

        q[needId] = x;
        p[needId] = pr;
    }
}


int Queue::pop()
{
    if (!isEmpty()) {
        int elem = q[0];
        int prior = p[0];
        for (int i = 1; i < real; i++) {
            q[i - 1] = q[i];
            p[i - 1] = p[i];
        }
        real--;
        return elem;
    }
}


int Queue::popPrior() {
    if (!isEmpty()) {
        int maxId = 0;
        for (int i = 0; i < real; i++) {
            if (p[i] > p[maxId]) {
                maxId = i;
            }
        }
        int temp = q[maxId];

        for (int i = maxId + 1; i < real; i++) {
            q[i - 1] = q[i];
            p[i - 1] = p[i];
        }
        real--;
        return temp;
    }
    return -1;
}


int Queue::popRing() //void
{
    if (!isEmpty()) {
        int elem = q[0];
        int prior = p[0];
        for (int i = 1; i < real; i++) {
            q[i - 1] = q[i];
            p[i - 1] = p[i];
        }
        q[real - 1] = elem;
        p[real - 1] = prior;
        return elem; //
    }
}


void Queue::clear()
{
    real = 0;
}


bool Queue::isEmpty()
{
    return !real;
}


bool Queue::isFull()
{
    return real == max;
}


int Queue::getCount()
{
    return real;
}


int main()
{
    srand(time(NULL));

    Queue q1{ 20 };

    for (int i = 0; i < 1; i++) {
        q1.pushPrior(rand() % 100 + 1, rand() % 100 + 1);
    }
    q1.print();
    q1.pushPrior(rand() % 100 + 1, rand() % 100 + 1);
    q1.print();
    std::cout << "--------------" << std::endl;
    
    for (int i = 0; i < 3; i++) {
        std::cout << q1.popPrior() << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------" << std::endl;

    q1.print();
    std::cout << "--------------" << std::endl;

    for (int i = 0; i < 5; i++) {
        q1.pushPrior(rand() % 100 + 1, rand() % 100 + 1);
    }
    q1.print();
    std::cout << "--------------" << std::endl;

    q1.pushPrior(45, 45);
    q1.pushPrior(46, 45);
    q1.pushPrior(47, 45);
    q1.pushPrior(48, 45);
    q1.pushPrior(49, 45);
    q1.pushPrior(50, 0);
    q1.pushPrior(51, 100);
    q1.print();
    std::cout << "--------------" << std::endl;


    std::cout << q1.getCount() << std::endl;
    q1.clear();
    std::cout << q1.getCount() << std::endl;

    return 0;
}

// В ДОМАШКУ НАПИСАТЬ pushPrior