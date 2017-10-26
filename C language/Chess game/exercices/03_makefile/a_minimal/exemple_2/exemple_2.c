#include <stdio.h>

#include "vecteur.h"


int main()
{
  struct vecteur vec1;
  vecteur_init(&vec1);
  vec1.x=1;
  vec1.y=2;
  printf("vecteur=(%d,%d)\n",vec1.x,vec1.y);
  return 0;
}

//Question:
//Pour compiler ce programme en ligne de commande et creer l'executable, il faut proceder en 3 étapes:
//$ gcc exemple_2.c -c
//$ gcc vecteur.c -c
//$ gcc exemple_2.o vecteur.o -o exemple_2
//Le processus peut etre fastidieux lorsqu'il y a de nombreux fichiers.
//
//L'appel a "make exemple_2" echoue: 
//L'erreur est la suivante:
//  exemple_2.c:(.text+0x10): undefined reference to `vecteur_init'
//  collect2: error: ld returned 1 exit status
//Elle demontre que l'edition de lien n'a pas ete realise avec le fichier compile issu de vecteur.c
//
//Tapez 
//$ make vecteur.o
//$ make exemple_2.o
//Notez que les fichiers objets sont bien créés. 
//Make est donc capable de creer les fichiers objets, mais ne peut pas trouver les dependances pour l'edition de liens tout seul.
//
//Creez desormais a l'aide d'un editeur de texte un fichier nomme: Makefile
//Dans ce fichier, ecrivez les lignes suivantes:
//exemple_2: vecteur.o exemple_2.o
//
//Cela indique que pour creer l'executable exemple_2, il faut prealablement avoir cree vecteur.o et exemple_2.o
//Tapez ensuite en ligne de commande "make" et observez que l'executable est maintenant cree.
//Note: La commande "make" sans arguments viens automatiquement chercher un fichier de configuration du nom de Makefile.
//
//Modifiez une ligne dans vecteur.c (par exemple un ajout de commentaire), sauvegardez, et relancez make en ligne de commande. Notez que le fichier vecteur.c est automatiquement recompile, et un nouvel executable est genere.
//L'outil make permet ainsi de ne compiler que les fichiers qui ont ete modifies.
//
//Modifiez une ligne dans vecteur.h, sauvegardez, et relancez make en ligne de commande. Notez que cette fois les fichiers ne sont pas recompiles. En effet, l'outil make ne peut pas savoir que vecteur.c depend de vecteur.h automatiquement. Pour cela, il faut lui indiquer les dependances explicitement dans le fichier Makefile.
//
//Ouvrez a nouveau le fichier Makefile et ajoutez la ligne suivante:
//vecteur.o: vecteur.c vecteur.h
//
//Modifiez a nouveau une ligne dans vecteur.h, sauvegardez, et relancez make. Notez que cette fois, la modification est prise en compte et que le projet est recompilee a nouveau.

