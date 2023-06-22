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
    public:
        Node *head = nullptr;
        //Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~LinkedList() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                free(temp);
                temp = head;
            }
            std::cout << "\nList has been Destroyed...!!!";
        }
        void Insert(int data);
        int CountNodes();
        void Display();
};

int LinkedList::CountNodes() {
    Node *temp = head;
    int count =0;
    if (head == nullptr) {
        std::cout << count;
        return -1;
    }
    while(temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return count;
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

int main() {

    //Object of class LinkedList.
    LinkedList list;
    int temp,ch;
    //Menu driven program.
    do {
        std::cout << "\t\t      MENU\n";
        std::cout << "\t\t1.Insert\n";
        std::cout << "\t\t2.Count the total number of nodes\n";
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
                    std::cout << "\nThe total number of nodes are: " << list.CountNodes() << "\n";
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