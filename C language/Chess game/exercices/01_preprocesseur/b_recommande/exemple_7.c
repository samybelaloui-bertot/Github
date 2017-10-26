#include "entete/mes_fonctions_1.h"

int main()
{
  int var=5;
  var=ma_fonction_1(var);
  var=ma_fonction_2(var);

  printf("%d\n",var);

  return 0;
}

// Question: 
// Visualiser la sortie du preprocesseur, qu'est devenu le #include ?
// Quelles lignes doit-on taper pour creer un executable de ce programme (on ignorera le warning concernant printf)? Realisez cet executable. Verifiez le resultat obtenu.
// Au moment de la compilation de exemple_7.c vers exemple_7.o a t'on connaissance de l'implémentation (c.a.d du corps de la fonction) de "ma_fonction_1" et "ma_fonction_2"? 
