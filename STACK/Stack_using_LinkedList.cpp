#include <iostream>

// Using "namepace std;" is considered as bad programming practice.

class Node {
    public:
        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class Stack {
    private:
        Node *top;
    public:

        Stack () {
            top = nullptr;
        }
        // Destructor to detroy the linked list and free memory allocated the list.
        // Default destructor only deletes head (allocated by constructor).
        // We need destructor to free the memory used by all individual nodes.
        ~Stack() {
            Node *temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }
        void Push(int data);
        int Pop();
        void Display();
};

void Stack::Push(int data) {
    Node *newNode = new Node(data);
    // Check if the stack is empty.
    if (top == nullptr) {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}
/*  NOTE:-  ->HERE DELETION MEANS POINTING TO THE NEXT->NEXT NODE AND NOT ACTUALLY DELETING THE NODE. 
            ->Reasons for not using free() :
        a.Using free() to deallocate memory allocated for an object in C++ is not recommended because 
          it does not call the object's destructor.
        b.When executed, a "SEGMENTATION FAULT" will occur.
        c.free() can only be used to deallocate memory that has been allocated using "malloc()" and "calloc()".
        d.delete is used when the memory is allocated using "new";
*/
int Stack::Pop() {
    // Check if the stack is empty.
    if (top == nullptr) {
        std::cout << "\nStack is empty\n";
        return -1;
    }
    Node *temp = top;
    top = top->next;
    return temp->data;
}

void Stack::Display() {
    // Check if the stack is empty.
    if (top == nullptr) {
        std::cout << "\nStack is empty..!\n";
        return;
    }
    std::cout << "\n";
    Node *temp = top;
    while (temp) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
}

int main() {
    Stack s;
    int ch, temp;
    // Menu driven program.
    do {
        std::cout << "\n\t\tMenu";
        std::cout << "\n1.Push";
        std::cout << "\n2.Pop";
        std::cout << "\n3.Display";
        std::cout << "\n4.Exit";
        std::cout << "\nEnter your choice: [ ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cout << "\nEnter the element to push into the stack: ";
                std::cin >> temp;
                s.Push(temp);
            break;
            case 2:
                std::cout << "\nElement popped out is : " << s.Pop();
            break;
            case 3:
                s.Display();
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
}