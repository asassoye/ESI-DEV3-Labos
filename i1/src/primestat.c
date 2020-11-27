#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "primestat.h"
#include "../../td04/src/td04.h"

int extr_decomp(int lower, int higher, bool mult) {
    assert(lower <= higher);

    unsigned winner = 0;
    unsigned winner_nb = 0;

    unsigned *facteurs = NULL;
    unsigned *multiplicities = NULL;
    unsigned taille;
    unsigned calc = 0;
    for (int i = lower; i <= higher; ++i) {
        taille = primeFactorsB(&facteurs, &multiplicities, i);
        if (mult) {
            for (int j = 0; j < taille; ++j) {
                calc = calc + multiplicities[j];
            }
        } else {
            calc = taille;
        }

        if (calc > winner_nb) {
            winner = i;
            winner_nb = calc;
        }

        calc = 0;
        free(facteurs);
        facteurs = NULL;
        free(multiplicities);
        multiplicities = NULL;
    }

    return (int) winner;
}
