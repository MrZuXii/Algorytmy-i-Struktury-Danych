#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> items, int x) {
    const int n = size(items);
    int i = 0;

    while (i < n) {
        if (items[i] == x) return i;
        i = i + 1;
    }
    return -1;
}

int linearSearch2(vector<int> items, int x) {
    const int n = size(items);
    int i = 0;

    while (i < n and items[i] != x) i = i + 1;
    if (i < n) return i;
    return -1;
}

int linerSearchSentinel(vector<int> items, int x) {
    const int n =
        size(items);  // Pobranie wielkości tablicy przed wstawieniem wartownika
    items.push_back(x);  // Wstawienie wartownika na koniec tablicy

    int i = 0;

    while (items[i] != x) {
        i = i + 1;
    }
    if (i < n) return i;
    return -1;
}

int binarySearch(vector<int> items, int x) {}

int main() {
    vector<int> items = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    cout << "linearSearch(items, 14) → " << linearSearch(items, 14);
    cout << "linearSearch(items, 3) → " << linearSearch(items, 3);
    cout << "linearSearch2(items, 3) → " << linearSearch2(items, 3);

    cout << "linerSearchSentinel(items, 3) → " << linerSearchSentinel(items, 3);

    return 0;
}