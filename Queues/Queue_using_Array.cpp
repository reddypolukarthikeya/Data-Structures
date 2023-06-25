#include <iostream>

// Using "namespace std;" is considered as a bad programming practice.

class Queue {

    private:

        // "top" is used to insert the elements from the queue.
        int top;
        // "front" is used to delete the elements from the queue.
        int front;
        int Arr[10];

    public:
        Queue() {
            // Queue initial conditions.
            top = -1;
            front = -1;
            Arr[10] = {0};
        }
        void Enqueue(int data);
        int Dequeue();
        void Display();
};

// Insertion operation in queue is called "Enqueue".
void Queue::Enqueue(int data) {
    // Check if the queue is empty.
    if (front == -1) {
        Arr[++top] = data;
        front++;
        return;
    }
    // Check if the queue is full.
    if (top > 9) {
        std::cout << "\nQueue is full.";
        return;
    }
    Arr[++top] = data;
}

// Deletion operation in queue is called "Dequeue".
int Queue::Dequeue() {
    // Check if the queue is empty.
    if (front == -1) {
        std::cout << "\nQueue is empty..!!";
        return -1;
    }
    int temp = Arr[front];
    front++;
    return temp;
}

void Queue::Display() {
    // Check if the queue is empty.
    if (front == -1) {
        std::cout << "\nQueue is empty..!!";
        return;
    }
    while (front <= top)  {
        std::cout << "\n" << Arr[front];
        front++;
    }
}

int main() {
    Queue q;
    int ch;
    // Menu driven program.
    do {
        std::cout << "\n\tMenu";
        std::cout << "\n1.Enqueue";
        std::cout << "\n2.Dequeue";
        std::cout << "\n3.Display";
        std::cout << "\n4.Exit";
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
                std::cout << "\nThe element deleted from the queue is : ";
                std::cout << q.Dequeue();
            break;
            case 3:
                q.Display();
            break;
            case 4:
                return 0;
            break;
            default:
                std::cout << "\nInvalid choice..!!";
            break;
        }    
    }while(ch != 4);
}