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
            std::cout << "\nThe list is destroyed...!!!";
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
    if(head == nullptr) {
        std::cout << "The list is empty";
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
        std::cout << "\t\t         MENU\n";
        std::cout << "1.Insert\n";
        std::cout << "2.Delete at Tail\n";
        std::cout << "3.Display\n";
        std::cout << "4.Exit\n";
        std::cout << "Enter your choice: [  ]\b\b";
        std::cin>> ch;
        switch (ch) {
            case 1:
                std::cout << "\nEnter the data to insert:";
                std::cin>> temp;
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
