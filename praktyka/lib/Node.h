// Node.h
#ifndef NODE_H
#define NODE_H

class Node {
   public:
    char dataItem;  // Przykład: dane w węźle
    Node* left;     // Wskaźnik na lewe dziecko
    Node* right;    // Wskaźnik na prawe dziecko

    // Konstruktor
    Node(char item) : dataItem(item), left(nullptr), right(nullptr) {}
};

#endif  // NODE_H
