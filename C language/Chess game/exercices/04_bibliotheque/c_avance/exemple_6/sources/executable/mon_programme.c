#include <vecteur.h>
#include <stdio.h>

int main()
{
  struct vecteur v1={1,1,1};
  struct vecteur v2={1,5,0};

  float resultat=vecteur_produit_scalaire(v1,v2);

  printf("Bonjour, je m'execute\n");
  printf("resultat=%3.2f\n",resultat);
  return 0;
  
}
