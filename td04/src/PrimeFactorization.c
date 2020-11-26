#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "PrimeFactor.h"
#include "PrimeFactorization.h"

PrimeFactorization *PrimeFactorization_new(unsigned int number) {
    PrimeFactorization *primeFactorization = malloc(sizeof(PrimeFactorization));

    if (primeFactorization == NULL) {
        return NULL;
    }

    primeFactorization->number = number;
    primeFactorization->count = 0;
    primeFactorization->primeFactors = malloc(number * sizeof(PrimeFactor));

    if (primeFactorization->primeFactors == NULL) {
        free(primeFactorization);
        return NULL;
    }

    return primeFactorization;
}

void PrimeFactorization_free(PrimeFactorization *primeFactorization) {
    if (primeFactorization != NULL) {
        if (primeFactorization->primeFactors != NULL) {
            free(primeFactorization->primeFactors);
            primeFactorization->primeFactors = NULL;
        }
        free(primeFactorization);
        primeFactorization = NULL;
    }
}

void PrimeFactorization_print(PrimeFactorization *primeFactorization) {
    assert(primeFactorization != NULL);
    assert(primeFactorization->primeFactors != NULL);

    printf("{%d, %d, ", primeFactorization->number, primeFactorization->count);
    for (int i = 0; i < primeFactorization->count; ++i) {
        primeFactor_print(&(primeFactorization->primeFactors)[i]);
    }

    printf("}");
}

void PrimeFactorization_addPrimeFactor(PrimeFactorization *primeFactorization, unsigned int value,
                                       unsigned int multiplicity) {
    assert(primeFactorization != NULL);
    assert(primeFactorization->primeFactors != NULL);
    assert(value > 1);
    assert(multiplicity != 0);

    primeFactorization->primeFactors[primeFactorization->count].value = value;
    primeFactorization->primeFactors[primeFactorization->count].multiplicity = multiplicity;
    (primeFactorization->count)++;
}

void PrimeFactorization_resizePrimeFactorsArray(PrimeFactorization *primeFactorization) {
    assert(primeFactorization != NULL);
    assert(primeFactorization->primeFactors != NULL);

    primeFactorization->primeFactors = realloc(primeFactorization->primeFactors,
                                               primeFactorization->count * sizeof(PrimeFactor));
}

