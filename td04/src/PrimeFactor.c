#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "PrimeFactor.h"

PrimeFactor *primeFactor_new(unsigned int value, unsigned int multiplicity) {
    PrimeFactor *primeFactor = malloc(sizeof(PrimeFactor));

    if (primeFactor == NULL) {
        return NULL;
    }

    primeFactor->value = value;
    primeFactor->multiplicity = multiplicity;

    return primeFactor;
}

void primeFactor_free(PrimeFactor *primeFactor) {
    if (primeFactor != NULL) {
        free(primeFactor);
        primeFactor = NULL;
    }
}

void primeFactor_print(PrimeFactor *primeFactor) {
    assert(primeFactor != NULL);

    printf("{%d, %d}", primeFactor->value, primeFactor->multiplicity);
}

unsigned primeFactor_getValue(PrimeFactor *primeFactor) {
    assert(primeFactor != NULL);

    return primeFactor->value;
}

void primeFactor_setValue(PrimeFactor *primeFactor, unsigned int value) {
    assert(primeFactor != NULL);
    assert(value != 1);

    primeFactor->value = value;
}

unsigned primeFactor_getMultiplicity(PrimeFactor *primeFactor) {
    assert(primeFactor != NULL);

    return primeFactor->multiplicity;
}

void primeFactor_setMultiplicity(PrimeFactor *primeFactor, unsigned int multiplicity) {
    assert(primeFactor != NULL);
    assert(multiplicity != 0);

    primeFactor->multiplicity = multiplicity;
}
