#include "utils.h"

int multiply2(int *result, int *a, int *b, int n);
grandEntier_s multiply(grandEntier_s a, grandEntier_s b);


// Multiply two large numbers using FFT
int multiply2(int *result, int *a, int *b, int n)
{
    int size = 1;
    while (size < 2 * n) size *= 2;

    complex double *fa = calloc(size, sizeof(complex double));
    complex double *fb = calloc(size, sizeof(complex double));

    for (int i = 0; i < n; i++) {
        fa[i] = a[i];
        fb[i] = b[i];
    }

    fft(fa, size, 0);
    fft(fb, size, 0);

    for (int i = 0; i < size; i++)
        fa[i] *= fb[i];

    fft(fa, size, 1);

    for (int i = 0; i < size; i++)
        result[i] = (int)round(creal(fa[i]));

    free(fa);
    free(fb);
 // Handle carry
    for (int i = 0; i < size - 1; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    int fs = size;
    while (fs > 1 && result[fs - 1] == 0)
        fs--;

    // Inversion de la portion significative pour mettre le chiffre le plus significatif en index 0
    for (int i = 0; i < fs / 2; i++) {
      int tmp = result[i];
      result[i] = result[fs - i - 1];
      result[fs - i - 1] = tmp;
    }
    return fs;
}

grandEntier_s multiply(grandEntier_s a, grandEntier_s b)
{
  int max_len = (a.len > b.len) ? a.len : b.len;
  unsigned int len2 = (max_len % 2)? (max_len + 1) / 2 : max_len / 2;
  if (a.len <= 1) {
    if (a.len == 0)
      return makeGrandEntier(0);
    if (a.digit[0] != '0') {
      if (b.len == 1 && b.digit[0] == '0') {
        return makeGrandEntier(0);
      }else {
        return makeGrandEntier((a.digit[0]-'0')  * (b.digit[0] -'0'));
      }
    }
    return makeGrandEntier(0);
  }
  if (b.len <= 1) {
    if (b.len == 0)
      return makeGrandEntier(0);
    if (b.digit[0] != '0') {
      if (a.len == 1 && a.digit[0] == '0') {
        return makeGrandEntier(0);
      }else {
        return makeGrandEntier(a.digit[0] * b.digit[0]);
      }
    }
    return makeGrandEntier(0);
  }  
    int half = len2; 

    grandEntier_s a1;
    a1.digit = a.digit;
    a1.len = half;
    grandEntier_s a0;
    a0.digit = a.digit + half;
    a0.len = a.len - half;

    grandEntier_s b1;
    b1.digit = b.digit;
    b1.len = half;
    grandEntier_s b0;
    b0.digit = b.digit + half;
    b0.len = b.len - half;


    grandEntier_s high = multiply(a0, b0);
    grandEntier_s low = multiply(a1, b1);
    grandEntier_s temp1 = add_entier(a0, a1);
    grandEntier_s temp2 = add_entier(b0, b1);
    
    grandEntier_s mid = multiply(temp1, temp2);

    grandEntier_s mid2 = subtract_entier(mid, high);
    grandEntier_s mid3 = subtract_entier(mid2, low);

    shiftLeft(&high, len2*2);
    shiftLeft(&mid3, len2);
    grandEntier_s res = add_entier(low, add_entier(high, mid3));

    free(high.digit);
    free(low.digit);
    free(mid.digit);
    free(mid2.digit);
    free(mid3.digit);
    free(temp1.digit);
    free(temp2.digit);
  return res;
}


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
