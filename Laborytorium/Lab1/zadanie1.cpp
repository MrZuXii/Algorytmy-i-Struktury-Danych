// Zadanie 2

#include <iostream>

using namespace std;

int binarySearch1(int* S, int n, int x) {
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (S[mid] == x) return mid;
        if (S[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
        return -1;
    }
}

// void print()

int main()

{
    int n = 20;  // przykładowy rozmiar
    int* S = new int[n]{/*  dane do testowania */};
    // S = [ 2, 4, 6, 8, 10, 12, 14, 16, 18 ];
    int x;
    // print(S, n);
    // wczytanie/ustawienie x dla przypadku 1
    cout << "Podaj liczbe x do wyszukania: ";
    cin >> x;

    cout << endl
         << "Przypadek 1: x znalezione w pierwszym kroku (pozycja ...) "
         << binarySearch1(S, n, x);  // x na pozycji .....
    //...
}