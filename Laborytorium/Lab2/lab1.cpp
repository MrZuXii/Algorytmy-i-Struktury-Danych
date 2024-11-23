#include <iostream>
using namespace std;

class ArrayStack {
   private:
    int* items;
    int capacity;  // pojemność stosu
    int top;       // wierzchołek stosu
   public:
    ArrayStack(int c) : capacity(c), top(-1) {
        items = new int[capacity];
    };  // tworzy pusty stos o pojemności c
    bool empty() { return top == -1; };
    bool full() { return capacity - 1 == top; };
    void push(int x) {
        if (full()) {
            cout << "Error: Nie mozna dodac danych. Stos jest pelny" << endl;
            return;
        }
        top++;
        items[top] = x;
    };  // wstawia daną na stos
    int peek() {
        if (empty()) {
            cout << "Error: Nie mozna wyswietlic danych. Stos jest pusty"
                 << endl;
            return;
        }
        return items[top];
    }  // zwraca daną ze stosu

    void pop() {
        if (empty()) {
            cout << "Error: Nie mozna usunac danych. Stos jest pusty" << endl;
            // cout << "Stos jest pusty" << endl;
            return;
        }
        top--;
    };  // usuwa daną ze stosu

    void clear() { top = -1; }  // usuwa wszystkie elementy ze stosu

    friend std::ostream& operator<<(std::ostream& out, ArrayStack& s) {
        if (s.empty()) {
            out << "Stos jest pusty" << endl;
            return out;
        }
        for (int i = 0; i <= s.top; i++) {
            out << s.items[i] << ' ';
        }
        // out << s.peek();
        return out;
    }  // wyświetla całą zawartość stosu
    ~ArrayStack() {
        delete[] items;
        capacity = 0;
        top = 0;
    };
};

int main() {
    ArrayStack stos(10);
    stos.push(2);               // 1
    stos.push(4);               // 2
    stos.push(6);               // 3
    stos.push(8);               // 4
    stos.push(12);              // 5
    stos.push(14);              // 6
    stos.push(16);              // 7
    stos.push(18);              // 8
    stos.push(20);              // 9
    stos.push(22);              // 10
    stos.push(24);              // 11
    stos.push(26);              // 12
    std::cout << stos << '\n';  // 10 elementów
    stos.pop();                 // 1
    std::cout << stos << '\n';  // 9 elementów
    stos.pop();                 // 1
    stos.pop();                 // 2
    stos.pop();                 // 3
    stos.pop();                 // 4
    stos.pop();                 // 5
    stos.pop();                 // 6
    stos.pop();                 // 7
    stos.pop();                 // 8
    stos.pop();                 // 9
    stos.pop();                 // 10
    std::cout << stos << '\n';  // 0 elementów
    return 0;
}