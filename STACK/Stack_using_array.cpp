#include <iostream>

// Using 'nampespace std;' is considered as bad programming practice.

class Stack {
    private:
        int top;
        int Arr[10];
    public:
        // Unparameterized constructor.
        Stack() {
            // Initialize top to -1 indicating an empty stack.
            top = -1;
        }
        // Function to push an element onto the stack.
        void Push(int);
        // Function to pop an element from the stack.
        int Pop();
        // Function to display the elements in the stack.
        void Display();
        //Destructor.
        ~Stack () {
            std::cout << "\nObject Destroyed...!!!";
        }
};

void Stack::Push(int n) {
    // Check if the stack is full.
    // Stack full condition is called "Stack Overflow".
    if (top > 10) {
        std::cout << "\nStack Overflow...!!!!";
        return;
    }
    // pre-increment is used because the value of top is increased first and inserted into the stack.
    Arr[++top] = n;
}

int Stack::Pop() {
    // Check if the stack is empty.
    // Stack empty condition is called "Stack Underflow"
    if (top == -1) {
        std::cout << "Stack Underflow...!!!\n";
        return -1;
    }
    int temp;
    // Post-decrement is used because the value of the top is assigned to the temp variable and then decremented.
    temp = Arr[top--];
    return temp;
}

void Stack::Display() {
    // Check if the stack is empty or not.
    if (top == -1) {
        std::cout << "\nStack is empty";
        return;
    }
    for (int i = top; i>=0 ; i--) 
        std::cout << Arr[i] << "\n";
    return;
}

int main() {
    Stack s;
    int ch,temp;
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
                std::cout << "\nThe element popped out is: " << s.Pop();
            break;
            case 3:
                s.Display();
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
}