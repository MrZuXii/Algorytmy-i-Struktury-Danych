#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> items, int x) {
    int size = items.size();  // Sprawdzam rozmiar tablicy

    int left = 0;          // przypisuje 0 do left
    int right = size - 1;  // przypisuje rozmiar tablicy -1 do right
    int mid;               // inicjalizuje środek

    while (left <= right) {
        mid = (left + right) / 2;
        if (items[mid] == x) return mid;
        if (items[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

// Example:

int main() {
    //                      1, 2, 3, 4, 5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14
    vector<int> example1 = {3, 6, 7, 9, 12, 15, 18, 19, 21, 22, 25, 28, 30, 32};

    cout << "binarySearch(example1,7)=> " << binarySearch(example1, 7) << endl;

    cout << "binarySearch(example1,21)=> " << binarySearch(example1, 21)
         << endl;
    cout << "binarySearch(example1,31)=> " << binarySearch(example1, 31)
         << endl;
    cout << "binarySearch(example1,32)=> " << binarySearch(example1, 32)
         << endl;
    return 0;
}