
#include "mes_fonctions_2.h"

void vecteur_addition(const struct vecteur* a,const struct vecteur* b,struct vecteur* resultat)
{
  resultat->x = a->x + b->x;
  resultat->y = a->y + b->y;
}
void vecteur_soustraction(const struct vecteur* a,const struct vecteur* b,struct vecteur* resultat)
{
  resultat->x = a->x - b->x;
  resultat->y = a->y - b->y;
}
