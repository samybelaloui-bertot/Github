
//Definition de constantes sous forme de macro.
//Les macros sont generalement ecrites en majuscules:
#define VALEUR_1 3
#define VALEUR_2 VALEUR_1+2

int main()
{
  int a=VALEUR_1;
  int tableau[VALEUR_1];
  tableau[0]=1;
  tableau[1]=VALEUR_1+2;
  tableau[2]=VALEUR_2;

  return 0;
}

// Question: 
// que deviennent les valeurs des constantes VALEUR_1 et VALEUR_2 apres l'etape de preprocesseur ?


