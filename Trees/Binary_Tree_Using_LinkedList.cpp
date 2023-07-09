#include <iostream>

// Using "namespace std;" is considered as bad programming practice.

class Node {

    public:

        Node *left;
        int data;
        Node *right;
        // Unparameterized constructor.
        Node (int data) {
            left = nullptr;
            this->data = data;
            right = nullptr;
        }
};

class BinaryTree {

    private:

        Node *root;

    public:

        BinaryTree() {
            root = nullptr;
        }
        void Insert(int data);
        void Display();
};