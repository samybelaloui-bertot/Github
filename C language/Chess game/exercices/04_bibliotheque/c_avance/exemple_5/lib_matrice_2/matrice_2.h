#ifndef MATRICE_2_H
#define MATRICE_2_H


struct matrice_2
{
  float x00; float x01;
  float x10; float x11;
};

struct matrice_2 matrice_2_addition(struct matrice_2 mat_1,struct matrice_2 mat_2);
struct matrice_2 matrice_2_soustraction(struct matrice_2 mat_1,struct matrice_2 mat_2);
struct matrice_2 matrice_2_multiplication(struct matrice_2 mat_1,struct matrice_2 mat_2);
void matrice_2_affiche(struct matrice_2 mat);

#endif
