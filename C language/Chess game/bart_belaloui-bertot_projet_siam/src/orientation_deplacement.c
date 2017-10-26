#include "orientation_deplacement.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int orientation_etre_integre(orientation_deplacement orientation)
{
    // L'enumeration designe une orientation integre si elle est compris
    //  entre 0 et 5.
    // Une enumeration etant un type non signe, il est forcement positif.
    // Il suffit donc que type soit < 5 pour designer un type valide.

    if(orientation<5)
      return 1;
    return 0;
}

void test_orientation_etre_integre()
{
  // Fonction test de orientation_etre_integre
  
  puts("Test orientation_etre_integre");
  
  int k=0, valid=1;
  for(k=0 ; k<5 ; k++)
    if(orientation_etre_integre(k)!=1)
    {
      valid=0;
      printf("KO pour %d\n", k);
    }
    
  for(k=5 ; k<100 ; k++)
    if(orientation_etre_integre(k) !=0)
    {
      valid=0;
      printf("KO pour %d\n", k);
    }
    
  if(valid!=1)
    puts("KO\n");
  else
    puts("OK\n");
    
}

int orientation_etre_integre_deplacement(orientation_deplacement direction_deplacement)
{
   // L'enumeration designe un type orientation si elle est comprise entre 0 et 4.
   // Une enumeration etant un type non signe, il est forcement positif.
   // Il suffit donc que type < 4 pour designer un type valide.
  
   if(direction_deplacement<4)
	return 1;
   return 0;
}

void test_orientation_etre_integre_deplacement()
{
  // Fonction de test de la fonction orientation_etre_integre_deplacement.
  
  puts("Test orientation_etre_integre_deplacement");
  int valid=1;
  
  if(orientation_etre_integre_deplacement(haut) !=1)
  {
    puts("haut KO");
    valid=0;
  }
  if(orientation_etre_integre_deplacement(bas)!=1)
  {
    puts("bas KO");
    valid=0;
  }
  if(orientation_etre_integre_deplacement(gauche)!=1)
  {
    puts("gauche KO");
    valid=0;
  }
  if (orientation_etre_integre_deplacement(droite) !=1)
  {
    puts("droite KO");
    valid=0;
  }
  
  int k=0;
  for(k=5 ; k<100 ; ++k)
    if(orientation_etre_integre_deplacement(k)!=0)
    {
      printf("valeur %d KO\n",k);
      valid++;
    }
   
  if(valid!=1)
    puts("KO\n");
  else
    puts("OK\n");
}

const char* orientation_nommer(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere correspondante.

    switch(orientation)
    {
    case haut:
        return "haut"; break;
    case bas:
        return "bas"; break;
    case gauche:
        return "gauche"; break;
    case droite:
        return "droite"; break;
    case aucune_orientation:
        return "aucune"; break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



const char* orientation_nommer_nom_cours(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere courte correspondante.

    switch(orientation)
    {
    case haut:
        return "^"; break;
    case bas:
        return "v"; break;
    case gauche:
        return "<"; break;
    case droite:
        return ">"; break;
    case aucune_orientation:
        return "????"; break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

orientation_deplacement orientation_inverser(orientation_deplacement orientation)
{
    assert(orientation_etre_integre_deplacement(orientation));

    // "Look up table" (LUT) convertissant une orientation vers
    //    son oppose
    // haut   <-> bas
    // droite <-> gauche


    switch(orientation)
    {
    case haut:
        return bas;
    case bas:
        return haut;
    case gauche:
        return droite;
    case droite:
        return gauche;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



int orientation_caractere_etre_integre(char orientation)
{
    // Verifie que le caractere saisi correspond à un déplacement :
    // haut (^), bas (v), droite (>) ou gauche (<).
    
    
    if(orientation == '^')
      return 1;
    if(orientation == 'v')
      return 1;
    if(orientation == '<')
      return 1;
    if(orientation == '>')
      return 1;
    
    else
      return 0;
}

void test_orientation_caractere_etre_integre()
{
    //Fonction de test de orientation_caractere_etre_integre
    puts("Test orientation_caractere_etre_integre");
    
    int valid=1;
    
    if((orientation_caractere_etre_integre('^'))!=1)
    {
      puts("KO haut");
      valid=0;
    }
     if((orientation_caractere_etre_integre('v'))!=1)
    {
      puts("KO bas");
      valid=0;
    }
     if((orientation_caractere_etre_integre('<'))!=1)
    {
      puts("KO gauche");
      valid=0;
    }
     if((orientation_caractere_etre_integre('>'))!=1)
    {
      puts("KO droite");
      valid=0;
    }
    
    if(valid!=1)
      puts("KO\n");
    else
      puts("OK\n");
}


orientation_deplacement orientation_correspondre_caractere(char orientation)
{
    // Converti un type char en un type int (0,1,2,3).
    // Verifie que le caractere saisi correspond à un deplacement haut (^), bas (v), gauche (<) ou droite (>).
    assert(orientation_caractere_etre_integre(orientation));
    
    // Declaration variable type_enum.
    orientation_deplacement type_enum = aucune_orientation;
    
    switch(orientation)
    {
      case '^':
	return haut;
      case 'v':
	return bas;
      case '<':
	return gauche;
      case '>':
	return droite;
	
      default:
	puts("Ceci n'est pas un deplacement valide");
	abort();
    }
    
    return type_enum;
}


void test_orientation_correspondre_caractere()
{
    //Fonction de test de test_orientation_correspondre_caractere
    puts("Test orientation_correspondre_caractere");
    
    int valid=1;
    
    if((orientation_correspondre_caractere('^'))!=haut)
    {
      puts("KO haut");
      valid=0;
    }
     if((orientation_correspondre_caractere('v'))!=bas)
    {
      puts("KO bas");
      valid=0;
    }
     if((orientation_correspondre_caractere('<'))!=gauche)
    {
      puts("KO gauche");
      valid=0;
    }
     if((orientation_correspondre_caractere('>'))!=droite)
    {
      puts("KO droite");
      valid=0;
    }
    
    if(valid!=1)
      puts("KO\n");
    else
      puts("OK\n");
}