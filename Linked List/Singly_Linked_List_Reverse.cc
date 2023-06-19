#include <iostream>

//Usage of namespace std is considered as bad programming practice.

class Node {
    public:
        int data;
        Node *next;
    
        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class List{
    private:

        Node *head;

    public:

        List() : head(nullptr) {}
        //Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~List () {
            Node *temp = head;
            while (head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
        } 
        void Insert (int data);
        void Reverse ();
        void Display();
};

void List::Insert(int data) {
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

void List::Display() {
    //Check if the list is empty.
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    //If the list is not empty
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void List::Reverse() {
    // If the list is empty
    if (head == nullptr) {
        std::cout << "The list is empty\n";
        return;
    }
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr) {
        // Store the next node.
        next = current->next;
        // Reverse the link.
        current->next = prev;

        // Move the pointers one poisition ahead.
        prev = current;
        current = next;
    }
    // Make the prev as new head of the list.
    head = prev;
}

int main() {
    List l;
    int ch;
    do {
        std::cout << "\tMenu\n";
        std::cout << "1.Insert\n";
        std::cout << "2.Reverse\n";
        std::cout << "3.Display\n";
        std::cout << "4.Exit\n";
        std::cout << "Enter your choice: [ ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                int temp;
                std::cin >> temp;
                l.Insert(temp);
            break;
            case 2:
                l.Reverse();
                l.Display();
            break;
            case 3:
                l.Display();
            break;
            case 4:
                return 0;
        }
    }while (ch != 4);
    return 0;
}