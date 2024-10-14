#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> items, int x) {
    int n = items.size();
    // Ustalam wielkość tablicy

    items.push_back(x);
    // Tutaj dodajesz wartość x na koniec wektora items.
    // W efekcie nawet jeśli x nie znajduje się w oryginalnej liście, to na
    // końcu zawsze będzie jego kopia. Dzięki temu możesz zaimplementować pętlę
    // bez skomplikowanego sprawdzania warunków granicznych.

    int i = 0;

    while (items[i] != x) i = i + 1;

    // W tej pętli sprawdzasz, czy items[i] jest różne od x.
    // Ponieważ na końcu wektora znajduje się wartownik, pętla zakończy się, gdy
    // znajdziesz x, czy to w oryginalnej liście, czy w dodanym wartowniku.

    if (i < n) return i;

    // Po zakończeniu pętli, sprawdzasz, czy i jest mniejsze od n. Jeśli tak,
    // oznacza to, że x zostało znalezione w oryginalnej liście, ponieważ
    // wartownik znajdował się na pozycji n. Jeśli i wynosi n, oznacza to, że x
    // nie było w oryginalnej liście, a pętla zakończyła się z powodu
    // wartownika.

    return -1;
}

int main() {
    vector<int> items = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int x;
    cin >> x;
    cout << linearSearch(items, x);

    return 0;
}