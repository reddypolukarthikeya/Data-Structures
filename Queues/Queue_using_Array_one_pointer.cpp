#include <iostream>

// Using "namespace std;" is considered as bad programming practice.

class Queue {
     
    private:
        int front;
        int Arr[10];
    public:
        Queue() {
            front = -1;
            Arr[10] = {0};
        }
        void Enqueue(int data);
        void Display();
};

void Queue::Enqueue(int data) {
    if (front > 9) {
        std::cout << "\nQueue is full.";
        return;
    }
    Arr[++front] = data;
}

void Queue::Display() {
    // Check if the queue is empty.
    if (front == -1) {
        std::cout << "\nQueue is empty.";
        return;
    }
    for (int i=0; i <= front ;i++) {
        std::cout << Arr[i] << "\n";
    }
}

int main() {
    Queue q;
    int ch;
    do {
        std::cout << "\n\tMenu";
        std::cout << "\n1.Enqueue";
        std::cout << "\n2.Display";
        std::cout << "\n4\3.Exit";
        std::cout << "\n\tEnter your choice : [ ]\b\b";
        std::cin >> ch;
        switch (ch) {
            case 1:
                int temp;
                std::cout << "\nEnter the element to insert into the queue: ";
                std::cin >> temp;
                q.Enqueue(temp);
            break;
            case 2:
                q.Display();
            break;
            case 3:
                return 0;
            break;
            default:
                std::cout << "\nInvalid choice..!!";
            break;
        }    
    }while(ch != 4);
}