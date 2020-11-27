#include <stdio.h>
#include "primestat.h"

int main() {
    puts("Hello world!");

    printf("gagnant entre %d et %d est %d\n", 7, 10, extr_decomp(7, 10, true));
    printf("gagnant entre %d et %d est %d\n", 7, 10, extr_decomp(7, 10, false));

    return 0;
}

