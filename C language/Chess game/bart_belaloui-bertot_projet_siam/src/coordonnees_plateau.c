#include "coordonnees_plateau.h"
#include "plateau_siam.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int coordonnees_etre_dans_plateau(int x,int y)
{
    if((x>=0 && x<NBR_CASES) && (y>=0 && y<NBR_CASES))
        return 1;
    return 0;
}

int coordonnees_etre_bordure_plateau(int x,int y)
{
    assert(verification_coordonnees);
    
    if(x==0 || y==0 || x==NBR_CASES-1 || y==NBR_CASES-1)
	return 1;
    else return 0;
}

void test_coordonnees_etre_bordure_plateau()
{
  puts("Test coordonnees_etre_bordure_plateau");
  int valid=1;
  int x=0;
  int y=0;
  
  for(x=0; x<NBR_CASES-1; x++)
  {
    if(coordonnees_etre_bordure_plateau(x,y)!=1)
      valid=0;
  }
  
  x=0;
  for(y=0; y<NBR_CASES-1; y++)
  {
    if(coordonnees_etre_bordure_plateau(x,y)!=1)
      valid=0;
  }
  
  y=NBR_CASES-1;
  for(x=0; x<NBR_CASES-1; x++)
  {
    if(coordonnees_etre_bordure_plateau(x,y)!=1)
      valid=0;
  }
  
  x=NBR_CASES-1;
  for(y=0; y<NBR_CASES-1; y++)
  {
    if(coordonnees_etre_bordure_plateau(x,y)!=1)
      valid=0;
  }
  
  if(valid!=1)
    puts("KO\n");
  else
    puts("OK\n");
}

void coordonnees_appliquer_deplacement(int* x,int* y,orientation_deplacement orientation)
{
    assert(x!=NULL);
    assert(y!=NULL);
    assert(orientation_etre_integre_deplacement(orientation));

    // Table de correspondance:
    //  haut   -> (x,y+1)
    //  bas    -> (x,y-1)
    //  gauche -> (x-1,y)
    //  droite -> (x+1,y)

    switch(orientation)
    {
    case haut:
        *y+=1;
        break;
    case bas:
        *y-=1;
        break;
    case gauche:
        *x-=1;
        break;
    case droite:
        *x+=1;
        break;
    default:
        printf("Probleme fonction %s\n",__FUNCTION__);
    }
}





