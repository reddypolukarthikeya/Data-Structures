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
        void Display();
        void Insert(int);
};

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
        cout << "2.Display" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter your choice: [  ]\b\b";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << endl << "Enter the data to insert:";
                cin >> temp;
                list.Insert(temp);
            break;
            case 2:
                list.Display();
            break;
            case 3:
                return 0;
        }
    }while(ch != 4);
}
