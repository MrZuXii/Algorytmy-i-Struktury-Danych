#include <iostream>
#include <string>

using namespace std;

// Problem:
// Czy element x nale cy do przestrzeni X nale y do sko czonego podzbioru S
// przestrzeni X?

struct Node {
    int data;
    Node* next;
};

class ADT {
   private:
    Node* head;

   public:
    ADT(int* array, int size) : head(nullptr) {
        for (int i = 0; i < size; i++) {
            addAtEnd(array[i]);
        }
    }

    void addAtBeginning(int value) {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int x;
    int X[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int S_array[] = {2, 3, 4, 5, 6};
    int size_of_S_array = sizeof(S_array) / sizeof(S_array[0]);
    ADT S(S_array, size_of_S_array);
    S.display();
    // cout << size_of_S_array;

    // int i = S[0];

    // while (i != size_of_S_array) {
    // }

    // cout << "Hello World";s
    return 0;
}