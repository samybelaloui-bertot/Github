#include "vecteur_3d.h"

#include <stdio.h>


struct vecteur_3d vecteur_3d_addition(struct vecteur_3d vec_1,struct vecteur_3d vec_2)
{
  struct vecteur_3d resultat;
  resultat.x=vec_1.x+vec_2.x;
  resultat.y=vec_1.y+vec_2.y;
  resultat.z=vec_1.z+vec_2.z;

  return resultat;
}

struct vecteur_3d vecteur_3d_soustraction(struct vecteur_3d vec_1,struct vecteur_3d vec_2)
{
  struct vecteur_3d resultat;
  resultat.x=vec_1.x+vec_2.x;
  resultat.y=vec_1.y+vec_2.y;
  resultat.z=vec_1.z+vec_2.z;

  return resultat;
}

void vecteur_3d_affiche(struct vecteur_3d vec)
{
  printf("(%3.1f,%3.1f,%3.1f)",vec.x,vec.y,vec.z);
}


