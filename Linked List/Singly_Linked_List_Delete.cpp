#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.

class Node {

    public:
        int data;
        Node *next;
    //Unparameterized constructor
    Node() {
        data = -1;
        next = nullptr;
    }
    //Parameterized constructor
    Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {

    private:

        Node *head;

    public:

        // Unparameterized constructor.
        LinkedList() {
            head = nullptr;
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
    //if the list is empty 
    if (head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    //If the list contains only one node.
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    //Traverse to the last before node using prev and delete it's next node "curr" i.e the tail node.
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
    //If the list is empty create a Node
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    else {
        Node *temp = head;
        //Traverse to the end of the list
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
}

void LinkedList::Display() {
    //Check if the list is empty.
    if (head == nullptr) {
        std::cout << "\nList is empty";
        return;
    }
    //If the list is not empty
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    //Object of class LinkedList.
    LinkedList list;
    int temp,ch;
    //Menu driven program.
    do {
        std::cout << "\t\t      MENU\n";
        std::cout << "\t\t1.Insert\n";
        std::cout << "\t\t2.Delete at TAIL\n";
        std::cout << "\t\t3.Display\n";
        std::cout << "\t\t4.Exit\n";
        std::cout << "Enter your choice: [  ]\b\b";
        std::cin >> ch;
        switch(ch) {
                case 1:
                    std::cout << "\nEnter the data to insert: ";
                    std::cin >> temp;
                    list.Insert(temp);
                break;
                case 2:
                    list.DeleteAtTail();
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