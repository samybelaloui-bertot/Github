#include "vecteur_2d.h"

#include <stdio.h>

struct vecteur_2d vecteur_2d_addition(struct vecteur_2d vec_1,struct vecteur_2d vec_2)
{
  struct vecteur_2d resultat;
  resultat.x=vec_1.x+vec_2.x;
  resultat.y=vec_1.y+vec_2.y;

  return resultat;
}

struct vecteur_2d vecteur_2d_soustraction(struct vecteur_2d vec_1,struct vecteur_2d vec_2)
{
  struct vecteur_2d resultat;
  resultat.x=vec_1.x+vec_2.x;
  resultat.y=vec_1.y+vec_2.y;

  return resultat;
}

void vecteur_2d_affiche(struct vecteur_2d vec)
{
  printf("(%3.1f,%3.1f)",vec.x,vec.y);
}


