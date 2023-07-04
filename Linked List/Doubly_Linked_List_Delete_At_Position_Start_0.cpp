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

class List {
    private:
        int size;
        Node *head;
    public:
        List () {
            size = 0;
            head = nullptr;
        }
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~List() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
            delete head;
            delete temp;
            std::cout << "\nThe object is destroyed...!!!";
        }
        void Display();
        void DeleteAtPosition(int);
        void Insert(int);
};

void List::DeleteAtPosition(int position) {
    if (position >= size) {
        std::cout << "\nInvalid Position";
        return;
    }
    Node* temp = head;
    if (position == 0) {
        head = head->next;
        head->prev = nullptr;
    }
    else {
        Node *pre = nullptr;
        temp = head;
        while (position > 0 && temp->next != nullptr) {
            pre = temp;
            temp = temp->next;
            position--;
        }
        pre->next = temp->next;
    }
    delete temp;
    size --;
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
    size ++;
}

void List::Display() {
    //Check if the list is empty or not.
    if (head == nullptr) {
        std::cout << "The list is empty";
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
    List list;
    int ch,temp,p;
    do {
        std::cout << "\n\t\t         MENU\n";
        std::cout << "1.Insert" << "\n2.Delete at POSITION\n";
        std::cout << "3.Display\n" << "4.Exit\n";
        std::cout << "\n\tEnter your choice: [  ]\b\b\b";
        std::cin>> ch;
        switch (ch) {
            case 1:
                std::cout << "\nEnter the element to insert: ";
                std::cin>> temp;
                list.Insert(temp);
            break;
            case 2:
                std::cout << "\nEnter the position to delete: ";
                std::cin>> p;
                list.DeleteAtPosition(p);
            break;
            case 3:
                list.Display();
            break;
            case 4:
                return 0;
            break;
            default:
                std::cout << "Invalid choice..!!";
            break;
        }
    }while(ch != 4);
}