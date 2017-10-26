#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "plateau_siam.h"
#include "type_piece.h"
#include "poussee.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,
                                                        int x,int y,
                                                        type_piece type,
                                                        orientation_deplacement orientation)
{
    assert(plateau!=NULL);		//Garantie du pointeur plateau non nul

    int valid=0;
    if(verification_coordonnees(x,y)!=1)		//Si les coordonnées ne sont pas valides 
    {
      puts("Coordonnees invalides");
      return 0;
    }
        
    if(coordonnees_etre_bordure_plateau(x,y)==1 && orientation_etre_integre(orientation)==1)	//Si les coordonnes de la piece sont en bordure de plateau et l'orientation est integre et le type est un animal integre
    {
        if((plateau->piece[x][y].type)==case_vide)
            valid=1;		//L'introduction de la piece est possible
                                //Sinon on test si la poussee est possible
        else
        {
            if(poussee_etre_valide(plateau, x, y, orientation)==1)      //SI LA POUSSE EST POSSIBLE
            {

                switch(orientation)         //ON VERIFIE L'ORIENTATION
                                            //ON REND VALIDE OU NON UNE INTRODUCTION DE POUSSEE EN OBSERVANT l'ORIENTATION DE LA PIECE QU'ON POSE
                {
                case haut:
                    if((y==0)&&(x>=0)&&(x<=NBR_CASES-1))
                        valid=1;

                    else
                        valid=0;

                    break;

                case bas:
                    if((y==4)&&(x>=0)&&(x<=NBR_CASES-1))
                        valid=1;

                    else
                        valid=0;
                    break;

                case gauche:
                    if((x==4)&&(y>=0)&&(y<=NBR_CASES-1))
                        valid=1;

                    else
                        valid=0;
                    break;

                case droite:
                    if((x==0)&&(y>=0)&&(y<=NBR_CASES-1))
                        valid=1;

                    else
                        valid=0;
                    break;

                default:
                    puts("Aucune orientation d'introduction");
                    valid=0;

                }
            }


            else
            {
                valid=0;
            }
        }
    }

    if(plateau_denombrer_type(plateau, type)==5)
    {
        puts("Vous ne pouvez pas faire ca");
        return 0;
    }

    if(plateau_etre_integre(plateau)!=1)
    {
      puts("Vous ne pouvez pas faire ca");
      return 0;
    }

    return valid;
}

//////////////////////////////////////////////////////////////////////////////////////////

void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           const int x, const int y,
                                           type_piece type,
                                           orientation_deplacement orientation)
{
    int x1=x,y1=y;
    
    if(plateau_modification_introduire_piece_etre_possible(plateau, x, y, type, orientation)==1
            && plateau_etre_integre(plateau)==1)		// Si l'introduction de la piece est possible
    {
        if(poussee_etre_valide(plateau, x,y, orientation)==1 && (plateau->piece[x][y]).type!=case_vide)   // On teste si la poussee est possible
        {
            switch(orientation)
            {
                case haut:
                    y1=y+1;
                    break;
                    
                case bas:
                    y1=y-1;
                    break;
                    
                case gauche:
                    x1=x-1;
                    break;
                    
                case droite:
                    x1=x+1;
                    break;
                    
                default:
                    puts("default");
            }
            poussee_realiser(plateau, x1, y1, type, orientation);
            piece_definir(&(plateau->piece[x][y]), type, orientation);
        }
        else
        {
            piece_definir(&(plateau->piece[x][y]), type, orientation);	//Alors on introduit la piece a la case renseignee
            //On verifite apres introduction que le plateau est toujours integre
        }
    }
    else puts("Introduction de la piece impossible");	//Sinon on n'introduit pas la piece et on renvoie un message d'erreur
}

//////////////////////////////////////////////////////////////////////////////////////////

