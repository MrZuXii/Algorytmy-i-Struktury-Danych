#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SimpleList
{
private:
    Node *head;

public:
    SimpleList() : head(nullptr) {}

    void addAtBeggining(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void display()
    {
        Node *temp = head; // zaczynamy od pierwszego elementu
        while (temp != nullptr)
        {
            cout << temp->data << " "; // wyświetlamy dane w węźle
            temp = temp->next;         // przechodzimy do kolejnego węzła
        }
        cout << endl;
    }
};

int main()
{
    SimpleList list;

    list.addAtBeggining(10);
    list.addAtBeggining(15);
    list.addAtBeggining(20);

    list.display();

    return 0;
}