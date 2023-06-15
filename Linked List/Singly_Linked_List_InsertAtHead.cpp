#include <iostream>
#include <memory>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {
    public:
        int data;
        std::unique_ptr<Node> next;
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
    private:
        std::unique_ptr<Node> head;
        std::unique_ptr<Node> tail;
    public:
        // Unparameterized constructor
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        /*
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
        */
        void InsertAtHead(int data);
        void Display();
};

void LinkedList::InsertAtHead(int data) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
    //if the list is empty 
    if (head == nullptr) {
        head = move(newNode);
        return;
    }
    //if the list is not empty
    newNode->next = move(head);
    head = move(newNode);
    return;
}

void LinkedList::Display() {
    //Check if the list is empty.
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    //If the list is not empty
    Node *temp = head.get();
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next.get();
    }
}

int main() {

    //Object of class LinkedList.
    LinkedList list;
    int temp,ch;
    //Menu driven program.
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
                    list.InsertAtHead(temp);
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