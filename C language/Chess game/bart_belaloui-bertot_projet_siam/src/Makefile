CC = gcc
CFLAGS = -Wall -Wextra -g -Wno-unused-parameter
LDFLAGS = -lm
SRC = $(wildcard *.h)


all : main

main : api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o main.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o poussee.o type_piece.o victoire_siam.o
	gcc $^ -o ../bin/jeu_siam $(LDFLAGS)

main.o : main.c $(SRC)

api_siam.o : api_siam.c $(SRC)

condition_victoire_partie.o : condition_victoire_partie.c $(SRC)

coordonnees_plateau.o : coordonnees_plateau.c $(SRC)

coup_jeu.o : coup_jeu.c $(SRC)

entree_sortie.o : entree_sortie.c $(SRC)

jeu_siam.o : jeu_siam.c $(SRC)

joueur.o : joueur.c $(SRC)

mode_interactif.o : mode_interactif.c $(SRC)

orientation_deplacement.o : orientation_deplacement.c $(SRC)

parseur_mode_interactif.o : parseur_mode_interactif.c $(SRC)

piece_siam.o : piece_siam.c $(SRC)

plateau_modification.o : plateau_modification.c $(SRC)

plateau_siam.o : plateau_siam.c $(SRC)

poussee.o : poussee.c $(SRC)

type_piece.o : type_piece.c $(SRC)

victoire_siam.o : victoire_siam.c $(SRC)

clean:
	rm -f *.o
