#ifndef POUSSEE_H
#define POUSSEE_H


#include "coup_jeu.h"
#include "plateau_siam.h"



/**
 * Fonction poussee_etre_valide:
 * ****************************
 *  Verifie s il est possible de realiser une poussee qui debute aux coordonees
 *  (x,y) dans l'orientation definie
 *
 *      Note:
 *      Les coordonees (x,y) designent la premiere piece rencontree dans la poussee.
 *
 *      Necessite :
 *      - Un pointeur non NULL vers un plateau integre non modifiable
 *      - Deux coordonees entieres (x,y) desigant une piece non-vide
 *      integre du plateau
 *      - Une orientation de poussee designant une direction integre
 *
 *      Garantie :
 *      - Un retour valant 1 si la poussee est possible
 *      - Un retour valant 0 sinon
 */
int poussee_etre_valide(const plateau_siam* plateau, int x, int y,
			orientation_deplacement orientation);

/**
 * Fonction pousse_realiser:
 * **************************
 *
 *      Necessite:
 *      - Un pointeur non NULL vers un plateau integre modifiable
 *      - Deux coordonees entieres (x,y) designant une piece non-vide integre
 *      du plateau
 *      - Un type d'animal a deplacer
 *      - Une orientation de pousse designant une direction integre
 *      - Un pointeur non NULL vers une condition de victoire modifiable
 *
 *      Garantie :
 *      - Un plateau integre mis a jour en ayant realise la poussee.
 *
 */
void poussee_realiser(plateau_siam* plateau, const int x, const int y, type_piece type,
		      orientation_deplacement orientation);


/**
 * Fonction forces_poussee_haut:
 * **************************
 * Calcule et renvoie la somme des forces de poussée dans le cas d'une poussée vers le haut
 *
 *      Note:
 *      Les coordonees (x,y) designent la premiere piece rencontree dans la poussee.
 *
 *      Necessite :
 *      - Un pointeur non NULL vers un plateau integre non modifiable
 *      - Deux coordonees entieres (x,y) desigant une piece non-vide
 *      integre du plateau
 *      - Une orientation de poussee designant une direction integre
 *
 *
 */
int forces_poussee_haut(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation);

/**
 * Fonction forces_poussee_bas:
 * **************************
 * Calcule et renvoie la somme des forces de poussée dans le cas d'une poussée vers le bas
 *
 *      Note:
 *      Les coordonees (x,y) designent la premiere piece rencontree dans la poussee.
 *
 *      Necessite :
 *      - Un pointeur non NULL vers un plateau integre non modifiable
 *      - Deux coordonees entieres (x,y) desigant une piece non-vide
 *      integre du plateau
 *      - Une orientation de poussee designant une direction integre
 *
 *
 */
int forces_poussee_bas(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation);

/**
 * Fonction forces_poussee_gauche:
 * **************************
 * Calcule et renvoie la somme des forces de poussée dans le cas d'une poussée vers la gauche
 *
 *      Note:
 *      Les coordonees (x,y) designent la premiere piece rencontree dans la poussee.
 *
 *      Necessite :
 *      - Un pointeur non NULL vers un plateau integre non modifiable
 *      - Deux coordonees entieres (x,y) desigant une piece non-vide
 *      integre du plateau
 *      - Une orientation de poussee designant une direction integre
 *
 *
 */
int forces_poussee_gauche(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation);

/**
 * Fonction forces_poussee_droite:
 * **************************
 * Calcule et renvoie la somme des forces de poussée dans le cas d'une poussée vers la droite
 *
 *      Note:
 *      Les coordonees (x,y) designent la premiere piece rencontree dans la poussee.
 *
 *      Necessite :
 *      - Un pointeur non NULL vers un plateau integre non modifiable
 *      - Deux coordonees entieres (x,y) desigant une piece non-vide
 *      integre du plateau
 *      - Une orientation de poussee designant une direction integre
 *
 *
 */
int forces_poussee_droite(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation);

#endif
