/**
 * @author Andrew SASSOYE
 */
#ifndef DEV3_PRIMEFACTORIZATION_H
#define DEV3_PRIMEFACTORIZATION_H

#include "PrimeFactor.h"

typedef struct PrimeFactorization {
    unsigned number;
    unsigned count;
    PrimeFactor* primeFactors;
} PrimeFactorization;

PrimeFactorization* PrimeFactorization_new(unsigned number);

void PrimeFactorization_free(PrimeFactorization* primeFactorization);

void PrimeFactorization_print(PrimeFactorization* primeFactorization);

void PrimeFactorization_addPrimeFactor(PrimeFactorization* primeFactorization, unsigned value, unsigned multiplicity);

void PrimeFactorization_resizePrimeFactorsArray(PrimeFactorization* primeFactorization);

#endif //DEV3_PRIMEFACTORIZATION_H
