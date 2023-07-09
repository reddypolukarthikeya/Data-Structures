#include <iostream>

// Using "namespace std;" is considered as bad programming practice.

class Node {
    
    public:
        int data;
        Node *next;
        // Parameterized constructor.
        Node (int data) {
            this->data = data;
            next = nullptr;
        }
};

class LinkedList {
    
    private:
        Node *head;
        Node *tail;
    
    public:

        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        ~LinkedList() { 
            Node *temp = head;
            tail->next = nullptr;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        void Insert(int data);
        void Display();
};

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

void LinkedList::Display() {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    Node *temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
}

int main() {
    LinkedList l;
    int ch, temp;
    do {
        std::cout << "\n\t\tMenu";
        std::cout << "\n1.Insert";
        std::cout << "\n2.Display";
        std::cout << "\n3.Exit";
        std::cout << "\nEnter your choice : [ ]\b\b";
        std::cin >> ch;
        switch(ch) {
            case 1:
                std::cout << "\nEnter the element to insert : ";
                std::cin >> temp;
                l.Insert(temp);
            break;
            case 2:
                l.Display();
            break;
            case 3:
                return 0;
            break;
            default:
                std::cout << "\nInvalid choice..!!";
            break;
        }
    }while(ch != 3);
}