#include <iostream>

using namespace std;

// struct Element {
//     char dataItem;
//     Element* next;
// };

class Element {
   private:
    char dataItem;
    Element* next;

   public:
    Element(char dataItem, Element* next) : dataItem(dataItem), next(next) {}

    char getValue() { return dataItem; };
    Element* getNext() { return next; };
    void setNext(Element* p) { next = p; };
};

class LinkedFifo {
   private:
    Element* head;
    Element* tail;

   public:
    LinkedFifo() : head(nullptr), tail(nullptr) {};

    bool empty() {
        if (head == nullptr) return true;
        return false;
    }

    void enqueue(char x) {
        // newItem->dataItem = x;
        // newItem->next = nullptr;

        Element* newItem = new Element(x, nullptr);

        // Jezeli kolejka jest pusta to ustawiam head na nowyh element
        if (empty()) head = newItem;
        // Jezeli kolejka nie jest pusta to ustawiam
        // kolejny element przed tail
        else
            tail->setNext(newItem);
        // tail->next = newItem;
        tail = newItem;
    }

    void dequeue() {
        if (empty()) {
            cout << "Lista jest pusta";
            return;
        }
        Element* temp = head->getNext();
        delete head;
        head = temp;
    };

    char peek() {
        if (empty()) {
            cout << "Lista jest pusta";
            return '\0';
        }
        return head->getValue();
    }

    ~LinkedFifo() {};

    void showAll() {
        Element* temp = head;
        while (temp != nullptr) {
            cout << temp->getValue() << ", ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    void clear() {
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    LinkedFifo fifo;
    fifo.enqueue('K');
    fifo.enqueue('A');
    fifo.enqueue('M');
    fifo.enqueue('I');
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.showAll();
    cout << "dana z kolejki: " << fifo.peek();
    return 0;
}