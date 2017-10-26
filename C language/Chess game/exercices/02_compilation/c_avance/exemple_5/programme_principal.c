#include <vecteur_2d.h>
#include <vecteur_3d.h>

#include <stdio.h>

int main()
{
  struct vecteur_2d vec_1={1,2};
  struct vecteur_2d vec_2={-2.5,1};

  struct vecteur_3d vec_3={ 1,1,5};
  struct vecteur_3d vec_4={-2,4,1.5};

  struct vecteur_2d vec_5=vecteur_2d_addition(vec_1,vec_2);
  struct vecteur_3d vec_6=vecteur_3d_addition(vec_3,vec_4);

  vecteur_2d_affiche(vec_1); printf("+"); vecteur_2d_affiche(vec_2);
  printf("="); vecteur_2d_affiche(vec_5); printf("\n");

  vecteur_3d_affiche(vec_3); printf("+"); vecteur_3d_affiche(vec_4);
  printf("="); vecteur_3d_affiche(vec_6); printf("\n");

  return 0;
  
}

//Question:
//Compilez ce programme sans deplacer de fichiers, ni modifier le code.
//Votre programme doit etre compile en mode debug, avec un maximum d'options de warnings.
