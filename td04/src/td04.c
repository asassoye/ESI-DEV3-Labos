/**
 * @file td04.c
 * @author Andrew SASSOYE
 */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "td04.h"
#include "../../td01/src/mathesi.h"

unsigned *primeFactorsA(unsigned *count, unsigned number) {
    assert(*count == 0);

    unsigned *decomposition = malloc(sizeof(unsigned) * number);

    if (decomposition == NULL) {
        return NULL;
    }

    int prime = 2;
    int power = 0;
    while (number != 1) {
        while (number % prime == 0) {
            number /= prime;
            ++power;
        }

        if (power > 0) {
            for (int i = 0; i < power; ++i) {
                decomposition[*count] = prime;
                (*count)++;
            }
            power = 0;
        }

        prime = nextPrime(prime);
    }

    return realloc(decomposition, (*count) * sizeof(unsigned));
}

unsigned primeFactorsB(unsigned **factor, unsigned **multiplicity, unsigned number) {
    assert(*factor == NULL);
    assert(*multiplicity == NULL);

    *factor = malloc(sizeof(unsigned) * number);
    if (*factor == NULL) {
        return 0;
    }

   *multiplicity = malloc(sizeof(unsigned) * number);
    if (*multiplicity == NULL) {
        free(*factor);
        *factor = NULL;

        return 0;
    }

    unsigned count = 0;
    int prime = 2;
    int power = 0;
    while (number != 1) {
        while (number % prime == 0) {
            number /= prime;
            ++power;
        }

        if (power > 0) {
            (*factor)[count] = prime;
            (*multiplicity)[count] = power;
            count++;
            power = 0;
        }
        prime = nextPrime(prime);
    }

    *factor = realloc(*factor, count * sizeof(unsigned));
    *multiplicity = realloc(*multiplicity, count * sizeof(unsigned));

    return count;
}

