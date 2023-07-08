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
        int size;

    public:
    

        // Constructor to initialize the linked list.
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
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
        void DeleteAtPosition(int);
        void Insert(int);
        void Display();
};

/*NOTE:- 
    ->Reasons for not using free() :
        a.Using free() to deallocate memory allocated for an object in C++ is not recommended 
          because it does not call the object's destructor.
        b.When executed, a "SEGMENTATION FAULT" will occur.
        c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
        d.delete is used when the memory is allocated using "new";
*/
void LinkedList::DeleteAtPosition(int position) {
    // If the list is empty.  
    if (position > size || position <= 0) {
        std::cout << "\nInvalid Position";
        return;
    }
    Node *temp = head;
    if (position == 1) {
        head = head->next;
        delete temp;
        return;
    }
    Node *prev = nullptr;
    temp = head;
    while (position > 1 && temp->next != nullptr) {
        prev = temp->next;
        temp = temp->next;
        position--;
    }
    prev->next = temp->next;
    delete temp;
    size--;
}

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
    size++;
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
    LinkedList list;
    int temp,ch;
    // Since position cannot be negative unsigned int is used.
    unsigned int position=0;
    // Menu driven program.
    do {
        std::cout << "\n\t\t      MENU";
        std::cout << "\n\t\t1.Insert";
        std::cout << "\n\t\t2.Delete at POSITION";
        std::cout << "\n\t\t3.Display";
        std::cout << "\n\t\t4.Exit";
        std::cout << "\nEnter your choice: [  ]\b\b";
        std::cin >> ch;
        switch(ch) {
                case 1:
                    std::cout << "\nEnter the data to insert: ";
                    std::cin >> temp;
                    list.Insert(temp);
                break;
                case 2:
                    std::cout << "\nEnter the position to delete: ";
                    std::cin >> position;
                    list.DeleteAtPosition(position);
                break;
                case 3:
                    list.Display();
                break;
                case 4:
                    return 0;
                break;
        }
    }while(ch != 4);
}