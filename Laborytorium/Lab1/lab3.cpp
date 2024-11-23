#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int linearSearchCount(vector<int> S, int x) {
    int i = 0;
    int n = S.size();
    int count = 0;
    while (i < n) {
        count++;
        if (S[i] == x) return count;
        i++;
    }
    return count;
}

int binarySearchCount(vector<int> items, int x) {
    int size = items.size();  // Sprawdzam rozmiar tablicy

    int left = 0;          // przypisuje 0 do left
    int right = size - 1;  // przypisuje rozmiar tablicy -1 do right
    int mid;               // inicjalizuje środek
    int count = 0;
    while (left <= right) {
        count++;
        mid = (left + right) / 2;
        if (items[mid] == x) return count;
        if (items[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return count;
}

int interpolationSearch(vector<int> items, int x) { int size = items.size(); }

int main() {
    srand(time(NULL));
    vector<int> test_data_1 = {};
    int liczba = 0;
    for (int i = 0; i <= 100000; i++) {
        liczba += (std::rand() % 5) + 1;
        // int random = round() % 10;

        test_data_1.push_back(liczba);
    }
    int szukanaLiczba = test_data_1[(std::rand() % (100000 - 1)) + 1];
    cout << "Tablica: ";

    // for (int i = 0; i <= 100; i++) {
    //     cout << " " << test_data_1[i];
    // }

    cout << endl << endl;
    cout << "Szukana liczba: " << szukanaLiczba << endl;

    cout << "Test dla linearSearchCount() => "
         << linearSearchCount(test_data_1, szukanaLiczba) << endl;
    cout << "Test dla binarySearch() => "
         << binarySearchCount(test_data_1, szukanaLiczba) << endl;
}