#include <iostream>

// Using 'namespace std;' is considered as bad programming practice.

class Diagonal {
    private:
        // Note that the diagonal matrix is a square matrix.
        int Dimension;
        int *Arr;
    public:
        // Constructor
        Diagonal(int Dimension) {
            this->Dimension = Dimension;
            Arr = new int[Dimension];
        }
        // Destructor
        ~Diagonal() {
            delete Arr;
            std::cout << "\nArray has been deallocated.";
        }
        bool IsDiagonal();
        void Set(int row, int col, int data);
        int Get(int row, int col);
        void Display();
};

bool Diagonal::IsDiagonal() {
    for (int i=0; i<Dimension;i++) {
        for (int j=0; j<Dimension;j++) {
            if (Arr[i] != Arr[j])
                return false;
        }
    }
    return true;
}

void Diagonal::Set(int row, int col,int data) { 
    if (row == col) {
        Arr[row] = data;
        return;
    }
}

int Diagonal::Get(int row, int col) {
    if (row == col) 
        return Arr[row];
    return 0;
}

void Diagonal::Display() { 
    for (int i=0; i<Dimension;i++) {
        for (int j=0; j<Dimension;j++) {
            if (i == j)
                std::cout << Arr[i] << " ";
            else 
                std::cout << "0" << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    Diagonal d(3);
    d.Set(0,0,1);
    d.Set(1,1,2);
    d.Set(2,2,3);
    std::cout <<  d.IsDiagonal() << "\n";
    std::cout <<  d.Get(1,2) << "\n";
    d.Display();
    return 0;
}