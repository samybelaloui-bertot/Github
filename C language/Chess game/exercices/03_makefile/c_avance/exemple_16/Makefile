#Utilisation de variables:

OPTION_DE_WARNING=-Wall -Wextra -Wfloat-equal -Wshadow -Wswitch-default -Wswitch-enum -Wwrite-strings -Wpointer-arith -Wcast-qual -Wredundant-decls -Winit-self

#repertoire ou se trouve la librairie
DIR=repertoire_ma_lib/
#nom de ma librairie
MA_LIB=ma_lib_vecteur
#chemin complet vers le fichier d'en tete
MA_LIB_H=${DIR}${MA_LIB}.h

all: mon_executable

mon_executable: ${MA_LIB}.o mon_programme.o
	gcc ${MA_LIB}.o mon_programme.o -o mon_executable

${MA_LIB}.o: ${DIR}${MA_LIB}.c ${MA_LIB_H}
	gcc -c ${DIR}/${MA_LIB}.c -o ${MA_LIB}.o -g ${OPTION_DE_WARNING} -I ${DIR}

mon_programme.o: mon_programme.c ${MA_LIB_H}
	gcc -c mon_programme.c -o mon_programme.o -g ${OPTION_DE_WARNING} -I ${DIR}

clean: 
	rm *.o mon_executable


#Question:
# Que vallent les variables: "DIR", "MA_LIB", et "MA_LIB_H"
# Relancez make. Notez qu'il n'y a pas de difference avec l'exemple precedent.
# Observez l'utilisation des variables permettant d'eviter la duplication du nom du repertoire.
# Renommez desormais le repertoire "repertoire_ma_lib" en "lib_vecteur".
# Modifiez le makefile afin de pouvoir compiler a nouveau le programme. Notez l'avantage a ne pas dupliquer le nom des fichiers/repertoires.

