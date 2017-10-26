#include "api_siam.h"
#include "plateau_modification.h"
#include "plateau_siam.h"
#include "orientation_deplacement.h"
#include "joueur.h"
#include "poussee.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


condition_victoire_partie victoire_siam_victoire(const jeu_siam *jeu, int x, int y)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    assert(verification_coordonnees(x,y));

    condition_victoire_partie condition_victoire;
    condition_victoire.victoire=0;      // Condition victoire initialisée.
    condition_victoire.joueur=0;

    if(plateau_denombrer_type(&(jeu->plateau), rocher)<3)        // Si il y a un cas de victoire.
    {

        piece_siam piece_poussante, piece_gagnante;

        // On récupère les infos sur la pièce a l'origine de la poussée.
        piece_poussante.type=plateau_obtenir_piece_info(&(jeu->plateau), x, y)->type;
        piece_poussante.orientation=plateau_obtenir_piece_info(&(jeu->plateau), x, y)->orientation;


        printf("\ninfo piece poussante: type=%d, orientation=%d, x=%d, y=%d \n",piece_poussante.type, piece_poussante.orientation, x, y);
        // On récupère la pièce en bordure ayant poussé le rocher a l'extérieur.
        switch(piece_poussante.orientation)
        {
        case haut:
            piece_gagnante.type=plateau_obtenir_piece_info(&(jeu->plateau), x, NBR_CASES-1)->type;
            piece_gagnante.orientation=plateau_obtenir_piece_info(&(jeu->plateau), x, NBR_CASES-1)->orientation;
            break;

        case bas:
            piece_gagnante.type=plateau_obtenir_piece_info(&(jeu->plateau), x, 0)->type;
            piece_gagnante.orientation=plateau_obtenir_piece_info(&(jeu->plateau), x, 0)->orientation;
            break;

        case droite:
            piece_gagnante.type=plateau_obtenir_piece_info(&(jeu->plateau), NBR_CASES-1, y)->type;
            piece_gagnante.orientation=plateau_obtenir_piece_info(&(jeu->plateau), NBR_CASES-1, y)->orientation;
            break;

        case gauche:
            puts("avant boucle gauche condition victoire");
            piece_gagnante.type=plateau_obtenir_piece_info(&(jeu->plateau), 0, y)->type;
            piece_gagnante.orientation=plateau_obtenir_piece_info(&(jeu->plateau), 0, y)->orientation;
            puts("apres boucle gauche condition victoire");
            break;

        default:
            puts("default");

        }

        int numero_joueur_gagnant=joueur_obtenir_numero_a_partir_animal(piece_gagnante.type);

        condition_victoire.joueur=numero_joueur_gagnant;
        condition_victoire.victoire=1;
    }

    // Sinon on ne fait rien.



    return condition_victoire;
}
