#include <iostream>

using namespace std;

class Element {
   private:
    int v;
    Element* next;

   public:
    Element(int x, Element* next) : v(x), next(next) {};
    int getValue() { return v; };
    Element* getNext() { return next; };
    void setNext(Element* p) { next = p; };
};

class LinkedStack {
   private:
    Element* top;

   public:
    LinkedStack() : top(nullptr) {};  // tworzy pusty stos
    bool empty() { return top == nullptr; };
    void push(int x) {
        Element* newItem = new Element(x, nullptr);
        if (top == nullptr) {
            top = newItem;
            return;
        }
        newItem->setNext(top);
        top = newItem;
    }  // wstawia daną na stos
    int peek() {
        if (empty()) {
            cout << "Error: Nie mozna sprawdzic danych. Stos jest pusty"
                 << endl;
            return;
        }

        return top->getValue();
    }  // zwraca daną ze stosu
    void pop() {
        if (empty()) {
            cout << "Error: Nie mozna usunac danych. Stos jest pusty" << endl;
            return;
        }
        top = top->getNext();
    }  // usuwa element ze stosu
    void clear() { top = nullptr; };  // usuwa wszystkie elementy ze stosu
    friend std::ostream& operator<<(std::ostream& out, LinkedStack& s) {
        Element* helper = s.top;
        while (s.top != null) {
            out <<
        };
    }
    // wyświetla zawartość całego stosu
    ~LinkedStack() { delete top; }
};

int main() {
    LinkedStack stos;
    stos.push(1);
    stos.push(2);
    stos.push(3);
    stos.pop();
    cout << stos.peek();
    // cout << "hello world";
    return 0;
}