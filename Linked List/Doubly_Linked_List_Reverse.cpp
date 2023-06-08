#include <iostream>

// Using 'namespace std; ' is considered as bad programing practice.
using std::cin;
using std::cout;
using std::endl;

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

class List {
    private:
        Node *head;
    public:
        List () {
            head = nullptr;
        }
        ~List () {
            Node *temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            delete head;
            delete temp;
            cout << endl << "The list is destroyed." << endl;
        }
        void Insert(int data);
        void Display();
        void Reverse();
};

void List::Insert(int data) {
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

void List::Display() {
    // Check if the list is empty.
    if (head == nullptr) {
        cout<< endl << "The list is empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp) {
        if (temp->next == nullptr) {
            cout << temp->data;
            return;
        }
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

void List::Reverse () {
    // Check if the list is empty.
    if (head == nullptr) {
        cout << "The list is empty." << endl;
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
    List l;
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);
    l.Reverse();
    l.Display();
    return 0;
}