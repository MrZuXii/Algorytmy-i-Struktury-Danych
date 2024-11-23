#include "draw_tree_binary_heap.h"

#include <cairo.h>

#include <functional>
#include <iostream>

using namespace std;

void drawTreeAndSaveFromHeap(int heap[], int size) {
    // Rozmiar obrazu
    int width = 1000;
    int height = 1000;

    const string filename = "binary_heap.png";
    cairo_surface_t* surface =
        cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cairo_t* cr = cairo_create(surface);

    // Ustawiamy kolor tła na biały
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    // Funkcja rysująca węzły i krawędzie
    function<void(int, double, double, double)> drawSubtree =
        [&](int index, double x, double y, double offset) {
            if (index >= size) return;

            // Rysowanie krawędzi
            int l = 2 * index + 1;
            int r = 2 * index + 2;

            if (l < size) {
                cairo_set_source_rgb(cr, 0.8, 0,
                                     0);  // Czerwony kolor dla krawędzi
                cairo_move_to(cr, x, y);  // Początek krawędzi
                cairo_line_to(cr, x - offset, y + 150);  // Lewe dziecko
                cairo_stroke(cr);                        // Rysowanie krawędzi
            }

            if (r < size) {
                cairo_set_source_rgb(cr, 0.8, 0,
                                     0);  // Czerwony kolor dla krawędzi
                cairo_move_to(cr, x, y);  // Początek krawędzi
                cairo_line_to(cr, x + offset, y + 150);  // Prawe dziecko
                cairo_stroke(cr);                        // Rysowanie krawędzi
            }

            // Rysowanie węzła (czewone kółko z czarnym obramowaniem)
            double radius = 30;
            cairo_set_source_rgb(cr, 0.8, 0, 0);  // Czerwony kolor dla węzła
            cairo_arc(cr, x, y, radius, 0, 2 * 3.14159);  // Rysowanie kółka
            cairo_fill(cr);                               // Wypełniamy kółko

            // Rysowanie czarnego obramowania wokół kółka
            cairo_set_source_rgb(cr, 0, 0, 0);  // Kolor czarny dla obramowania
            cairo_set_line_width(cr, 2);        // Grubość linii obramowania
            cairo_arc(cr, x, y, radius, 0, 2 * 3.14159);  // Kontur kółka
            cairo_stroke(cr);  // Rysowanie obramowania

            // Rysowanie tekstu w węźle (liczba)
            cairo_set_source_rgb(cr, 1, 1, 1);  // Biały kolor dla tekstu
            cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL,
                                   CAIRO_FONT_WEIGHT_BOLD);
            cairo_set_font_size(cr, 36);
            cairo_text_extents_t extents;
            cairo_text_extents(cr, to_string(heap[index]).c_str(), &extents);
            double textWidth = extents.width;
            double textHeight = extents.height;

            // Wyśrodkowanie tekstu w węźle
            cairo_move_to(cr, x - textWidth / 2, y + textHeight / 2);
            cairo_show_text(cr, to_string(heap[index]).c_str());

            // Rekursywne rysowanie dzieci
            if (l < size) {
                drawSubtree(l, x - offset, y + 150,
                            offset / 1.4);  // Zwiększając kąt
            }

            if (r < size) {
                drawSubtree(r, x + offset, y + 150,
                            offset / 1.4);  // Zwiększając kąt
            }
        };

    // Rysowanie kopca zaczynając od korzenia
    drawSubtree(0, width / 2, 100, 180);

    // Rysowanie tablicowej reprezentacji kopca
    int tableY = height - 100;  // Pozycja Y pod drzewem

    // Rysowanie tablicy
    cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL,
                           CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 24);

    // Wypisujemy tablicową reprezentację kopca
    for (int i = 0; i < size; i++) {
        double x =
            width / 2 - size * 30 +
            i * 70;  // Wyrównanie elementów w poziomie (zwiększamy odstęp)

        // Rysowanie prostokąta dla elementu (kafelka)
        cairo_set_source_rgb(cr, 0.8, 0, 0);  // Kolor czerwony dla kafelka
        cairo_move_to(cr, x,
                      tableY - 40);  // Pozycja lewego górnego rogu prostokąta
        cairo_rectangle(cr, x, tableY - 40, 60, 40);  // Prostokąt dla elementu
        cairo_fill_preserve(cr);                      // Wypełniamy kafelek
        cairo_set_source_rgb(cr, 0, 0, 0);  // Kolor czarny dla obramowania
        cairo_set_line_width(cr, 2);        // Grubość linii
        cairo_stroke(cr);                   // Rysowanie obramowania

        // Rysowanie tekstu z wartością elementu w kafelku
        cairo_set_source_rgb(cr, 1, 1, 1);       // Kolor biały
        cairo_move_to(cr, x + 20, tableY - 10);  // Pozycja tekstu
        cairo_show_text(cr, to_string(heap[i]).c_str());
    }

    // Rysowanie indeksów pod kwadratami (czyste liczby)
    for (int i = 0; i < size; i++) {
        double x =
            width / 2 - size * 30 + i * 70;  // Wyrównanie elementów w poziomie

        // Rysowanie indeksu
        cairo_set_source_rgb(cr, 0, 0, 0);  // Kolor czarny dla indeksów
        cairo_move_to(cr, x + 25,
                      tableY + 30);  // Pozycja indeksu pod kafelkiem
        cairo_show_text(cr,
                        to_string(i).c_str());  // Czyste liczby (np. 0, 1, 2)
    }

    // Zapisujemy obraz
    cairo_surface_write_to_png(surface, filename.c_str());

    // Czyszczenie
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    system(("xdg-open " + filename).c_str());
}
