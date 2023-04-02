#include <iostream>


// Using 'nampespace std;' is considered as bad programming practice.
using std::cin;
using std::cout;
using std::endl;

class Node {
    public:
        Node *prev;
        int data;
        Node *next;
        Node() {
            prev = NULL;
            data = -1;
            next = NULL;
        }
        Node (int data) {
            prev = NULL;
            this->data = data;
            next = NULL;
        }
};

class List {
    private:
        Node *head = NULL;
    public:
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~List() {
            Node *temp = head;
            while(head != NULL) {
                head = head->next;
                free (temp);
                temp = head;
            }
            free(head);
            free(temp);
            cout << endl << "The list is destroyed...!!!";
        }
        void Insert(int);
        void Display();
        void DeleteAtTail();
};

/*NOTE:- ->HERE DELETION MEANS POINTING TO THE NEXT->NEXT NODE AND NOT ACTUALLY DELETING THE NODE. 
         ->Reasons for not using free() and delete() :
                a.Using free() to deallocate memory allocated for an object in C++ is not recommended because 
                  it does not call the object's destructor.
                b.When executed, a "SEGMENTATION FAULT" will occur.
         ->In the end thats why a destructor is added to destroy the memory used and free the allocated memory.
*/
void List::DeleteAtTail(){
    //Check if the list is empty or not.
    if(head == NULL) {
        cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) 
        temp = temp->next;
    temp = temp->prev;
    temp->next = NULL;
}

void List::Insert(int data) {
    Node *newNode = new Node(data);
    //Check if the list is empty or not and if the list is empty, make the newNode as head of the list.
    if (head == NULL) {
        head = newNode;
        return;
    }
    //If not empty, traverse to the end of the list.
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void List::Display() {
    //Check if the list is empty or not.
    if (head == NULL) {
        cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        if(temp->next == NULL) {
            cout << temp->data;
            return;
        }
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

int main() {
    List list;
    int ch,temp,p;
    do {    
        cout << "\t\t         MENU" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Delete at Tail" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: [  ]\b\b";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << endl << "Enter the data to insert:";
                cin >> temp;
                list.Insert(temp);
            break;
            case 2:
                list.DeleteAtTail();
            case 3:
                list.Display();
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
}