#include <iostream>

// Using 'namespace std;' is considered as bad programming practice.

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

class LinkedList {
    private:
        Node *head;
        Node *tail;
    public:
        LinkedList () {
            head = nullptr;
            tail = nullptr;
        }
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~LinkedList () {
            Node *temp = head;
            while (temp) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        void Insert(int data);
        void Display();
        void CreateLoop();
        void RemoveLoop();
        Node* FindLoopPoint();
};

void LinkedList::RemoveLoop() {
    // In order to destroy all the nodes we need to remove the loop.
    tail->next = nullptr;
}

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty or not. If it is empty, then make the newNode as head of the list.
    if (head == nullptr) {
        head = newNode;
        // Since it is the first node tail and head will be same.
        tail = head;
        return;
    }
    // By using the tail node we don't need to traverse the entire list to add the node at the end of the list.
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = newNode;
}

void LinkedList::Display() {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout << "\nThe list is empty.";
        return;
    }
    Node *temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::CreateLoop() {
    Node *loopNode = head->next;
    tail->next = loopNode;
}

Node* LinkedList::FindLoopPoint() {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout << "\nThe list is empty.";
        return nullptr;
    }
    // Create two pointers 'slow' and 'fast' 
    // Here slow refers to tortoise and fast refers to hare.
    Node *tortoise = head;
    Node *hare = head;

    // Here tortoise traverses by one node at a time
    // And hare traverses by two nodes at a time.
    while (hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        // If there is a loop both animals meet at the same node.
        if (hare == tortoise) {
            // Reset the tortoise pointer to the head of the linked list
            // And move both pointers one step at a time until they meet again. 
            // The node where they meet is the starting point of the cycle.
            tortoise = head;
            while (tortoise != hare) {
                tortoise = tortoise->next;
                hare = hare->next;
            }
            return tortoise;
        }
    } 
    // If the two pointers don't meet at a node, then there is no loop.
    return nullptr;
}

int main () {
    LinkedList l;
    Node *temp = nullptr;
    int ch;
    do {
        std::cout << "\n\t\tMenu";
        std::cout << "\n1.Insert";
        std::cout << "\n2.Create Loop";
        std::cout << "\n3.Find the Starting Point of the Loop";
        std::cout << "\n4.Display";
        std::cout << "\n5.Exit";
        std::cout << "\n\tEnter your choice : [ ]\b\b";
        std::cin>> ch;
        switch (ch) {
            case 1:
                int tem;
                std::cout << "\nEnter the element to be inserted : ";
                std::cin>> tem;
                l.Insert(tem);
            break;
            case 2:
                l.CreateLoop();
            break;
            case 3:
                temp = l.FindLoopPoint();
                if (temp) {
                    std::cout << "Address : " << temp;
                    std::cout << "  |  Data : " << temp->data;
                }
                else 
                    std::cout << "\nThere is no loop in the list.";
            break;
            case 4:
                l.Display();
            break;
            case 5:
                l.RemoveLoop();
                return 0;
            break;
            default:
                std::cout << "\nInvalid choice..!!";
            break;
        }
    }while (ch != 5);
}