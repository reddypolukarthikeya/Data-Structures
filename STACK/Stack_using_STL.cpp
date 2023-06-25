#include <iostream>
#include <stack>

// Using 'nampespace std;' is considered as bad programming practice.

int main() {
    std::stack<int> s,t;
    int ch,temp;
    do {
        std::cout << "\n\t\tMenu";
        std::cout  << "\n1.Push";
        std::cout  << "\n2.Pop";
        std::cout  << "\n3.Display";
        std::cout  << "\n4.Exit";
        std::cout  << "\nEnter your choice: [ ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cout  << "\nEnter the element to push into the stack: ";
                std::cin >> temp;
                // Using the push member funciton to insert the element into the stack.
                s.push(temp);
            break;
            case 2:
                // empty() memeber function returns true if the stack is empty and false if not empty.
                if(s.empty())  {
                    std::cout  << "\nStack Underflow..!!";
                    // To avoid Segmentation Fault break statement is added.
                    break;
                }
                std::cout  << "\nThe element popped out is: ";
                //The top() member function returns the top most element of the stack.
                std::cout  << s.top();
                //The pop() member function deletes the element from the stack.
                s.pop();
            break;
            case 3:
            // Since pop() function deletes the element from the stack which 
            // brings the temporary stack to print the elements in the stack.
                t = s;
                while(!t.empty()) {
                    std::cout  << t.top();
                    std::cout << "\n";
                    t.pop();
                }
            break;
            case 4:
                return 0;
        }
    }while(ch != 4);
    return 0;
}