#include "poussee.h"
#include "plateau_siam.h"
#include "orientation_deplacement.h"
#include "piece_siam.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


//DEFINITION DES COEFFICIENTS DE POUSSEE
#define COEFF_CASE_VIDE 0           //Case vide
#define COEFF_ROCHER -9             //Rocher
#define COEFF_ANIMAL_MSENS 10       // Animal dans le même sens
#define COEFF_ANIMAL_CSENS -10      // Animal dans le sens contraire
#define COEFF_ANIMAL_SENSD 0        // Animal de sens différent sauf contraire


/////////////////////////////////////////////////////////////////////////////


int poussee_etre_valide(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation)                //Plateau non modifibale : on met un "const"
{

    //ASSERTIONS
    assert(plateau!=NULL);          //Vérification pointeur non nul vers un plateau intègre (indépendant de l'utilisateur ici)
    assert(plateau_etre_integre(plateau));


    //TEST DES PARAMETRES RENSEIGNES PAR L'UTILISATEUR
    if(orientation_etre_integre(orientation)!=1)        //On vérifie si l'orientation de poussée est intègre (dépend de l'utilisateur)
    {
        puts("Orientation de poussee non integre");
        return 0;
    }

    if(verification_coordonnees(x,y)!=1)            //On vérifie si les coordonnées sont intègres (dépend de l'utilisateur)

    {
        puts("Coordonnées non intègres");
        return 0;
    }

    if(plateau_exister_piece(plateau, x, y)!=1)
    {
//         puts("La case selectionnee pour la poussee est vide");      //On vérifie si la case sélectionnée n'est pas vide (dépend de l'utilisateur)
        return 0;
    }


    //CALCUL DE LA SOMME DES FORCES
    int somme_forces=10;         //Initialisation de la somme des forces de poussée à 0
    int renvoie;            //Variable de renvoie

    switch(orientation)
    {
    case haut:          //Si l'orientation est '^'
        somme_forces=forces_poussee_haut(plateau, x, y, orientation);       //Appel de la fonction de calcul de forces de poussée pour le cas "haut"
        //printf("La somme des forces est %hd\n", somme_forces);
        break;

    case bas:           //Si l'orientation est 'v'
        somme_forces=forces_poussee_bas(plateau, x, y, orientation);       //Appel de la fonction de calcul de forces de poussée pour le cas "bas"
        printf("La somme des forces est %hd\n", somme_forces);
        break;

    case gauche:        //Si l'orientation est '<'
        somme_forces=forces_poussee_gauche(plateau, x, y, orientation);       //Appel de la fonction de calcul de forces de poussée pour le cas "gauche"
        //printf("La somme des forces est %hd\n", somme_forces);
        break;

    case droite:        //Si l'orientation est '>'
        somme_forces=forces_poussee_droite(plateau, x, y, orientation);       //Appel de la fonction de calcul de forces de poussée pour le cas "droite"
        //printf("La somme des forces est %hd\n", somme_forces);
        break;

    default:            //Autres cas (ne doit pas arriver)
         somme_forces=somme_forces;

    }

    //ON VALIDE LA POUSSE OU NON SELON LA SOMME CALCULEE
    if(somme_forces>0)          //Si la somme des forces de poussée est positive, la poussée est valide
    {
        renvoie=1;
    }
    else                        //Si la somme des forces de poussée est négative ou nulle, la poussée est invalide
        renvoie=0;

   return renvoie;
}


/////////////////////////////////////////////////////////////////////////////

