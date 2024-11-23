#include <iostream>
#include <vector>

using namespace std;

const int capacity = 20;

int linearSearch1(vector<int> S, int n, int x) {
    int i = 0;
    while (i < n) {
        if (S[i] == x) return i;
        i++;
    }
    return -1;
}

int main() {
    vector<int> items = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = items.size();

    cout << "Rozmiar tablicy: " << size << endl;

    cout << "linearSearch(items, 14) → " << linearSearch1(items, size, 14)
         << endl;
    cout << "linearSearch(items, 2) → " << linearSearch1(items, size, 2)
         << endl;
    cout << "linearSearch(items, 20) → " << linearSearch1(items, size, 20)
         << endl;
    cout << "linearSearch(items, 3) → " << linearSearch1(items, size, 3)
         << endl;

    return 0;
}