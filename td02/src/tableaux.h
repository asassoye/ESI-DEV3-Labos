/**
 * @file tableaux.h
 * @author Andrew SASSOYE
 */
#ifndef DEV3_TABLEAUX_H
#define DEV3_TABLEAUX_H

#include <stdbool.h>

/**
 * Print an array in console
 *
 * @param data array to display
 * @param nbElem [element1, element2, ...]
 */
void arrayIntPrint(const int data[], unsigned nbElem);

/**
 * Use bubble sort
 *
 * @param data array to sort
 * @param nbElem array size
 * @param ascending true sort asc, false sort desc
 */
void arrayIntSort(int data[], unsigned nbElem, bool ascending);

/**
 * Use bubble sort with given comparison
 * @param data array to sort
 * @param nbElem array size
 * @param comp compare function
 */
void arrayIntSortGeneric(int data[], unsigned nbElem, int (*comp)(const void *, const void *));

/**
 * ASC compare function
 *
 * @param a first element
 * @param b second element
 * @return positive number if a is greater than b
 * @return negative number if b is greater than a
 */
int comp_asc(const void *a, const void *b);

/**
 * DESC compare function
 *
 * @param a first element
 * @param b second element
 * @return negative number if a is greater than b
 * @return positive number if b is greater than a
 */
int comp_desc(const void *a, const void *b);

#endif //DEV3_TABLEAUX_H
