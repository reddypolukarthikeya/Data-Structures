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
    //Check if the list is empty.
    if (head == NULL) 
        return;
    Node *temp = head;
    //If the data of the current node is equal to the data of the next node then remove the next node.
    while (temp->next != NULL) {
        if (temp->data == temp->next->data) {
            temp->next = temp->next->next;
        }
        else 
            temp = temp->next;
    }
}

int LinkedList::CountNodes() {
    Node *temp = head;
    int count =0;
    if (head == NULL) {
        cout << count;
        return -1;
    }
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

/*NOTE:- ->HERE DELETION MEANS POINTING TO THE NEXT->NEXT NODE AND NOT ACTUALLY DELETING THE NODE. 
         ->Reasons for not using free() and delete() :
                a.Using free() to deallocate memory allocated for an object in C++ is not recommended because it does not call the object's destructor.
                b.When executed, a "SEGMENTATION FAULT" will occur.
         ->In the end thats why a destructor is added to destroy the memory used and free the allocated memory.
*/
void LinkedList::DeleteAtHead() {
    //Deleting head meaning moving the head to the next node.
    head = head->next;
    head = head->next;
}

void LinkedList::DeleteAtPosition(int position) {
    //if the list is empty.
    if (head == NULL) {
        cout << "The list is empty";
        return;
    } 
    if (position == 1) {
        head = head->next;
        return;
    }
    Node *temp = head;
    //Travese to the position and remove the required node.
    while (--position > 1) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void LinkedList::DeleteAtTail() {
    //if the list is empty 
    if (head == NULL) {
        cout << "The list is empty";
        return;
    }
    //Travese to the last before node and delete it's next node i.e the tail node.
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

    //Object of class LinkedList.
    LinkedList list;
    int position,temp,ch;
    //Menu driven program.
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
}