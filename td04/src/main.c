/**
 * @file main.c
 * @author Andrew SASSOYE
 */

#include <stdio.h>
#include <stdlib.h>
#include "td04.h"

int main() {
    unsigned nbElem = 0;
    unsigned number = 84;
    unsigned* decomposition = primeFactorsA(&nbElem, number);

    printf("%d = {", number);
    for (int i = 0; i < nbElem; ++i) {
        if (i == nbElem - 1) {
            printf("%d", decomposition[i]);
        } else {
            printf("%d, ", decomposition[i]);
        }
    }
    printf("}\n");
    free(decomposition);

    unsigned* facteurs = NULL;
    unsigned* multiplicites = NULL;
    nbElem = primeFactorsB(&facteurs, &multiplicites, 84);

    printf("- nbElem contient la valeur %d;\n", nbElem);

    printf("- le contenu du tableau d'unsigned dont le premier élément est pointé par facteurs est : {");
    for (int i = 0; i < nbElem; ++i) {
        if (i == nbElem - 1) {
            printf("%d", facteurs[nbElem]);
        } else {
            printf("%d, ", facteurs[nbElem]);
        }
    }
    printf("}\n");

    printf("- le contenu du tableau d'unsigned dont l'adresse du premier élément est tockée dans le pointeur multiplicités est : {");
    for (int i = 0; i < nbElem; ++i) {
        if (i == nbElem - 1) {
            printf("%d", multiplicites[nbElem]);
        } else {
            printf("%d, ", multiplicites[nbElem]);
        }
    }
    printf("}\n");

    free(multiplicites);
    free(facteurs);
}
