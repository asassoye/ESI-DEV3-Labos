/**
 * @file td04.h
 * @author Andrew SASSOYE
 */
#ifndef DEV3_TD04_H
#define DEV3_TD04_H

#include "PrimeFactor.h"
#include "PrimeFactorization.h"

unsigned *primeFactorsA(unsigned *count, unsigned number);

unsigned primeFactorsB(unsigned **factor, unsigned **multiplicity, unsigned number);

PrimeFactor *primeFactorsC(unsigned *count, unsigned number);

void primeFactorD(PrimeFactorization *primeFactorization);

#endif //DEV3_TD04_H
