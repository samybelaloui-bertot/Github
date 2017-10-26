#!/bin/bash

#compilation en mode debug, avec options de Warnings activees
gcc -c exemple_1.c -o exemple_1.o -g -Wall -Wextra -Wfloat-equal -Wshadow -Wswitch-default -Wswitch-enum -Wwrite-strings -Wpointer-arith -Wcast-qual -Wredundant-decls -Winit-self

#edition de liens
gcc exemple_1.o -o exemple_1
