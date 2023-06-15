#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {
    public:
        int data;
        Node *next;
    //Unparameterized constructor
    Node() {
        data = -1;
        next = nullptr;
    }
    //Parameterized constructor
    Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};
  
class LinkedList {
    public:
        Node *head;
        Node *tail;
        // Unparameterized constructor
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        //Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~LinkedList() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
            std::cout  << "\nList has been Destroyed...!!!";
        }
        void Insert(int data);
        void Display();
};

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty and if empty make the newNode as head and tail.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    // If the LinkedList is not empty, traverse to the end of the list and add the newNode
    while(tail->next != nullptr) 
        tail = tail->next;
    tail->next = newNode;
}

void LinkedList::Display() {
    //Check if the list is empty.
    if (head == nullptr) {
        std::cout  << "List is empty\n";
        return;
    }
    //Traverse to each node and display the data of the node.
    Node *temp = head;
    while (temp != nullptr) {
        std::cout  << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    // Object of class LinkedList.
    LinkedList list;
    int temp,ch;
    //Menu driven program.
    do {
        std::cout  << "\t\t      MENU\n";
        std::cout  << "\t\t1.Insert\n";
        std::cout  << "\t\t2.Display\n";
        std::cout  << "\t\t3.Exit\n";
        std::cout << "Enter your choice: [  ]\b\b";
        std::cin >> ch;
        switch(ch) {
                case 1:
                    std::cout << "\nEnter the element to be inserted: ";
                    std::cin >> temp;
                    list.Insert(temp);
                break;
                case 2:
                    list.Display();
                break;
                case 3:
                    return 0;
                break;
                default: 
                    std::cout << "\nInvalid choice..!!";
                break;
        }
    }while(ch != 3);
}
