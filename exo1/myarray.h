#ifndef ARRAY_H_

#define ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct intArray_s
{
  int len;
  int maxLen;
  int *tab;
}intArray_t;
  
intArray_t *create(int maxLen);

int *at(intArray_t *array, int index);

bool isEqual(intArray_t *fst, intArray_t *snd);

// Ajoute un element a la fin de l'array
//
// Complexité:
// Grand_O(1)
void appendElement(intArray_t *array, int nbr);


// Retire un element a l'index de l'array
//
// Complexité:
//  Grand_O( ??? )
void removeElement(intArray_t *array, int index);


// Retire les elements aux index de indexArray dans array 
//
// Objectif:
//  Realiser la fonction removeElements tel que:
//  Grand_O(removeElements) < Grand_O(n^2)
//
// Note:
//  La complexité theorique est Grand_O(n)
void removeElements(intArray_t *array, intArray_t *indexArray);


#endif
