#include "utils.h"

char *to_string(int *lst, int len)
{
  char *str = malloc(sizeof(char) * len);

  for (int i = 0; i < len; i++) {
    str[i] = lst[i] + '0';
  }
  return str;
}

int *to_nbr(char *str, int len)
{
  int *lst = malloc(sizeof(int) * len);

  for (int i = 0; i < len; i++) {
    lst[i] = str[i] - '0';
  }
  return lst;
}

// utilse grand o(n)
void revStr(char *str, int len) {
  for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void myprintbit(char * str, int len)
{
  for (int i = 0; i < len; i++)
    {
      printf("%c", (str[i]));
    }
  printf("\n");
}
//---------------------------------------------------

// poid faible a gauche index 0
// return nb bit in the array
grandEntier_s add_entier(grandEntier_s tab1, grandEntier_s tab2) {
  int max_len = (tab1.len > tab2.len) ? tab1.len : tab2.len;
  int carry = 0;

  grandEntier_s result;
  result.digit = malloc(sizeof(char) * (max_len + 1)); // +2 for possible carry and null terminator
  result.len = max_len;
    
  for (int i = 0; max_len > i; i++) {
      int bit1 = (i < tab1.len) ? tab1.digit[i] - '0' : 0;
      int bit2 = (i < tab2.len) ? tab2.digit[i] - '0' : 0;
      
      int sum = bit1 + bit2 + carry;
      result.digit[i] = (sum % 10) + '0';
      carry = sum / 10;
    }
  if (carry != 0) {
    result.digit[max_len] = carry + '0';
    result.len++;
  }
  return result;
}

grandEntier_s subtract_entier(grandEntier_s tab1, grandEntier_s tab2)
{
  int max_len = (tab1.len > tab2.len) ? tab1.len : tab2.len;

  grandEntier_s result;
  result.digit = malloc(sizeof(char) * (max_len)); // +2 for possible carry and null terminator
  result.len = max_len;

  int borrow = 0;

  for (int i = 0; max_len > i; i++) {
      int bit1 = (i < tab1.len) ? tab1.digit[i] - '0' : 0;
      int bit2 = (i < tab2.len) ? tab2.digit[i] - '0' : 0;

      int sub = bit1 - bit2 - borrow;
      if (sub < 0) {
          sub += 10;
          borrow = 1;
      } else {
          borrow = 0;
      }        
      result.digit[i] = sub + '0';
  }
  return result;
}

void shiftLeft(grandEntier_s *a, int shift)
{  
  a->digit = realloc(a->digit, sizeof(char) * (a->len + shift ));
  for (int i = a->len - 1; i >= 0; i--) {
    a->digit[i + shift] = a->digit[i];
    a->digit[i] = '0';
  }
  for (int i = 0; i < shift; i++)
  {
    a->digit[i] = '0';
  }
  a->len += shift;
}

grandEntier_s makeGrandEntier(int singleVal)
{
  grandEntier_s ret;
 
  if (singleVal > 9) {
    ret.digit = malloc(sizeof(char) * 2);
    ret.digit[0] = singleVal % 10 + '0';
    ret.len = 2;
    ret.digit[1] = singleVal / 10 + '0';
  } else {
    ret.digit = malloc(sizeof(char) );
    ret.digit[0] = singleVal % 10 + '0';
    ret.len = 1;
  }
  return ret;
}


// Fast Fourier Transform
void fft(complex double *a, int n, int invert)
{
  if (n == 1) return;

  complex double *a0 = malloc(n / 2 * sizeof(complex double));
  complex double *a1 = malloc(n / 2 * sizeof(complex double));

  for (int i = 0; 2 * i < n; i++) {
      a0[i] = a[i * 2];
      a1[i] = a[i * 2 + 1];
  }

  fft(a0, n / 2, invert);
  fft(a1, n / 2, invert);

  for (int i = 0; 2 * i < n; i++) {
      complex double w = cexp((invert ? -1 : 1) * 2.0 * I * PI * i / n);
      a[i] = a0[i] + w * a1[i];
      a[i + n / 2] = a0[i] - w * a1[i];

      if (invert) {
          a[i] /= 2;
          a[i + n / 2] /= 2;
      }
  }

  free(a0);
  free(a1);
}