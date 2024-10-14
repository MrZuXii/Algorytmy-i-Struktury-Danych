

## Lista Jednokierunkowa w C++

Lista jednokierunkowa to struktura danych, która składa się z sekwencji elementów (węzłów), gdzie każdy węzeł zawiera dane i wskaźnik do następnego węzła w kolejności. Jest to forma listy, która pozwala na dynamiczne zarządzanie pamięcią, co czyni ją bardziej elastyczną niż tablice. 

### Struktura Węzła

Każdy węzeł w liście jednokierunkowej jest zdefiniowany przez strukturę `Node`, która zawiera dwa składniki:

1. **Dane** (`data`): Przechowuje wartość węzła.
2. **Wskaźnik do następnego węzła** (`next`): Przechowuje adres następnego węzła w liście.

W poniższym kodzie widzimy definicję struktury węzła:

```cpp
struct Node {
    int data;       // Wartość przechowywana w węźle
    Node *next;    // Wskaźnik do następnego węzła
};
```

### Klasa `SimpleList`

Klasa `SimpleList` zarządza listą jednokierunkową i zawiera:

- **Prywatny wskaźnik `head`**: Wskazuje na pierwszy węzeł w liście.
- **Konstruktor**: Inicjalizuje `head` jako wskaźnik do `nullptr`, co oznacza, że lista jest początkowo pusta.
- **Metoda `addAtBeggining`**: Dodaje nowy węzeł na początku listy.
- **Metoda `display`**: Wyświetla wszystkie elementy listy.

#### Implementacja Klasy `SimpleList`

Poniżej znajduje się fragment kodu ilustrujący implementację klasy `SimpleList`:

```cpp
class SimpleList {
private:
    Node *head;  // Wskaźnik do pierwszego węzła

public:
    SimpleList() : head(nullptr) {}  // Konstruktor inicjalizujący head jako nullptr

    void addAtBeggining(int value) {
        Node *newNode = new Node();   // Tworzymy nowy węzeł
        newNode->data = value;        // Ustawiamy wartość
        newNode->next = head;         // Nowy węzeł wskazuje na aktualny head
        head = newNode;               // Aktualizujemy head
    }

    void display() {
        Node *temp = head;            // Zaczynamy od pierwszego elementu
        while (temp != nullptr) {
            cout << temp->data << " "; // Wyświetlamy dane w węźle
            temp = temp->next;         // Przechodzimy do kolejnego węzła
        }
        cout << endl;
    }
};
```

### Przykład użycia

W funkcji `main` tworzona jest instancja `SimpleList`, a następnie dodawane są trzy węzły na początku listy i wyświetlane ich wartości:

```cpp
int main() {
    SimpleList list;  // Tworzymy nową listę

    list.addAtBeggining(10);  // Dodajemy węzeł o wartości 10
    list.addAtBeggining(15);  // Dodajemy węzeł o wartości 15
    list.addAtBeggining(20);  // Dodajemy węzeł o wartości 20

    list.display();  // Wyświetlamy listę

    return 0;
}
```

### Zalety i Wady Listy Jednokierunkowej

#### Zalety:
- **Dynamiczna alokacja pamięci**: Możliwość dodawania i usuwania węzłów w czasie rzeczywistym.
- **Elastyczność**: Rozmiar listy nie jest z góry określony, co pozwala na łatwe dostosowanie do potrzeb.

#### Wady:
- **Brak dostępu losowego**: Aby uzyskać dostęp do węzła, należy przejść przez całą listę od początku.
- **Wskaźniki**: Wymaga więcej pamięci na przechowywanie wskaźników w porównaniu do tablic.

### Podsumowanie

Lista jednokierunkowa to podstawowa struktura danych, która umożliwia efektywne zarządzanie danymi w dynamiczny sposób. Dzięki zastosowaniu wskaźników, możliwe jest dodawanie, usuwanie i przeglądanie elementów bez potrzeby ustalania rozmiaru listy z góry. W przedstawionym przykładzie zaimplementowano podstawowe operacje, które pokazują, jak działa ta struktura w praktyce.