#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Stack initial condition
int top = -1;
int Arr[10];

class Stack {
    public:
        void Push(int);
        int Pop();
        void Display();
        //Destructor.
        ~Stack () {
            cout << endl << "Object Destroyed...!!!";
        }
};

void Stack::Push(int n) {
    //if the stack is emtpy
    //pre-increment is used because the value of top is increased first and inserted into the stack.
    Arr[++top] = n;
}

int Stack::Pop() {
    if (top == -1) {
        cout << "Stack is emtpy...!!!" << endl;
        return -1;
    }
    int temp;
    //post-decrement is used because the value of the top is assigned to the temp variable and then decremented.
    temp = Arr[top--];
    return temp;
}

void Stack::Display() {
    //Check if the stack is empty or not.
    if (top == -1) {
        cout << endl << "Stack is empty";
        return;
    }
    for (int i = 0; i <= top; i++) 
        cout << Arr[i] << endl;
    return;
}

int main() {
    Stack s;
    int ch,temp;
    do {
        cout << endl << "\t\tMenu";
        cout << endl << "1.Push";
        cout << endl << "2.Pop";
        cout << endl << "3.Display";
        cout << endl << "4.Exit";
        cout << endl << "Enter your choice: [ ]\b\b";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << endl << "Enter the element to push into the stack: ";
                cin >> temp;
                s.Push(temp);
            break;
            case 2:
                cout << endl << "The element popped out is: " << s.Pop();
            break;
            case 3:
                s.Display();
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
    return 0;
}