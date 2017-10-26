#Compilation pour plusieurs fichiers

all: mon_programme

CFLAGS = -g -Wall -Wextra

#Edition de liens: notez que cette partie ne sera executee qu'une fois que les fichiers .o auront etes crees
mon_programme: ma_lib_vecteur.o mon_programme.o

ma_lib_vecteur.o: ma_lib_vecteur.c ma_lib_vecteur.h

#mon programme.c doit etre recompile si mon_programme.c est modifiee, ou si ma_lib_vecteur.h est modifie.
mon_programme.o: mon_programme.c ma_lib_vecteur.h


clean: 
	rm *.o mon_executable


#Question:
# Lancez make, notez l'ordre d'execution de gcc sur chaque fichier.
# Relancez make, que ce passe t-il?
# Lancez make clean, puis relancez make. Que ce passe t-il?
# Modifiez ma_lib_vecteur.c et sauvegardez. Relancez make, quels fichiers sont recompiles?
# Modifiez ma_lib_vecteur.h et sauvegardez. Relancez make, quels fichiers sont recompiles?
