### Algorytmy i Struktury Danych - Notatki z pełnym wyjaśnieniem oraz kodem w C++

Poniżej znajdziesz omówienie algorytmów wyszukiwania oraz wybrane fragmenty kodu w C++ z pełnymi komentarzami, które pomogą w przyswojeniu materiału.

---

### 1. **Wyszukiwanie Liniowe (Linear Search)**

#### Opis:
Wyszukiwanie liniowe polega na przeszukiwaniu tablicy elementów jeden po drugim, aż znajdziemy szukany element lub zakończymy przeszukiwanie. Jest to najprostsza metoda wyszukiwania, ale jej złożoność wynosi O(n).

#### Kod w C++:
```cpp
#include <iostream>
using namespace std;

// Funkcja do wyszukiwania liniowego
int linearSearch(int items[], int n, int x) {
    int i = 0; // zaczynamy od pierwszego elementu
    while (i < n) { // przeszukujemy tablicę aż do ostatniego elementu
        if (items[i] == x) // jeśli znajdziemy element x, zwracamy jego indeks
            return i;
        i++; // przechodzimy do kolejnego elementu
    }
    return -1; // jeśli nie znaleziono, zwracamy -1
}

int main() {
    int items[] = {14, 86, 161, 24, 102, 18, 20}; // tablica do przeszukania
    int x = 102; // element, którego szukamy
    ```cpp
    int n = sizeof(items) / sizeof(items[0]); // obliczamy rozmiar tablicy

    // Wywołanie funkcji linearSearch
    int result = linearSearch(items, n, x);

    // Sprawdzamy wynik wyszukiwania
    if (result != -1)
        cout << "Element znaleziony na pozycji: " << result << endl;
    else
        cout << "Element nie został znaleziony." << endl;

    return 0;
}
```

#### Wyjaśnienie:
1. **Funkcja `linearSearch`**: 
   - Iterujemy przez wszystkie elementy tablicy, zaczynając od indeksu `0`.
   - Jeśli znajdziemy poszukiwany element, zwracamy jego indeks. W przeciwnym razie, po zakończeniu pętli zwracamy `-1`, co oznacza, że element nie istnieje w tablicy.
   
2. **Złożoność czasowa**: O(n) – algorytm przeszukuje każdy element, więc czas rośnie liniowo wraz z liczbą elementów.

---

### 2. **Wyszukiwanie Liniowe z Wartownikiem**

#### Opis:
Wartownik to sztuczny element dodawany na końcu tablicy. Pozwala to uprościć warunki zakończenia pętli, ponieważ nie musimy sprawdzać, czy indeks wykracza poza tablicę.

#### Kod w C++:
```cpp
#include <iostream>
using namespace std;

// Funkcja wyszukiwania liniowego z wartownikiem
int linearSearchWithSentinel(int items[], int n, int x) {
    items[n] = x; // dodajemy wartownika na końcu tablicy
    int i = 0;

    // Przeszukujemy tablicę, dopóki nie znajdziemy elementu x
    while (items[i] != x) {
        i++;
    }

    // Jeśli znaleziono przed wartownikiem, zwracamy indeks
    return (i < n) ? i : -1; // jeśli wartownik, zwracamy -1
}

int main() {
    int items[] = {14, 86, 161, 24, 102, 18, 20, 0}; // tablica o 1 większa na wartownika
    int x = 102; // element do znalezienia
    int n = 7; // prawdziwy rozmiar tablicy

    // Wywołanie funkcji wyszukiwania z wartownikiem
    int result = linearSearchWithSentinel(items, n, x);

    // Sprawdzenie wyników
    if (result != -1)
        cout << "Element znaleziony na pozycji: " << result << endl;
    else
        cout << "Element nie został znaleziony." << endl;

    return 0;
}
```

#### Wyjaśnienie:
1. **Dodanie wartownika**: Element wartownika (`x`) jest dodawany na końcu tablicy, dzięki czemu nie musimy sprawdzać, czy indeks nie wykracza poza tablicę w każdym kroku.
2. **Złożoność czasowa**: O(n) – podobnie jak w klasycznym wyszukiwaniu liniowym.

---

### 3. **Wyszukiwanie Binarne (Binary Search)**

#### Opis:
Wyszukiwanie binarne działa na **posortowanej tablicy**. Algorytm dzieli przestrzeń wyszukiwania na połowy i wybiera część, w której znajduje się element.

#### Kod w C++:
```cpp
#include <iostream>
using namespace std;

// Funkcja wyszukiwania binarnego
int binarySearch(int items[], int n, int x) {
    int left = 0, right = n - 1;

    // Dzielimy tablicę na pół, dopóki lewy indeks jest mniejszy lub równy prawemu
    while (left <= right) {
        int mid = left + (right - left) / 2; // obliczamy indeks środka, aby uniknąć przepełnienia

        // Sprawdzamy, czy element jest na środku
        if (items[mid] == x)
            return mid;

        // Jeśli element jest mniejszy niż środkowy, przeszukujemy lewą połowę
        if (items[mid] > x)
            right = mid - 1;
        // W przeciwnym razie przeszukujemy prawą połowę
        else
            left = mid + 1;
    }
    return -1; // zwracamy -1, jeśli element nie został znaleziony
}

