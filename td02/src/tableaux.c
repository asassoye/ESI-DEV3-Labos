/**
 * @file tableaux.c
 * @author Andrew SASSOYE
 */
#include <assert.h>
#include <stdio.h>
#include "tableaux.h"

void arrayIntPrint(const int data[], unsigned nbElem) {
    assert(data != NULL);

    printf("[");
    for (int i = 0; i < nbElem; ++i) {
        if (i == nbElem - 1) {
            printf("%d", data[i]);
        } else {
            printf("%d, ", data[i]);
        }
    }
    printf("]\n");
}

void arrayIntSort(int data[], unsigned nbElem, bool ascending) {
    int c;
    for (int j = 1; j <= nbElem; j++)
        for (int i = 0; i < nbElem - 1; i++)
            if (ascending ? data[i] > data[i + 1] : data[i] < data[i + 1]) {
                c = data[i];
                data[i] = data[i + 1];
                data[i + 1] = c;
            }
}

void arrayIntSortGeneric(int data[], unsigned nbElem, int (*comp)(const void *, const void *)) {
    int c;
    for (int j = 1; j <= nbElem; j++)
        for (int i = 0; i < nbElem - 1; i++)
            if (comp(&data[i], &data[i + 1]) > 0) {
                c = data[i];
                data[i] = data[i + 1];
                data[i + 1] = c;
            }
}

int comp_asc(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int comp_desc(const void *a, const void *b) {
    return (*(int *) b - *(int *) a);
}
