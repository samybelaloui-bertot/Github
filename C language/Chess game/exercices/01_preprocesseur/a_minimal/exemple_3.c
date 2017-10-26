
#define VERSION_1

#ifdef VERSION_1
 #define VALEUR 1
#else
 #define VALEUR 2
#endif

int main()
{
  int a=VALEUR;
}

// Que vaut a?
// Que vaut a, si on commente la premiere ligne (#define VERSION_1) ?
