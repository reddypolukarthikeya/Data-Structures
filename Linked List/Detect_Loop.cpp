#include <iostream>

// Using 'namespace std; ' is considered as bad programming practice.

class Node {
    public: 
        int data;
        Node *next;
        // Parameterized constructor
        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {
    private: 
        Node *head;
        Node *tail;
    public: 
        // Default constructor 
        LinkedList () {
            head = nullptr;
            tail = nullptr;
        }
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~LinkedList() {
            Node *temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            std::cout << "\nList has been destroyed.";
        }
        void Insert (int data);
        void Display();
        bool HasLoop();
        void CreateLoop();
        void RemoveLoop();
};

void LinkedList::RemoveLoop() {
    // In order to destroy all the nodes we need to remove the loop.
    tail->next = nullptr;
}

void LinkedList::CreateLoop () {
    Node *loopNode = head->next;
    tail->next = loopNode;
}

void LinkedList::Insert (int data) {
    Node *newNode = new Node (data);
    // Check if the LinkedList is empty or not and if the LinkedList is empty, make the newNode as the head.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    // If the LinkedList is not empty, traverse to the end of the LinkedList.
    while (tail->next != nullptr)
        tail = tail->next;
    tail->next = newNode;
}

void LinkedList::Display() {
    // Check if the LinkedList is empty or not.
    if (head == nullptr) {
        std::cout<< "\nThe LinkedList is empty.";
        return;
    }
    Node *temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

bool LinkedList::HasLoop() {
    // if head is NULL then return false.
    if (head == nullptr) {
        std::cout << "\nThe LinkedList is empty.";
        return false;
    }
    // Create two pointers 'slow' and 'fast'
    // Here slow refers to tortoise and fast refers to hare.
    Node *tortoise = head;
    Node *hare = head;

    // Here tortoise traverses by one node at a time
    // And hare is traverses by two nodes at a time. 
    while (hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        // If there is a loop both animals meet a point.
        if (hare == tortoise)
        {
            std::cout << "Loop detected";
            return true; // Loop is detected.
        }
    }
    // No loop detected.
    std::cout << "\nNo loop detected";
    return false;
}

int main() {
    LinkedList l;
    int ch;
    do {
        std::cout << "\n\t\tMenu";
        std::cout << "\n1.Insert";
        std::cout << "\n2.Create Loop";
        std::cout << "\n3.Detect Loop";
        std::cout << "\n4.Display";
        std::cout << "\n5.Exit";
        std::cout << "\n\tEnter your choice : [ ]\b\b";
        std::cin>> ch;
        switch (ch) {
            case 1:
                int temp;
                std::cout << "\nEnter the element to be inserted : ";
                std::cin>> temp;
                l.Insert(temp);
            break;
            case 2:
                l.CreateLoop();
            break;
            case 3:
                l.HasLoop();
            break;
            case 4:
                l.Display();
            break;
            case 5:
                l.RemoveLoop();
                return 0;
            break;
        }
    }while (ch != 5);
    return 0;
}