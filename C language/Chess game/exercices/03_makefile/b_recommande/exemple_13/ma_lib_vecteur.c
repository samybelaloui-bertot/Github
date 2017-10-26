#include "ma_lib_vecteur.h"

#include <stdio.h>

void vecteur_initialise(struct vecteur* a_initialiser,float x,float y,float z)
{
  if(a_initialiser!=NULL)
    {
      a_initialiser->x=x;
      a_initialiser->y=y;
      a_initialiser->z=z;
    }
}

float vecteur_produit_scalaire(struct vecteur vec_1,struct vecteur vec_2)
{
return vec_1.x*vec_2.x + vec_1.y*vec_2.y + vec_1.z*vec_2.z;
}

struct vecteur vecteur_produit_vectoriel(struct vecteur vec_1,struct vecteur vec_2)
{
struct vecteur resultat;
resultat.x=vec_1.y*vec_2.z-vec_1.z*vec_2.y;
resultat.y=vec_1.z*vec_2.x-vec_1.x*vec_2.z;
resultat.z=vec_1.x*vec_2.y-vec_1.y*vec_2.x;
return resultat;
}
