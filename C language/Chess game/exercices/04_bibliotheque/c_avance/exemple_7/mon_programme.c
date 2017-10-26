#include <est_premier.h>

#include <stdio.h>

int main()
{
  int a=est_premier(8);
  int b=est_premier(11);
  int c=est_premier(14574523);

  printf("a/%d\n",a);
  printf("b/%d\n",b);
  printf("c/%d\n",c);

  return 0;
}
