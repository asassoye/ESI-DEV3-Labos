#include <stdio.h>
#include <stdlib.h>
#include "primestat.h"
#include "statsample.h"
#include "../../td04/src/td04.h"

int main() {
    puts("\t===QUESTION 4===");
    int n1 = extr_decomp(5000, 20000, true);
    printf("extr_decomp(5000, 20000, true) = %d\n", n1);
    int n2 = extr_decomp(5000, 20000, false);
    printf("extr_decomp(5000, 20000, false) = %d\n", n2);

    puts("\n\t===QUESTION 10===");
    int lower = 4000;
    int higher = 20000;
    StatSample s;
    init_stat(&s);
    unsigned taille;
    unsigned *facteurs = NULL;
    unsigned *multiplicities = NULL;
    unsigned calc = 0;
    for (int i = lower; i <= higher; ++i) {
        taille = primeFactorsB(&facteurs, &multiplicities, i);
        for (int j = 0; j < taille; ++j) {
            calc = calc + multiplicities[j];
        }

        update_stat(calc, &s);

        calc = 0;
        free(facteurs);
        facteurs = NULL;
        free(multiplicities);
        multiplicities = NULL;
    }
    printf("la moyenne des nombres de facteurs premiers des nombre entre [%d, %d] est %f", lower, higher,
           sample_avg(s));

    return 0;
}

