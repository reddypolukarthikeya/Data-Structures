#include <iostream>

using std::endl;
using std::cout;
using std::cin;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class List {
    private:
        Node *head;
    public:
        List() {
            head = nullptr;
        }
        void Find_Middle();
        void Insert(int data);
};

void List::Find_Middle() {
    Node *ptr1 = head;
    Node *ptr2 = ptr1->next;
    while (ptr2->next != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    cout << ptr1->data << endl;
}

void List::Insert(int data) {
    //If the list is empty create a Node
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    else {
        Node *temp = head;
        //Traverse to the end of the list
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
}

int main() {
    List l;
    int ch;
    do {
        cout << "\tMENU " << endl;
        cout << "1.Insert" << endl;
        cout << "2.Find the Middle Element" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter your choice : [ ]\b\b";
        cin >> ch;
        switch (ch) {
            case 1: 
                cout << "Enter the element to insert : ";
                int temp;
                cin >> temp;
                l.Insert(temp);
            break;
            case 2: 
                cout << endl;
                l.Find_Middle();
            break;
            case 3: 
                return 0;
            break;
        }
    }while (ch!= 3);
}