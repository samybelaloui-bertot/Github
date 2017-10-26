
#include "piece_siam.h"
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "api_siam.h"
#include "mode_interactif.h"

#include <stdio.h>


#include "type_piece.h"
 
 void lancer_test()
 {
   test_type_etre_animal();
   test_type_etre_integre();
   test_type_caractere_animal_etre_integre();
   test_type_correspondre_caractere_animal();
   test_orientation_etre_integre();
   test_orientation_etre_integre_deplacement();
   test_orientation_caractere_etre_integre();
   test_orientation_correspondre_caractere();
   test_piece_etre_integre();
   test_piece_etre();
   test_piece_definir();
   test_verification_coordonnees();
   test_coordonnees_etre_bordure_plateau();
 }

int main ()
{
  //lancer_test();
  
  mode_interactif_lancer();
  
  return 0;
}