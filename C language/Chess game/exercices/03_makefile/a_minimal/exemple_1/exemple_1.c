#include <stdio.h>

int main()
{
  
  int a=1;
  puts("Bonjour");

  return 0;
}

//Question:
// Tapez en ligne de commande: make exemple_1
// Quel fichier est créé ?
// make est un outil qui permet de simplifier certaines tâches fastidieuses, ici en inferant la ligne de compilation.

// Explication: En tapant make exemple_1, make detecte la volonte de creer le fichier exemple_1 et recherche une source sous le nom de exemple_1.c
// Une fois cette source detectee, il appelle la commande 
// $ cc exemple_1.c -o exemple_1
// Notez que le programme "cc" est en fait le nom specifique du compilateur C de gcc (gcc etant un nom generique couvrant differents programmes)
