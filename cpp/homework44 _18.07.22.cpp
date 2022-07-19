// STEP _CPP _classwork44 _18.07.22
/*
ООП

*/

#include <iostream>

struct Node {
    int val;
    Node* next;
};


//queue
class List {
    Node* head;
    Node* tail;
    int count;
public:
    List();
    ~List();
    void add(int x);
    void del();
    void delAll();
    void print();
    int getCount();

    List(const List& obj) {
        Node* temp = obj.head;
        count = 0;
        while (temp != nullptr) {
            add(temp->val);
            temp = temp->next;
        }

        
    }

    // если к себе(вызывающему объекту) прибавить
    /*void operator+(const List& obj2) {
        Node* temp = obj2.head;
        while (temp != nullptr) {
            add(temp->val);
            temp = temp->next;
        }
    }*/

    friend List operator+(const List& obj1, const List& obj2);

    friend List operator*(const List& obj1, const List& obj2);

};

// Перегрузить * (общие элементы обоих списков)
List operator*(const List& obj1, const List& obj2) {
    List multList{};
    Node* temp1 = obj1.head;
    Node* temp2 = obj2.head;

    while (temp1 != nullptr) {
        temp2 = obj2.head;
        while (temp2 != nullptr) {
            if (temp2->val == temp1->val) {
                multList.add(temp2->val);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return multList;
}


List operator+(const List& obj1, const List& obj2) {
    List sumList{obj1};
    Node* temp = obj2.head;
    while (temp != nullptr) {
        sumList.add(temp->val);
        temp = temp->next;
    }
    return sumList;
}


// раюотает только если используется деструктор по-умолчанию
/*List operator+(const List& l1, const List& l2)
{
    List l11{ l1 };
    List l22{ l2 };
    l11.tail->next = l22.head;
    l11.tail = l22.tail;
    l11.count += l22.count;
    return l11;
}*/

List::List() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

List::~List() {
    delAll();
}


void List::add(int x) {
    Node* temp = new Node;
    temp->val = x;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
    }
    else {
        tail->next = temp;
    }
    tail = temp;
    count++;
}

void List::del() {
    Node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    count--;
}

void List::delAll() {
    while (head != nullptr) {
        del();
    }
}

void List::print() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int List::getCount() {
    return count;
}


int main()
{
    List l1;
    for (int i = 0; i < 6; i++) {
        l1.add(i);
    }

    l1.print();
    std::cout << "-------------------- l1.del();" << std::endl;
    l1.del();
    l1.print();
    std::cout << l1.getCount() << std::endl;

    std::cout << "-------------------- List l2{ l1 };" << std::endl;
    List l2{ l1 };
    l2.print();
    std::cout << l2.getCount() << std::endl;

    //l1 + l2;
    //l1.print();
    //std::cout << l1.getCount() << std::endl;

    std::cout << "-------------------- List l3 = l1 + l2;" << std::endl;;
    List l3 = l1 + l2;
    l3.print();
    std::cout << l3.getCount() << std::endl;



    List l5;
    for (int i = 3; i < 8; i++) {
        l5.add(i);
    }
    std::cout << "-------------------- List l5;" << std::endl;;
    l5.print();
    std::cout << l5.getCount() << std::endl;


    std::cout << "-------------------- List l4 = l5 * l2;" << std::endl;;
    List l4 = l5 * l2;
    l4.print();
    std::cout << l4.getCount() << std::endl;

    std::cout << "-------------------- l2.del();" << std::endl;
    l2.del();
    l2.print();
    std::cout << l2.getCount() << std::endl;

    l1.print();
    std::cout << l1.getCount() << std::endl;

    return 0;

}