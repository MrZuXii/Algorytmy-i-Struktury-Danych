
# Kolejka FIFO oparta na podwójnie wiązanej liście z wartownikiem

## Opis ogólny

Kolejka FIFO (First In, First Out) jest strukturą danych, w której elementy są dodawane na końcu kolejki i usuwane z początku. W tej implementacji używamy podwójnie wiązanej listy z wartownikiem, co pozwala na efektywne zarządzanie elementami kolejki.

## Struktura `Element`

Każdy element kolejki jest reprezentowany przez strukturę `Element`, która zawiera:

- `dataItem`: przechowuje dane typu `char`.
- `next`: wskaźnik do następnego elementu w liście.
- `prev`: wskaźnik do poprzedniego elementu w liście.

```cpp
struct Element {
    char dataItem;
    Element* next;
    Element* prev;
};
```

## Klasa `ADT`

Klasa `ADT` (Abstract Data Type) implementuje kolejkę FIFO. Zawiera wskaźnik do głowy listy, który jest wartownikiem, co oznacza, że jest to element sentinel, który nie przechowuje żadnych danych użytkownika, ale ułatwia zarządzanie elementami w kolejce.

### Konstruktor

Konstruktor inicjalizuje `head` oraz ustawia wskaźniki `prev` i `next` na samą głowę, co oznacza, że lista jest początkowo pusta.

```cpp
ADT() {
    head = new Element();
    head->prev = head;
    head->next = head;
    head->dataItem = '\0';
};
```

### Metoda `EMPTY()`

Metoda sprawdza, czy kolejka jest pusta. Jeśli `head->next` wskazuje na `head`, to oznacza, że nie ma żadnych elementów w kolejce.

```cpp
bool EMPTY() {
    if (head->next == head) return true;
    return false;
}
```

### Metoda `ENQUEUE(char x)`

Metoda `ENQUEUE` dodaje nowy element na końcu kolejki. Wykonuje następujące kroki:

1. Tworzy nowy element `newItem`.
2. Ustawia `dataItem` na przekazaną wartość `x`.
3. Ustawia wskaźnik `prev` nowego elementu na ostatni element w kolejce (czyli na `head->prev`).
4. Ustawia `next` ostatniego elementu na nowy element.
5. Ustawia `head->prev` na nowy element, co oznacza, że nowy element jest teraz ostatnim elementem w kolejce.

```cpp
void ENQUEUE(char x) {
    Element* newItem = new Element();
    newItem->dataItem = x;

    newItem->prev = head->prev;
    head->prev->next = newItem;

    head->prev = newItem;
}
```

### Metoda `DEQUEUE()`

Metoda `DEQUEUE` usuwa element z początku kolejki. Jeśli kolejka jest pusta, wyświetla komunikat o błędzie. W przeciwnym razie:

1. Przechowuje wskaźnik do pierwszego elementu w zmiennej `oldItem`.
2. Ustawia `head->next` na następny element w kolejce.
3. Ustawia `prev` następnego elementu na `head`.
4. Usuwa `oldItem`.

```cpp
void DEQUEUE() {
    if (EMPTY()) {
        cout << "Error: Pusta kolejka" << endl;
        return;
    }
    Element* oldItem = head->next;
    head->next = oldItem->next;
    oldItem->next->prev = head;
    delete oldItem;
}
```

### Metoda `FRONT()`

Metoda `FRONT` zwraca pierwszy element kolejki (nie usuwa go). Jeśli kolejka jest pusta, wyświetla komunikat o błędzie. W przeciwnym razie, wyświetla `dataItem` pierwszego elementu.

```cpp
void FRONT() {
    if (EMPTY()) {
        cout << "Error: Pusta kolejka" << endl;
        return;
    }
    cout << "Pierwszy element kolejki to: " << head->next->dataItem << endl;
}
```

## Przykład użycia

W funkcji `main()` możemy zobaczyć, jak działa kolejka FIFO:

```cpp
int main() {
    ADT kolejka;
    kolejka.ENQUEUE('K');
    kolejka.ENQUEUE('A');
    kolejka.ENQUEUE('M');
    kolejka.ENQUEUE('I');
    kolejka.ENQUEUE('L');
    kolejka.FRONT();  // Oczekiwany wynik: K

    kolejka.DEQUEUE();  // Usuwa K
    kolejka.FRONT();    // Oczekiwany wynik: A

    return 0;
}
```

### Oczekiwane wyniki:

- Po dodaniu elementów `K`, `A`, `M`, `I`, `L`, pierwszy element to `K`.
- Po usunięciu elementu, pierwszy element zmienia się na `A`.

## Wnioski

Kolejka FIFO oparta na podwójnie wiązanej liście z wartownikiem jest efektywną strukturą danych, która pozwala na łatwe dodawanie i usuwanie elementów. Wartownik upraszcza operacje na pustej liście, eliminując konieczność obsługi wyjątków w przypadku, gdy lista nie zawiera elementów.