int main() {
    int items[] = {14, 18, 20, 24, 86, 102, 161}; // posortowana tablica
    int x = 102; // element do znalezienia
    int n = sizeof(items) / sizeof(items[0]);

    // Wywołanie funkcji wyszukiwania binarnego
    int result = binarySearch(items, n, x);

    // Sprawdzenie wyników
    if (result != -1)
        cout << "Element znaleziony na pozycji: " << result << endl;
    else
        cout << "Element nie został znaleziony." << endl;

    return 0;
}
```

#### Wyjaśnienie:
1. **Podział przestrzeni**: Wyszukiwanie binarne dzieli tablicę na dwie części. Jeśli poszukiwany element jest mniejszy od elementu środkowego, przeszukuje lewą połowę; w przeciwnym razie prawą.
2. **Złożoność czasowa**: O(log n) – przy każdym kroku liczba elementów do przeszukania jest zmniejszana o połowę, co daje logarytmiczną złożoność.

---

### 4. **Wyszukiwanie Interpolacyjne (Interpolation Search)**

#### Opis:
Interpolacyjne wyszukiwanie działa podobnie do wyszukiwania binarnego, ale zakłada, że wartości w tablicy są równomiernie rozmieszczone. Zamiast wybierać środek tablicy, algorytm szacuje, gdzie może znajdować się element na podstawie jego wartości.

#### Kod w C++:
```cpp
#include <iostream>
using namespace std;

// Funkcja wyszukiwania interpolacyjnego
int interpolationSearch(int items[], int n, int x) {
    int left = 0, right = n - 1;

    // Algorytm działa dopóki x mieści się między wartościami na krańcach tablicy
    while (left <= right && x >= items[left] && x <= items[right]) {
        if (left == right) { // jeśli mamy tylko jeden element
            if (items[left] == x) return left;
            return -1;
        }

        // Obliczamy pozycję elementu na podstawie interpolacji
        int mid = left + ((x - items[left]) * (right - left)) / (items[right] - items[left]);

        // Jeśli znaleziono element, zwracamy jego indeks
        if (items[mid] == x)
            return mid;

        // Jeśli x jest większy, przesuwamy lewą granicę
        if (items[mid] < x)
            left = mid + 1;
        // Jeśli x jest mniejszy, przesuwamy prawą granicę
        else
            right = mid - 1;
    }
    return -1; // zwracamy -1, jeśli element nie został znaleziony
}

int main() {
    int items[] = {14, 18, 20, 24, 86, 102, 161}; // posortowana tablica
    int x = 102; // element do znalezienia
    int n = sizeof(items) / sizeof(items[0]);

    // Wywołanie funkcji wyszukiwania interpolacyjnego
    int result = interpolationSearch(items, n, x);

    // Sprawdzenie wyników
    if (result != -1)
        cout << "Element znaleziony na pozycji: " << result << endl;
    else
        cout << "Element nie został znaleziony." << endl;

    return 0;
}
```

#### Wyjaśnienie:
1. **Interpolacja**: Wyszukiwanie interpolacyjne szacuje, gdzie może znajdować się element na podstawie jego wartości, a nie wybiera po prostu środkowego elementu jak w przypadku wyszukiwania binarnego.
2. **Złożoność czasowa**: O(log log n) – w optymalnych warunkach, jeśli elementy są równomiernie rozmieszczone. W najgorszym przypadku złożoność może wynosić O(n).

---

### 5. **Złożoność Czasowa i Rekurencja**

#### Notacje asymptotyczne:
- **O(g(n))**: Granica górna – najgorszy możliwy czas działania algorytmu.
- **Ω(g(n))**: Granica dolna – najlepszy możliwy czas działania algorytmu.
- **Θ(g(n))**: Dokładne oszacowanie – czas działania algoryt

mu w przeciętnym przypadku.

#### Przykład rekurencyjny – Silnia (n!):
Rekurencja to technika, w której funkcja wywołuje samą siebie. Typowym przykładem jest obliczanie silni.

```cpp
#include <iostream>
using namespace std;

// Funkcja do obliczania silni n!
int factorial(int n) {
    if (n == 0) // warunek bazowy
        return 1;
    return n * factorial(n - 1); // rekurencyjne wywołanie
}

int main() {
    int n = 5; // liczba, dla której chcemy obliczyć silnię

    // Wywołanie funkcji silni
    cout << "Silnia " << n << " wynosi: " << factorial(n) << endl;

    return 0;
}
```

#### Wyjaśnienie:
1. **Warunek bazowy**: Gdy `n == 0`, silnia wynosi 1.
2. **Rekurencja**: Funkcja wywołuje samą siebie z argumentem zmniejszonym o 1, aż osiągnie warunek bazowy.
3. **Złożoność czasowa**: O(n) – liczba wywołań funkcji jest proporcjonalna do `n`.

---

### Podsumowanie:
- **Wyszukiwanie liniowe**: Proste, ale ma liniową złożoność czasową.
- **Wyszukiwanie binarne**: Znacznie szybsze na posortowanych danych – O(log n).
- **Wyszukiwanie interpolacyjne**: Używane, gdy dane są równomiernie rozłożone, złożoność O(log log n).
- **Rekurencja**: Ważne narzędzie do rozwiązywania problemów, z przykładem na obliczanie silni.

Każdy z tych algorytmów znajduje zastosowanie w zależności od problemu, złożoności danych i wymaganej wydajności.