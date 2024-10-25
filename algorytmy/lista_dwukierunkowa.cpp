#include <iostream>

using namespace std;

struct Element {
    Element* prev;
    char dataItem;
    Element* next;
};

class DLLWS {
   private:
    Element* head;
    Element* tail;
    int size;

   public:
    DLLWS() : size(0) {
        head = new Element();
        head->prev = head;
        head->next = head;
        tail = head;
    }

    // Zwraca długość/rozmiar listy
    int SIZE() { return size; };

    // Zwraca true jeśli lista jest pusta, false jeśli lista nie jest pusta
    bool EMPTY() { return size == 0; }

    void FIRST() {
        if (EMPTY()) {
            cout << "Error: Lista jest pusta" << endl;
            return;
        }
        cout << "Pierwszy element listy: " << head->next->dataItem << endl;
    }

    void LAST() {
        if (EMPTY()) {
            cout << "Error: Lista jest pusta" << endl;
            return;
        }
        cout << "Ostatni element listy: " << tail->dataItem << endl;
    }

    void LOCATE(char x) {
        if (EMPTY()) {
            cout << "Error: Lista jest pusta" << endl;
            return;
        }
        Element* helper = head->next;

        while (helper != head) {
            if (helper->dataItem == x) {
                cout << "Znalazłem: " << helper->dataItem << endl;
                return;
            }
            helper = helper->next;
        }
        cout << "Nie znalazłem: " << x << " :( " << endl;
    }

    // Usuwa wszystkie elementy listy
    void CLEAR() {
        while (!EMPTY()) {
            Element* oldItem = tail;
            tail = tail->prev;
            delete oldItem;
            size--;
        }
        head->next = head;
        head->prev = head;
        tail = head;
    }

    void INSERT(char x) {
        Element* newItem = new Element();

        newItem->prev = tail;
        newItem->dataItem = x;
        newItem->next = head;

        tail->next = newItem;
        tail = newItem;
        head->prev = tail;
        size++;
    }

    void TRAVERSE() {
        if (EMPTY()) {
            cout << "Error: Lista jest pusta" << endl;
            return;
        }

        cout << "Wszystkie elementy listy: ";

        Element* helper = head->next;
        while (helper != head) {
            cout << helper->dataItem << ", ";
            helper = helper->next;
        }
        cout << endl;
    }
};

int main() {
    DLLWS lista;
    cout << "----------------------------------------------------\n";
    lista.INSERT('K');
    lista.INSERT('A');
    lista.INSERT('M');
    lista.INSERT('I');
    lista.INSERT('L');
    lista.FIRST();
    lista.LAST();
    cout << "----------------------------------------------------\n";
    lista.LOCATE('W');
    lista.INSERT(' ');
    lista.INSERT('B');
    lista.TRAVERSE();
    cout << "----------------------------------------------------\n";
    return 0;
}