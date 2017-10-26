
//declaration de macro en tant que fonction de 'x'
#define FONCTION_1(x) x*x
#define FONCTION_2(x) ((x)*(x))

int main()
{

  int a=3;
  int b=FONCTION_1(a);
  int c=FONCTION_2(a);
  int d=FONCTION_1(a+1);
  int e=FONCTION_2(a+1);

  return 0;
}

// Question:
// Les macros peuvent definir des fonctions. Observez le resultat de FONCTION_1 et FONCTION_2 apres l'etape de preprocesseur?
// Pourquoi l'utilisation des parentheses est conseillee lors de l'utilisation de telles macros?
