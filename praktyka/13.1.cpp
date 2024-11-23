#include <iostream>

using namespace std;

void wyswietl_tablice(const int* items, int size) {
    for (int i = 0; i < size; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

// T(n) = n*(n-1)/2 → O(n^2)
// https://www.youtube.com/watch?v=GUhWeJyHBCU
void sortowanie_przez_wybieranie(int* items, int size) {
    cout << "Przed sortowaniem: ";
    wyswietl_tablice(items, size);

    //-------- Algorytm Sortowanie przez Wybieranie--------//
    for (int i = 0; i <= size - 2; i++) {
        int min = i;
        for (int j = i + 1; j <= size - 1; j++) {
            if (items[j] < items[min]) min = j;
        }
        swap(items[i], items[min]);
    }
    //-------- Algorytm Sortowanie przez Wybieranie--------//

    cout << "Tablica po sortowaniu: ";
    wyswietl_tablice(items, size);
}

int main() {
    int items_1[6] = {6, 4, 10, 5, 2, 7};
    int items_2[8] = {10, 54, 41, 59, 84, 83, 19, 75};
    int items_3[10] = {52, 73, 27, 38, 54, 50, 60, 14, 23, 72};
    int items_4[5] = {4, 74, 21, 1, 38};

    sortowanie_przez_wybieranie(items_1, 6);

    return 0;
}