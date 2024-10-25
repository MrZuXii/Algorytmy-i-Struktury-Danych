#include <iostream>

using namespace std;

struct Element {
    char dataItem;
    Element* next;
    Element* prev;
};

class LinkedList {
    Element* head;
    Element* tail;
    int size = 0;

   public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    };
    int SIZE() { return size; }

    bool EMPTY() {
        if (head == nullptr) return true;
        return false;
    };

    Element* FIRST() {
        if (EMPTY()) throw out_of_range("lista jest pusta");
        return tail;
    }

    Element* LAST() {
        if (EMPTY()) throw out_of_range("Lista jest pusta");
        return head;
    }

    void INSERT(char x, int k) {
        Element* tmp = new Element;
        tmp->dataItem = x;
        tmp->next = head;     // Nowy element wskazuje na stary head
        tmp->prev = nullptr;  // Nowy element będzie na początku, więc prev
                              // ustawiamy na nullptr

        if (head != nullptr) {  // Jeżeli lista nie jest pusta, poprzednia głowa
                                // musi wskazywać na nowy element
            head->prev = tmp;
        }

        head = tmp;  // Przesuwamy wskaźnik head na nowy element

        if (tail == nullptr) {  // Jeśli lista była pusta, tail również wskazuje
                                // na nowy element
            tail = tmp;
        }

        size++;  // Inkrementujemy rozmiar listy
    }
};

int main() {
    LinkedList List;
    cout << List.SIZE() << endl;
    List.INSERT('k', 1);
    List.INSERT('a', 1);
    List.INSERT('m', 1);
    cout << "Czy lista jest pusta? " << (List.EMPTY() ? "Tak" : "Nie") << endl;

    try {
        // Wyświetlanie pierwszego i ostatniego elementu
        cout << "Pierwszy element: " << List.FIRST()->dataItem << endl;
        cout << "Ostatni element: " << List.LAST()->dataItem << endl;
    } catch (const out_of_range& e) {
        cout << "Błąd: " << e.what() << endl;
    }

    return 0;
}