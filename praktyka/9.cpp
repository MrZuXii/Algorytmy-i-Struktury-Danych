#include <iostream>

#include "lib/draw_tree.h"

using namespace std;

class Node {
   public:
    char dataItem;
    Node* left;
    Node* right;
    Node* parent;

    Node(char dataItem, Node* left = nullptr, Node* right = nullptr,
         Node* parent = nullptr)
        : dataItem(dataItem), left(left), right(right), parent(parent) {}
};

class BinaryTree {
   private:
    Node* root;

   public:
    BinaryTree() : root(nullptr) {}

    bool empty(Node* n) {
        if (n == nullptr)
            return true;
        else
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
        }
        return n->parent;
    }
    char retrieve(Node* n) {
        if (empty(n)) {
            cout << "Error: n nie istnieje";
        }
        return n->dataItem;
    }
    bool leaf(Node* n) {
        if (empty(n)) {
            cout << "Error: n nie istnieje";
        }
        if (empty(left(n)) && empty(right(n)))
            return true;
        else
            return false;
    }

    void preoder(Node* n) {
        if (!empty(n)) {
            cout << retrieve(n) << " ";
            preoder(left(n));
            preoder(right(n));
        }
    }

    void inorder(Node* n) {
        if (!empty(n)) {
            inorder(left(n));
            cout << retrieve(n) << " ";
            inorder(right(n));
        }
    }

    void postorder(Node* n) {
        if (!empty(n)) {
            postorder(left(n));
            postorder(right(n));
            cout << retrieve(n) << " ";
        }
    }

    int size(Node* n) {
        if (empty(n))
            return 0;
        else
            return 1 + size(left(n)) + size(right(n));
    }
    int height(Node* n) {
        if (empty(n))
            return -1;
        else
            return (1 + max(height(left(n)), height(right(n))));
    }

    void clear(Node* n) {
        if (!empty(n)) {
            clear(left(n));
            clear(right(n));
            delete n;
        }
    }

    void setRoot(char data) { root = new Node(data); }

    void addLeft(Node* parent, char data) {
        if (empty(parent)) {
            cout << "Error: Rodzic nie istnieje. " << endl;
            return;
        }
        if (parent->left != nullptr) {
            cout << "Error: Lewe podrzewo już istnieje." << endl;
            return;
        }
        parent->left = new Node(data, nullptr, nullptr, parent);
    }

    void addRight(Node* parent, char data) {
        if (empty(parent)) {
            cout << "Error: Rodzic nie istnieje. " << endl;
            return;
        }
        if (parent->right != nullptr) {
            cout << "Error: Prawe podrzewo już istnieje. " << endl;
            return;
        }
        parent->right = new Node(data, nullptr, nullptr, parent);
    }

    Node* getRoot() { return root; }

    ~BinaryTree() { clear(root); }
};

int main() {
    BinaryTree Tree;
    Tree.setRoot('A');
    Node* root = Tree.getRoot();

    // Dodawanie lewogo rozgałeźnienia
    Tree.addLeft(root, 'L');
    Tree.addLeft(root->left, 'R');
    Tree.addRight(root->left, 'I');
    Tree.addLeft(root->left->left, 'K');
    Tree.addRight(root->left->left, 'M');
    // Dodawanie Prawego rozgałeźnienia
    Tree.addRight(root, 'O');
    Tree.addLeft(root->right, 'H');
    Tree.addRight(root->right, 'G');
    cout << "Tu powinnien być error bo dodaje ponownie do G: ";
    Tree.addRight(root->right, 'G');
    Tree.addRight(root->right->right, 'T');
    Tree.addRight(root->right->left, 'P');
    Tree.addLeft(root->right->left, 'S');

    cout << "Wielkość drzewa: " << Tree.height(root) << endl;

    cout << "Czy root->right jest liściem?: "
         << (Tree.leaf(root->right) ? "Tak" : "Nie") << endl;

    cout << "Czy root->right->right->right jest liściem?: "
         << (Tree.leaf(root->right->right->right) ? "Tak" : "Nie") << endl;

    cout << "Czy root->left->left->left jest drzewem pustym?: "
         << (Tree.empty(root->left->left->left) ? "Tak" : "Nie") << endl;

    cout << "Czy root->left->left->left->left jest drzewem pustym?: "
         << (Tree.empty(root->left->left->left->left) ? "Tak" : "Nie") << endl;

    cout << "Co najduje się w root->left->right: "
         << Tree.retrieve(root->left->right) << endl;

    cout << "Jaki jest rozmiar root: " << Tree.size(root) << endl;
    cout << "Jaki jest wysokość root: " << Tree.height(root) << endl;

    // drawTreeAndSave(root);

    // cout << "Usuwamy poddrzewo root->right->left: ";
    // Tree.clear(root->right->left);
    // root->right->left = nullptr;

    cout << "Inorder: ";
    Tree.inorder(root);
    cout << endl;

    cout << "Preorder: ";
    Tree.preoder(root);
    cout << endl;

    cout << "Postorder: ";
    Tree.postorder(root);
    cout << endl;

    drawTreeAndSave(root);

    cout << endl;
    return 0;
}