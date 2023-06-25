#include <iostream>

// Using "namespace std" is considered as a bad programming practice.

class Queue {

    private:
        int top;
        int front;
    public:
        Queue() {
            top = -1;
            front = -1;
        }
        void Enqueue(int data);
        int Dequeue();
};