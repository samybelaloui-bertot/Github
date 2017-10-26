
#include <stdio.h>
#include <stdlib.h>


void ma_fonction();

int main()
{

  ma_fonction();

  return 0;
}

void ma_fonction()
{
  puts("Je suis une fonction");
  
  printf("Je suis dans la fonction [%s], dans le fichier [%s], a la ligne %d\n",__FUNCTION__,__FILE__,__LINE__);


}

// Compilez ce programme, qu'affiche-il ?
// Notez que les appels __FUNCTION__,__FILE__,et __LINE__ sont des parametres particuliers connus du compilateur.
// Quels parametres sont directements remplaces pendant l'etape de preprocesseurs?
// Note: Ces parametres peuvent etre utiles pour afficher des messages d'erreurs designants precisement ou se passe l'erreur en question.

