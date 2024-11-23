#include <iostream>

#include "lib/draw_tree_binary_heap.h"

using namespace std;

class BinaryHeap {
   private:
    int capacity = 100;
    int heap[100];
    int size;

   public:
    BinaryHeap() : size(0) {}

    /**
     * Sprawdza, czy kopiec jest pusty.
     *
     * Funkcja zwraca `true`, jeśli kopiec (drzewo) nie zawiera żadnych
     * elementów, czyli jego rozmiar wynosi 0. W przeciwnym razie zwraca
     * `false`.
     *
     * @return `true`, jeśli kopiec H jest pusty, `false` w przeciwnym
     * przypadku.
     *
     * Złożoność czasowa: O(1).
     */
    bool empty() {
        if (size == 0) return true;
        return false;
    }

    /**
     * Sprawdza, czy kopiec jest pełny.
     *
     * @return `true`, jeśli kopiec osiągnął swoją maksymalną pojemność, w
     * przeciwnym razie `false`.
     *
     * Złożoność czasowa: O(1).
     */
    bool full() {
        if (size == capacity) return true;
        return false;
    }

    /**
     * Pobiera wartość elementu z kopca na podanej pozycji n.
     *
     * @param n Indeks węzła w kopcu (powinien być legalny: 0 ≤ n < size).
     * @return Wartość elementu w węźle n.
     *         Zwraca -1 i wypisuje komunikat błędu, jeśli kopiec jest pusty.
     *
     * Uwaga:
     * - Funkcja nie sprawdza, czy indeks n znajduje się w zakresie kopca.
     * - Jeśli n jest poza zakresem (n < 0 lub n ≥ size), wynik działania jest
     * niezdefiniowany.
     * - Obsługa pustego kopca polega na zwróceniu -1 i wypisaniu komunikatu na
     * standardowe wyjście.
     *
     * Złożoność czasowa: O(1).
     */
    int retrieve(int n) {
        if (empty()) {
            cout << "Error: Kopiec pusty" << endl;
            return -1;  // Zwrócenie wartości błędu
        }
        return heap[n];
    }

    /**
     * Usuwa wszystkie elementy z kopca, ustawiając jego rozmiar na 0.
     *
     *
     * Złożoność czasowa: O(1).
     */
    void clear() { size = 0; }

    /**
     * Zwraca indeks rodzica węzła n w kopcu.
     *
     * @param n Indeks węzła, dla którego szukamy rodzica (musi być legalnym
     * indeksem w kopcu).
     * @return Indeks rodzica węzła n lub -1, jeśli n jest korzeniem (czyli n =
     * 0).
     *
     * Złożoność czasowa: O(1).
     */
    int parent(int n) {
        if (n == 0) return -1;  // Korzeń nie ma rodzica
        return (n - 1) / 2;
    }

    /**
     * Zwraca indeks lewego syna węzła n w kopcu.
     *
     * @param n Indeks węzła, dla którego szukamy lewego syna (musi być legalnym
     * indeksem w kopcu).
     * @return Indeks lewego syna węzła n lub -1, jeśli syn nie istnieje.
     *
     * Złożoność czasowa: O(1).
     */
    int left(int n) {
        int leftIndex = 2 * n + 1;
        if (leftIndex < size) return leftIndex;
        return -1;  // Brak lewego dziecka
    }

    /**
     * Zwraca indeks prawego syna węzła n w kopcu.
     *
     * @param n Indeks węzła, dla którego szukamy prawego syna (musi być
     * legalnym indeksem w kopcu).
     * @return Indeks prawego syna węzła n lub -1, jeśli syn nie istnieje.
     *
     * Złożoność czasowa: O(1).
     */
    int right(int n) {
        int rightIndex = 2 * n + 2;
        if (rightIndex < size) return rightIndex;
        return -1;  // Brak prawego dziecka
    }

    /**
     * Przywraca własność kopca binarnego typu max, wykonując operację top-down.
     *
     * @param n Indeks węzła, który może naruszać własność kopca.
     *
     * Złożoność czasowa: O(log2(n)).
     */
    void top_down(int n) {
        int l = left(n);
        int r = right(n);
        int largest = n;

        if (l != -1 && heap[l] > heap[largest]) {
            largest = l;
        }
        if (r != -1 && heap[r] > heap[largest]) {
            largest = r;
        }
        if (largest != n) {
            swap(heap[n], heap[largest]);
            top_down(largest);
        }
    }

    /**
     * Przywraca własność kopca binarnego typu max, wykonując operację
     * bottom-up.
     *
     * @param n Indeks węzła, który może naruszać własność kopca.
     *
     * Złożoność czasowa: O(log2(n)).
     */
    void bottom_up(int n) {
        while (n > 0 && heap[n] > heap[parent(n)]) {
            swap(heap[n], heap[parent(n)]);
            n = parent(n);
        }
    }

    /**
     * Wstawia nową wartość x do kopca.
     *
     * @param x Wartość do wstawienia.
     *
     * Złożoność czasowa: O(log2(n)).
     */
    void insert(int x) {
        if (full()) {
            cout << "Error: Kopiec pełny" << endl;
            return;
        }
        heap[size] = x;
        bottom_up(size);  // Przywracamy porządek kopca "bottom-up"
        size++;           // Zwiększamy rozmiar kopca
    }

    /**
     * Usuwa element o największej wartości (korzeń kopca) z kopca.
     *
     *
     * Złożoność czasowa: O(log2(n)).
     */
    void delete_max() {
        if (empty()) {
            cout << "Error: Kopiec pusty" << endl;
            return;
        }
        swap(heap[0], heap[size - 1]);  // Zamiana korzenia z ostatnim elementem
        size--;                         // Zmniejszamy rozmiar kopca
        top_down(0);  // Przywracamy porządek kopca "top-down"
    }

    /**
     * Usuwa węzeł o podanym indeksie n z kopca.
     *
     * @param n Indeks węzła do usunięcia.
     *
     * Złożoność czasowa: O(log2(n)).
     */
    void delete_element(int n) {
        if (empty()) {
            cout << "Error: Kopiec pusty" << endl;
            return;
        }
        if (n < 0 || n >= size) {
            cout << "Error: Nieprawidłowy indeks" << endl;
            return;
        }
        swap(heap[n], heap[size - 1]);  // Zamiana elementu z ostatnim
        size--;                         // Zmniejszamy rozmiar kopca
        top_down(n);   // Przywracamy porządek kopca "top-down"
        bottom_up(n);  // Przywracamy porządek kopca "bottom-up"
    }

    /**
     * Buduje kopiec binarny na podstawie nieuporządkowanej tablicy.
     *
     * @param H Kopiec binarny.
     *
     * Złożoność czasowa: O(n log2(n)).
     */
    void build() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            top_down(i);
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void drawTree() { drawTreeAndSaveFromHeap(heap, size); }
};

int main() {
    BinaryHeap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(25);

    cout << "Kopiec po wstawieniu elementów: ";
    heap.print();  // Oczekiwane: 30 25 10 5 20

    // Usuwanie maksymalnego elementu
    heap.empty();
    heap.delete_max();
    cout << "Kopiec po usunięciu maksymalnego elementu: ";
    heap.print();  // Oczekiwane: 25 20 10 5

    // Usuwanie elementu na pozycji 1
    heap.delete_element(1);
    cout << "Kopiec po usunięciu elementu na pozycji 1: ";
    heap.print();  // Oczekiwane:j 25 5 10

    heap.drawTree();

    return 0;
}
