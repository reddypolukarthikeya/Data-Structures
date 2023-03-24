#include <iostream>

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
    ~Node() {}
};

  
class LinkedList {
    public:
        Node *head = NULL;
        ~LinkedList() {
            cout << endl << "Object Destroyed...!!!";
        }
        void Insert(int data);
        void DeleteAtPosition(int);
        void Display();
        void InsertAtHead(int data);
        void InsertAtPosition(int data, int position);
        void DeleteAtTail();
        void DeleteAtHead();
        void RemoveDuplicates();
        int CountNodes();
};

void LinkedList::RemoveDuplicates() {
    if (head == NULL) 
        return;
    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->data == temp->next->data) {
            temp->next = temp->next->next;
        }
        else 
            temp = temp->next;
    }
}

void LinkedList::DeleteAtHead() {
    head = head->next;
    head = head->next;
}

int LinkedList::CountNodes() {
    Node *temp = head;
    int count =0;
    if (head == NULL) {
        cout << count;
        return -1;
    }
    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void LinkedList::DeleteAtPosition(int position) {
    //if the list is empty
    if (head == NULL) {
        cout << "The list is empty";
        return;
    } 
    Node *temp1 = head;
    Node *temp2 = head;
    
    while (position) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        position--;
    }
    temp1->next = temp2->next->next;
}

void LinkedList::DeleteAtTail() {
    //if the list is empty 
    if (head == NULL) {
        cout << "The list is empty";
        return;
    }
     
    Node *temp = head;
    if (temp->next == NULL) {
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void LinkedList::InsertAtPosition (int data, int position) {
    position --;
    Node *newNode = new Node(data);
    //if the list is empty 
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp1 = head;
    Node *temp2 = head;
    while (position) {
        temp1 = temp1->next;
        position--;    
    }
    temp2 = temp1->next;
    temp1->next = newNode;
    newNode->next = temp2;
}

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

    LinkedList list;
    int position;
    int temp;
    int ch;
    do {
        cout << "\t\t      MENU" << endl;
        cout << "\t\t1.Insert at head" << endl;
        cout << "\t\t2.Insert at tail" << endl;
        cout << "\t\t3.Insert at position" << endl;
        cout << "\t\t4.Delete at head" << endl;
        cout << "\t\t5.Delete at tail" << endl;
        cout << "\t\t6.Delete at position" << endl;
        cout << "\t\t7.Count nodes" << endl;
        cout << "\t\t8.Remove duplicates" << endl;
        cout << "\t\t9.Display" << endl;
        cout << "\t\t99.Exit" << endl;
        cout << "\t     Enter your choice : [ ]\b\b";
        cin >> ch;
        switch(ch) { 
            case 1:
                cin >> temp;
                list.InsertAtHead(temp);
            break;
            case 2:
                cin >> temp;
                list.Insert(temp);
            break;
            case 3:
                cin >> temp;
                cin >> position;
                list.InsertAtPosition(temp, position);
            break;
            case 4:
                list.DeleteAtHead();
            break;
            case 5:
                list.DeleteAtTail();
            break;
            case 6:
                cin >> position;
                list.DeleteAtPosition(position);
            break;
            case 7:
                list.CountNodes();
            break;
            case 8:
                list.RemoveDuplicates();
            break;
            case 9:
                list.Display();
            break;
            case 99:
                return 0;
        }
    }while(ch != 99);
    return 0;
}