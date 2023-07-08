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
    // Desstructor to destroy the nodes and free memory allocated to the nodes.
    ~Node() {
        std::cout  << "\nAll the node have been destroyed..!!";
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
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            delete temp;
            delete head;
            std::cout  << "\nList has been Destroyed...!!!";
        }
        void Insert(int data);
        void DeleteAtPosition(int);
        void Display();
        void InsertAtHead(int data);
        void InsertAtPosition(int data, int position);
        void DeleteAtTail();
        void DeleteAtHead();
        void RemoveDuplicates();
        int CountNodes();
};

void LinkedList::RemoveDuplicates() {
    // Check if the list is empty.
    if (head == nullptr) 
        return;
    Node *temp = head;
    // If the data of the current node is equal to the data of the next node then remove the next node.
    while (temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            temp->next = temp->next->next;
        }
        else 
            temp = temp->next;
    }
}

int LinkedList::CountNodes() {
    Node *temp = head;
    int count =0;
    if (head == nullptr) {
        std::cout  << count;
        return -1;
    }
    while(temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return count;
}

/*NOTE:-
    ->Reasons for not using free() :
        a.Using free() to deallocate memory allocated for an object in C++ is not recommended because 
            it does not call the object's destructor.
        b.When executed, a "SEGMENTATION FAULT" will occur.
        c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
        d.delete is used when the memory is allocated using "new";
*/
void LinkedList::DeleteAtHead() {
    // Deleting head meaning moving the head to the next node.
    head = head->next;
    head = head->next;
}

void LinkedList::DeleteAtPosition(int position) {
    // If the list is empty.
    if (head == nullptr) {
        std::cout  << "The list is empty";
        return;
    } 
    if (position == 1) {
        head = head->next;
        return;
    }
    Node *temp = head;
    // Travese to the position and remove the required node.
    while (--position > 1) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void LinkedList::DeleteAtTail() {
    // If the list is empty 
    if (head == nullptr) {
        std::cout  << "The list is empty";
        return;
    }
    // Travese to the last before node and delete it's next node i.e the tail node.
    Node *temp = head;
    if (temp->next == nullptr) {
        return;
    }
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nullptr;
}

void LinkedList::InsertAtPosition (int data, int position) {
    position --;
    Node *newNode = new Node(data);
    // If the list is empty 
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *temp1 = head;
    Node *temp2 = head;
    while (position) {
        temp1 = temp1->next;
        position--;    
    }
    temp2 = temp1->next;
    temp1->next = newNode;
    newNode->next = temp2;
}

void LinkedList::InsertAtHead(int data) {
    Node *newNode = new Node(data);
    // If the list is empty 
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // If the list is not empty
    newNode->next = head;
    head = newNode;
    return;
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
    if (head == nullptr) {
        std::cout  << "\nList is empty";
        return;
    }
    // If the list is not empty
    Node *temp = head;
    while (temp != nullptr) {
        std::cout  << temp->data << " ";
        temp = temp->next;
    }
}


int main() {

    // Object of class LinkedList.
    LinkedList l;
    int position,temp,ch;
    // Menu driven program.
    do {
        std::cout  << "\n\t\t      MENU";
        std::cout  << "\n\t\t1.Insert at head";
        std::cout  << "\n\t\t2.Insert at tail";
        std::cout  << "\n\t\t3.Insert at position";
        std::cout  << "\n\t\t4.Delete at head";
        std::cout  << "\n\t\t5.Delete at tail";
        std::cout  << "\n\t\t6.Delete at position";
        std::cout  << "\n\t\t7.Count nodes";
        std::cout  << "\n\t\t8.Remove duplicates";
        std::cout  << "\n\t\t9.Display";
        std::cout  << "\n\t\t99.Exit";
        std::cout  << "\n\t     Enter your choice : [ ]\b\b";
        std::cin >> ch;
        switch(ch) { 
            case 1:
                std::cin >> temp;
                l.InsertAtHead(temp);
            break;
            case 2:
                std::cin >> temp;
                l.Insert(temp);
            break;
            case 3:
                std::cin >> temp;
                std::cin >> position;
                l.InsertAtPosition(temp, position);
            break;
            case 4:
                l.DeleteAtHead();
            break;
            case 5:
                l.DeleteAtTail();
            break;
            case 6:
                std::cin >> position;
                l.DeleteAtPosition(position);
            break;
            case 7:
                l.CountNodes();
            break;
            case 8:
                l.RemoveDuplicates();
            break;
            case 9:
                l.Display();
            break;
            case 99:
                return 0;
            default:
                std::cout << "\nInvalid choice..!!";
            break;
        }
    }while(ch != 99);
}