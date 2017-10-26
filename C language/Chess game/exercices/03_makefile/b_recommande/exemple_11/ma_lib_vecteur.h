
#ifndef MA_LIB_VECTEUR_H
#define MA_LIB_VECTEUR_H

struct vecteur
{
  float x;
  float y;
  float z;
};

void vecteur_initialise(struct vecteur* a_initialiser,float x,float y,float z);
float vecteur_produit_scalaire(struct vecteur vec_1,struct vecteur vec_2);
struct vecteur vecteur_produit_vectoriel(struct vecteur vec_1,struct vecteur vec_2);




#endif
