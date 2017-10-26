
/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 *
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Le mode interactif permet d'interfacer le jeu de siam avec
 *  la commande d'utilisateur en ligne de commande.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions proposee dans le mode interactifs permettent de
 *  demarer le controle du jeu en ligne de commande.
 * Les fonctions du mode interactif ont pour but de dialoguer avec
 *  un utilisateur (potentiellement non programmeur). Elles
 *  affichent donc les messages de dialogue avec l'utilisateur.
 * Le mode interactif vient egalement realiser la synchronisation
 *  des fonctions de gestion du jeu (demande d'action, realisation
 *  d'actions, affichage informatif, enregistrement et lecture
 *  a partir de fichiers et affichage du vainqueur).
 * Comme les fonctions traitent de demandent utilisateurs elles
 *  ne peuvent pas presuposer de contraintes de type "assertions"
 *  sur les variables completees interactivement.
 *
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Ce niveau d'abstraction a pour role de realiser l'interface entre
 *  une entree sous forme de demande utilisateur vers l'API du programme.
 * Le mode interactif ne vient utiliser que des fonctions de hauts
 *  niveaux du jeu qu'il utilise comme une librairie externe.
 */





#ifndef MODE_INTERACTIF_H
#define MODE_INTERACTIF_H

#include "jeu_siam.h"



/**
 * Fonction mode_interactif_lancer
 * ******************************
 *  Lance le mode intéractif.
 *  Initialise le jeu et les actions de départ.
 *  Vérifie s'il y a victoire ou fin de partie sans victoire.
 *
 */
void mode_interactif_lancer();

/////////////////////////////////////////////////////////////////////////////

/**
 * Fonction mode_interactif_introduire_nouvelle_piece
 * ******************************
 *  Introduit une nouvelle piece sur le plateau aux coordonées (x,y) avec une orientation définie.
 *
 *  Nécessite :
 *      - Un pointeur de jeu non NULL.
 *      - Un pointeur de victoire non NULL.
 *      - Des coordonnées entières x,y.
 *  Garantie :
 *      - Les paramètres d'introduction sont OK
 *      - La pièce introduite est valide.
 *      - Si le coup est victorieux, met fin au jeu. *
 */
void mode_interactif_introduire_nouvelle_piece(jeu_siam* jeu,int x,int y,orientation_deplacement orientation,int* victoire);

/////////////////////////////////////////////////////////////////////////////

/**
 * Fonction mode_interactif_deplacer_piece
 * ******************************
 *  Déplacer une piece sur le plateau aux coordonées (x,y) avec une orientation définie.
 *
 *  Nécessite :
 *      - Un pointeur de jeu non NULL.
 *      - Un pointeur de victoire non NULL.
 *      - Des coordonnées entières x,y.
 *      - Une orientation et un déplacement valides
 *  Garantie :
 *      - Les paramètres de déplacement sont OK ou non.
 *      - La pièce déplacée est valide.
 *      - Si le coup est victorieux, met fin au jeu.
 */
void mode_interactif_deplacer_piece(jeu_siam* jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation,int* victoire);

/////////////////////////////////////////////////////////////////////////////

/**
 * Fonction mode_interactif_changer_orientation
 * ******************************
 *  Changer l'orientation de la piece aux coordonées (x,y).
 *
 *  Nécessite :
 *      - Un pointeur de jeu non NULL.
 *      - Des coordonnées entières x,y.
 *      - Une orientation valide.
 *  Garantie :
 *      - Les paramètres de changement d'orientation sont OK ou non.
 *      - La pièce nouvellement orientée est valide.
 */
void mode_interactif_changer_orientation(jeu_siam* jeu,int x,int y,orientation_deplacement orientation);

/////////////////////////////////////////////////////////////////////////////

/**
 * Fonction mode_interactif_sauvegarder_jeu_fichier
 * ******************************
 *  Sauvegarde le fichier du jeu.
 *
 *  Nécessite :
 *      - Un pointeur de jeu non NULL non modifiable.
 *      - Un jeu intègre.
 *  Garantie :
 *      - Sauvegarde de l'état du jeu dans le fichier "etat_courant.txt"
 */
void mode_interactif_sauvegarder_jeu_fichier(const jeu_siam* jeu);

/////////////////////////////////////////////////////////////////////////////

/**
 * Fonction mode_interactif_lire_fichier
 * ******************************
 *  Lit un fichier.
 *
 *  Nécessite :
 *      - Un pointeur de jeu non NULL.
 *      - Un pointeur sur char non NULL et non modifiable.
 *  Garantie :
 *      - Un jeu intègre.
 */
void mode_interactif_lire_fichier(jeu_siam* jeu,const char* filename);

/////////////////////////////////////////////////////////////////////////////

/**
 * Fonction mode_interactif_parametres_etre_valides
 * ******************************
 *  Valide ou non les paremètres
 *
 *  Nécessite :
 *      - Un pointeur de jeu non NULL et non modifiable.
 *      - Un jeu intègre.
 *      - Des coordonnées x,y dans le plateau.
 *      - Un orientation intègre.
 *  Garantie :
 *      - Les paramètres en entrée sont valides. Les coordonnées x,y
 *      sont dans le plateau et l'orientation est intègre.
 */
int mode_interactif_parametres_etre_valides(const jeu_siam* jeu,int x,int y,orientation_deplacement orientation);


#endif
