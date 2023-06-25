#include <iostream>

// Using "namepace std;" is considered as bad programming practice.

class Node {
    public:
        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class Stack {
    private:
        Node *top;
    public:
        Stack () {
            top = nullptr;
        }
        void Push(int data);
        Node* Pop();
        void Display();
};

void Stack::Push(int data) {
    Node *newNode = new Node(data);
    // Check if the stack is empty.
    if (top == nullptr) {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

Node* Stack::Pop() {
    // Check if the stack is empty.
    if (top == nullptr) {
        std::cout << "Stack is empty..!\n";
        return nullptr;
    }
    Node *temp = top;
    top = top->next;
    return temp;
}

void Stack::Display() {
    // Check if the stack is empty.
    if (top == nullptr) {
        std::cout << "Stack is empty..!\n";
        return;
    }
    std::cout << "\n";
    Node *temp = top;
    while (temp) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
}

int main() {
    Stack s;
    int ch,temp;
    // Menu driven program.
    do {
        std::cout << "\n\t\tMenu";
        std::cout << "\n1.Push";
        std::cout << "\n2.Pop";
        std::cout << "\n3.Display";
        std::cout << "\n4.Exit";
        std::cout << "\nEnter your choice: [ ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cout << "\nEnter the element to push into the stack: ";
                std::cin >> temp;
                s.Push(temp);
            break;
            case 2:
                std::cout << "\nThe element popped out is: " << s.Pop()->data;
            break;
            case 3:
                s.Display();
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
}