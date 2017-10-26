#Utilisation de variables:

CFLAGS=-Wall -Wextra

all: mon_executable

mon_executable: ma_lib_vecteur.o mon_programme.o
	gcc $^ -o $@

ma_lib_vecteur.o: ma_lib_vecteur.c ma_lib_vecteur.h

mon_programme.o: mon_programme.c ma_lib_vecteur.h

clean: 
	rm *.o mon_executable


#Question:
# Lancez make.
# Observez les variables $^ et $@, à quoi correspondent-elles ?
# Ces variables sont connues par l'outil Make et permettent de simplifier des ecriture en evitant des repetitions.

