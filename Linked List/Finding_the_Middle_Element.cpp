#include <iostream>

// Using "namespace std;" is considered as bad programming practice.

class Node {
    public:
        int data;
        Node *next;
        // Parameterized constructor.
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {

    private:

        Node *head;
        Node *tail;

    public:

        // Unparameterized constructor.
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        // Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
/*NOTE:-
    ->Reasons for not using free() :
        a.Using free() to deallocate memory allocated for an object in C++ is not recommended because 
            it does not call the object's destructor.
        b.When executed, a "SEGMENTATION FAULT" will occur.
        c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
        d.delete is used when the memory is allocated using "new";
*/
        ~LinkedList() {
            Node *temp = head;
            delete temp;
            head = head->next;
        }
        void Find_Middle();
        void Insert(int data);
};

void LinkedList::Find_Middle() {
    // The first pointer moves by one node at a time.
    Node *ptr1 = head;
    // The second poitner moves by two nodes at a time.
    Node *ptr2 = ptr1->next;
    // By the time the second pointer moves to last node, the first pointer moves to the middle of the list.
    while (ptr2->next != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    std::cout << ptr1->data << "\n";
}

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}

int main() {
    // Object of class LinkedList.
    LinkedList l;
    int ch;
    // Menu driven program.
    do {
        std::cout << "\n\tMENU " ;
        std::cout << "\n1.Insert" ;
        std::cout << "\n2.Find the Middle Element" ;
        std::cout << "\n3.Exit" ;
        std::cout << "\nEnter your choice : [ ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1: 
                std::cout << "\nEnter the element to insert : ";
                int temp;
                std::cin >> temp;
                l.Insert(temp);
            break;
            case 2: 
                std::cout << "\n" ;
                l.Find_Middle();
            break;
            case 3: 
                return 0;
            break;
            default:
                std::cout << "\nInvalid choice..!!";
            break;
        }
    }while (ch!= 3);
}