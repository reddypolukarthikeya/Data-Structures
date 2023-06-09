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

    public:

        // Unparameterized constructor
        LinkedList () {
            head = nullptr;
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
        void InsertAtPosition(int ,int );
        void Display();
};

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

void LinkedList::InsertAtPosition (int data, int position) {
    position --;
    Node *newNode = new Node(data);
    //if the list is empty 
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // To insert at given position two temporary nodes are required.
    Node *temp1 = head;
    Node *temp2 = head;
    // Traversing to the position.
    while (position) {
        temp1 = temp1->next;
        position--;    
    }
    // Assigning the newNode at the given position.
    temp2 = temp1->next;
    temp1->next = newNode;
    newNode->next = temp2; 
}

int main() {

    //Object of class LinkedList.
    LinkedList l;
    int temp,ch;
    //Since the position cannot be negative. Therefore, unsigned int is used.
    unsigned int position = 0;
    //Menu driven program.
    do {
        std::cout << "\t\t      MENU\n";
        std::cout << "\t\t1.Insert at Position\n";
        std::cout << "\t\t2.Display\n";
        std::cout << "\t\t3.Exit\n";
        std::cout << "Enter your choice: [  ]\b\b";
        std::cin >> ch;
        switch(ch) {
                case 1:
                    std::cout << "\nEnter the data: ";
                    std::cin >> temp;
                    std::cout << "\nEnter the positon to insert: ";
                    std::cin >> position;
                    l.InsertAtPosition(temp,position);
                break;
                case 2:
                    l.Display();
                break;
                case 3:
                    return 0;
                break;
                default:
                    std::cout << "\nInvalid choice..!!";
                break;
        }
    }while(ch != 3);
}