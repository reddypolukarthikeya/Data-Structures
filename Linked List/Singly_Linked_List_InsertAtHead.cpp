#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.
using std::cin;
using std::cout;
using std::endl;

class Node {
    public:
        int data;
        Node *next;
    //Unparameterized constructor
    Node() {
        data = -1;
        next = NULL;
    }
    //Parameterized constructor
    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

  
class LinkedList {
    public:
        Node *head = NULL;
        //Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~LinkedList() {
            Node *temp = head;
            while(head != NULL) {
                head = head->next;
                free(temp);
                temp = head;
            }
            cout << endl << "List has been Destroyed...!!!";
        }
        void InsertAtHead(int data);
        void Display();
};

void LinkedList::InsertAtHead(int data) {
    Node *newNode = new Node(data);
    //if the list is empty 
    if (head == NULL) {
        head = newNode;
        return;
    }
    //if the list is not empty
    newNode->next = head;
    head = newNode;
    return;
}

void LinkedList::Display() {
    //Check if the list is empty.
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    //If the list is not empty
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {

    //Object of class LinkedList.
    LinkedList list;
    int temp,ch;
    //Menu driven program.
    do {
        cout << "\t\t      MENU" << endl;
        cout << "\t\t1.Insert at HEAD" << endl;
        cout << "\t\t2.Display" << endl;
        cout << "\t\t3.Exit" << endl;
        cout << "Enter your choice: [  ]\b\b" << endl;
        cin >> ch;
        switch(ch) {
                case 1:
                    cin >> temp;
                    list.InsertAtHead(temp);
                break;
                case 2:
                    list.Display();
                break;
                case 3:
                    return 0;
                break;
        }
    }while(ch != 3);
}