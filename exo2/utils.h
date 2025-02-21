#ifndef UTILS_H

#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265358979323846

////
// applique une transformé de fourrié a 'a'
void fft(complex double *a, int n, int invert);


// ---------------
typedef struct grandEntier
{
  char *digit;
  int len;
} grandEntier_s;

////
//
grandEntier_s add_entier(grandEntier_s tab1, grandEntier_s tab2);
////
//
grandEntier_s subtract_entier(grandEntier_s tab1, grandEntier_s tab2);

////
//
void shiftLeft(grandEntier_s *a, int shift);

////
//
grandEntier_s makeGrandEntier(int singleVal);


// utilisé pour l'ecriture
int *to_nbr(char *str, int len);
char *to_string(int *lst, int len);
void revStr(char *str, int len);
void myprintbit(char * str, int len);


 #endif