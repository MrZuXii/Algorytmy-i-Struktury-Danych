#include <iostream>

using namespace std;

const int capacity = 1000;

class ADT {
   private:
    char items[capacity];
    int head;
    int tail;
    int size;

    int addone(int i) { return (i + 1) % capacity; }

   public:
    ADT() : head(0), tail(0), size(0) {}

    bool EMPTY() {
        if (size == 0) return true;
        return false;
    }
    bool FULL() {
        if (size == capacity) return true;
        return false;
    }

    // Wstawia element x na końcu kolejki (za elementem na pozycji tail)
    void ENQUEUE(char x) {
        if (FULL()) {
            cout << "Error: Kolejka jest pełna" << endl;
            return;
        }
        items[tail] = x;
        tail = addone(tail);
        size = size + 1;
    }

    // Usuwa element z początku kolejki (z pozycji head)
    void DEQUEUE() {
        if (EMPTY()) {
            cout << "Error: Kolejka jest pusta";
            return;
        }
        head = addone(head);
        size = size - 1;
    }

    // Zwraca pierwszy element kolejki (ale go nie usuwa)
    void FRONT() {
        if (EMPTY()) {
            cout << "Error: Kolejka jest pusta";
            return;
        }
        cout << "Pierwszy element kolejki to: " << items[head] << endl;
    }

    // Usuwa wszystkie elementu kolejki
    void CLEAR() {
        if (EMPTY()) {
            cout << "Error: Kolejka jest pusta";
            return;
        }
        size = 0;
        head = 0;
        tail = -1;
    }
};

int main() {
    ADT kolejka;
    kolejka.ENQUEUE('K');
    kolejka.ENQUEUE('A');
    kolejka.ENQUEUE('M');
    kolejka.ENQUEUE('I');
    kolejka.ENQUEUE('L');
    kolejka.FRONT();    // Oczekiwany wynik: K
    kolejka.DEQUEUE();  // Usuwa K
    kolejka.FRONT();    // Oczekiwany wynik: A
    kolejka.CLEAR();    // Resetuje kolejkę
    kolejka.FRONT();    // Oczekiwany wynik: Error: Kolejka jest pusta
    return 0;
}