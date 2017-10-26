#include "type_piece.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int type_etre_integre(type_piece type)
{
    // L'enumeration designe un type integre si elle est comprise
    //  entre 0 et 4.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 4 pour designer un type valide.
    if(type<4)
        return 1;
    return 0;
}

void test_type_etre_integre()
{
  // Fonction test de type_etre_integre
  
  puts("Test type_etre_integre");
  
  int k=0, valid=1;
  for(k=0 ; k<4 ; k++)
    if(type_etre_integre(k)!=1)
    {
      valid=0;
      printf("KO pour %d\n", k);
    }
    
  for(k=4 ; k<100 ; k++)
    if(type_etre_integre(k) !=0)
    {
      valid=0;
      printf("KO pour %d\n", k);
    }
    
  if(valid!=1)
    puts("KO\n");
  else
    puts("OK\n");
    
}


int type_etre_animal(type_piece type)
{
    // L'enumeration designe un type animal si elle est comprise entre 0 et 2.
    // Il suffit donc que type < 2 pour designer un type valide.
  
     if(type<2)
	return 1;
     return 0;
}


void test_type_etre_animal()
{
  // Fonction de test de la fonction type_etre_animal.
  
  puts("Test type_etre_animal");
  int valid=1;
  
  if(type_etre_animal(elephant)!=1)
  {
    puts("elephant KO");
    valid=0;
  }
  if(type_etre_animal(rhinoceros)!=1)
  {
    puts("rhinoceros KO");
    valid=0;
  }
  if(type_etre_animal(rocher)!=0)
  {
    puts("rocher KO");
    valid=0;
  }
  if ( type_etre_animal(case_vide)!=0)
  {
    puts("case vide KO");
    valid=0;
  }
  
  int k=0;
  for(k=4 ; k<100 ; ++k)
    if(type_etre_animal(k)!=0)
    {
      printf("valeur %d KO\n",k);
      valid++;
    }
   
  if(valid!=1)
    puts("KO\n");
  else
    puts("OK\n");
}


const char* type_nommer(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere correspondante.

    switch(type)
    {
    case elephant:
        return "elephant"; break;
    case rhinoceros:
        return "rhinoceros"; break;
    case rocher:
        return "rocher"; break;
    case case_vide:
        return "vide"; break;
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


const char* type_nommer_nom_cours(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere courte correspondante.

    switch(type)
    {
    case elephant:
        return "e"; break;
    case rhinoceros:
        return "r"; break;
    case rocher:
        return "RRR"; break;
    case case_vide:
        return "***"; break;
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

int type_caractere_animal_etre_integre(char type)
{
    // Verifie que le caractere correspond a elephant (e) ou rhinoceros (r).
    if(type=='e' || type=='r')
        return 1;
    return 0;
}

void test_type_caractere_animal_etre_integre()
{
    // Fonction test de type_caractere_animal_etre_integre.
    puts("Test type_caractere_animal_etre_integre");
    
    int valid=1;
    
    if(type_caractere_animal_etre_integre('e')!=1)
      {
      puts("KO elephant");
      valid=0;
      }
    
    if(type_caractere_animal_etre_integre('r')!=1)
    {
      puts("KO rhinoceros");
      valid=0;
    }
    
    if(valid!=1)
      puts("KO\n");
    else
      puts("OK\n");
}

type_piece type_correspondre_caractere_animal(char type)
{
    // Verifie que le caractere saisi correspond à un animal elephant (e) ou rhinoceros (r).
    assert(type_caractere_animal_etre_integre(type));
    
    // Valeur par défaut de la variable de retour.
    type_piece type_enum=elephant;
    
    if(type == 'e')
      type_enum = elephant;
    else
      type_enum = rhinoceros;
    
    return type_enum;
}

void test_type_correspondre_caractere_animal()
{
    //Fonction de test de type_correspondre_caractere_animal
    puts("Test type_correspondre_caractere_animal");
    
    int valid=1;
    
    if((type_correspondre_caractere_animal('e'))!=elephant)
    {
      puts("KO elephant");
      valid=0;
    }
     if((type_correspondre_caractere_animal('r'))!=rhinoceros)
    {
      puts("KO rhinoceros");
      valid=0;
    }
    
    if(valid!=1)
      puts("KO\n");
    else
      puts("OK\n");
}
