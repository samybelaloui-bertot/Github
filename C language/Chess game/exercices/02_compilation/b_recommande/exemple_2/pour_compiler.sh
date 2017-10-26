#!/bin/bash

#l'appel a ${OPTION_WARNING} permet de dupliquer la ligne lui correspondant
OPTION_WARNING="-Wall -Wextra -Wfloat-equal -Wshadow -Wswitch-default -Wswitch-enum -Wwrite-strings -Wpointer-arith -Wcast-qual -Wredundant-decls -Winit-self"

#compilation exemple_2.c
gcc -c exemple_2.c -o exemple_2.o -g ${OPTION_WARNING}
#compilation ma_lib_vecteur.c
gcc -c ma_lib_vecteur.c -o ma_lib_vecteur.o -g ${OPTION_WARNING}

#edition de liens
gcc exemple_2.o ma_lib_vecteur.o -o executable
