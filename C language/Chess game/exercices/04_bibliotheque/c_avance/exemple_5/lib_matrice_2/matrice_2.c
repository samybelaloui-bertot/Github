
#include <matrice_2.h>
#include <stdio.h>

struct matrice_2 matrice_2_addition(struct matrice_2 mat_1,struct matrice_2 mat_2)
{
  struct matrice_2 resultat;
  resultat.x00 = mat_1.x00 + mat_2.x00;
  resultat.x10 = mat_1.x10 + mat_2.x10;
  resultat.x01 = mat_1.x01 + mat_2.x01;
  resultat.x11 = mat_1.x11 + mat_2.x11;
  return resultat;
}

struct matrice_2 matrice_2_soustraction(struct matrice_2 mat_1,struct matrice_2 mat_2)
{
  struct matrice_2 resultat;
  resultat.x00 = mat_1.x00 - mat_2.x00;
  resultat.x10 = mat_1.x10 - mat_2.x10;
  resultat.x01 = mat_1.x01 - mat_2.x01;
  resultat.x11 = mat_1.x11 - mat_2.x11;
  return resultat;
}

struct matrice_2 matrice_2_multiplication(struct matrice_2 mat_1,struct matrice_2 mat_2)
{
  struct matrice_2 resultat;
  resultat.x00 = mat_1.x00*mat_2.x00 + mat_1.x01*mat_2.x10;
  resultat.x10 = mat_1.x10*mat_2.x00 + mat_1.x11*mat_2.x10;
  resultat.x01 = mat_1.x00*mat_2.x01 + mat_1.x11*mat_2.x11;
  resultat.x11 = mat_1.x10*mat_2.x01 + mat_1.x11*mat_2.x11;
  return resultat;
}


void matrice_2_affiche(struct matrice_2 mat)
{
  printf("(%3.2f %3.2f)\n(%3.2f %3.2f)\n",mat.x00,mat.x01,mat.x10,mat.x11);
}

