#include "draw_tree_numbers.h"  // W tym pliku włączamy draw_tree.h

#include <cairo.h>

#include <functional>
#include <iostream>
#include <string>

using namespace std;

class Node {
   public:
    int dataItem;  // Zmieniamy na typ int
    Node* left;
    Node* right;
    Node* parent;

    Node(int dataItem, Node* left = nullptr, Node* right = nullptr,
         Node* parent = nullptr)
        : dataItem(dataItem), left(left), right(right), parent(parent) {}
};

void drawTreeAndSave(Node* root) {
    int width = 1000;   // Szerokość obrazu
    int height = 1000;  // Wysokość obrazu
    const string filename = "binary_tree.png";

    // Tworzymy powierzchnię i kontekst Cairo
    cairo_surface_t* surface =
        cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cairo_t* cr = cairo_create(surface);

    // Ustawiamy kolor tła na biały
    cairo_set_source_rgb(cr, 1, 1, 1);  // Białe tło
    cairo_paint(cr);

    // Rysujemy drzewo
    if (root != nullptr) {
        double rootX = width / 2;
        double rootY = 100;
        double radius = 30;  // Promień węzłów
        cairo_arc(cr, rootX, rootY, radius, 0, 2 * 3.14159);  // Korzeń
        cairo_set_source_rgb(cr, 0.8, 0, 0);  // Ciemnoczerwony kolor węzła
        cairo_fill(cr);

        // Rysowanie tekstu w korzeniu (biały tekst)
        cairo_set_source_rgb(cr, 1, 1, 1);
        cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL,
                               CAIRO_FONT_WEIGHT_BOLD);
        cairo_set_font_size(cr, 36);

        // Konwersja liczby na ciąg znaków
        string rootText = to_string(root->dataItem);
        cairo_text_extents_t extents;
        cairo_text_extents(cr, rootText.c_str(), &extents);
        double textWidth = extents.width;
        double textHeight = extents.height;

        // Wyśrodkowanie tekstu
        cairo_move_to(cr, rootX - textWidth / 2, rootY + textHeight / 2);
        cairo_show_text(cr, rootText.c_str());

        // Funkcja do rysowania węzłów i łączenia z dziećmi
        function<void(Node*, double, double, double)> drawSubtree =
            [&](Node* n, double x, double y, double offset) {
                if (n == nullptr) return;

                // Rysujemy krawędzie
                if (n->left != nullptr) {
                    cairo_set_source_rgb(cr, 0.8, 0, 0);
                    cairo_move_to(cr, x, y);
                    cairo_line_to(cr, x - offset, y + 150);  // Lewe dziecko
                    cairo_stroke(cr);
                }

                if (n->right != nullptr) {
                    cairo_set_source_rgb(cr, 0.8, 0, 0);
                    cairo_move_to(cr, x, y);
                    cairo_line_to(cr, x + offset, y + 150);  // Prawe dziecko
                    cairo_stroke(cr);
                }

                // Rysowanie węzła
                cairo_arc(cr, x, y, radius, 0, 2 * 3.14159);
                cairo_set_source_rgb(cr, 0.8, 0, 0);
                cairo_fill(cr);

                // Rysowanie tekstu w węźle
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL,
                                       CAIRO_FONT_WEIGHT_BOLD);
                cairo_set_font_size(cr, 36);

                // Konwersja liczby na ciąg znaków
                string nodeText = to_string(n->dataItem);
                cairo_text_extents(cr, nodeText.c_str(), &extents);
                double textWidthNode = extents.width;
                double textHeightNode = extents.height;

                // Wyśrodkowanie tekstu w okręgu
                cairo_move_to(cr, x - textWidthNode / 2,
                              y + textHeightNode / 2);
                cairo_show_text(cr, nodeText.c_str());

                // Rekursywne rysowanie dzieci
                if (n->left != nullptr) {
                    drawSubtree(n->left, x - offset, y + 150,
                                offset / 1.4);  // Zmniejszamy kąt
                }

                if (n->right != nullptr) {
                    drawSubtree(n->right, x + offset, y + 150,
                                offset / 1.4);  // Zmniejszamy kąt
                }
            };

        drawSubtree(root, width / 2, 100, 180);  // Rysowanie drzewa
    }

    // Zapisujemy obraz
    cairo_surface_write_to_png(surface, filename.c_str());

    // Czyszczenie
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    system(("xdg-open " + filename).c_str());
}
