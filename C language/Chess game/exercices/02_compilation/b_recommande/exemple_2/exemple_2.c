
#include <stdio.h>
#include "ma_lib_vecteur.h"

int main()
{
  struct vecteur vec_1={1.5 , 2.0, 3.0};
  struct vecteur vec_2={-2.0, 2.1, 1.0};

  float r=vecteur_produit_scalaire(vec_1,vec_2);
  struct vecteur vec_3=vecteur_produit_vectoriel(vec_1,vec_2);

  printf("v1.v2=%f\n",r);
  printf("v1xv2=(%f,%f,%f)\n",vec_3.x,vec_3.y,vec_3.z);

  return 0;
}

//Question:
//Que fait-ce programme?
//Comprennez les deux lignes de compilation, et la ligne d'edition de liens du fichier "pour_compiler.sh".
//Vous devez etre en mesure de compiler des programmes contenant un nombre quelconque de fichiers.
