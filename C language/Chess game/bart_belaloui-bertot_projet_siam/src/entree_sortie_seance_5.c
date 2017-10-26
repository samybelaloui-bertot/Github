/*
void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu)
{

  assert ( filename != NULL);
  assert ( jeu != NULL);

  jeu_initialiser(jeu); // Initialisation du jeu

  FILE* file;
  file = fopen(filename, "r"); // On ouvre le ficihier et on le lit;

  // Lecture de joueur;
  int joueur=1;
  char nom [10];
  int x = fscanf(file,"joueur %d (%8s)\n ",&joueur,nom);
  printf("%d joueur %d (%s)\n ",x,joueur,nom);
  jeu->joueur = joueur;


  // Lecture du plateau;
  int i,j;
  plateau_siam plateau = jeu->plateau;


  int nb_collones = 5;
  int nb_lignes   = 5;



  for(i=nb_lignes-1;i>=0;i--)
    {

      fscanf(file,
         "[%d] "
         ,&i);
      //Trouver la ligne
      // N'est pas exactement necessaire

      for(j=0;j<nb_collones;j++)
    {
      char str_piece[3];

      fscanf(file,"%3s |",str_piece);
      //On prend le trois charactere qui forme notre piece

      plateau.piece[j][i] = piece_correspondre_nom_cours(str_piece);
    }

      fscanf(file,"\n");
      // Nouvelle ligne
    }

  jeu->plateau = plateau;

  assert(jeu_etre_integre(jeu)==1);
}

////////////////////////////////////////////////////////////////////
/// \brief entree_sortie_ecrire_plateau_pointeur_fichier
/// \param identifiant
/// \param plateau
///

void entree_sortie_ecrire_plateau_pointeur_fichier(FILE* identifiant,const plateau_siam* plateau)
{
  assert(identifiant != NULL);
  assert(plateau     != NULL);

  int i;
  int j;

  int nb_collones = 5;
  int nb_lignes   = 5;

  for (i = nb_collones-1; i>=0;i--)
    {
      fprintf(identifiant, "[%i]",i);

      for(j=0; j<nb_lignes; j++)
    {
      piece_siam piece = plateau -> piece [j][i];
      const char *str=type_nommer_nom_cours(piece.type);
      //On a une case vide
      if(*str == '*')
        {
          fprintf(identifiant," %s |",str);
        }
      //On a une rocher
      else if(*str == 'R')
        {
          fprintf(identifiant," RRR |");
        }
      // Sinon, on a une piece
      else
        {
          char t =*str;
          const char *c=orientation_nommer_nom_cours(piece.orientation);
          fprintf(identifiant," %c-%c |",t,*c);

        }
    }
      fprintf(identifiant,"\n");
    }

  fprintf(identifiant,"    [0]   [1]   [2]   [3]   [4]  \n ");
}
*/
