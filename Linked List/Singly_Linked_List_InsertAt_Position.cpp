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
                delete temp;
                temp = head;
            }
            cout << endl << "List has been Destroyed...!!!";
        }
        void InsertAtPosition(int ,int );
        void Display();
};

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

void LinkedList::InsertAtPosition (int data, int position) {
    position --;
    Node *newNode = new Node(data);
    //if the list is empty 
    if (head == NULL) {
        head = newNode;
        return;
    }
    //To insert at given position two temporary nodes are required.
    Node *temp1 = head;
    Node *temp2 = head;
    //Traversing to the position.
    while (position) {
        temp1 = temp1->next;
        position--;    
    }
    //Assigning the newNode at the given position.
    temp2 = temp1->next;
    temp1->next = newNode;
    newNode->next = temp2;
    delete temp1;
    delete temp2;
}

int main() {

    //Object of class LinkedList.
    LinkedList list;
    int temp,ch;
    //Since the position cannot be negative. Therefore, unsigned int is used.
    unsigned int position = 0;
    //Menu driven program.
    do {
        cout << "\t\t      MENU" << endl;
        cout << "\t\t1.Insert at Position" << endl;
        cout << "\t\t2.Display" << endl;
        cout << "\t\t3.Exit" << endl;
        cout << "Enter your choice: [  ]\b\b";
        cin >> ch;
        switch(ch) {
                case 1:
                    cout << endl << "Enter the data: ";
                    cin >> temp;
                    cout << endl << "Enter the positon to insert: ";
                    cin >> position;
                    list.InsertAtPosition(temp,position);
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