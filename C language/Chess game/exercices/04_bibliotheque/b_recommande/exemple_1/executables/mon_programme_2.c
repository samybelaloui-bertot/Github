#include "vecteur.h"
#include <stdio.h>

int main()
{
  struct vecteur v1={1,1,1};
  struct vecteur v2={1,5,0};

  struct vecteur v3=vecteur_produit_vectoriel(v1,v2);

  printf("(%3.2f,%3.2f,%3.2f)\n",v3.x,v3.y,v3.z);
  return 0;
  
}
