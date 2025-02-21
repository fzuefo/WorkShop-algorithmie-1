#include "myarray.h"
#include <assert.h>
#include <string.h>

void myAssert(intArray_t *array, intArray_t *expected, const char *msg)
{
  bool test = isEqual(array, expected);
  if (test == false) {
    
    printf("Test: %s\ngot:",msg);
    for (int i = 0; array->len > i; i++) {
      printf("%d", array->tab[i]);
    }
    printf(" | expected: ");
    for (int i = 0; expected->len > i; i++) {
      printf("%d", expected->tab[i]);
    }
    printf("\n");
    assert(test);
  }
}

void testIntegrite()
{
  intArray_t *tab1 = create(11);
  intArray_t *tab2 = create(11);

  for (int i = 0; i != 9; i++) {
    tab1->tab[i] = i;
    tab2->tab[i] = i;
    tab1->len++;
    tab2->len++;
  }
  tab2->tab[9] = 4;
  tab2->len++;
// -----
  appendElement(tab1, 21);
  appendElement(tab2, 21);
// -----
  assert(*at(tab1, 4) == 4);
// -----
  assert(!isEqual(tab1, tab2));  
  removeElement(tab2, 9);
  assert(isEqual(tab1, tab2));  
  assert(tab1->tab == at(tab1, 0));
  printf("Test SUCCES\n");
}

void resetValue(intArray_t *tab, int nb)
{
  tab->len = 0;
  for (int i = 0; i != nb; i++) {
    tab->tab[i] = i;
    tab->len++;
  }
}

intArray_t *makeTest(intArray_t *array, const char *st, int nb)
{
  char buffer[100];
  strcpy(buffer, st);
  char *token = strtok(buffer, ",");

  for (int i = 0; i != nb; i++){
    array->tab[i] = atoi(token);
    token = strtok(NULL, ",");

  }
  array->len = nb;
}

void simpleTest()
{
  intArray_t *tab1 = create(10);
  intArray_t *index = create(10);
  intArray_t *temoin = create(10);
  
  printf("Simple Test\n");
  // ---- Temoin
  resetValue(tab1, 5);
  resetValue(index, 0);
  myAssert(tab1, makeTest(temoin, "0,1,2,3,4", 5), "temoin");
  //------debut
  resetValue(tab1, 5);
  resetValue(index, 0);
  appendElement(index, 0);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "1,2,3,4", 4), "start");
  //------midel
  resetValue(tab1, 10);
  resetValue(index, 0);
  appendElement(index, 5);
  
  removeElements(tab1, index);  
  myAssert(tab1, makeTest(temoin, "0,1,2,3,4,6,7,8,9", 9), "between");
  //------fin
  resetValue(tab1, 5);
  resetValue(index, 0);
  appendElement(index, 4);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "0,1,2,3", 4), "end");
  //------2 suite
  resetValue(tab1, 10);
  resetValue(index, 0);
  appendElement(index, 2);
  appendElement(index, 3);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "0,1,4,5,6,7,8,9", 8), "2 suite");
  //------ nothing
  resetValue(tab1, 1);
  resetValue(index, 0);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "0", 1), "nothing");
  // --- all
  resetValue(tab1, 1);
  resetValue(index, 1);

  removeElements(tab1, index);
  assert(tab1->len == 0);
  myAssert(tab1, makeTest(temoin, "", 0), "all");
  printf("Test SUCCES\n");
}

void mediumTest()
{
  intArray_t *tab1 = create(10);
  intArray_t *index = create(10);
  intArray_t *temoin = create(10);
  
  printf("Medium Test\n");
  // ---- Temoin
  resetValue(tab1, 5);
  resetValue(index, 0);
  myAssert(tab1, makeTest(temoin, "0,1,2,3,4", 5), "Temoin2");
  //------debut & fin
  resetValue(tab1, 5);
  resetValue(index, 0);
  appendElement(index, 0);
  appendElement(index, 4);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "1,2,3", 3), "start & end");
  //------midel & fin
  resetValue(tab1, 10);
  resetValue(index, 0);
  appendElement(index, 5);
  appendElement(index, 9);
  
  removeElements(tab1, index);  
  myAssert(tab1, makeTest(temoin, "0,1,2,3,4,6,7,8", 8), "between & end");
  //------fin & debut
  resetValue(tab1, 5);
  resetValue(index, 0);
  appendElement(index, 4);
  appendElement(index, 0);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "1,2,3", 3), "end & start");
  //------4 element
  resetValue(tab1, 10);
  resetValue(index, 0);
  appendElement(index, 2);
  appendElement(index, 3);
  appendElement(index, 7);
  appendElement(index, 8);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "0,1,4,5,6,9", 6), "4 elem");
  //------ fin desordre
  resetValue(tab1, 10);
  resetValue(index, 0);
  appendElement(index, 9);
  appendElement(index, 8);
  appendElement(index, 6);
  appendElement(index, 7);

  removeElements(tab1, index);
  myAssert(tab1, makeTest(temoin, "0,1,2,3,4,5", 6), "desorder");
  // --- all mediuù
   resetValue(tab1, 10);
  resetValue(index, 0);
  appendElement(index, 0);
  appendElement(index, 1);
  appendElement(index, 2);
  appendElement(index, 4);
  appendElement(index, 3);
  appendElement(index, 5);
  appendElement(index, 6);
  appendElement(index, 7);
  appendElement(index, 8);
  appendElement(index, 9);

  removeElements(tab1, index);
  assert(tab1->len == 0);
  myAssert(tab1, makeTest(temoin, "", 0), "all2");
  printf("Test SUCCES\n");
}


int main()
{
  printf("Test Integrité\n");
  testIntegrite();
  simpleTest();
  mediumTest();
  printf("All Test Complete\n");
  return 0;
}
