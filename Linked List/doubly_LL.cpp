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

class List {
    private:
        Node *head = nullptr;
    public:
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~List() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                free (temp);
                temp = head;
            }
            free(head);
            free(temp);
            cout << endl << "The object is destroyed...!!!";
        }
        int CountNodes();
        void Display();
        void DeleteAtTail();
        void DeleteAtHead();
        void DeleteAtPosition(int);
        void Insert(int);
        void InsertAtHead(int);
        void InsertAtPosition(int, int);
        void RemoveDuplicates();
        void ReverseDispaly();
        void Reverse();
};

//This function actually performs the reverse function.
void List::Reverse() {
    if (head == nullptr){
        cout << "The list is empty...!!!" << endl;
        return;
    }
    Node *temp = nullptr;
    Node *current = head;
    // Swap all the prev and next
    while(current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr)
        head = temp->prev;
}

//Note:- This function does not reverse the linked instead it just prints in reverse order.
void List::ReverseDispaly() {
    if (head == nullptr) {
        cout << "The list is empty...!!!" << endl;
        return;
    }
    Node *temp = head;
    while(temp->next != nullptr) 
        temp = temp->next;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

void List::DeleteAtPosition(int position) {
    // Check if the given positon is valid or not.
    if (position > CountNodes()) {
        cout << "Invalid position" << endl;
        return;
    }
    // Check if the list is empty or not.
    if(head == nullptr) 
        cout << "The list is empty..!!" << endl;
    if (position == 1) {
        DeleteAtHead();
        return;
    }
    // To delete the last node in the list.
    if (position == CountNodes()) {
        DeleteAtTail();
        return;
    }
    Node *temp = head;
    while (position > 1 && temp->next != nullptr) {
        temp = temp->next;
        position--;
    }
    temp = temp->prev;
    temp->next = temp->next->next;
    temp = temp->next;
    temp->prev = temp->prev->prev;
}  

int List::CountNodes() {
    //Check if the list is empty or not.
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return 0;
    }
    int count=0;
    Node *temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void List::DeleteAtHead() {
    //Check if the list is empty or not.
    if (head == nullptr) {
        cout << "The list is empty";
        return;
    }
    head = head->next;
    head->prev = nullptr;
}

void List::InsertAtPosition(int data, int position) {
    Node *newNode = new Node(data);
    //Check if the list is empty and if emtpy make the newNode as head node of the list.
    if(head == nullptr) {
        head = newNode;
        return;
    }
    Node *temp = head;
    if (position == 1) {
        InsertAtHead(data);
        return;
    }
    //Traversing to the position to insert.
    while(position > 1 && temp != nullptr) {
        position--;
        temp = temp->next;
    }  
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
}

void List::InsertAtHead(int data) {
    Node *newNode = new Node(data);
    //Check if the list is empty and if the list is empty make the newNode as the head of the list.
    if(head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void List::DeleteAtTail() {
    //Check if the list is empty or not.
    if(head == nullptr) {
        cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp->next != nullptr) 
        temp = temp->next;
    temp = temp->prev;
    temp->next = nullptr;
}

void List::Insert(int data) {
    Node *newNode = new Node(data);
    //Check if the list is empty or not and if the list is empty, make the newNode as head of the list.
    if (head == nullptr) {
        head = newNode;
        return;
    }
    //If not empty, traverse to the end of the list.
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void List::Display() {
    //Check if the list is empty or not.
    if (head == nullptr) {
        cout << "The list is empty";
        return;
    }
    Node *temp = head;
    while(temp != nullptr) {
        if(temp->next == nullptr) {
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
        cout << "1.Insert" << endl << "2.Inset at Head" << endl;
        cout << "3.Insert at Position" << endl;
        cout << "4.Delete at Tail" << endl;
        cout << "5.Delete at Position" << endl;
        cout << "6.Delete at Head" << endl;
        cout << "7.Reverse" << endl;
        cout << "8.Reverse Display" << endl;
        cout << "9.Display" << endl;
        cout << "99.Exit" << endl;
        cout << "\n\tEnter your choice: [  ]\b\b\b";
        cin >> ch;
        switch (ch) {
            case 1:
                cin >> temp;
                list.Insert(temp);
            break;
            case 2:
                cin >> temp;
                list.InsertAtHead(temp);
            break;
            case 3:
                cin >> temp;
                cout << endl << "Enter the position to insert: ";
                list.InsertAtPosition(temp,p);
            break;
            case 4:
                list.DeleteAtTail();
            break;
            case 5:
                cout << endl << "Enter the position to delete: ";
                cin >> p;
                list.DeleteAtPosition(p);
            break;
            case 6:
                list.DeleteAtHead();
            break;
            case 7:
                list.Reverse();
            break;
            case 8:
                list.ReverseDispaly();
            break;
            case 9:
                list.Display();
            break;
            case 99:
                return 0;
        }
    }while(ch != 99);
    return 0;
}