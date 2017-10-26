
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Bonjour CPE\n");
  return 0;
}

// Compilez ce programme de ces différentes manieres:
//
// 1. Methode directe
// Tapez en ligne de commande:
// $ gcc exemple_0.c
// Quel fichier a ete genere? Est-ce un fichier executable?
// Ouvrez ce fichier avec un editeur de texte (il peut y avoir un warning car le fichier contient du binaire), retrouver la chaine "Bonjour CPE"
// Il est possible d'observer le code hexadecimale avec la commande suivante:
// $ hexdump -C <FICHIER>
// ou
// $ od <FICHIER>
//
// Supprimez le fichier precedent:
// $ rm a.out
//
// 2. Methode directe avec sortie imposee
// Tapez:
// $ gcc exemple_0.c -o mon_executable
// Observez quel fichier a ete genere.
// Il s'agit toujours du meme fichier executable, mais cette fois son nom a ete impose.
// Supprimez le fichier precedent:
// $ rm mon_executable
// Tapez:
// $ gcc -o mon_executable exemple_0.c
// Qu'observez-vous, est-ce que l'ordre des arguments est important?
//
//
// Supprimez le fichier precedent:
// $ rm mon_executable
//
// 3. Methode en deux etapes
// Tapez 
// $ gcc -c exemple_0.c
// Observez quel fichier a ete genere.
// S'agit-il d'un fichier executable?
// Observez le contenu du fichier a l'aide d'un editeur de texte, ou en visualisant le contenu hexadecimale.
// Que pouvez-vous dire sur la taille du fichier .o par rapport a la taille du fichier executable genere precedemment? Expliquez pourquoi.
// Supprimez le fichier precedent:
// $ rm exemple_0.o
// Tapez la commande suivante:
// $ gcc exemple_0.c -c
// Est-ce que la place du "-c" est importante?
//
// Tapez ensuite:
// $ gcc exemple_0.o
// Quel fichier est genere? Cette fois, il s'agit du fichier executable.
// L'appel a gcc sur le fichier .o a permis l'appel a l'edition des liens et a la generation du fichier executable.
//
// Supprimez les fichiers precedents:
// $ rm exemple_0.o a.out
//
// 4. Methode en deux etapes avec noms imposes:
// Tapez:
// $ gcc -c exemple_0.c -o mon_fichier_objet.o
// Quel fichier est genere? 
// $ gcc mon_fichier_objet.o -o mon_fichier_executable
// Quel fichier est genere?
// Aurait-on obtenu un resultat different si on avait tape les lignes suivantes?
// $ gcc -o mon_fichier_objet.o exemple_0.c -c
// $ gcc -o mon_fichier_executable mon_fichier_objet.o
//
