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
        void DeleteAtHead();
        void Insert(int);
        void Display();
};

/*NOTE:-
         ->Reasons for not using free() :
                a.Using free() to deallocate memory allocated for an object in C++ is not recommended because 
                  it does not call the object's destructor.
                b.When executed, a "SEGMENTATION FAULT" will occur.
                c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
                d.delete is used when the memory is allocated using "new";
*/
void LinkedList::DeleteAtHead() {
    // Check if teh list is empty.
    if (head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    // Deleting head means moving the head to the next node.
    Node *temp = head;
    head = head->next;
    delete temp;
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
    tail = tail->next;
}

void LinkedList::Display() {
    // Check if the list is empty.
    if (head == nullptr) {
        std::cout << "\nList is empty";
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
        std::cout << "\n\t\t      MENU";
        std::cout << "\n\t\t1.Insert";
        std::cout << "\n\t\t2.Delete at HEAD";
        std::cout << "\n\t\t3.Display";
        std::cout << "\n\t\t4.Exit";
        std::cout << "\nEnter your choice: [  ]\b\b";
        std::cin >> ch;
        switch(ch) {
                case 1:
                    std::cout << "\nEnter the data to insert: ";
                    std::cin >> temp;
                    l.Insert(temp);
                break;
                case 2:
                    l.DeleteAtHead();
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