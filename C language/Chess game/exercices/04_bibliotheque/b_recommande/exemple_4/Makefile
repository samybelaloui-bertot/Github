
CFLAGS=-g -Wall -Wextra -fPIC

all: mon_executable

mon_executable: mon_programme.o libvecteur.so
	gcc mon_programme.o -L. -lvecteur -o mon_executable

mon_programme.o: mon_programme.c vecteur.h
	gcc -c mon_programme.c ${CFLAGS}

libvecteur.so: vecteur.o 
	gcc -shared vecteur.o -o libvecteur.so

vecteur.o: vecteur.c vecteur.h
	gcc -c vecteur.c ${CFLAGS}

clean:
	rm *.o *.so mon_executable
