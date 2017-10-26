#include <stdio.h>

#include "vecteur.h"
#include "exemple_3.h"


int main()
{
  struct vecteur vec1;
  vecteur_init(&vec1);
  vec1.x=1;
  vec1.y=2;
  printf("vecteur=(%d,%d)\n",vec1.x,vec1.y);

  printf("b=%d\n",b);
 
  float c;
  unsigned int d=4;
  if(d<0)
  {
    puts("Bonjour");
  }

  return 0;
}

//Question:
//Ecrivez le fichier Makefile permettant de creer l'executable exemple_3 correspondant a ces fichiers.
//Compilez, notez que le programme n'est pas compile avec les options de debugs ni de warnings.
//Un mot cle particulier du fichier Makefile permet d'indiquer les options de compilations.
//Ajoutez en debut de fichier:
// CFLAGS=-g -Wall -Wextra
//Supprimez les fichiers .o du repertoire et relancez make.
//Notez que cette fois, les options de compilations sont utilisees.
//
// Note: explication de CFLAGS
// FLAGS en informatique correspond à "options"
// la lettre C indique qu'il s'agit des options pour la compilation en C.

