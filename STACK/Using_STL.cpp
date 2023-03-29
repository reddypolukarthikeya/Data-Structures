#include <iostream>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::stack;

int main() {
    stack<int> s,t;
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
                //Using the push member funciton to insert the element into the stack.
                s.push(temp);
            break;
            case 2:
                // empty() memeber function returns true if the stack is empty and false if not empty.
                if(s.empty())  {
                    cout << endl << "Stack Underflow..!!";
                    // To avoid Segmentation Fault break statement is added.
                    break;
                }
                cout << endl << "The element popped out is: ";
                //The top() member function returns the top most element of the stack.
                cout << s.top();
                //The pop() member function deletes the element from the stack.
                s.pop();
            break;
            case 3:
            // Since pop() function deletes the element from the stack which 
            // brings the temporary stack to print the elements in the stack.
                t = s;
                while(!t.empty()) {
                    cout << t.top() << endl;
                    t.pop();
                }
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
    return 0;
}