int plateau_modification_changer_orientation_piece_etre_possible(const plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
    assert(plateau!=NULL);
    assert(plateau_etre_integre(plateau));
    
    if(verification_coordonnees(x0,y0)!=1)
      return 0;
    
    if(orientation_etre_integre_deplacement(orientation)!=1)
      return 0;
    
    if(piece_etre_animal(&(plateau->piece[x0][y0]))==1 && (plateau->piece[x0][y0].orientation) != orientation)
      return 1;
    
    else return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////


void plateau_modification_changer_orientation_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
    assert(plateau!=NULL);
    assert(verification_coordonnees(x0,y0));
    assert(piece_etre_animal(&(plateau->piece[x0][y0])));
    assert(orientation_etre_integre_deplacement(orientation));
    assert(plateau_modification_changer_orientation_piece_etre_possible(plateau, x0, y0, orientation));
    assert(plateau_etre_integre(plateau));
    
    (plateau->piece[x0][y0].orientation)=orientation;
    
    assert(piece_etre_animal(&(plateau->piece[x0][y0])));
    assert(piece_etre_integre(&(plateau->piece[x0][y0])));
    assert(plateau_etre_integre(plateau));
}

//////////////////////////////////////////////////////////////////////////////////////////


int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau,
                                                      int x0,int y0,
                                                      orientation_deplacement direction_deplacement,
                                                      orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau));
  
  // Si coordonnées en dehors du plateau --> Sortie
  if(verification_coordonnees(x0,y0)!=1)
  {
    puts("Coordonnées invalides");
    return 0;
  }
  
  // Si type non animal --> Sortie
  if(piece_etre_animal(&(plateau->piece[x0][y0]))!=1)
  {
    puts("Pas un animal");
    return 0;
  }
  
  // Si l'orientation après déplacement est mauvaise --> Sortie
  if(orientation_etre_integre(orientation)!=1)
  {
    puts("Orientation de la piece invalide");
    return 0;
  }
  
  // Si la direction de deplacement demandée est invalide --> Sortie
  if(orientation_etre_integre(direction_deplacement)!=1)
  {
    puts("Deplacement invalide");
    return 0;
  }
  
  // Vérifie les cases adjacentes
  switch(direction_deplacement)
  {
    case haut:

      if(((plateau_obtenir_piece_info(plateau, x0, y0+1)->type)!=case_vide))
      {



        if(poussee_etre_valide(plateau, x0, y0+1, direction_deplacement)==1)      //Si la poussée est posssible
        {
            if(orientation!=direction_deplacement)      //Si l'utilisateur tente de changer son orientation pendant la poussée
                                                        //On interdit le déplacement
            {
                puts("Vous ne pouvez pas pousser : changer son orientation est interdit");
                return 0;
            }
            else
            {

                return 1;
            }

        }
        else                //Si la poussée n'est pas possible
        {

            return 0;
        }


      }
      else return 1;
      break;
      
    case bas:
      
      if(((plateau_obtenir_piece_info(plateau, x0, y0-1)->type)!=case_vide))
      {

          if(poussee_etre_valide(plateau, x0, y0-1, direction_deplacement)==1)      //Si la poussée est posssible
          {
              if(orientation!=direction_deplacement)      //Si l'utilisateur tente de changer son orientation pendant la poussée
                                                          //On interdit le déplacement
              {
                  puts("Vous ne pouvez pas pousser : changer son orientation est interdit");
                  return 0;
              }
              else
              {

                  return 1;
              }

          }
          else                //Si la poussée n'est pas possible
          {

              return 0;
          }


      }
      else return 1;
      break;
      
    case droite:

      if(((plateau_obtenir_piece_info(plateau, x0+1, y0)->type)!=case_vide)&&(verification_coordonnees(x0+1,y0)!=0))
      {



          if(poussee_etre_valide(plateau, x0+1, y0, direction_deplacement)==1)      //Si la poussée est posssible
          {
              if(orientation!=direction_deplacement)      //Si l'utilisateur tente de changer son orientation pendant la poussée
                                                          //On interdit le déplacement
              {
                  puts("Vous ne pouvez pas pousser : changer son orientation est interdit");
                  return 0;
              }
              else
              {

                  return 1;
              }

          }
          else                //Si la poussée n'est pas possible
          {

              return 0;
          }


      }
      else return 1;
      break;
      
    case gauche:

      if(((plateau_obtenir_piece_info(plateau, x0-1, y0)->type)!=case_vide)&&(verification_coordonnees(x0-1,y0)!=0))
      {



          if(poussee_etre_valide(plateau, x0-1, y0, direction_deplacement)==1)      //Si la poussée est posssible
          {
              if(orientation!=direction_deplacement)      //Si l'utilisateur tente de changer son orientation pendant la poussée
                                                          //On interdit le déplacement
              {
                  puts("Vous ne pouvez pas pousser : changer son orientation est interdit");
                  return 0;
              }
              else
              {

                  return 1;
              }

          }
          else                //Si la poussée n'est pas possible
          {

              return 0;
          }


      }
      else return 1;
      break;
      
    default :
        puts("Orientation invalide");
        return 0;
  }
      
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////