void poussee_realiser(plateau_siam* plateau, const int x, const int y, type_piece type,
		      orientation_deplacement orientation)
{      //On récupère l'orientation de la piece aux coordonnees
  int cptpoussee=0, seuil=0;

  switch(orientation)
  {
  case haut:

      seuil=y;
      while((seuil<(NBR_CASES)) && plateau_obtenir_piece_info(plateau, x, seuil)->type != case_vide)
      {
          seuil++;
      }

      for(cptpoussee=seuil-1; cptpoussee>=y-1; cptpoussee--)      //Sur la colonne on pousse piece par piece en commencant par la piece au bord du plateau
      {
          orientation_deplacement op = (plateau->piece[x][cptpoussee]).orientation;
          type_piece typep = (plateau->piece[x][cptpoussee]).type;

          if((piece_etre_rocher(&(plateau->piece[x][NBR_CASES]))==1)||(piece_etre_animal(&(plateau->piece[x][NBR_CASES]))==1))
          {
              piece_definir_case_vide(&(plateau->piece[x][NBR_CASES]));
          }

          piece_definir(&(plateau->piece[x][cptpoussee+1]),typep,op);
          piece_definir_case_vide(&(plateau->piece[x][cptpoussee]));

      }


      break;

  case bas:

      seuil=y;
      while((seuil>=0) && plateau_obtenir_piece_info(plateau, x, seuil)->type != case_vide)
      {
          seuil--;
      }

      for(cptpoussee=seuil+1; cptpoussee<=y+1; cptpoussee++)      //Sur la colonne on pousse piece par piece en commencant par la piece au bord du plateau
      {
          orientation_deplacement op = (plateau->piece[x][cptpoussee]).orientation;
          type_piece typep = (plateau->piece[x][cptpoussee]).type;

          if((piece_etre_rocher(&(plateau->piece[x][0]))==1)||(piece_etre_animal(&(plateau->piece[x][0]))==1))
          {
              piece_definir_case_vide(&(plateau->piece[x][0]));
          }

          piece_definir(&(plateau->piece[x][cptpoussee-1]),typep,op);
          piece_definir_case_vide(&(plateau->piece[x][cptpoussee]));
      }
      break;

  case gauche:

      seuil=x;
      while((seuil>=0) && plateau_obtenir_piece_info(plateau, seuil, y)->type != case_vide)
      {
          seuil--;
      }

      for(cptpoussee=seuil+1; cptpoussee<=x+1; cptpoussee++)      //Sur la colonne on pousse piece par piece en commencant par la piece au bord du plateau
      {
          orientation_deplacement op = (plateau->piece[cptpoussee][y]).orientation;
          type_piece typep = (plateau->piece[cptpoussee][y]).type;

          if((piece_etre_rocher(&(plateau->piece[y][0]))==1)||(piece_etre_animal((&(plateau->piece[y][0]))==1)))
          {
              piece_definir_case_vide(&(plateau->piece[x][NBR_CASES]));
          }

          piece_definir(&(plateau->piece[cptpoussee-1][y]),typep,op);
          piece_definir_case_vide(&(plateau->piece[cptpoussee][y]));
      }
      break;

  case droite:

      seuil=x;
      while((seuil<(NBR_CASES)) && plateau_obtenir_piece_info(plateau, seuil, y)->type != case_vide)
      {
          seuil++;
      }

      for(cptpoussee=seuil-1; cptpoussee>=x-1; cptpoussee--)      //Sur la colonne on pousse piece par piece en commencant par la piece au bord du plateau
      {
          orientation_deplacement op = (plateau->piece[cptpoussee][y]).orientation;
          type_piece typep = (plateau->piece[cptpoussee][y]).type;

          if((piece_etre_rocher(&(plateau->piece[y][NBR_CASES]))==1)||(piece_etre_animal(&(plateau->piece[y][NBR_CASES]))==1))
          {
              piece_definir_case_vide(&(plateau->piece[x][NBR_CASES]));
          }


          piece_definir(&(plateau->piece[cptpoussee+1][y]),typep,op);
          piece_definir_case_vide(&(plateau->piece[cptpoussee][y]));
      }

  case aucune_orientation:
      break;

  }
}

