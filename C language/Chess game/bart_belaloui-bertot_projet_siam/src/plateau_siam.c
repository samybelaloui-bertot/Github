#include "plateau_siam.h"
#include "entree_sortie.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



void plateau_initialiser(plateau_siam* plateau)
{
    // Initialise l'ensemble des cases du plateau a piece_vide
    // sauf les 3 cases du milieu avec un rocher (1,2), (2,2) et (3,2)
    //
    // L'etat de l'echiquier initial est le suivant:
    //
    // [4] *** | *** | *** | *** | *** |
    // [3] *** | *** | *** | *** | *** |
    // [2] *** | RRR | RRR | RRR | *** |
    // [1] *** | *** | *** | *** | *** |
    // [0] *** | *** | *** | *** | *** |
    //     [0]   [1]   [2]   [3]   [4]
    //

    
    int kx=0;
    for(kx=0 ; kx<NBR_CASES ; ++kx)
    {
        int ky=0;
        for(ky=0 ; ky<NBR_CASES ; ++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);
            if(ky==2 && (kx>=1 && kx<=3) )
	    {
              piece_definir_rocher(piece);
	    }
	      //piece_definir(piece, elephant, haut); // Test de la fonction api_siam_tenter_changer_orientation_piece_si_possible
            else
	    {
                piece_definir_case_vide(piece);
	    }
        }
    }

    assert(plateau_etre_integre);
}

/////////////////////////////////////////////////////////////////////////

int plateau_etre_integre(const plateau_siam* plateau)
{
    assert(plateau!=NULL);
    
    int x=0;
    int y=0;
    int NBrocher=0;
    int NBelephant=0;
    int NBrhinoceros=0;
        

    for(x=0; x<NBR_CASES; x++)
    {
      for(y=0; y<NBR_CASES; y++)
      {
	
	const piece_siam* piece=plateau_obtenir_piece_info(plateau,x,y);
	assert(piece!=NULL);
	
	if(piece_etre_integre(piece)!=1)
	{

	  return 0;
	} 
      }
    }
    NBrocher=plateau_denombrer_type(plateau, rocher);
    NBelephant=plateau_denombrer_type(plateau, elephant);
    NBrhinoceros=plateau_denombrer_type(plateau,rhinoceros);
    
    if((NBrocher>=0 && NBrocher<=3) && (NBelephant>=0 && NBelephant<=5) && (NBrhinoceros>=0 && NBrhinoceros<=5))
      return 1;
    else
      return 0;

}


/////////////////////////////////////////////////////////////////////////

int verification_coordonnees(int x, int y)
{
  if((x>=0 && y>=0)&&(x<NBR_CASES && y<NBR_CASES))
    return 1;
  else
    return 0;
}

/////////////////////////////////////////////////////////////////////////

void test_verification_coordonnees()
{
  puts("Test verification_coordonnees");
  
  int i,j;
  int valid=1;
  
  // Coordonnees a l'interieur du plateau.
  for(i=0; i<NBR_CASES; i++)
  {
    for(j=0; j<NBR_CASES; j++)
    {
      if(verification_coordonnees(i,j)!=1)
	valid=0;
    }
  }
  // Coordonnees en dehors du plateau (on incremente de 6 pour eviter nos cases dans le plateau)
  // -19+3*6=-1 et -1+6=5, on a bien eviter nos cases du plateau.
  for(i=-19; i<18; i=i+6)
  {
    for(j=-19; j<18; j=j+6)
    {
      if(verification_coordonnees(i,j)!=0)
	valid=0;
    }
  }
  
  if(valid!=1)
    puts("KO\n");
  else
    puts("OK\n");
}

/////////////////////////////////////////////////////////////////////////

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    
    if(verification_coordonnees(x,y)!=1)
    {
      puts("Coordonnees invalides");
      return 0;
    }
        
    return &(plateau->piece[x][y]);
}

/////////////////////////////////////////////////////////////////////////


const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(verification_coordonnees(x,y));
    
    return &(plateau->piece[x][y]);
}


/////////////////////////////////////////////////////////////////////////


int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
    assert(plateau!=NULL);
        
    int i=0;
    int j=0;
    int compteur=0;
    for(i=0;i<NBR_CASES;++i)
    {
        for(j=0;j<NBR_CASES;++j) 
        {
	    const piece_siam* piece=plateau_obtenir_piece_info(plateau, i, j);
	    assert(piece!=NULL);
	    
            if(piece->type==type)
                compteur++;
        }
    }
    return compteur;
}

/////////////////////////////////////////////////////////////////////////

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(verification_coordonnees(x,y));
    
    const piece_siam* piece;
    
    piece=plateau_obtenir_piece_info(plateau, x, y);
    if((piece->type) != case_vide)
      return 1;
    else return 0;
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////

void plateau_afficher(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    //utilisation d'une fonction generique d'affichage
    // le parametre stdout permet d'indiquer que l'affichage
    // est realise sur la ligne de commande par defaut.
    entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}
