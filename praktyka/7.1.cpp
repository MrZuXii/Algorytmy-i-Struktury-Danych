#include <iostream>

using namespace std;

struct Element {
    char dataItem;
    Element* next;
};

void printFIFO() {
    std::cout << R"(  _  __     _      _ _           ______ _____ ______ ____  
 | |/ /    | |    (_) |         |  ____|_   _|  ____/ __ )"
              << "\\\n"
                 R"( | ' / ___ | | ___ _| | ____ _  | |__    | | | |__ | |  | |
 |  < / _ \| |/ _ \ | |/ / _` | |  __|   | | |  __|| |  | |
 | . \ (_) | |  __/ |   < (_| | | |     _| |_| |   | |__| |
 |_|\_\___/|_|\___| |_|\_\__,_| |_|    |_____|_|    \____/ 
                 _/ |                                      
                |__/                                       
)" << std::endl;
}

class ADT {
   private:
    Element* head;
    Element* tail;

   public:
    ADT() : head(nullptr), tail(nullptr) {};

    // Zwraca true jeśli kolejka jest kolejką pustą, false jeśli nie jest
    bool EMPTY() {
        if (head == nullptr) return true;
        return false;
    }

    // Wstawia element x na końcu kolejki (za elementem na pozycji tail)
    void ENQUEUE(char x) {
        Element* newItem = new Element();
        newItem->dataItem = x;
        newItem->next = nullptr;

        if (!EMPTY())
            tail->next = newItem;
        else
            head = newItem;
        tail = newItem;
    }

    // Usuwa element z początku kolejki (z pozycji head)
    void DEQUEUE() {
        if (EMPTY()) {
            cout << "Error: pusta kolejka" << endl;
            return;
        }
        Element* oldItem = head;
        head = head->next;
        delete oldItem;
        if (EMPTY()) {
            head = nullptr;
            tail = nullptr;
        }
    }
    void CLEAR() {
        while (!EMPTY()) DEQUEUE();
    }
    void FRONT() {
        if (EMPTY()) {
            cout << "Error: Kolejka pusta" << endl;
            return;
        }
        cout << "Pierwszy element kolejki to: " << head->dataItem << endl;
    }
};

int main() {
    printFIFO();
    ADT kolejka;
    cout << "-----------------------------------------" << endl;
    kolejka.ENQUEUE('K');
    kolejka.FRONT();
    kolejka.ENQUEUE('A');
    kolejka.FRONT();
    kolejka.ENQUEUE('M');
    kolejka.FRONT();
    cout << "-----------------------------------------" << endl;
    kolejka.CLEAR();
    kolejka.ENQUEUE('D');
    kolejka.FRONT();
    return 0;
}