
#include <est_premier.h>

#include <stdio.h>
#include <math.h>

int est_premier(unsigned int a)
{
  printf("Test nombre %d\n",a);

  //cas particuliers
  if(a==0)
    return 0;
  if(a==1)
    return 0;
  if(a==2)
    return 0;

  //Algorithme:
  // Pour tous nombre k plus petit que sqrt(a)
  //   Si k est un diviseur de a
  //      Alors renvoie faux
  // Fin Pour
  // renvoie vraie


  unsigned int s=sqrt(a);
  unsigned int k=0;



  printf("Test nombres compris entre [2,%d]\n",s);
  for(k=2;k<=s;++k)
    {
      if(a%k==0)
	{
	  printf("Trouve que %d est diviseur de %d\n",k,a);
	  return 0;
	}
    }
  printf("Aucun diviseur trouve pour %d\n",a);
  return 1;
}
