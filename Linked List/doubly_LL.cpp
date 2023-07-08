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

        // Unparameterized constructor.
        LinkedList () {
            head = nullptr;
        }
        ~LinkedList() {
            Node *temp = head;
            while(head != nullptr) {
                head = head->next;
                free (temp);
                temp = head;
            }
            delete head;
            std::cout << "\nThe object is destroyed...!!!";
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
void LinkedList::Reverse() {
    if (head == nullptr){
        std::cout << "\nThe list is empty...!!!";
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
void LinkedList::ReverseDispaly() {
    if (head == nullptr) {
        std::cout << "\nThe list is empty...!!!";
        return;
    }
    Node *temp = head;
    while(temp->next != nullptr) 
        temp = temp->next;
    while(temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
}

void LinkedList::DeleteAtPosition(int position) {
    // Check if the given positon is valid or not.
    if (position > CountNodes()) {
        std::cout << "\nInvalid position.";
        return;
    }
    // Check if the list is empty or not.
    if(head == nullptr) 
        std::cout << "\nThe list is empty..!!";
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

int LinkedList::CountNodes() {
    //Check if the list is empty or not.
    if (head == nullptr) {
        std::cout << "\nThe list is empty";
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

void LinkedList::DeleteAtHead() {
    //Check if the list is empty or not.
    if (head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    head = head->next;
    head->prev = nullptr;
}

void LinkedList::InsertAtPosition(int data, int position) {
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

void LinkedList::InsertAtHead(int data) {
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

void LinkedList::DeleteAtTail() {
    //Check if the list is empty or not.
    if(head == nullptr) {
        std::cout << "\nThe list is empty";
        return;
    }
    Node *temp = head;
    while(temp->next != nullptr) 
        temp = temp->next;
    temp = temp->prev;
    temp->next = nullptr;
}

void LinkedList::Insert(int data) {
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

void LinkedList::Display() {
    //Check if the list is empty or not.
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
    LinkedList list;
    int ch,temp,p;
    do {
        std::cout << "\n\t\t         MENU";
        std::cout << "\n1.Insert" << "2.Inset at Head";
        std::cout << "\n3.Insert at Position";
        std::cout << "\n4.Delete at Tail";
        std::cout << "\n5.Delete at Position";
        std::cout << "\n6.Delete at Head";
        std::cout << "\n7.Reverse";
        std::cout << "\n8.Reverse Display";
        std::cout << "\n9.Display";
        std::cout << "\n99.Exit";
        std::cout << "\n\tEnter your choice: [  ]\b\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cin >> temp;
                list.Insert(temp);
            break;
            case 2:
                std::cin >> temp;
                list.InsertAtHead(temp);
            break;
            case 3:
                std::cin >> temp;
                std::cout << "\nEnter the position to insert: ";
                list.InsertAtPosition(temp,p);
            break;
            case 4:
                list.DeleteAtTail();
            break;
            case 5:
                std::cout << "\nEnter the position to delete: ";
                std::cin >> p;
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