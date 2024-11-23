#!/bin/bash

# Kompilowanie programu - uwzględniamy plik draw_tree.cpp
g++ -o bin/binary_tree_cairo 11.cpp lib/draw_tree_binary_heap.cpp -I/usr/include/cairo -L/usr/lib/x86_64-linux-gnu -lcairo

# Uruchamianie programu
./bin/binary_tree_cairo
