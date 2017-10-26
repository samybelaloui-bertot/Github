#include <stdio.h>

#include "vecteur.h"
#include "exemple_4.h"


int main()
{
  struct vecteur vec1;
  vecteur_init(&vec1);
  vec1.x=1;
  vec1.y=2;
  printf("vecteur=(%d,%d)\n",vec1.x,vec1.y);

  return 0;
}


//Question:
//Observez le Makefile
//Que ce passe t-il lorsque l'on appelle make?
//Observez la ligne demandant le deplacement du fichier executable dans le repertoire bin/
//Notez que les lignes de commandes specifiques sont precedes d'une tabulation
//Tapez en ligne de commande: make clean
//Que ce passe t-il? Retrouvez l'instruction realisee dans le Makefile
