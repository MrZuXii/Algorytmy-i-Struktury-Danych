#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> items, int x) {
    int i = 0;
    int n = items.size();
    while (i < n && items[i] != x) {
        i = i + 1;
    }
    if (i < n) return i;
    return -1;
}

int main() {
    vector<int> items = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int x;

    cout << "Wprowadź wartość do wyszukania: ";
    cin >> x;

    int index = linearSearch(items, x);

    if (index != -1)
        cout << "Element " << x << " znaleziony na indeksie: " << index << endl;
    else
        cout << "Element " << x << " nie zostal znaleziony " << endl;

    return 0;
}
