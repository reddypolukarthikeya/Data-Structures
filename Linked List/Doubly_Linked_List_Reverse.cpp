#include <iostream>

// Using 'namespace std; ' is considered as bad programing practice.

class Node {
    public: 
        Node *prev;
        int data;
        Node *next;
        Node (int data) {
            prev = nullptr;
            this->data = data;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node *head;
    public:
        LinkedList () {
            head = nullptr;
        }
        ~LinkedList () {
            Node *temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            delete head;
            delete temp;
            std::cout  << "\nThe list is destroyed.";
        }
        void Insert(int data);
        void Display();
        void Reverse();
};

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty or not and if the list is empty make the newNode as head of the list.
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // If the list not empty, traverse to the end of the list.
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void LinkedList::Display() {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout <<  "\nThe list is empty.";
        return;
    }
    Node *temp = head;
    while (temp) {
        if (temp->next == nullptr) {
            std::cout  << temp->data;
            return;
        }
        std::cout  << temp->data << " <=> ";
        temp = temp->next;
    }
}

void LinkedList::Reverse () {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout  << "\nThe list is empty.";
        return;
    }
    Node *current = head;
    Node *temp = nullptr;
    while (current) {
        temp  = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    head = temp->prev;
}

int main() {
    LinkedList l;
    int ch;
    do {
        std::cout  << "\n\t MENU ";
        std::cout  << "\n1.Insert";
        std::cout  << "\n2.Reverse";
        std::cout  << "\n3.Display";
        std::cout  << "\n4.EXIT";
        std::cout  << "\nEnter your choice :[ ]\b\b";
        std::cin >> ch;
        switch(ch) {
            case 1:
                int temp;
                std::cout  <<  "\nEnter the element to insert: ";
                std::cin >> temp;
                l.Insert(temp);
            break;
            case 2: 
                l.Reverse();
            break;
            case 3:
                l.Display();
            break;
            case 4:
                return 0;
            break;
        }
    }while (ch != 4);
    return 0;
}