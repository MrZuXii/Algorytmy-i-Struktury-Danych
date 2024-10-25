#include <iostream>

using namespace std;

struct Element {
    char dataItem;
    Element* next;
    Element* prev;
};

class ADT {
   private:
    Element* head;

   public:
    ADT() {
        head = new Element();
        head->prev = head;
        head->next = head;
        head->dataItem = '\0';
    };

    // Zwraca true jeśli kolejka jest kolejką pustą, false jeśli nie jest
    bool EMPTY() {
        if (head->next == head) return true;
        return false;
    }

    // Wstawia element x na końcu kolejki
    void ENQUEUE(char x) {
        Element* newItem = new Element();
        newItem->dataItem = x;

        newItem->prev = head->prev;
        head->prev->next = newItem;

        head->prev = newItem;
    }

    // Usuwa element z początku kolejki
    void DEQUEUE() {
        if (EMPTY()) {
            cout << "Error: Pusta kolejka" << endl;
            return;
        }
        Element* oldItem = head->next;
        head->next = oldItem->next;
        oldItem->next->prev = oldItem->prev;
        delete oldItem;
    }

    // Zwraca pierwszy element kolejki (ale go nie usuwa)
    void FRONT() {
        if (EMPTY()) {
            cout << "Error: Pusta kolejka" << endl;
            return;
        }
        cout << "Pierwszy element kolejki to: " << head->next->dataItem << endl;
    }
};

int main() {
    ADT kolejka;
    kolejka.ENQUEUE('K');
    kolejka.ENQUEUE('A');
    kolejka.ENQUEUE('M');
    kolejka.ENQUEUE('I');
    kolejka.ENQUEUE('L');
    kolejka.FRONT();  // Oczekiwany wynik: K

    kolejka.DEQUEUE();  // Usuwa K
    kolejka.FRONT();    // Oczekiwany wynik: A

    return 0;
}