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
            printf("%d", facteurs[i]);
        } else {
            printf("%d, ", facteurs[i]);
        }
    }
    printf("}\n");

    printf("- le contenu du tableau d'unsigned dont l'adresse du premier élément est tockée dans le pointeur multiplicités est : {");
    for (int i = 0; i < nbElem; ++i) {
        if (i == nbElem - 1) {
            printf("%d", multiplicites[i]);
        } else {
            printf("%d, ", multiplicites[i]);
        }
    }
    printf("}\n");

    free(multiplicites);
    free(facteurs);

    printf("\n\tEXERCICE 4.3\n");

    nbElem = 0;
    PrimeFactor* decompositionC = primeFactorsC(&nbElem, 84);

    printf("- nbElem contient la valeur %d\n", nbElem);
    printf("- Le contenu du tableau de PrimeFactor est: {");
    for (int i = 0; i < nbElem; ++i) {
        primeFactor_print(&(decompositionC[i]));
        if (i != nbElem - 1) {
            printf(" ");
        }
    }
    printf("}\n");

    printf("\n\tEXERCICE 4.4\n");
    PrimeFactorization* f = PrimeFactorization_new(84);
    primeFactorD(f);

    PrimeFactorization_print(f);
    PrimeFactorization_free(f);
}
