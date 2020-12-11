#include <stdio.h>
#include <stdlib.h>
#include "primestat.h"
#include "statsample.h"
#include "../resources/td04.h"

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
    size_t length, count;
    unsigned *factors = NULL;
    unsigned *multiplicities = NULL;
    for (int i = lower; i <= higher; ++i) {
        length = primeFactorsB(&factors, &multiplicities, i);
        count = countPrimeFactors(multiplicities, length, true);
        update_stat((int) count, &s);

        free(factors);
        factors = NULL;
        free(multiplicities);
        multiplicities = NULL;
    }
    printf("la moyenne des nombres de facteurs premiers des nombre entre [%d, %d] est %f", lower, higher,
           sample_avg(s));

    free_stat(&s);
    return 0;
}

