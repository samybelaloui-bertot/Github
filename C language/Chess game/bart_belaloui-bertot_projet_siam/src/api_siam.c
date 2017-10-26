#include "api_siam.h"
#include "plateau_modification.h"
#include "plateau_siam.h"
#include "orientation_deplacement.h"
#include "joueur.h"
#include "poussee.h"
#include "victoire_siam.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// REGARDER LES DEPASSEMENTS DE TABLEAU. ON UTILISE plateau.piece[x][y] au lieu de plateau_obtenir_piece_info.
// Préférer les fonctions au l'écriture brute.

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{

    coup_jeu coup;		//On initialise un coup de jeu
    coup_jeu_initialiser(&coup);
    
    int type_animal;
    type_animal=jeu_obtenir_type_animal_courant(jeu);
  
    if(plateau_modification_introduire_piece_etre_possible(&(jeu->plateau), x, y, type_animal, orientation)==1)
    {
      plateau_modification_introduire_piece(&(jeu->plateau), x, y, type_animal, orientation);

      coup.valide=1;
      victoire_siam_victoire(jeu, x, y);    // On met à jour la structure de condition_victoire.
      jeu_changer_joueur(jeu);
    }
    else
      coup.valide=0;
    
    return coup;
}




coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    coup_jeu coup;
    coup_jeu_initialiser(&coup);


    
    int x2,y2;

    switch(deplacement)         // Si les futures coordonnées sont hors plateau on supprime la pièce
    {
        case haut:
            x2=x;
            y2=y+1;
            
            break;
            
        case bas:
            x2=x;
            y2=y-1;
            
            break;
            
        case gauche:
            x2=x-1;
            y2=y;
            
            break;
            
        case droite:
            x2=x+1;
            y2=y;
            
            break;

        default:
            puts("Aucune orientation");
            break;
    }
    if(verification_coordonnees(x2,y2)==0)
    {
        (jeu->plateau).piece[x][y].type=case_vide;
        (jeu->plateau).piece[x][y].orientation=aucune_orientation;
        coup.valide=1;
        return coup;
    }
            
    
    int condition1=plateau_modification_deplacer_piece_etre_possible(&(jeu->plateau),x,y,deplacement,orientation);
    int condition2=(joueur_obtenir_animal(jeu->joueur))==(jeu->plateau.piece[x][y].type);
    int condition3=(verification_coordonnees(x,y)*orientation_etre_integre_deplacement(orientation)*orientation_etre_integre(deplacement));

    if((condition1!=0)&&(condition2!=0)&&(condition3!=0))   //Si le déplacement est possible
                                                            //Si le type du joueur est le meme que celui de la piece
                                                            //Si les coordonnées sont dans le plateau
                                                            //Si l'orientation et la direction de déplacement sont integres
    {
                // Alors on met a jour le jeu

                coup.valide=1;                  //Le coup est valide

                plateau_modification_deplacer_piece(&(jeu->plateau), x, y, deplacement, orientation); // Appel de la fonction de déplacement
                coup.condition_victoire=victoire_siam_victoire(jeu, x2, y2);    // On met à jour la structure de condition_victoire.


                jeu_changer_joueur(jeu);        //On change de joueur

    }

    else            // Sinon on sort : Le jeu n'est pas mis a jour et le coup est invalide
    {
        coup.valide=0;
        puts("Veuillez renseigner un deplacement valide...");
    }





    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
    assert(jeu!=NULL);		//Garanties

    coup_jeu coup;		// Initialisation des conditions de victoire
    coup_jeu_initialiser(&coup);

    int condition1=(joueur_obtenir_animal(jeu->joueur))==(jeu->plateau.piece[x][y].type);
    int condition2=verification_coordonnees(x,y)*orientation_etre_integre(orientation);
    int condition3=piece_etre_animal(plateau_obtenir_piece_info(&(jeu->plateau), x, y));
    int condition4=(plateau_obtenir_piece_info(&(jeu->plateau), x, y)->orientation)!=orientation;


    if((condition1*condition2*condition3*condition4)!=0)   //Si le type du joueur est le meme que celui de la piece
                                                           //Si les coordonnées sont dans le plateau et l'orientatione est intègre
                                                           //Si la piece est un animal
                                                           //Si on ne tente pas de changer l'orientation de la piece avec la meme orientation


    {
        // Alors on met a jour le jeu
        plateau_modification_changer_orientation_piece(&(jeu->plateau), x, y, orientation);	//Alors on modifie l'orientation
        coup.valide=1;		//Le coup est valide
        jeu_changer_joueur(jeu);    //Changement de joueur

    }
    else
    {
        coup.valide=0;		//Sinon le coup est invalide
        puts("Veuillez renseigner une orientation valide...");
    }

    return coup;
}
