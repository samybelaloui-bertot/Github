#ifndef VECTEUR_2D_H
#define VECTEUR_2D_H

struct vecteur_2d
{
  float x;
  float y;
};

struct vecteur_2d vecteur_2d_addition(struct vecteur_2d vec_1,struct vecteur_2d vec_2);
struct vecteur_2d vecteur_2d_soustraction(struct vecteur_2d vec_1,struct vecteur_2d vec_2);
void vecteur_2d_affiche(struct vecteur_2d vec);

#endif
