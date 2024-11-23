#include <iostream>

using namespace std;

class ArrayFifo {
   private:
    int* items;
    int capacity;  // pojemność kolejki
    int size;      // rozmiar kolejki (liczba elementów w kolejce)
    int head;      // indeks pierwszego elementu kolejki
    int tail;      // indeks ostatniego elementu kolejki
   public:
    ArrayFifo(int c) : capacity(c) {};  // tworzy pustą kolejkę o pojemności c
    bool empty() {
        if (size == 0) return true;
        return false;
    };
    bool full() {
        if (size >= capacity) return true;
        return false;
    };

    int addone(int i) { return (i + 1) % capacity; }

    void enqueue(int x) {
        if (full()) {
            cout << "Error: Kolejka jest pełna";
            return;
        }

    };  // dodaje daną do kolejki
    int peek();      // zwraca daną z kolejki
    void dequeue();  // usuwa daną z kolejki
    void clear();    // usuwa wszystkie elementy z kolejki
    friend std::ostream& operator<<(
        std::ostream& out,
        ArrayFifo& f);  // wyświetla zawartość kolejki (od head do tail)
    ~ArrayFifo();
};

int main() {
    cout << "Hello World";
    return 0;
}