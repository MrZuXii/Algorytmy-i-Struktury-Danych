#include <iostream>
#include <string>

using namespace std;

// zsumuj n kolejnych liczb naturalnych rozpoczynając od podanej liczby k

// k od jakie liczby zaczac np 1. n ile kolejnych liczb
// Przyklad:
// k = 10; n = 5; 10+11+12+13+14 = 60

int main() {
    int n, k, wynik, i;

    cout << "Podaj wartosc liczby n: ";
    cin >> n;
    cout << "Podaj wartosc liczby k: ";
    cin >> k;

    if (k < 1 || n < 1) {
        cout << "Bledne dane";
        return 0;
    }
    // wynik = k;
    // i = k;
    // while (i < k + n - 1) {
    //     i = i + 1;
    //     wynik = wynik + i;
    // }
    wynik = n * (n - 1 + k + k) / 2;

    cout << "Wynik " << n << " kolejnych liczb rozpoczanajac od liczby: " << k
         << " wynosi: " << wynik;

    return 0;
}