#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Stack {
    public:
        class Node {
            public:
                int data;
                Node *next;
                Node () {
                    int data = -1;
                    next = NULL;
                }
                Node (int data) {
                    this->data = data;
                    this->next = NULL;
                }
        };
        Node *head = NULL;
        Node *top  = NULL;
        void Push(int value);
        int Pop();
        void Display();
};

void Stack::Push(int value) {
    Node *newNode = new Node(value);
    if (top == NULL) {
        top = newNode;
        head = top;
        return;
    }
    top = top->next;
    top = newNode;
    return;
}

int Stack::Pop() {
    if(top == NULL) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int element;
    element = top->data;
    Node *temp = head;
    while(temp->next->next != NULL) 
        temp = temp->next;
    temp->next = NULL;
    return element;  
}

void Stack::Display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    top->next = NULL;
    Node *temp = head;
    while(temp != NULL) {
        if (temp->data == -1) 
            temp = temp->next;
        cout << temp->data << endl;
    }
    
}