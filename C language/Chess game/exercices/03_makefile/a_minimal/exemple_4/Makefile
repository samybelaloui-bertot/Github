
CFLAGS=-g -Wall -Wextra

#all designe la cible par default
all: executable

#viens ici deplacer l'executable
executable: exemple_4
	mkdir -p bin/
	mv exemple_4 bin/

#compilation des sources et edition de liens
exemple_4: exemple_4.o vecteur.o
exemple_4.o: exemple_4.c exemple_4.h
vecteur.o: vecteur.c vecteur.h

#clean permet de nettoyer le repertoire courant
clean:
	rm -f *.o *~ 


