#include <stdio.h>

int main()
{
  float y=2.0;
  float x0=1.0;
  float x1=1.0;

  int a=0;
  if(x0+x1==y)
    {
      a=1;
    }

  printf("%d\n",a);

  int k=0;
  for(k=0;k<10;++k)
    {
      int a=k;
    }
  printf("%d\n",a);
  return 0;
}

//Question:
//Compilez ce programme avec la lignes suivantes:
//$ gcc exemple_1.c -o exemple_1
//Lancez le, est-ce le resultat attendu? 
//  * A t-on bien 1+1=2
//  * A quoi sert la seconde boucle?
//  * Quel "a" est affiche par le dernier printf ?
//Observez les lignes de compilation dans le fichier pour_compiler.sh
//Assurez vous que le fichier "pour_compiler.sh" soit executable avec la commande: chmod +x pour_compiler.sh
//Lancez ce fichier. Observez les nouveaux Warnings obtenus.
//Lisez attentivement chaque Warning et retrouvez a quels problemes ils referent.
//Concluez sur l'aide qu'apporte ces Warnings pour aider le developpeur lors de l'ecriture de son code.
