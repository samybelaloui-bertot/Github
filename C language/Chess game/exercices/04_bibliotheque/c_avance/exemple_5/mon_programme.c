#include <vecteur_2d.h>
#include <vecteur_3d.h>
#include <matrice_2.h>

#include <stdio.h>

int main()
{
  printf("Je me lance\n\n");

  struct vecteur_2d vec_1={1,2};
  struct vecteur_2d vec_2={1,3};

  struct vecteur_3d vec_3={1,2,1};
  struct vecteur_3d vec_4={2,3,1};

  struct matrice_2 mat_1={8,1,
			  2,4};
  struct matrice_2 mat_2={2,1,
			  1,2};

  struct vecteur_2d vec_5=vecteur_2d_addition(vec_1,vec_2);
  struct vecteur_3d vec_6=vecteur_3d_addition(vec_3,vec_4);
  struct matrice_2 mat_3=matrice_2_addition(mat_1,mat_2);

  printf("vec_5=");vecteur_2d_affiche(vec_5);printf("\n");
  printf("vec_6=");vecteur_3d_affiche(vec_6);printf("\n");
  printf("mat_3=\n");
  matrice_2_affiche(mat_3);

  return 0;
}
