#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Node {
    public:
        Node *prev;
        int data;
        Node *next;
        Node() {
            prev = NULL;
            data = -1;
            next = NULL;
        }
        Node (int data) {
            prev = NULL;
            this->data = data;
            next = NULL;
        }
};

class List {
    private:
        Node *head = NULL;
    public:
        ~List() {
            cout << endl << "The object is destroyed...!!!";
        }
        void Display();
        void DeleteAtTail();
        void DeleteAtHead();
        void DeleteAtPosition(int);
        void Insert(int);
        void InsertAtHead(int);
        void InsertAtPosition(int, int);
        void CountNodes();
        void RemoveDuplicates();
};

void List::RemoveDuplicates() {
    if(head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) {
        if (temp->data == temp->next->data) {
            temp->next = temp->next->next;
        }
        else 
            temp = temp->next; 
    }
}

void List::CountNodes() {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    int count=0;
    Node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << endl << count << endl;
}

void List::DeleteAtPosition(int position) {
    if (head == NULL ) {
        cout << "The list is empty";
        return;
    }
    if(position == 1) {
        head = head->next;
        head->prev = NULL;
        return;
    }
    Node *temp = head;
    position--;
    while(position--) {
        temp = temp->next;
    }
    
}

void List::DeleteAtHead() {
    if (head == NULL) {
        cout << "The list is empty";
        return;
    }
    head = head->next;
    head->prev = NULL;
}

void List::InsertAtPosition(int data, int position) {
    Node *newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    position--;
    position--;
    while(position--) 
        temp = temp->next;
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
}

void List::InsertAtHead(int data) {
    Node *newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void List::DeleteAtTail(){
    if(head == NULL) {
        cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) 
        temp = temp->next;
    temp = temp->prev;
    temp->next = NULL;
}

void List::Insert(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void List::Display() {
    if (head == NULL) {
        cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        if(temp->next == NULL) {
            cout << temp->data;
            return;
        }
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

int main() {
    List list;
    list.Insert(9);
    list.Insert(9);
    list.Insert(2);
    list.DeleteAtPosition(2);
    list.RemoveDuplicates();
    list.InsertAtPosition(9,2);
    list.InsertAtPosition(9,2);
    list.InsertAtPosition(4,2);
    list.Display();
    return 0;
}