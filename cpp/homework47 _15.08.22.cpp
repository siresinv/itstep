// STEP _CPP _homework47 _15.08.22
/*
ООП
Бинарные деревья
Binary Tree

*/

#include <iostream>
#include <cmath>
#include <ctime>


struct  Node
{
    int value;
    Node* parent;
    Node* left;
    Node* right;
};

class Tree {
    Node* root;

public:
    Tree();
    ~Tree();
    void print(Node* elem);
    Node* search(Node* elem, int key);
    Node* min(Node* elem);
    Node* max(Node* elem);
    Node* next(Node* elem);
    Node* prev(Node* elem);
    void insert(Node* elem);
    void del(Node* elem = nullptr);
    Node* getRoot();
};

int main()
{

    srand(time(NULL));

    Tree tree1;

    /*Node* rootElem = new Node;
    rootElem->value = 50;
    tree1.root*/


    for (int i = 0; i < 10; i++) {
        Node* elem = new Node;
        int val = rand() % 100;
        std::cout << val << " ";
        elem->value = val;
        tree1.insert(elem);
        /*if (i == 0) {
            rootElem = elem;
        }*/
    }
    //tree1.print(rootElem);
    std::cout << std::endl;


    tree1.print(tree1.getRoot());
    std::cout << std::endl;

    Node* elem = new Node;
    elem->value = 50;
    tree1.insert(elem);
    tree1.print(tree1.getRoot());
    std::cout << std::endl;

    tree1.del(tree1.search(tree1.getRoot(), 50));
    tree1.print(tree1.getRoot());
    std::cout << std::endl;

    tree1.del(tree1.search(tree1.getRoot(), tree1.getRoot()->value));
    tree1.print(tree1.getRoot());
    std::cout << std::endl;

    std::cout << tree1.getRoot()->value;
    std::cout << std::endl;


    tree1.del(tree1.getRoot());
    tree1.print(tree1.getRoot());
    std::cout << std::endl;

    return 0;
}

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    del();
}

void Tree::print(Node* elem)
{
    if (elem != nullptr) {
        print(elem->left);
        std::cout << elem->value << " ";
        print(elem->right);
    }
}

Node* Tree::search(Node* elem, int key)
{
    //
    /*while (elem != nullptr && key != elem->value) {
        if (key < elem->value) {
            elem = elem->left;
        }
        else {
            elem = elem->right;
        }
    }
    return elem;*/

    if (elem == nullptr || elem->value == key) return elem;
    if (key < elem->value) {
        search(elem->left, key);
    }
    else {
        search(elem->right, key);
    }
}

Node* Tree::min(Node* elem)
{
    if (elem != nullptr) {
        while (elem->left != nullptr) {
            elem = elem->left;
        }
    }

    return elem;
}

Node* Tree::max(Node* elem)
{
    if (elem != nullptr) {
        while (elem->right != nullptr) {
            elem = elem->right;
        }
    }

    return elem;
}

Node* Tree::next(Node* elem)
{
    Node* temp = nullptr;

    if (elem != nullptr) {
        if (elem->right != nullptr) {
            return min(elem->right);
        }
        temp = elem->parent;
        while (temp != nullptr && elem == temp->right) {
            elem = temp;
            temp = temp->parent;
        }
    }

    return temp;
}

Node* Tree::prev(Node* elem)
{
    Node* temp = nullptr;

    if (elem != nullptr) {
        if (elem->left != nullptr) {
            return max(elem->left);
        }
        temp = elem->parent;
        while (temp != nullptr && elem == temp->left) {
            elem = temp;
            temp = temp->parent;
        }
    }

    return temp;
}

void Tree::insert(Node* elem)
{
    if (elem != nullptr) {
        elem->left = nullptr;
        elem->right = nullptr;

        Node* temp = root;
        Node* tempParent = nullptr;

        while (temp != nullptr) {
            tempParent = temp;
            if (elem->value < temp->value) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        elem->parent = tempParent;
        if (tempParent == nullptr) {
            root = elem;
        }
        else if (elem->value < tempParent->value) {
            tempParent->left = elem;
        }
        else {
            tempParent->right = elem;
        }
    }
}

void Tree::del(Node* elem)
{
    if (elem != nullptr) {
        Node* temp;
        Node* tempParent;
        if (elem->left == nullptr || elem->right == nullptr) {
            temp = elem;
        }
        else {
            temp = next(elem);
        }

        if (temp->left != nullptr) {
            tempParent = temp->left;
        }
        else {
            tempParent = temp->right;
        }
        if (tempParent != nullptr) {
            tempParent->parent = temp->parent;
        }

        if (temp->parent == nullptr) {
            root = tempParent;
        }
        else if (temp == temp->parent->right) {
            temp->parent->right = tempParent;

        } else {
            temp->parent->left = tempParent;
        }

        if (elem != temp) {
            elem->value = temp->value;
        }

        delete temp;

        /*if (temp != nullptr) {

        }*/
    }
    else {
        while (root != nullptr) {
            del(root);
        }
    }
}

Node* Tree::getRoot()
{
    return root;
}
