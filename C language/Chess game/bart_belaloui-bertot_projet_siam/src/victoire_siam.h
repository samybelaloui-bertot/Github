
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
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Condition victoire partie est un conteneur stockant un vainqueur
 *  possible.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ce fichier permettent de verifier si un joueur
 *  est vainqueur.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il s'agit d'un niveau d'abstraction ayant uniquement la connaissance
 *  de l'existance d'un vainqueur et du numero du joueur associe.
 *
 */


/**
 * Fonction victoire_siam_victoire
 * *******************************
 *  Vérifie si un joueur a gagné et renvoie le résultat.
 *
 *  Nécessite :
 *      - Un pointeur de jeu non NULL et non modifiable.
 *      - Un jeu intègre.
 *      - Des coordonnées x,y intègres.
 *
 *  Garantie :
 *      - Une structure condition_victoire_partie mise à jour.
 *
 */
condition_victoire_partie victoire_siam_victoire(const jeu_siam *jeu, int x, int y);
