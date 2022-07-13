// STEP _CPP _classwork42 _13.07.22
/*
СТЭК
ОЧЕРЕДЬ

*/


#include <iostream>

/*

class Stack {
    int st[20];
    int top;

public:
    Stack();
    void push(int x);
    int pop();
    void clear();
    bool isEmpty();
    bool isFull();
    int getCount();


    void print() {
        for (int i = 0; i < top; i++) {
            std::cout << st[i] << " ";
        }
        std::cout << std::endl;
    }

};

Stack::Stack()
{
    top = 0;
}
void Stack::push(int x)
{
    if (!isFull()) {
        st[top++] = x;
    }
}
int Stack::pop()
{
    if (!isEmpty()) {
        return st[--top];
    }
}
void Stack::clear()
{
    top = 0; // эффективная "очистка"
}
bool Stack::isEmpty()
{
    return !top;
}
bool Stack::isFull()
{
    return top == 20;
}
int Stack::getCount()
{
    return top;
}


*/


class Queue {
    int* q;
    int* p;
    int max;
    int real;

public:
    Queue(int size);
    ~Queue();

    void push(int x, int pr);
    int pop();
    int popPrior();
    void clear();
    bool isEmpty();
    bool isFull();
    int getCount();

    void print() {
        for (int i = 0; i < real; i++) {
            std::cout << q[i] << "-" << p[i] << "  ";
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
    int maxId = 0;
    for (int i = 0; i < real; i++) {
        if (p[i] > p[max]) {
            max = i;
        }
    }
    int temp = q[max];

    for (int i = max + 1; i < real; i++) {
        q[i - 1] = q[i];
        p[i - 1] = p[i];
    }
    real--;
    return temp;
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

    /*
    Stack st1;

    for (int i = 0; i < 5; i++) {
        st1.push(rand() % 100 + 1);
    }
    st1.print();
    st1.push(rand() % 100 + 1);
    st1.print();


    for (int i = 0; i < 3; i++) {
       std::cout << st1.pop() << " ";
    }
    std::cout << std::endl;

    st1.print();

    std::cout << st1.getCount() << std::endl;
    st1.clear();
    std::cout << st1.getCount() << std::endl;
    */


    Queue q1{ 10 };

    for (int i = 0; i < 5; i++) {
        q1.push(rand() % 100 + 1, rand() % 100 + 1);
    }
    q1.print();
    /*q1.push(rand() % 100 + 1, rand() % 100 + 1);
    q1.print();*/

    std::cout << "--------------" << std::endl;


    /*for (int i = 0; i < 3; i++) {
        std::cout << q1.pop() << " ";
    }*/

    for (int i = 0; i < 3; i++) {
        std::cout << q1.popPrior() << " ";
    }

    std::cout << std::endl;

    q1.print();

    std::cout << q1.getCount() << std::endl;
    q1.clear();
    std::cout << q1.getCount() << std::endl;

    return 0;
}

// В ДОМАШКУ НАПИСАТЬ pushPrior