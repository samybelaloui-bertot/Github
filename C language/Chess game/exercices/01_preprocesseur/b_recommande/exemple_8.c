#include "entete/mes_fonctions_2.h"

int main()
{
  struct vecteur vec_1;
  struct vecteur vec_2;
  vecteur_init(&vec_1);
  vecteur_init(&vec_2);

  vec_1.x=5; vec_1.y=6;
  vec_2.x=1; vec_2.y=1;

  struct vecteur vec_3;
  vecteur_addition(&vec_1,&vec_2,&vec_3);

  printf("(%d,%d)\n",vec_3.x,vec_3.y);
  return 0;
}

//Question:
//Quelle sortie est obtenue apres le passage du preprocesseur.
//Notez l'inclusion en chaine permettant la definition de la struct.
//Observez egalement la sortie du preprocesseur sur le fichier mes_fonctions_2.c
//Compiler tous les fichiers necessaires (on pourra laisser le warning concernant le printf) et générez l'executable de ce programme. Que realise ce programme, verifiez la sortie obtenue.

