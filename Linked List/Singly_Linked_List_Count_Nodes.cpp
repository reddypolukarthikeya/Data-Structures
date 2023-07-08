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

        int size;
        // Unparameterized constructor
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        // Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
/*NOTE:-
    ->Reasons for not using free() :
        a.Using free() to deallocate memory allocated for an object in C++ is not recommended because it 
          does not call the object's destructor.
        b.When executed, a "SEGMENTATION FAULT" will occur.
        c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
        d.delete is used when the memory is allocated using "new";
*/
        ~LinkedList() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
            std::cout << "\nList has been Destroyed...!!!";
        }
        void Insert(int data);
        void Display();
};

void LinkedList::Insert(int data) {
    // If the list is empty create a Node
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = tail->next;
    }
    /*
        Instead of creating a function which returns number of nodes
        create a LinkedList variable called size which increments when 
        a new node is added.
    */
    size++;
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

    // Object of class LinkedList.
    LinkedList l;
    int temp,ch;
    // Menu driven program.
    do {
        std::cout << "\t\t      MENU\n";
        std::cout << "\t\t1.Insert\n";
        std::cout << "\t\t2.Count the total number of nodes\n";
        std::cout << "\t\t3.Display\n";
        std::cout << "\t\t4.Exit\n";
        std::cout << "Enter your choice: [  ]\b\b";
        std::cin >> ch;
        switch(ch) {
                case 1:
                    std::cout << "\nEnter the data to insert: ";
                    std::cin >> temp;
                    l.Insert(temp);
                break;
                case 2:
                    std::cout << "\nThe total number of nodes are: " << l.size << "\n";
                break;
                case 3:
                    l.Display();
                break;
                case 4:
                    return 0;
                break;
        }
    }while(ch != 4);
}