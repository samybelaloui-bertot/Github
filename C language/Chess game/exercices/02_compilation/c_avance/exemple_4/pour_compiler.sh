#!/bin/bash

#inclusion d'un repertoire dans le chemin local par l'option -I

#compilation
gcc -c exemple_4.c -o exemple_4.o -I repertoire_ma_lib/
gcc -c repertoire_ma_lib/ma_lib_vecteur.c -o ma_lib_vecteur.o -I repertoire_ma_lib/

#edition de liens
gcc exemple_4.o ma_lib_vecteur.o -o executable
