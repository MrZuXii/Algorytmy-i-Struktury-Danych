
#include <iostream>

using namespace std;

struct Element {
    char dataItem;
    Element* next;
    Element* prev;
};

class doubleLinkedList {
   private:
    Element* head;
    Element* tail;
    int size;

   public:
    doubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int SIZE() { return size; }

    bool EMPTY() {
        if (head == nullptr) return true;
        return false;
    }

    Element* FIRST() {
        // if (EMPTY()) return null;
        return head;
    }

    void INSERT()
};

int main() {
    doubleLinkedList List;

    cout << "Rozmiar listy: " << List.EMPTY();
    cout << "Dzien dobry";
    return 0;
}