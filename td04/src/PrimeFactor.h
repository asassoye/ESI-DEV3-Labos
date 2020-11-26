/**
 * @file PrimeFactor.h
 * @author Andrew SASSOYE
 */

#ifndef DEV3_PRIMEFACTOR_H
#define DEV3_PRIMEFACTOR_H

typedef struct PrimeFactor {
    unsigned value;
    unsigned multiplicity;
} PrimeFactor;

PrimeFactor *primeFactor_new(unsigned value, unsigned multiplicity);

void primeFactor_free(PrimeFactor *primeFactor);

void primeFactor_print(PrimeFactor *primeFactor);

unsigned primeFactor_getValue(PrimeFactor *primeFactor);

void primeFactor_setValue(PrimeFactor *primeFactor, unsigned value);

unsigned primeFactor_getMultiplicity(PrimeFactor *primeFactor);

void primeFactor_setMultiplicity(PrimeFactor *primeFactor, unsigned multiplicity);

#endif //DEV3_PRIMEFACTOR_H