void plateau_modification_deplacer_piece(plateau_siam* plateau,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final)
{
    //ASSERTIONS
    assert(plateau!=NULL);
    assert(plateau_etre_integre(plateau));
    assert(piece_etre_animal(&(plateau->piece[x0][y0])));

    
    if(plateau_modification_deplacer_piece_etre_possible(plateau, x0, y0, direction_deplacement, orientation_final) ==1)    //Si le déplacement est possible
    {
      switch(direction_deplacement)
      {
        case haut:      //Déplacement '^'************************************************

          //CAS DE POUSSEE
          if(poussee_etre_valide(plateau, x0, y0+1, direction_deplacement)==1)      //Si la poussée est possible
          {
              type_piece typep = (plateau->piece[x0][y0+1]).type;       //On récupère le type de la piece a pousser
              poussee_realiser(plateau,x0,y0+1,typep,orientation_final);       //On pousse la piece
          }
          else
          {
            //CAS DE DEPLACEMENT STANDART
            if((y0+1)>=0 && (y0+1)<=4)        //Si la case rencontrée lors du déplacement est dans le plateau
            {
              plateau->piece[x0][y0+1].type=plateau->piece[x0][y0].type;      //On recopie la piece sur cette case
              plateau->piece[x0][y0+1].orientation=orientation_final;
            }
             plateau->piece[x0][y0].type=case_vide;            //On remplace la piece par une case vide sur la case précédente
             plateau->piece[x0][y0].orientation=aucune_orientation;
          }
              break;

        case bas:       //Déplacement 'v'***************************************************

          //CAS DE POUSSEE
          if(poussee_etre_valide(plateau, x0, y0-1, direction_deplacement)==1)      //Si la poussée est possible
          {
              type_piece typep = (plateau->piece[x0][y0-1]).type;       //On récupère le type de la piece a pousser
              poussee_realiser(plateau,x0,y0-1,typep,orientation_final);       //On pousse la piece
          }
          else
          {
            //CAS DE DEPLACEMENT STANDART

          if((y0-1)>=0 && (y0-1)<=4)
          {
            plateau->piece[x0][y0-1].type=plateau->piece[x0][y0].type;
            plateau->piece[x0][y0-1].orientation=orientation_final;
          }
              plateau->piece[x0][y0].type=case_vide;
              plateau->piece[x0][y0].orientation=aucune_orientation;
          }
              break;



        case droite:    //Déplacement '>'****************************************************
             //CAS DE POUSSEE***********

          if(poussee_etre_valide(plateau, x0+1, y0, direction_deplacement)==1)      //Si la poussée est possible
                  {
                      type_piece typep = (plateau->piece[x0+1][y0]).type;       //On récupère le type de la piece a pousser
                      poussee_realiser(plateau,x0+1,y0,typep,orientation_final);       //On pousse la piece
                  }
                  else
                  {
          if((x0+1)>=0 && (x0+1)<=4)
          {
            plateau->piece[x0+1][y0].type=plateau->piece[x0][y0].type;
            plateau->piece[x0+1][y0].orientation=orientation_final;
          }
              plateau->piece[x0][y0].type=case_vide;
              plateau->piece[x0][y0].orientation=aucune_orientation;
                  }
              break;



        case gauche:    //Déplacement '<'*****************************************************

          //CAS DE POUSSEE***********
          if(poussee_etre_valide(plateau, x0-1, y0, direction_deplacement)==1)      //Si la poussée est possible
          {
              type_piece typep = (plateau->piece[x0-1][y0]).type;       //On récupère le type de la piece a pousser
              poussee_realiser(plateau,x0-1,y0,typep,orientation_final);       //On pousse la piece
          }
          else
          {
          if((x0-1)>=0 && (x0-1)<=4)
          {
            plateau->piece[x0-1][y0].type=plateau->piece[x0][y0].type;
            plateau->piece[x0-1][y0].orientation=orientation_final;
          }
              plateau->piece[x0][y0].type=case_vide;
              plateau->piece[x0][y0].orientation=aucune_orientation;
          }
              break;

        case aucune_orientation:
              break;
      }      
    }

    assert(plateau_etre_integre(plateau));
}


