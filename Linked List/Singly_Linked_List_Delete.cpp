#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {

    public:
        int data;
        Node *next;
    // Unparameterized constructor
    Node() {
        data = -1;
        next = nullptr;
    }
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

        // Unparameterized constructor.
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }
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
        void DeleteAtTail();
        void Insert(int);
        void Display();
};

/*NOTE:-    ->Reasons for not using free() :
                a.Using free() to deallocate memory allocated for an object in C++ is not recommended because it does not call the object's destructor.
                b.When executed, a "SEGMENTATION FAULT" will occur.
                c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
                d.delete is used when the memory is allocated using "new";
*/
void LinkedList::DeleteAtTail() {
    // If the list is empty 
    if (head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    // If the list contains only one node.
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    // Traverse to the last before node using prev and delete it's next node "curr" i.e the tail node.
    Node *prev = nullptr;
    Node *curr = head;
    while(curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}

void LinkedList::Insert(int data) {
    // If the list is empty create a Node
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;    
}

void LinkedList::Display() {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout << "\nList is empty";
        return;
    }
    // If the list is not empty
    Node *temp = head;
    while (temp) {
        std::cout << temp->data << " => ";
        temp = temp->next;
    }
}

int main() {

    // Object of class LinkedList.
    LinkedList l;
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);
    l.Insert(4);
    l.Insert(5);
    l.Display();
}