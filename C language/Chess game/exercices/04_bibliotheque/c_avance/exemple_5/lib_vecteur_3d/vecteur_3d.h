#ifndef VECTEUR_3D_H
#define VECTEUR_3D_H

struct vecteur_3d
{
  float x;
  float y;
  float z;
};

struct vecteur_3d vecteur_3d_addition(struct vecteur_3d vec_1,struct vecteur_3d vec_2);
struct vecteur_3d vecteur_3d_soustraction(struct vecteur_3d vec_1,struct vecteur_3d vec_2);
void vecteur_3d_affiche(struct vecteur_3d vec);

#endif
