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
    //Desstructor to destroy the nodes and free memory allocated to the nodes.
    ~Node() {
        cout << endl << "All the node have been destroyed..!!";
    }
};

  
class LinkedList {
    public:
        Node *head = NULL;
        //Destructor to detroy the linked list and free memory allocated the list.
        ~LinkedList() {
            cout << endl << "List has been Destroyed...!!!";
        }
        void DeleteAtTail();
        void Insert(int);
        void Display();
};

/*NOTE:- ->HERE DELETION MEANS POINTING TO THE NEXT->NEXT NODE AND NOT ACTUALLY DELETING THE NODE. 
         ->Reasons for not using free() and delete() :
                a.Since the objects of a class are static, not dynamic.
                b.When executed, a "SEGMENTATION FAULT" will occur.
         ->In the end thats why a destructor is added to destroy the memory used and free the allocated memory.
*/
void LinkedList::DeleteAtTail() {
    //if the list is empty 
    if (head == NULL) {
        cout << "The list is empty";
        return;
    }
    //If the list contains only one node.
    Node *temp = head;
    if (temp->next == NULL) {
        return;
    }
    //Travese to the last before node and delete it's next node i.e the tail node.
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void LinkedList::Insert(int data) {
    //If the list is empty create a Node
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    else {
        Node *temp = head;
        //Traverse to the end of the list
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
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
        cout << "\t\t1.Insert" << endl;
        cout << "\t\t2.Delete at TAIL" << endl;
        cout << "\t\t3.Display" << endl;
        cout << "\t\t4.Exit" << endl;
        cout << "Enter your choice: [  ]\b\b";
        cin >> ch;
        switch(ch) {
                case 1:
                    cout << endl << "Enter the data to insert: ";
                    cin >> temp;
                    list.Insert(temp);
                break;
                case 2:
                    list.DeleteAtTail();
                break;
                case 3:
                    list.Display();
                break;
                case 4:
                    return 0;
                break;
        }
    }while(ch != 4);
}