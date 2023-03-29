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
                s.push(temp);
            break;
            case 2:
                if(s.empty())  {
                    cout << endl << "Stack Underflow..!!";
                    break;
                }
                cout << endl << "The element popped out is: ";
                cout << s.top();
                s.pop();
            break;
            case 3:
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