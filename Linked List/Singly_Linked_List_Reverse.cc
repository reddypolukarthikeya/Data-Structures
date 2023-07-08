#include <iostream>

// Usiing of "namespace std;" is considered as bad programming practice.

class Node {
    public:
        int data;
        Node *next;
        // Parameterized constructor.
        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList{

    private:

        Node *head;
        Node *tail;

    public:

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
        ~LinkedList () {
            Node *temp = head;
            while (head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
        } 
        void Insert (int data);
        void Reverse ();
        void Display();
};

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is emtpy.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
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

void LinkedList::Reverse() {
    // If the list is empty
    if (head == nullptr) {
        std::cout << "The list is empty\n";
        return;
    }
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr) {
        // Store the next node.
        next = current->next;
        // Reverse the link.
        current->next = prev;

        // Move the pointers one poisition ahead.
        prev = current;
        current = next;
    }
    // Make the prev as new head of the list.
    head = prev;
}

int main() {
    LinkedList l;
    int ch, temp;
    // Menu driven program.
    do {
        std::cout << "\tMenu\n";
        std::cout << "1.Insert\n";
        std::cout << "2.Reverse\n";
        std::cout << "3.Display\n";
        std::cout << "4.Exit\n";
        std::cout << "Enter your choice: [ ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cin >> temp;
                l.Insert(temp);
            break;
            case 2:
                l.Reverse();
                l.Display();
            break;
            case 3:
                l.Display();
            break;
            case 4:
                return 0;
        }
    }while (ch != 4);
    return 0;
}