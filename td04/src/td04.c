/**
 * @file td04.c
 * @author Andrew SASSOYE
 */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "td04.h"
#include "../../td01/src/mathesi.h"

unsigned* primeFactorsA(unsigned* count, unsigned number) {
    assert(*count == 0);

    unsigned* decomposition = malloc(sizeof(unsigned ) * number);

    if (decomposition == NULL) {
        return NULL;
    }

    int prime = 2;
    int power = 0;
    while(number != 1) {
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

unsigned primeFactorsB(unsigned** factor, unsigned** multiplicity, unsigned number) {
    assert(*factor == NULL);
    assert(*multiplicity == NULL);

    unsigned* factors = malloc(sizeof(unsigned) * number);
    if (factors == NULL) {
        return 0;
    }

    unsigned* multiplicities = malloc(sizeof(unsigned) * number);
    if (multiplicities == NULL) {
        free(factors);
        factors = NULL;

        return 0;
    }

    unsigned count = 0;
    int prime = 2;
    int power = 0;
    while(number != 1) {
        while (number % prime == 0) {
            number /= prime;
            ++power;
        }

        if (power > 0) {
            factors[count] = prime;
            multiplicities[count] = power;
            count++;
        }
        prime = nextPrime(prime);
    }

    for (int i = 0; i < count; ++i) {
        printf("%d x %d + ", factors[i], multiplicities[i]);
    }
    printf("\n");

    factors = realloc(factors, count * sizeof(unsigned));
    multiplicities = realloc(multiplicities, count * sizeof(unsigned));

    *factor = factors;
    *multiplicity = multiplicities;

    return count;
}

