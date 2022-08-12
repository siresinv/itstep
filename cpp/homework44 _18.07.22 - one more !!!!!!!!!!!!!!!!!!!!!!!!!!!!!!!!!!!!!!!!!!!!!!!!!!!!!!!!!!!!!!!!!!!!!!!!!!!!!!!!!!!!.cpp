// STEP _CPP _homework44 _18.07.22 - one more
/*
ООП

*/

#include <iostream>


struct Node{
	int val;
	Node* next;
};

// queue
class List {
	Node* head;
	Node* tail;
	int count;

public:
	List();
	~List();
	List(const List& obj);
	void add(int x);
	void del();
	void delAll();
	int getCount();

	void print();


	List& operator=(const List& obj) { // List&, или без & - как правильно???
		List equalList;
		Node* temp = obj.head;
		count = 0;
		while (temp != nullptr) {
			equalList.add(temp->val);
			temp = temp->next;
		}
		return equalList;
	}


	friend List operator+(const List& obj1, const List& obj2);

	friend List operator*(const List& obj1, const List& obj2);



};

List::List(const List& obj) {
	Node* temp = obj.head;
	count = 0;
	while (temp != nullptr) {
		add(temp->val);
		temp = temp->next;
	}
}

List::List(){
	head = nullptr;
	tail = nullptr;
	count = 0;
}

List::~List(){
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

void List::del(){
	Node* temp = head;
	head = head->next;
	delete temp;
}

void List::delAll(){
	while (head != nullptr) {
		del();
	}
}

int List::getCount(){
	return count;
}

void List::print(){
	Node* temp = head;
	int i = 0;
	while (temp != nullptr) {
		std::cout << temp->val << "-[" << ++i << "] ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

List operator+(const List& obj1, const List& obj2){ //List& - то List l4 = l2 + l3; - получаем пустой спиоск
	List newList;
	Node* temp1 = obj1.head;
	Node* temp2 = obj2.head;
	while (temp1 != nullptr) {
		newList.add(temp1->val);
		temp1 = temp1->next;
	}

	while (temp2 != nullptr) {
		newList.add(temp2->val);
		temp2 = temp2->next;
	}

	return newList;
}

List operator*(const List& obj1, const List& obj2){
	return List();
}


int main() {

	List l1;
	for (int i = 5; i < 15; i++) {
		l1.add(i);
	}

	l1.print();
	l1.del();
	l1.print();
	//l1.delAll();
	//l1.print();
	List l2{ l1 };
	l2.print();
	List l3 = l2;
	/*List l3;
	l3 = l2;*/
	l3.print();

	List l4 = l2 + l3;

	/*List l4;
	l4 = l2 + l3;*/
	l4.print();


	return 0;
}