/////////////////////////////////////////////////////////////////////////////
int forces_poussee_haut(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation)
{
    int somme_forces=10;      //Somme des forces (variable de sortie)
        int i, seuil=y;      //Initialisation du compteur de coordonnées

    if(coordonnees_etre_bordure_plateau(x,y)!=1)
    {
        if((plateau_obtenir_piece_info(plateau, x, y-1)->orientation)!=orientation)     //Si l'orientation du joueur est différente de l'orientation de poussée
        {
            puts("La poussée est impossible : L'orientation de votre piece est différente de votre orientation de poussée...");
            return 0;
        }
    }

    while((seuil<(NBR_CASES)) && plateau_obtenir_piece_info(plateau, x, seuil)->type != case_vide)
    {
        seuil++;
    }


    for(i=y ; i<seuil ; i++)     //On parcout les cases de la colonne
    {
        if(somme_forces<0)
        {
            somme_forces=-200; // Dès qu'on rencontre une pièce bloquante on vérouille la force de poussée dans le négatif
        }
            switch(plateau_obtenir_piece_info(plateau, x, i)->type)
            {
            case elephant:          //Si il y a un éléphant sur la case
                //puts("IL Y A UN ELEPHANT");

                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==haut)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;

                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==bas)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;

                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;

            case rhinoceros:        //Si il y a un rhinocéros sur la case (idem que pour l'éléphant)
                //puts("IL Y A UN RHINOCEROS");

                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==haut)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;
                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==bas)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;
                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;


            case case_vide:         //Si il y a une case vide sur la case
                //puts("IL Y A UNE CASE VIDE");
                somme_forces=somme_forces+COEFF_CASE_VIDE;
                break;

            case rocher:            //Si il y a un rocher sur la case
                //puts(" IL Y A UN ROCHER ");
                somme_forces=somme_forces+COEFF_ROCHER;
                break;
            }
    }
    return somme_forces;
}

/////////////////////////////////////////////////////////////////////////////
int forces_poussee_bas(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation)
{
    int somme_forces=10;      //Somme des forces (variable de sortie)
    signed int i, seuil=y;      //Initialisation du compteur de coordonnées

    if(coordonnees_etre_bordure_plateau(x,y)!=1)
    {
        if((plateau_obtenir_piece_info(plateau, x, y+1)->orientation)!=orientation)     //Si l'orientation du joueur est différente de l'orientation de poussée
        {
            puts("La poussée est impossible : L'orientation de votre piece est différente de votre orientation de poussée...");
            return 0;
        }
    }

    while((seuil>=0) && plateau_obtenir_piece_info(plateau, x, seuil)->type != case_vide)
    {
        seuil--;
    }

    for(i=y ; i>seuil ; i--)     //On parcout les cases de la colonne
    {
        if(somme_forces<0)
        {
            somme_forces=-200; // Dès qu'on rencontre une pièce bloquante on vérouille la force de poussée dans le négatif
        }
            switch(plateau_obtenir_piece_info(plateau, x, i)->type)
            {
            case elephant:          //Si il y a un éléphant sur la case
                puts("IL Y A UN ELEPHANT");

                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==bas)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;

                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==haut)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;

                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;

            case rhinoceros:        //Si il y a un rhinocéros sur la case (idem que pour l'éléphant)
                puts("IL Y A UN RHINOCEROS");

                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==bas)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;
                if((plateau_obtenir_piece_info(plateau, x, i)->orientation)==haut)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;
                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;


            case case_vide:         //Si il y a une case vide sur la case
                puts("IL Y A UNE CASE VIDE");
                somme_forces=somme_forces+COEFF_CASE_VIDE;
                break;

            case rocher:            //Si il y a un rocher sur la case
                puts(" IL Y A UN ROCHER ");
                somme_forces=somme_forces+COEFF_ROCHER;
                break;
            }
    }
    return somme_forces;
}

