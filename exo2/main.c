#include "utils.h"

int multiply2(int *result, int *a, int *b, int n);
grandEntier_s multiply(grandEntier_s a, grandEntier_s b);

int main(int ac, char **av)
{
  if (ac < 3) {
    return 84;
  }
  char *a = strdup(av[1]);
  char *b = strdup(av[2]);
  int len = strlen(a);

  revStr(a, len); // put low digit to left
  revStr(b, len);
  int result[2 * len];
 
  int lenm = multiply2(result, to_nbr(a, len), to_nbr(b, len), len);
  for (int i = 0; lenm > i ; i++)
    printf("%d", result[i]);
  printf("\n");

  grandEntier_s v1;
  grandEntier_s v2;
  v1.len = strlen(av[1]);
  v2.len = strlen(av[2]);
  v1.digit = a;
  v2.digit = b;
  grandEntier_s res = multiply(v1, v2);  
  revStr(res.digit, res.len);
  for (int i = 0; i < res.len; i++)
    printf("%c", res.digit[i]);
  printf("\n");
  
  return 0;
}
