#include <stdio.h>
#include "primestat.h"

int main() {
    puts("\t===QUESTION 4===");
    int n1 = extr_decomp(5000, 20000, true);
    printf("extr_decomp(5000, 20000, true) = %d\n", n1);
    int n2 = extr_decomp(5000, 20000, false);
    printf("extr_decomp(5000, 20000, false) = %d\n", n2);

    return 0;
}

