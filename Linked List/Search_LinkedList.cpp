#include <iostream>

// Using "namespace std;" is considered as bad programming practice.

class Node {

    public:

        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            next = nullptr;
        }
};

class LinkedList {

    private:
        
        Node *head;
        Node *tail;
    
    public:

        // Unparameterized constructor.
        LinkedList () {
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
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            delete head;
        }
        bool Search(int key);
        void Insert(int data);
        void Display();
};

bool LinkedList::Search(int key) {
    // Check if the list is emtpy.
    if (head == nullptr) {
        std::cout << "\nThe list is empty.";
        return false;
    }
    Node *temp = head;
    while (temp) {
        if (temp->data == key) 
            return true;
        temp = temp->next;
    }
    return false; 
}

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = tail->next;
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

int main() {
    // Object of class LinkedList.
    LinkedList l;
    int ch, temp;
    // Menu driven program.
    do {
        std::cout << "\n\tMENU " ;
        std::cout << "\n1.Insert" ;
        std::cout << "\n2.Search" ;
        std::cout << "\n3.Display" ;
        std::cout << "\n4.Exit" ;
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
                std::cout << "\nEnter the element to search : ";
                std::cin >> temp;
                if (l.Search(temp)) 
                    std::cout << "\nElement found..!!";
                else 
                    std::cout << "\nElement NOT found..!!";
            break;
            case 3: 
                l.Display();
            break;
            case 4: 
                return 0;
            break;
            default:
                std::cout << "\nInvalid choice..!!";
            break;
        }
    }while(ch != 4);
}