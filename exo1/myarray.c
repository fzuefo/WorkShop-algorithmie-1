#include "myarray.h"
#include <string.h>

intArray_t *create(int maxLen)
{
  intArray_t *new = malloc(sizeof(intArray_t));

  new->tab = malloc(sizeof(int) * maxLen);
  new->maxLen = maxLen;
  new->len = 0;
  return new;
}

int *at(intArray_t *array, int index)
{
  if (0 > index || index >= array->len) {
    printf("Error: Get out of memory\n");
    exit(84);
  }
  return array->tab + index;
}

bool isEqual(intArray_t *fst, intArray_t *snd)
{
  if (fst->len != snd->len)
    return false;
  for (int i = 0; i < fst->len; i++) {
    if (fst->tab[i] != snd->tab[i])
      return false;
  }
  return true;
}

void appendElement(intArray_t *array, int nbr)
{
  if (array->len >= array->maxLen) {
    printf("Error: Tentative d'ajout dans un array plein\n");
    exit(84);
  }
  array->tab[array->len] = nbr;
  array->len++;
}

void removeElement(intArray_t *array, int index)
{
  if (0 > index || index >= array->len) {
    printf("Error: Index Out of range\n");
    exit(84);
  }
  for (int i = index + 1; i < array->len; i++) {
    array->tab[i - 1] = array->tab[i];
  }
  array->len--;
}


void removeElements(intArray_t *array, intArray_t *indexArray)
{
  for (int i = 0; i < indexArray->len; i++) {
    if (0 > indexArray->tab[i] || indexArray->tab[i] >= array->len) {
      printf("Error: Index n°%d Out of range\n", i);
    }
  }
  /// Code to implemente

  // here

  ///
}

