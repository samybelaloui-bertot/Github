#include "piece_siam.h"
#include "type_piece.h"
#include "orientation_deplacement.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int piece_etre_integre(const piece_siam* piece)
{

    assert(piece!=NULL);
    //puts("nouvelle sequence de tests");
    //printf("type etre animal = %d\n",type_etre_animal(piece->type));
    //printf ("orientation integre = %d\n", orientation_etre_integre_deplacement(piece->orientation));

  
    if((type_etre_animal(piece->type)!=0) && (orientation_etre_integre_deplacement(piece->orientation)!=0))
      return 1;
    if((type_etre_animal(piece->type)!=1) && (orientation_etre_integre_deplacement(piece->orientation)!=1))
      return 1;
    else
      {puts("cause 2");
      return 0;}
}

///////////////////////////////////////////////////////////////////////////////

void test_piece_etre_integre()
{
    puts("Test piece_etre_integre");
    int valid=1;
    piece_siam piece;
    int i,j;
    // Test cas qui donnent 1 (animal + orientation)
    for(i=0 ; i<2 ; i++)
    {
      for(j=0 ; j<4 ; j++)
      {
	piece.type=i;
	piece.orientation=j;
	
	if(piece_etre_integre(&piece)!=1)
	{
	  valid=0;
	  puts("erreur boucle 1");
	}
      }
    }
    // (non_animal + pas_orientation)
    for(i=2 ; i<4 ; i++)
    {
      j=4;
      piece.type=i;
      piece.orientation=j;
      
      if(piece_etre_integre(&piece)!=1)
      {
	  valid=0;
	  puts("erreur boucle 2");
      }
    }
    
    // Test cas qui donnent 0 (animal + pas_orientation)
    for(i=0 ; i<2 ; i++)
    {
      j=4;
      piece.type=i;
      piece.orientation=j;
      
      if(piece_etre_integre(&piece)!=0)
      {
	  valid=0;
	  puts("erreur boucle 3");
      }
    }
    // (non_animal + orientation)
    for(i=2 ; i<4 ; i++)
    {
      for(j=0 ; j<4 ; j++)
      {
	piece.type=i;
	piece.orientation=j;
	
	if(piece_etre_integre(&piece)!=0)
	{
	  valid=0;
	  puts("erreur boucle 4");
	}
      }
    }	
    
    if(valid!=1)
      puts("KO\n");
    else
      puts("OK\n");
}

///////////////////////////////////////////////////////////////////////////////

void piece_initialiser(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece, case_vide, aucune_orientation);
    assert(piece_etre_integre(piece));
}

///////////////////////////////////////////////////////////////////////////////

int piece_etre_animal(const piece_siam* piece)
{
  assert(piece!=NULL);
  assert(piece_etre_integre(piece));
  if(type_etre_animal(piece->type)!=0)
    return 1;

  else return 0;
}

///////////////////////////////////////////////////////////////////////////////

int piece_etre_rocher(const piece_siam* piece)
{
  assert(piece!=NULL);
  assert(piece_etre_integre(piece));
  if((piece->type)==2)
    return 1;
  else return 0;
}

///////////////////////////////////////////////////////////////////////////////

int piece_etre_case_vide(const piece_siam* piece)
{
  assert(piece!=NULL);
  assert(piece_etre_integre(piece));
  if((piece->type)==3)
    return 1;
  else return 0;
}

///////////////////////////////////////////////////////////////////////////////

// Fonction de test

void test_piece_etre()
{
  puts(" Test piece_etre_animal / piece_etre_rocher / piece_etre_case_vide");
  int i, valid=1;
  piece_siam piece;
  for(i=0 ; i<4 ; i++)
  {
    piece.type=i;
    
    if(i<2 && piece_etre_animal(&piece)!=1)
    {
      valid=0;
      puts("erreur animal");
    }
    if(i==2 && piece_etre_rocher(&piece)!=1)
    {
      valid=0;
      puts("erreur rocher");
    }
    if(i==3 && piece_etre_case_vide(&piece)!=1)
    {
      valid=0;
      puts("erreur case_vide");
    }
  }
  
  if(valid!=1)
     puts("KO\n");
  else
     puts("OK\n");
}

///////////////////////////////////////////////////////////////////////////////

void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation)
{
    assert(piece!=NULL);
    assert(type_etre_integre(type));
    assert(orientation_etre_integre(orientation));
   
    piece->type=type;
    piece->orientation=orientation;
    
    assert(piece_etre_integre(piece));
}

///////////////////////////////////////////////////////////////////////////////

void test_piece_definir()
{
  puts("Test piece_definir");
  
    piece_siam pieceIntegre, pieceNonIntegre;
    piece_siam *p1, *p2;
    int valid=1;
    
    p1=&pieceIntegre;
    p2=&pieceNonIntegre;
  
    piece_definir(p1, elephant, haut);
    piece_definir(p2, rocher, bas);
    
    if((p1->type) != elephant && (p1->orientation) != haut)
    {
      valid=0;
      puts("KO pieceIntegre");
    }
    if((p2->type)==rocher && (p2->orientation)==bas)
    {
      valid=0;
      puts("KO pieceNonIntegre");
    }
    
    if(valid==1)
      puts("OK\n");
}

///////////////////////////////////////////////////////////////////////////////

void piece_definir_rocher(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,rocher,aucune_orientation);
    assert(piece_etre_integre(piece));
}

///////////////////////////////////////////////////////////////////////////////

void piece_definir_case_vide(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,case_vide,aucune_orientation);
    assert(piece_etre_integre(piece));
}


///////////////////////////////////////////////////////////////////////////////


orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    assert(piece_etre_animal(piece));

    return piece->orientation;
}

///////////////////////////////////////////////////////////////////////////////

void piece_afficher(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s,%s\n",type_nommer(piece->type),orientation_nommer(piece->orientation));
}

///////////////////////////////////////////////////////////////////////////////

void piece_afficher_nom_cours(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s",type_nommer_nom_cours(piece->type));
    if(piece_etre_animal(piece))
        printf("-%s",orientation_nommer_nom_cours(piece->orientation));
}

///////////////////////////////////////////////////////////////////////////////

piece_siam piece_correspondre_nom_cours(const char* nom_cours)
{
    assert(nom_cours!=NULL);
    assert(strlen(nom_cours)==3);

    //Possibilites:
    //
    // - nom vaut "***" -> case vide
    // - nom vaut "RRR" -> rocher
    // - nom commence par "e-" ou "r-"
    //     Alors il s'agit d'un animal.
    //     -> Recuperer le 3eme caractere
    //     -> Le convertir dans l'orientation de l'animal.
    //  - Si aucun des cas precedent, alors affiche erreur.

    piece_siam piece;
    piece_initialiser(&piece);


    if(strncmp(nom_cours,"***",3)==0)
    {
        piece_definir_case_vide(&piece);
    }
    else if(strncmp(nom_cours,"RRR",3)==0)
    {
        piece_definir_rocher(&piece);
    }
    else if((nom_cours[0]=='e' || nom_cours[0]=='r') && nom_cours[1]=='-')
    {
        const type_piece type=type_correspondre_caractere_animal(nom_cours[0]);
        const orientation_deplacement orientation=orientation_correspondre_caractere(nom_cours[2]);

        piece_definir(&piece,type,orientation);
    }
    else
    {
        printf("Erreur fonction %s\n",__FUNCTION__);
        abort();
    }

    return piece;

}
