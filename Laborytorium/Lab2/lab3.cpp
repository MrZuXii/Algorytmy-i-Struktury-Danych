#include <iostream>

using namespace std;

class Element {
   private:
    int v;
    Element* next;
    Element* prev;

   public:
    // tworzy pusty element
    Element() : next(nullptr), prev(nullptr) {};

    // tworzy element przechowujący x
    Element(int x, Element* next, Element* prev)
        : v(x), next(next), prev(prev) {};

    // zwraca wartość
    int getValue() { return v; };

    // ustawia warość v
    void setValue(int v) { this->v = v; };

    // zwraca ozycję następnego elementu
    Element* getNext() { return next; };

    // zwraca pozycję poprzedniego elementu
    Element* getPrev() { return prev; };

    // ustawia p jako następny element
    void setNext(Element* p) { next = p; };

    // ustawia p jako poprzedni element
    void setPrev(Element* p) { prev = p; };
};

class LinkedList {
   private:
    // pozycja pierwszego elementu
    Element* head;

    // pozycja ostatniego elementu
    Element* tail;
    int size;

   public:
    LinkedList()
        : head(nullptr), tail(nullptr), size(0) {};  // tworzy pustą listę

    // zwraca prawdę jeśli lista pusta, fałsz w przeciwnym przypadku
    bool empty() { return size == 0; };

    // zwraca wielkość listy (liczbę elementów w liście)
    int getSize() { return size; }

    // zwraca pozycję (wskaźnik do) pierwszego elementu listy
    Element* getFirst() {
        if (empty()) {
            cout << "Error: lista jest pusta";
            return nullptr;
        }
        return head;
    };

    // zwraca pozycję (wskaźnik do) ostatniego elementu listy
    Element* getLast() { return tail; };

    // zwraca pozycję (wskaźnik do) następniego elementu listy
    Element* getNext(Element* p) { return p->getNext(); };

    // zwraca pozycję (wskaźnik do) poprzedniego elementu listy
    Element* getPrev(Element* p) { return p->getPrev(); };

    // zwraca element (wartość) z pozycji (wskazywanej przez) p
    // int retrive(Element* p) {};

    // wstawia element z x na końcu listy
    void append(int x) {
        Element* newItem = new Element();
        newItem->setValue(x);
        if (empty()) {
            head = newItem;
            tail = newItem;

        } else {
            tail->setNext(newItem);
            newItem->setPrev(tail);
            tail = newItem;
        }

        size++;
        // if (head == nullptr) {
        //     Element* newItem = new Element();
        //     newItem->setValue(x);
        //     head = newItem;
        //     tail = newItem;
        //     return;
        // }

        // Element* newItem = new Element(x, nullptr, tail->getPrev());
        // tail = newItem;
    };

    // wstawia element z x na początku listy
    void preppend(int x) {
        Element* newItem = new Element();
        newItem->setValue(x);
        head->setPrev(newItem);
        newItem->setNext(head);
        head = newItem;
        size++;
    };

    // usuwa całą listę
    void clear() {
        Element* temp;
        tail = nullptr;
        while (head != nullptr) {
            temp = head->getNext();
            delete head;
            head = temp;
        }
        size = 0;
    };

    // zwraca pozycję pierwszego wystąpienia elementu x, NULL jeśli x nie
    // występuje
    Element* locate(int x) {
        Element* temp;
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            if (temp->getValue() == x) return temp;
            temp = temp->getNext();
        };
        return NULL;
    };

    // wstawia element z wartością x na pozycję (wskazywaną przez) p
    void insert(Element* p, int x) {
        Element* temp;
        temp = head;
        while (temp != nullptr && temp ==) {
            if (temp->getValue() == x) return temp;
            temp = temp->getNext();
        };
    };

    // usuwa element z pozycji (wskazywanej przez) p
    void del(Element* p);

    // wypisuje elementu listy
    friend ostream& operator<<(ostream& out, LinkedList& l) {
        if (l.empty()) {
            cout << "Error: lista jest pusta nie moge nic wyświetlić" << endl;
            return out;
        }
        Element* temp = l.head;
        while (temp != nullptr) {
            out << temp->getValue() << ' ';
            temp = temp->getNext();
        }
        out << endl;
        return out;
    };
    ~LinkedList() { clear(); };
};

int main() {
    // LinkedList* list = new LinkedList();
    LinkedList lista;
    lista.append(2);
    lista.append(4);
    lista.append(6);
    lista.append(8);
    lista.append(10);
    // cout << lista.getFirst()->getValue() << endl;
    // cout << lista.getLast()->getPrev() << endl;
    // std::cout << lista;
    // lista.clear();
    // std::cout << lista;
    // lista.append(8);
    // lista.append(4);
    // lista.preppend(1);
    // std::cout << lista;
    cout << lista.locate(6)->getValue();

    // lista.append(8);
    // cout << lista.getFirst()->getValue() << endl;
    // cout << lista.getLast()->getValue() << endl;
    // cout << "First: " << lista.getFirst() << endl;
    // cout << "Hello World";
    return 0;
}