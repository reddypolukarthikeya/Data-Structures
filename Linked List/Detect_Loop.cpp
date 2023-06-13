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

class List {
    private: 
        Node *head;
        Node *tail;
    public: 
        // Default constructor 
        List () {
            head = nullptr;
            tail = nullptr;
        }
        void Insert (int data);
        void Display();
        bool HasLoop();
        void CreateLoop();
};

void List::CreateLoop () {
    Node *temp = head;
    Node *loopNode = head->next;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = loopNode;
}

void List::Insert (int data) {
    Node *newNode = new Node (data);
    // Check if the list is empty or not and if the list is empty, make the newNode as the head.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    // If the list is not empty, traverse to the end of the list.
    while (tail->next != nullptr)
        tail = tail->next;
    tail->next = newNode;
}

void List::Display() {
    // Check if the list is empty or not.
    if (head == nullptr) {
        std::cout<< "\nThe list is empty.";
        return;
    }
    Node *temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

bool List::HasLoop() {
    // if head is NULL then return false.
    if (head == nullptr) {
        std::cout << "\nThe list is empty.";
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
        // If there is a cycle both animals meet a point.
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
    List l;
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
                return 0;
            break;
        }
    }while (ch != 5);
    return 0;
}