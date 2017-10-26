#Utilisation des options par defaut

CFLAGS=-g -Wall -Wextra -Wfloat-equal -Wshadow -Wswitch-default -Wswitch-enum -Wwrite-strings -Wpointer-arith -Wcast-qual -Wredundant-decls -Winit-self
TARGET=mon_executable
OBJS = ma_lib_vecteur.o mon_programme.o

all: mon_executable

${TARGET}: ${OBJS}
	gcc ${OBJS} -o ${TARGET}

ma_lib_vecteur.o: ma_lib_vecteur.c ma_lib_vecteur.h

mon_programme.o: mon_programme.c ma_lib_vecteur.h

clean: 
	rm *.o ${TARGET}


#Question:
# Ici, les lignes de compilations sont omises. Lancez make, observez que la compilation se deroule correctement.
# Les options de warnings sont elles-activees? 
# Ici, make possede des regles d'inferences automatique. Il est capable de definir automatiquement comment passer d'un fichier .c vers un fichier .o
# Pour parametrer ses regles, il utilise des variables au nom particuliers: ici CFLAGS (prononcee C-Flags), pour "Option de compilation (flags) en C".
# Commentez la ligne CFLAGS, et lancez "make clean" puis "make". Observez les options par defauts.

