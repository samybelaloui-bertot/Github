
#include <stdio.h>
#include <stdlib.h>

#define VERSION_TEST

#ifdef VERSION_TEST
#define VERIFICATION(k,N) {if((k)>=(N)){printf("Erreur index %d/%d\n",k,N);exit(1);}}
#else
#define VERIFICATION(k,N) 
#endif

#define TAILLE 10

int accede(int tableau[],int index);

int main()
{
  int tableau[TAILLE];

  //remplissag
  int k=0;
  for(k=0;k<TAILLE;++k)
    tableau[k]=k*k+2;


  int a=accede(tableau,5);
  int b=accede(tableau,9);
  int c=accede(tableau,12);
  printf("%d,%d,%d\n",a,b,c);

  return 0;
}

int accede(int tableau[],int index)
{
  VERIFICATION(index,TAILLE);
  return tableau[index];
}

// Que realise ce programme? 
// Observez la sortie du preprocesseur. Compilez et executez le programme.
// Que se passe t-il si l'on commente la premiere ligne (#define VERSION_TEST)
// Reexecutez le programme dans ce cas. Qu'affiche-il?
// Concluez sur l'utilisation d'une telle macro?
