#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.
using std::cin;
using std::cout;
using std::endl;

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
    public:
        Node *head;
        int size;
        //Constructor to initialize the linked list.
        LinkedList() {
            head = nullptr;
            size = 0;
        }
        //Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~LinkedList() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
            cout << endl << "List has been Destroyed...!!!";
        }
        void DeleteAtPosition(int);
        void Insert(int);
        void Display();
};

/*NOTE:- ->HERE DELETION MEANS POINTING TO THE NEXT->NEXT NODE AND NOT ACTUALLY DELETING THE NODE. 
         ->Reasons for not using free() :
                a.Using free() to deallocate memory allocated for an object in C++ is not recommended because it does not call the object's destructor.
                b.When executed, a "SEGMENTATION FAULT" will occur.
                c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
                d.delete is used when the memory is allocated using "new";
*/
void LinkedList::DeleteAtPosition(int position) {
    //if the list is empty.
    if (head == nullptr) {
        cout << "The list is empty";
        return;
    } 
    if (position == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    if (position <= size-1) {
        Node *prev = nullptr;
        Node *curr = head;
        for (int i = 2;i <= size && i <= position ; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }
    else 
        cout << "Invalid position " << endl;
    size--;
}

void LinkedList::Insert(int data) {
    //If the list is empty create a Node
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node *temp = head;
        //Traverse to the end of the list
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void LinkedList::Display() {
    //Check if the list is empty.
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    //If the list is not empty
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {

    //Object of class LinkedList.
    LinkedList list;
    int temp,ch;
    //Since position cannot be negative unsigned int is used.
    unsigned int position=0;
    //Menu driven program.
    do {
        cout << "\t\t      MENU" << endl;
        cout << "\t\t1.Insert" << endl;
        cout << "\t\t2.Delete at POSITION" << endl;
        cout << "\t\t3.Display" << endl;
        cout << "\t\t4.Exit" << endl;
        cout << "Enter your choice: [  ]\b\b";
        cin >> ch;
        switch(ch) {
                case 1:
                    cout << endl << "Enter the data to insert: ";
                    cin >> temp;
                    list.Insert(temp);
                break;
                case 2:
                    cout << endl << "Enter the position to delete: ";
                    cin >> position;
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