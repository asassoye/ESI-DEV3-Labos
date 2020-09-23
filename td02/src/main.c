/**
 * @file main.c
 * @author Andrew SASSOYE
 */
#define SIZE 15

#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"

int main() {
    printf("Coucou\n");
    int tableau[SIZE] = {1, 20, 3, 4, 30, 50, 4, 6, 85, 15, 32, 45, 1, 2, 5};
    arrayIntPrint(tableau, SIZE);

    printf("arrayIntSort DESC\n");
    arrayIntSort(tableau, SIZE, false);
    arrayIntPrint(tableau, SIZE);

    printf("arrayIntSort ASC\n");
    arrayIntSort(tableau, SIZE, true);
    arrayIntPrint(tableau, SIZE);

    printf("qsort DESC\n");
    qsort(tableau, SIZE, sizeof(int), comp_desc);
    arrayIntPrint(tableau, SIZE);

    printf("qsort ASC\n");
    qsort(tableau, SIZE, sizeof(int), comp_asc);
    arrayIntPrint(tableau, SIZE);

    printf("arrayIntSortGeneric DESC\n");
    arrayIntSortGeneric(tableau, SIZE, comp_desc);
    arrayIntPrint(tableau, SIZE);

    printf("arrayIntSortGeneric ASC\n");
    arrayIntSortGeneric(tableau, SIZE, comp_asc);
    arrayIntPrint(tableau, SIZE);

    return 0;
}
