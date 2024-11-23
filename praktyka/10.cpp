#include <iostream>

#include "lib/draw_tree.h"

using namespace std;

class Node {
   public:
    int dataItem;
    Node* left;
    Node* right;
    Node* parent;

    Node(int dataItem, Node* left = nullptr, Node* right = nullptr,
         Node* parent = nullptr)
        : dataItem(dataItem), left(left), right(right), parent(parent) {};
};

class BST {
   private:
    Node* root;

   public:
    BST() : root(nullptr) {}

    bool empty(Node* n) {
        if (n == nullptr) return true;
        return false;
    }

    Node* left(Node* n) {
        if (empty(n)) {
            cout << "Error: n nie istnieje";
            return nullptr;
        }
        return n->left;
    }

    Node* right(Node* n) {
        if (empty(n)) {
            cout << "Error: n nie istnieje";
            return nullptr;
        }
        return n->right;
    }

    Node* parent(Node* n) {
        if (empty(n)) {
            cout << "Error: n nie istnieje";
            return nullptr;
        }
        return n->parent;
    }

    int retrieve(Node* n) {
        if (empty(n)) {
            cout << "Error: n nie istnieje";
            return -1;
        }
        return n->dataItem;
    }

    bool leaf(Node* n) {
        if (empty(n)) {
            cout << "Error: n nie istnieje";
            return false;
        }
        if (empty(n->left) && empty(n->right)) return true;
        return false;
    }

    void preorder(Node* n) {
        if (!empty(n)) {
            cout << n->dataItem << ' ';
            preorder(left(n));
            preorder(right(n));
        }
    }

    void inorder(Node* n) {
        if (!empty(n)) {
            inorder(left(n));
            cout << n->dataItem << ' ';
            inorder(right(n));
        }
    }

    void postorder(Node* n) {
        if (!empty(n)) {
            postorder(left(n));
            postorder(right(n));
            cout << n->dataItem << ' ';
        }
    }

    int size(Node* n) {
        if (empty(n)) return 0;
        return 1 + size(left(n)) + size(right(n));
    }

    int height(Node* n) {
        if (empty(n)) return -1;
        return max(1 + height(left(n)), height(right(n)));
    }

    void clear(Node* n) {
        if (!empty(n)) {
            clear(n->left);
            clear(n->right);
            delete n;
        }
    }

    ////----------------------------------------------------------///
    /// Operacje specyficzne dla Binarne drzewo poszukiwań (BST) ///
    //----------------------------------------------------------//

    // zwraca pozycję (wskaźnik) węzła z wartością x lub NULL jeśli T jest
    // drzewem pustym lub x nie występuje w T

    Node* search(Node* T, int x) {
        Node* n = T;
        while (!empty(n) && retrieve(n) != x) {
            if (retrieve(n) > x)
                n = left(n);
            else
                n = right(n);
        }
        return n;
    }

    // zwraca pozycję (wskaźnik) węzła z minimalną wartością w T lub NULL jeśli
    // T jest drzewem pustym

    Node* minimum(Node* T) {
        if (empty(root)) return NULL;
        Node* n = T;
        while (!empty(left(n))) n = left(n);
        return n;
    }

    Node* maximum(Node* T) {
        if (empty(root)) return nullptr;
        Node* n = T;
        while (!empty(right(n))) n = right(n);
        return n;
    }

    void insert(int x) {
        Node* e = new Node(x);
        if (empty(root)) {
            root = e;
            return;
        }
        Node* p = root;
        bool stop = false;

        while (!stop) {
            if (retrieve(p) > x) {
                if (!empty(left(p)))
                    p = left(p);
                else {
                    p->left = e;
                    e->parent = p;
                    stop = true;
                }
            }
            if (retrieve(p) < x) {
                if (!empty(right(p)))
                    p = right(p);
                else {
                    p->right = e;
                    e->parent = p;
                    stop = true;
                }
            }
        }
    }

    Node* getRoot() { return root; }
};

int main() {
    BST Tree;

    Tree.insert(8);
    Tree.insert(5);
    Tree.insert(2);
    Tree.insert(1);
    Tree.insert(3);
    Tree.insert(7);
    Tree.insert(12);
    Tree.insert(9);
    Tree.insert(14);
    Tree.insert(17);

    Node* szukany = Tree.search(Tree.getRoot(), 3);

    // cout << szukany->dataItem;

    if (szukany != nullptr) {
        cout << Tree.retrieve(szukany)
             << endl;  // Wydrukuj wartość, jeśli znaleziono węzeł
    } else {
        cout << "Nie znaleziono elementu w drzewie!"
             << endl;  // Komunikat, jeśli nie znaleziono
    }

    cout << "Minimalna wartość w drzewie to: "
         << Tree.retrieve(Tree.minimum(Tree.getRoot())) << endl;

    cout << "Maksymalna wartość w drzewie to: "
         << Tree.retrieve(Tree.maximum(Tree.getRoot())) << endl;

    // Rysowanie drzewa
    drawTreeAndSave(Tree.getRoot());

    return 0;
}