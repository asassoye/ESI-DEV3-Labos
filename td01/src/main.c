/**
 * @file main.c
 * @author Andrew SASSOYE
 */
#include <stdio.h>
#include <limits.h>
#include "../resources/mathesi.h"

int main() {
    printPrimeTable(200, 350);
    printPrimeFactor(126, false);
    printPrimeFactor(126, true);

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j > 0) {
                printf(" | ");
            }
            printGcd(423 + (3 * i), 135 - (5 * j), false);
        }
        printf("\n");
    }
}
