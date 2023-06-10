#include <iostream>


// Using 'nampespace std;' is considered as bad programming practice.
using std::cin;
using std::cout;
using std::endl;

class Node {
    public:
        Node *prev;
        int data;
        Node *next;
        Node() {
            prev = nullptr;
            data = -1;
            next = nullptr;
        }
        Node (int data) {
            prev = nullptr;
            this->data = data;
            next = nullptr;
        }
};

class List {
    private:
        Node *head = nullptr;
    public:
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~List() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
            delete head;
            delete temp;
            cout << endl << "The list is destroyed...!!!";
        }
        void Display();
        void InsertAtHead(int);
};

void List::InsertAtHead(int data) {
    Node *newNode = new Node(data);
    //Check if the list is empty and if the list is empty make the newNode as the head of the list.
    if(head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void List::Display() {
    //Check if the list is empty or not.
    if (head == nullptr) {
        cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp != nullptr) {
        if(temp->next == nullptr) {
            cout << temp->data;
            return;
        }
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

int main() {
    List list;
    int ch,temp,p;
    do {    
        cout << "\t\t         MENU" << endl;
        cout << "1.Insert at HEAD" << endl;
        cout << "2.Display" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter your choice: [  ]\b\b";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << endl << "Enter the data to insert:";
                cin >> temp;
                list.InsertAtHead(temp);
            break;
            case 2:
                list.Display();
            break;
            case 3:
                return 0;
        }
    }while(ch != 4);
}
