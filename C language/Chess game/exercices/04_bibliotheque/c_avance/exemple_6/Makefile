

CFLAGS=-Wall -Wextra -g -fPIC
SRC_LIB=sources/code_librairie/
SRC_EXE=sources/executable/

all: ${SRC_EXE}mon_executable

${SRC_LIB}vecteur.o: ${SRC_LIB}vecteur.c ${SRC_LIB}vecteur.h
	gcc -c ${SRC_LIB}vecteur.c -I ${SRC_LIB} ${CFLAGS} -o ${SRC_LIB}vecteur.o

${SRC_EXE}mon_programme.o: ${SRC_EXE}mon_programme.c ${SRC_LIB}vecteur.h
	gcc -c ${SRC_EXE}mon_programme.c -I ${SRC_LIB} ${CFLAGS} -o ${SRC_EXE}mon_programme.o


${SRC_EXE}mon_executable: ${SRC_EXE}mon_programme.o ${SRC_LIB}libvecteur.so
	gcc ${SRC_EXE}mon_programme.o -L${SRC_LIB} -lvecteur -o ${SRC_EXE}mon_executable

${SRC_LIB}libvecteur.so: ${SRC_LIB}vecteur.o ${SRC_LIB}vecteur.h
	gcc -shared ${SRC_LIB}vecteur.o -o ${SRC_LIB}libvecteur.so

clean:
	rm -rf ${SRC_LIB}*.so ${SRC_LIB}*.o ${SRC_EXE}*.o temporaire/ local/ runme.sh

install: ${SRC_EXE}mon_executable ${SRC_LIB}libvecteur.so ${SRC_LIB}vecteur.h runme.sh
	rm -rf temporaire/
	rm -rf local/
	mkdir temporaire/
	mkdir local/
	mkdir local/bin/
	mkdir local/lib/
	mkdir local/include/
	mv ${SRC_LIB}libvecteur.so local/lib/
	cp ${SRC_LIB}vecteur.h local/include/
	mv ${SRC_LIB}vecteur.o temporaire/
	mv ${SRC_EXE}mon_executable local/bin/
	mv ${SRC_EXE}mon_programme.o temporaire/

runme.sh:
	echo "#!/bin/bash" > runme.sh
	echo "export LD_LIBRARY_PATH=local/lib/:$LD_LIBRARY_PATH" >> runme.sh
	echo "local/bin/mon_executable" >> runme.sh
	chmod +x runme.sh