/////////////////////////////////////////////////////////////////////////////
int forces_poussee_gauche(const plateau_siam* plateau, int x, int y,
                        orientation_deplacement orientation)
{
    int somme_forces=10;      //Somme des forces (variable de sortie)
        int i, seuil=x;      //Initialisation du compteur de coordonnées

    if(coordonnees_etre_bordure_plateau(x,y)!=1)
    {
        if((plateau_obtenir_piece_info(plateau, x+1, y)->orientation)!=orientation)     //Si l'orientation du joueur est différente de l'orientation de poussée
        {
            puts("La poussée est impossible : L'orientation de votre piece est différente de votre orientation de poussée...");
            return 0;
        }
    }

    while((seuil>=0) && plateau_obtenir_piece_info(plateau, seuil, y)->type != case_vide)
    {
        seuil--;
    }

    for(i=x ; i>seuil ; i--)     //On parcout les cases de la colonne
    {
        if(somme_forces<0)
        {
            somme_forces=-200; // Dès qu'on rencontre une pièce bloquante on vérouille la force de poussée dans le négatif
        }
            switch(plateau_obtenir_piece_info(plateau, i, y)->type)
            {
            case elephant:          //Si il y a un éléphant sur la case
                //puts("IL Y A UN ELEPHANT");

                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==gauche)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;

                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==droite)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;

                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;

            case rhinoceros:        //Si il y a un rhinocéros sur la case (idem que pour l'éléphant)
                //puts("IL Y A UN RHINOCEROS");

                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==gauche)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;
                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==droite)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;
                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;


            case case_vide:         //Si il y a une case vide sur la case
                //puts("IL Y A UNE CASE VIDE");
                somme_forces=somme_forces+COEFF_CASE_VIDE;
                break;

            case rocher:            //Si il y a un rocher sur la case
                //puts(" IL Y A UN ROCHER ");
                somme_forces=somme_forces+COEFF_ROCHER;
                break;
            default:
            puts("ok");
            }
    }
    return somme_forces;
}

/////////////////////////////////////////////////////////////////////////////
int forces_poussee_droite(const plateau_siam* plateau, int x, int y,orientation_deplacement orientation)
{
    int somme_forces=10;      //Somme des forces (variable de sortie)
        int i, seuil=x;      //Initialisation du compteur de coordonnées

    if(coordonnees_etre_bordure_plateau(x,y)!=1)
    {
        if((plateau_obtenir_piece_info(plateau, x-1, y)->orientation)!=orientation)     //Si l'orientation du joueur est différente de l'orientation de poussée
        {
            puts("La poussée est impossible : L'orientation de votre piece est différente de votre orientation de poussée...");
            return 0;
        }
    }



    while((seuil<(NBR_CASES)) && plateau_obtenir_piece_info(plateau, seuil, y)->type != case_vide)
    {
        seuil++;
    }

    for(i=x ; i<seuil ; i++)     //On parcout les cases de la colonne
    {
        if(somme_forces<0)
        {
            somme_forces=-200; // Dès qu'on rencontre une pièce bloquante on vérouille la force de poussée dans le négatif
        }
            switch(plateau_obtenir_piece_info(plateau, i, y)->type)
            {

            case elephant:          //Si ilsomme_forces y a un éléphant sur la case
                //puts("IL Y A UN ELEPHANT");

                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==droite)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;

                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==gauche)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;

                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;

            case rhinoceros:        //Si il y a un rhinocéros sur la case (idem que pour l'éléphant)
                //puts("IL Y A UN RHINOCEROS");

                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==droite)      //Si l'éléphant et le joueur sont dans le meme sens
                    somme_forces=somme_forces+COEFF_ANIMAL_MSENS;
                if((plateau_obtenir_piece_info(plateau, i, y)->orientation)==gauche)       //Si l'éléphant et le joueur sont en contre sens
                    somme_forces=somme_forces+COEFF_ANIMAL_CSENS;
                else                                                                    //Si l'éléphant et le joueur sont en sens différents
                    somme_forces=somme_forces+COEFF_ANIMAL_SENSD;

                break;


            case case_vide:         //Si il y a une case vide sur la case
                //puts("IL Y A UNE CASE VIDE");
                somme_forces=somme_forces+COEFF_CASE_VIDE;
                break;

            case rocher:            //Si il y a un rocher sur la case
                //puts(" IL Y A UN ROCHER ");
                somme_forces=somme_forces+COEFF_ROCHER;
                break;

                default:
                puts("ok");

            }
    }
    return somme_forces;
}
