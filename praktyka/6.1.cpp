#include <iostream>

using namespace std;

const int capacity = 1000;

class Stack {
   private:
    char items[capacity];
    int top;

   public:
    Stack() : top(-1) {}

    bool EMPTY() { return top == -1; }

    bool FULL() { return top == capacity - 1; }

    void PUSH(char x) {
        if (FULL()) {
            cout << "Error: Stos pełny" << endl;
            return;
        }
        top = top + 1;
        items[top] = x;
    }

    void POP() {
        if (EMPTY()) {
            cout << "Error: Stos pusty" << endl;
            return;
        }
        top = top - 1;
    }

    void CLEAR() {
        while (!EMPTY()) POP();
    }

    char TOP() {
        if (EMPTY()) {
            cout << "Error: Stos pusty" << endl;
            return '\0';
        }
        return items[top];
    }
};

int main() {
    Stack stos;
    cout << "STOS ADT" << endl;

    stos.PUSH('K');
    stos.PUSH('A');
    stos.PUSH('M');
    stos.PUSH('I');
    stos.PUSH('L');

    cout << "Góra stosu: " << stos.TOP() << endl;
    stos.POP();
    cout << "Góra stosu: " << stos.TOP() << endl;
    stos.PUSH('K');
    cout << "Góra stosu: " << stos.TOP() << endl;
    return 0;
}
