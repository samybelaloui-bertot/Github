
CFLAGS=-g -fPIC -Wall -Wextra

all: mon_executable

mon_executable: mon_programme.o lib_matrice_2/libmatrice_2.so lib_vecteur_2d/libvecteur_2d.so lib_vecteur_3d/libvecteur_3d.so
	gcc mon_programme.o -L lib_matrice_2 -L lib_vecteur_2d -L lib_vecteur_3d -lmatrice_2 -lvecteur_2d -lvecteur_3d -o mon_executable


mon_programme.o: mon_programme.c lib_matrice_2/matrice_2.h lib_vecteur_2d/vecteur_2d.h lib_vecteur_3d/vecteur_3d.h
	gcc -c mon_programme.c -I lib_matrice_2 -I lib_vecteur_2d -I lib_vecteur_3d -o mon_programme.o ${CFLAGS}


lib_matrice_2/libmatrice_2.so: lib_matrice_2/matrice_2.o
	gcc -shared lib_matrice_2/matrice_2.o -o lib_matrice_2/libmatrice_2.so
lib_vecteur_2d/libvecteur_2d.so: lib_vecteur_2d/vecteur_2d.o
	gcc -shared lib_vecteur_2d/vecteur_2d.o -o lib_vecteur_2d/libvecteur_2d.so
lib_vecteur_3d/libvecteur_3d.so: lib_vecteur_3d/vecteur_3d.o
	gcc -shared lib_vecteur_3d/vecteur_3d.o -o lib_vecteur_3d/libvecteur_3d.so


lib_matrice_2/matrice_2.o: lib_matrice_2/matrice_2.c lib_matrice_2/matrice_2.h
	gcc -c lib_matrice_2/matrice_2.c -o lib_matrice_2/matrice_2.o ${CFLAGS} -I lib_matrice_2/
lib_vecteur_2d/vecteur_2d.o: lib_vecteur_2d/vecteur_2d.c lib_vecteur_2d/vecteur_2d.h
	gcc -c lib_vecteur_2d/vecteur_2d.c -o lib_vecteur_2d/vecteur_2d.o ${CFLAGS} -I lib_vecteur_2d/
lib_vecteur_3d/vecteur_3d.o: lib_vecteur_3d/vecteur_3d.c lib_vecteur_3d/vecteur_3d.h
	gcc -c lib_vecteur_3d/vecteur_3d.c -o lib_vecteur_3d/vecteur_3d.o ${CFLAGS} -I lib_vecteur_3d/

clean:
	rm *.o lib_matrice_2/*.o lib_matrice_2/*.so lib_vecteur_2d/*.o lib_vecteur_2d/*.so lib_vecteur_3d/*.o lib_vecteur_3d/*.so mon_executable
