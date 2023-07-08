#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {
    public:
        Node *prev;
        int data;
        Node *next;
        Node() {
            prev = nullptr;
            data = -1;
            next = nullptr;
        }
        Node (int data) {
            prev = nullptr;
            this->data = data;
            next = nullptr;
        }
};

class LinkedList {

    private:

        Node *head;

    public:

        LinkedList () {
            head = nullptr;
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
        void Display();
        void InsertAtHead(int);
};

void LinkedList::InsertAtHead(int data) {
    Node *newNode = new Node(data);
    // Check if the list is empty and if the list is empty make the newNode as the head of the list.
    if(head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void LinkedList::Display() {
    // Check if the list is empty or not.
    if (head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    Node *temp = head;
    while(temp != nullptr) {
        if(temp->next == nullptr) {
            std::cout << temp->data;
            return;
        }
        std::cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

int main() {
    LinkedList l;
    // Menu driven program.
    int ch,temp,p;
    do {    
        std::cout << "\n\t\t         MENU";
        std::cout << "\n1.Insert at HEAD";
        std::cout << "\n2.Display";
        std::cout << "\n3.Exit";
        std::cout << "\nEnter your choice: [  ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cout << "\nEnter the data to insert:";
                std::cin >> temp;
                l.InsertAtHead(temp);
            break;
            case 2:
                l.Display();
            break;
            case 3:
                return 0;
        }
    }while(ch != 4);
}
