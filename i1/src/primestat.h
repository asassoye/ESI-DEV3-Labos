#ifndef DEV3_PRIMESTAT_H
#define DEV3_PRIMESTAT_H

#include <stdbool.h>

int extr_decomp(int lower, int higher, bool mult);

size_t countPrimeFactors(const unsigned *multiplicities, size_t length, bool mult);

#endif //DEV3_PRIMESTAT_H
