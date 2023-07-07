#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {
    public:
        Node *prev;
        int data;
        Node *next;
        // Unparameterized constructor.
        Node() {
            prev = nullptr;
            data = -1;
            next = nullptr;
        }
        // Parameterized constructor.
        Node (int data) {
            prev = nullptr;
            this->data = data;
            next = nullptr;
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
            delete head;
            std::cout << "\nThe list is destroyed...!!!";
        }
        void Insert(int);
        void Display();
        void DeleteAtTail();
};

/*NOTE:-    ->Reasons for not using free() :
                a.Using free() to deallocate memory allocated for an object in C++ is not recommended because it does not call the object's destructor.
                b.When executed, a "SEGMENTATION FAULT" will occur.
                c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
                d.delete is used when the memory is allocated using "new";
*/
void LinkedList::DeleteAtTail(){
    // Check if the list is empty or not.
    if(head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    else if (tail == head) {
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    return;
    
}

void LinkedList::Insert(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty or not and if the list is empty, make the newNode as head of the list.
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    // If not empty, update the tail node as the newNode.
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void LinkedList::Display() {
    // Check if the list is empty or not.
    if (head == nullptr) {
        std::cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp) { 
        std::cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

int main() {
    LinkedList l;
    int ch,temp,p;
    // Menu driven program.
    do {    
        std::cout << "\n\t\t         MENU\n";
        std::cout << "1.Insert\n";
        std::cout << "2.Delete at Tail\n";
        std::cout << "3.Display\n";
        std::cout << "4.Exit\n";
        std::cout << "Enter your choice: [  ]\b\b";
        std::cin>> ch;
        switch (ch) {
            case 1:
                std::cout << "\nEnter the data to insert:";
                std::cin>> temp;
                l.Insert(temp);
            break;
            case 2:
                l.DeleteAtTail();
            break;
            case 3:
                l.Display();
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
}
