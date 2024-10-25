#include <iostream>

using namespace std;

class ArrayList {
   private:
    char* items;   // będzie tablicą przechowującą dane (elementy)
    int capacity;  // będzie maksymalną (aktualnie) pojemnością
    int tail;      // będzie pozycją ostatniego elementu listy

    int head;  // będzie pozycją pierwszego elementu listy
    int size;  // będzie długością/rozmiarem listy

   public:
    ArrayList(int initialCapacity = 1000) {
        if (initialCapacity <= 0)
            throw invalid_argument("Pojemność listy ADT musi być wieksza od 0");
        capacity = initialCapacity;
        size = 0;
        tail = -1;
        head = 0;
        items = new char[capacity];
    };

    // Zwraca długość listy
    int SIZE() { return size; };

    // Zwraca true jeśli lista jest pusta, false jeśli lista nie jest pusta
    bool EMPTY() {
        if (size == 0) return true;
        return false;
    };

    // Zwraca pozycję pierwszego elementu listy L lub END(L) jeśli lista jest
    // pusta

    int FIRST() {
        if (EMPTY()) throw out_of_range("List is empty");
        return head;
    };

    // Zwraca pozycję ostatniego elementu listy L lub END(L) jeśli lista jest
    // pusta

    int LAST() {
        if (EMPTY()) throw out_of_range("List is empty");
        return tail;
    }

    // zwraca pozycję pierwszego wystąpienia elementu x w liście L – jeśli x
    // występuję w L, lub end(L) jeśli x nie występuje w L

    int LOCATE(char x) {
        if (EMPTY()) throw out_of_range("List is empty");
        for (int i = FIRST(); i <= LAST(); i++)
            if (items[i] == x) return i;
        return LAST() + 1;
    }

    // –wstawia x do listy L na pozycję k (tj. pomiędzy elementy na pozycjach
    // k-1 i k) lub na pozycję END(L) jeśli k = END(L) –jeśli lista L nie ma
    // pozycji k to wynik jest niezdefiniowany

    void INSERT(char x, int k) {
        if (size >= capacity - 1) throw overflow_error("lista jest pełna");

        if (k < 0 || k > size) throw out_of_range("pozycja nie istnieje");

        for (int i = size - 1; i >= k; i--) items[i + 1] = items[i];
        items[k] = x;
        tail++;
        size++;
    }

    // –usuwa element z pozycji k – jeśli pozycja k istnieje w L
    // –wynik jest niezdefiniowany dla k = END(L) lub jeśli lista L nie ma
    // pozycji k

    void DELETE(int k) {
        if (k < FIRST() || k > LAST())
            throw out_of_range("pozycja nie istnieje");
        for (int i = k; i <= LAST() - 1; i++) items[i] = items[i + 1];
        tail = tail - 1;
    }

    // –usuwa wszystkie elementy listy L
    // –zwykle zwraca END(L)

    void CLEAR() {
        if (EMPTY()) throw out_of_range("list jest pusta");
        tail = -1;
        size = 0;
    }

    // zwraca pozycję elementu następnego za elementem na pozycji k lub END(L)
    // jeśli k jest pozycją ostatniego elementu wynik jest niezdefiniowany dla k
    // = END(L) lub jeśli lista L nie ma pozycji k

    int NEXT(int k) {
        if (EMPTY()) throw out_of_range("lista jest pusta");
        if (k < FIRST() || k > LAST())
            throw out_of_range("pozycja nie istnieje");
        return k + 1;
    }

    // zwraca pozycję elementu poprzedzającego element na pozycji k
    // wynik jest niezdefiniowany dla pozycji pierwszego elementu, lub jeśli
    // lista L nie ma pozycji k

    int PREVIOUS(int k) {
        if (EMPTY()) throw out_of_range("lista jest pusta");
        if (k <= FIRST() || k > LAST())
            throw out_of_range("pozycja nie istnieje");
        return k - 1;
    }

    // ODWIEDZA ELEMENT W LISCIE

    void VISIT(int i) { cout << RETRIEVE(i); }

    char RETRIEVE(int i) { return items[i]; }

    // zastępuje/modyfikuje element na pozycji k elementem x

    void REPLACE(char x, int k) {
        if (k < FIRST() || k > LAST())
            throw out_of_range("pozycja nie istnieje");
        items[k] = x;
    }

    // odwiedza” wszystkie elementy listy L w porządku ich występowania na
    // liście

    void TRAVERSE() {
        for (int i = FIRST(); i <= LAST(); i++) VISIT(i);
        cout << endl;
    }
};
int main() {
    ArrayList ADT;
    try {
        cout << "Długość listy: " << ADT.SIZE() << endl;

        ADT.INSERT('A', 0);
        ADT.INSERT('D', 1);
        ADT.INSERT('T', 2);
        ADT.INSERT('L', 3);
        ADT.INSERT('I', 4);
        ADT.INSERT('S', 5);
        ADT.INSERT('T', 6);

        // cout << ADT.LOCATE('S') << endl;
        ADT.INSERT('-', 3);
        ADT.TRAVERSE();
        ADT.REPLACE('B', 7);
        ADT.TRAVERSE();
        // ADT.DELETE(10);
        // ADT.TRAVERSE();
        // ADT.VISIT(ADT.PREVIOUS(7));
        // ADT.CLEAR();
        // cout << "Po usunieciu: ";
        // ADT.TRAVERSE();
        // cout << "Długość listy: " << ADT.SIZE() << endl;
        // ADT.INSERT('A', 0);
        // ADT.TRAVERSE();
        // ADT.INSERT('A', 0);
        // cout << "Długość listy: " << ADT.SIZE() << endl;

        // cout << "Czy tablica jest pusta: " << (ADT.EMPTY() ? "Tak" : "Nie")
        //      << endl;
        // cout << "Ostatni element listy: " << ADT.LAST() << endl;

        // cout << ADT.RETRIEVE(ADT.LOCATE('d'));
        // ADT.TRAVERSE();

    } catch (const exception& e) {
        cout << "Bład: " << e.what() << endl;
    }

    return 0;
}