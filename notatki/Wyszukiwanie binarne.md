Wyszukiwanie binarne to algorytm, który służy do znajdowania pozycji szukanego elementu w posortowanej tablicy. Działa w oparciu o zasadę dzielenia tablicy na pół i sprawdzania, w której części może znajdować się szukany element. Algorytm wykonuje to efektywnie, zmniejszając liczbę porównań do minimum. Wyjaśnię to na podstawie podanego kodu.

### Kod
```cpp
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> items, int x) {
    const int n = size(items); // Pobieramy rozmiar wektora
    int left = 0, right = n - 1, mid; // Inicjujemy lewą i prawą granicę oraz zmienną na środek

    while (left <= right) { // Dopóki lewa granica nie przekroczy prawej
        mid = (right + left) / 2; // Znajdujemy środek przedziału
        if (items[mid] == x) // Jeśli środkowy element to szukana wartość
            return mid; // Zwracamy indeks środkowego elementu
        else if (items[mid] > x) // Jeśli wartość w środku jest większa od szukanej
            right = mid - 1; // Przesuwamy prawą granicę (szukamy w lewej połowie)
        else // Jeśli wartość w środku jest mniejsza od szukanej
            left = mid + 1; // Przesuwamy lewą granicę (szukamy w prawej połowie)
    }
    return -1; // Zwracamy -1, jeśli nie znaleziono elementu
}

int main() {
    vector<int> items = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Posortowany wektor
    cout << "binarySearch(items, 14) → " << binarySearch(items, 14) << endl; // Szukamy liczby 14
    cout << "binarySearch(items, 5) → " << binarySearch(items, 5) << endl; // Szukamy liczby 5 (która nie istnieje)
    return 0;
}
```

### Wyjaśnienie algorytmu:

1. **Inicjalizacja zmiennych**:
   - `left` jest ustawione na indeks 0, co oznacza początek tablicy.
   - `right` jest ustawione na indeks ostatniego elementu tablicy (n - 1).
   - `mid` to indeks środkowy przedziału, który obliczamy jako `(left + right) / 2`.

2. **Główna pętla `while`**:
   Algorytm działa dopóki `left` jest mniejsze lub równe `right` (dopóki istnieje przedział, w którym można szukać elementu).

3. **Porównanie z elementem środkowym**:
   - Jeśli element na pozycji `mid` jest równy szukanemu elementowi `x`, to znaleziono element i algorytm zwraca jego indeks.
   - Jeśli element na pozycji `mid` jest większy niż szukany element, to znaczy, że szukany element musi być w lewej połowie, dlatego zmniejszamy `right` do `mid - 1`.
   - Jeśli element na pozycji `mid` jest mniejszy niż szukany, to szukany element znajduje się w prawej połowie, więc zwiększamy `left` do `mid + 1`.

4. **Zakończenie wyszukiwania**:
   Jeśli pętla zakończy się bez znalezienia elementu, oznacza to, że element nie istnieje w tablicy, więc algorytm zwraca -1.

### Przykład 1: Wyszukiwanie liczby 14
Tablica: {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}

- **Krok 1**: Środek to `(0 + 9) / 2 = 4`. Element o indeksie 4 to 10. 14 > 10, więc szukamy w prawej połowie.
- **Krok 2**: Nowy przedział to `left = 5`, `right = 9`. Środek to `(5 + 9) / 2 = 7`. Element o indeksie 7 to 16. 14 < 16, więc szukamy w lewej połowie.
- **Krok 3**: Nowy przedział to `left = 5`, `right = 6`. Środek to `(5 + 6) / 2 = 5`. Element o indeksie 5 to 12. 14 > 12, więc szukamy w prawej połowie.
- **Krok 4**: Nowy przedział to `left = 6`, `right = 6`. Środek to `(6 + 6) / 2 = 6`. Element o indeksie 6 to 14, czyli szukany element. Zwracamy 6.

### Przykład 2: Wyszukiwanie liczby 5
Tablica: {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}

