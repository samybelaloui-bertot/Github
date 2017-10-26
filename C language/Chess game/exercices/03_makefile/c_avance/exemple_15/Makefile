#Utilisation de repertoires distincts:

OPTION_DE_WARNING=-Wall -Wextra -Wfloat-equal -Wshadow -Wswitch-default -Wswitch-enum -Wwrite-strings -Wpointer-arith -Wcast-qual -Wredundant-decls -Winit-self


all: mon_executable

mon_executable: ma_lib_vecteur.o mon_programme.o
	gcc ma_lib_vecteur.o mon_programme.o -o mon_executable

ma_lib_vecteur.o: repertoire_ma_lib/ma_lib_vecteur.c repertoire_ma_lib/ma_lib_vecteur.h 
	gcc -c repertoire_ma_lib/ma_lib_vecteur.c -o ma_lib_vecteur.o -g ${OPTION_DE_WARNING} -I repertoire_ma_lib/

mon_programme.o: mon_programme.c repertoire_ma_lib/ma_lib_vecteur.h
	gcc -c mon_programme.c -o mon_programme.o -g ${OPTION_DE_WARNING} -I repertoire_ma_lib/

clean: 
	rm *.o mon_executable


#Question:
# Lancez make, observez ou apparait le repertoire et l'inclusion du chemin de recherche de fichier courant -I de gcc.
# L'exemple suivant montre comment minimiser les repetitions grace a l'utilisation des variables.

