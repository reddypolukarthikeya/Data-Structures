#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Node {
    public:
        int data;
        Node *next;
    Node ()
    {
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList {
    private:
        Node* head = new Node();
    public:
        void insert(int);
        void print();
};

void LinkedList::insert(int x) {
    Node* newnode = new Node(x);
    if (head == NULL) {
        head = newnode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
};

void LinkedList::print() {
    Node* temp = head;  
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL) {
        temp = temp->next;
        cout << temp->data << " ";
        
    }
}
int main()
{
    LinkedList list;
    int n,temp;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> temp;
        list.insert(temp);
    }
    list.print();
    return 0;
}