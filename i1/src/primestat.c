#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "primestat.h"
#include "../resources/td04.h"

int extr_decomp(int lower, int higher, bool mult) {
    assert(lower <= higher);

    unsigned winner = 0;
    unsigned winner_count = 0;

    unsigned *factors = NULL;
    unsigned *multiplicities = NULL;
    size_t length, count;
    for (int i = lower; i <= higher; ++i) {
        length = primeFactorsB(&factors, &multiplicities, i);
        count = countPrimeFactors(multiplicities, length, mult);

        if (count > winner_count) {
            winner = i;
            winner_count = count;
        }

        free(factors);
        factors = NULL;
        free(multiplicities);
        multiplicities = NULL;
    }

    return (int) winner;
}

size_t countPrimeFactors(const unsigned *multiplicities, size_t length, bool mult) {
    assert(multiplicities != NULL);
    assert(length > 0);

    unsigned tmp = 0;
    if (mult) {
        for (int j = 0; j < length; ++j) {
            tmp = tmp + multiplicities[j];
        }
    } else {
        tmp = length;
    }

    return tmp;
}