- **Krok 1**: Środek to `(0 + 9) / 2 = 4`. Element o indeksie 4 to 10. 5 < 10, więc szukamy w lewej połowie.
- **Krok 2**: Nowy przedział to `left = 0`, `right = 3`. Środek to `(0 + 3) / 2 = 1`. Element o indeksie 1 to 4. 5 > 4, więc szukamy w prawej połowie.
- **Krok 3**: Nowy przedział to `left = 2`, `right = 3`. Środek to `(2 + 3) / 2 = 2`. Element o indeksie 2 to 6. 5 < 6, więc szukamy w lewej połowie.
- **Krok 4**: Nowy przedział to `left = 2`, `right = 1`. Ponieważ `left` > `right`, kończymy wyszukiwanie i zwracamy -1.

Złożoność obliczeniowa wyszukiwania binarnego zależy od liczby porównań, jakie algorytm wykonuje w najgorszym przypadku. Wyszukiwanie binarne dzieli przedział poszukiwań na pół przy każdej iteracji, co pozwala efektywnie skracać obszar przeszukiwania. 

### Złożoność czasowa - analiza krok po kroku:

1. **Liczba elementów na początku**:
   Na początku mamy `n` elementów w tablicy. Przy każdym kroku zmniejszamy przedział poszukiwań o połowę. Na przykład, jeśli początkowo przedział ma długość \(n\), to po pierwszej iteracji będzie miał długość \(n/2\), po drugiej \(n/4\), i tak dalej.

2. **Ile razy możemy podzielić przedział na pół?**:
   Wyszukiwanie binarne dzieli tablicę na pół w każdym kroku, dopóki przedział nie zawęzi się do pojedynczego elementu. Z tego wynika, że liczba kroków potrzebna do zredukowania tablicy o rozmiarze \(n\) do jednego elementu wynosi:
   \[
   \log_2(n)
   \]
   Oznacza to, że liczba iteracji (porównań) jest proporcjonalna do logarytmu z liczby elementów \(n\).

3. **Najgorszy przypadek**:
   W najgorszym przypadku algorytm przeszuka całą tablicę, zanim znajdzie element lub stwierdzi, że go nie ma. W takim przypadku liczba porównań będzie równa logarytmowi z rozmiaru tablicy \(n\). Dlatego złożoność czasowa wyszukiwania binarnego w najgorszym przypadku wynosi:
   \[
   O(\log n)
   \]

4. **Przykład**:
   Jeśli tablica ma 16 elementów (\(n = 16\)), to maksymalna liczba kroków potrzebnych do znalezienia elementu wynosi:
   \[
   \log_2(16) = 4
   \]
   Po 4 porównaniach algorytm zawęzi przedział do pojedynczego elementu.

### Złożoność pamięciowa:
W przedstawionej implementacji nie wykorzystujemy dodatkowej pamięci poza zmiennymi pomocniczymi (`left`, `right`, `mid`), a tablica jest przekazywana jako referencja (nie jest kopiowana). Dlatego złożoność pamięciowa wynosi:
\[
O(1)
\]
Algorytm nie używa dodatkowych struktur danych zależnych od wielkości tablicy.

### Podsumowanie:
- **Złożoność czasowa**: \(O(\log n)\) — w najgorszym przypadku algorytm wykona logarytmiczną liczbę kroków.
- **Złożoność pamięciowa**: \(O(1)\) — algorytm nie wymaga dodatkowej pamięci zależnej od liczby elementów.

Właśnie dlatego wyszukiwanie binarne jest efektywnym algorytmem, zwłaszcza w porównaniu z wyszukiwaniem liniowym, które ma złożoność \(O(n)\).

### Podsumowanie:
Wyszukiwanie binarne jest szybkim algorytmem o złożoności czasowej \(O(\log n)\), ponieważ w każdej iteracji dzieli tablicę na pół. Z tego powodu wymaga, aby tablica była posortowana.