#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {
    public:
        int data;
        Node *next;

    // Unparameterized constructor
    Node() : data(-1), next(nullptr) {};
    
    // Parameterized constructor
    explicit Node (int data) : data(data), next(nullptr) {};
};

  
class LinkedList {

    private:

        Node *head;

    public:

        // Default constructor 
        LinkedList() : head(nullptr) {};
        // Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~LinkedList() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
            std::cout << "\nList has been Destroyed...!!!";
        }
        void InsertAtHead(int data);
        void Display();
};

void LinkedList::InsertAtHead(int data) {
    Node *newNode = new Node(data);
    // If the list is empty 
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // If the list is not empty
    newNode->next = head;
    head = newNode;
}

void LinkedList::Display() {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    // If the list is not empty
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    {
        // Object of class LinkedList.
        LinkedList l;
        int ch;
        int temp;
        // Menu driven program.
        do {
            std::cout << "\t\t      MENU\n";
            std::cout << "\t\t1.Insert at HEAD\n";
            std::cout << "\t\t2.Display\n";
            std::cout << "\t\t3.Exit\n";
            std::cout << "Enter your choice: [  ]\b\b";
            std::cin >> ch;
            switch(ch) {
                    case 1:
                        std::cout << "Enter the element to insert: ";
                        std::cin >> temp;
                        l.InsertAtHead(temp);
                    break;
                    case 2:
                        l.Display();
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
}