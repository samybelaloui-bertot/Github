#Utilisation de variables:

CFLAGS=-Wall -Wextra -Wfloat-equal -Wshadow -Wswitch-default -Wswitch-enum -Wwrite-strings -Wpointer-arith -Wcast-qual -Wredundant-decls -Winit-self

all: mon_executable

mon_executable: ma_lib_vecteur.o mon_programme.o
	gcc ma_lib_vecteur.o mon_programme.o -o mon_executable

ma_lib_vecteur.o: ma_lib_vecteur.c ma_lib_vecteur.h

mon_programme.o: mon_programme.c ma_lib_vecteur.h

clean: 
	rm *.o mon_executable


#Question:
# Lancez make, les options de warnings sont-elles inclues lors de la compilation? Notez l'utilisation d'une variable permettant d'eviter les repetitions.

