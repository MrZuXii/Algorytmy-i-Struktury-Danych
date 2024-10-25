#include <iostream>

using namespace std;

struct Element {
    char dataItem;
    Element* next;
};

class Stack {
   private:
    Element* top;

   public:
    Stack() : top(nullptr) {};

    bool EMPTY() {
        if (top == nullptr) return true;
        return false;
    }
    void PUSH(char x) {
        Element* newItem = new Element;
        newItem->next = top;
        newItem->dataItem = x;
        top = newItem;
    }
    void POP() {
        if (EMPTY()) {
            cout << "Error: Stos pusty" << endl;
            return;
        }
        Element* temp = top;
        top = top->next;
        delete temp;
    }
    void TOP() {
        if (EMPTY()) {
            cout << "Error: Stos pusty" << endl;
            return;
        }
        cout << "Gora stosu: " << top->dataItem << endl;
    }
    void CLEAR() {
        while (!EMPTY()) POP();
    };
};
int main() {
    Stack stos;
    stos.PUSH('K');
    stos.PUSH('A');
    stos.PUSH('M');
    stos.PUSH('I');
    stos.TOP();
    stos.POP();
    stos.TOP();
    stos.CLEAR();
    stos.TOP();
    stos.PUSH('I');
    stos.TOP();
    return 0;
}