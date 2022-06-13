#!/usr/bin/bash
g++ -c -Isrc/include src/realizations/*.cpp -Wall
g++ ./*.o -o Snake -Wall -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window
rm *.o

