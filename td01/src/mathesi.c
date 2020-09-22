/**
 * @file mathesi.c
 * @author Andrew SASSOYE
 */
#include <stdio.h>
#include <math.h>
#include "mathesi.h"

bool isPrime(unsigned int number) {
    int max = (int) sqrt(number);

    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= max; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimeFactor(unsigned int number, bool showPower) {
    printf("%d = ", number);
    int prime = 2;
    int power = 0;
    bool first = true;
    while(number != 1) {
        while (number % prime == 0) {
            number /= prime;
            ++power;
        }

        if (power > 0) {
            if(!first) {
                printf("x ");
            }

            if (showPower) {
                if (power == 1) {
                    printf("%d ", prime);
                } else {
                    printf("%d^%d ", prime, power);
                }

            } else {
                for (int i = 0; i < power; ++i) {
                    if (i > 0) {
                        printf("x ");
                    }
                    printf("%d ", prime);
                }
            }
            power = 0;
            first = false;
        }

        prime = nextPrime(prime);
    }
    printf("\n");
}

void printPrimeTable(int min, int max) {
    int count;
    count = 1;

    for (int i = min; i < max; ++i, ++count) {
        if (isPrime(i)) {
            printf("%3d ", i);
        } else {
            printf("%3s ", ".");
        }

        if (count % 10 == 0) {
            printf("\n");
        }
    }
}

int nextPrime(int actualPrime) {
    int nextPrime = actualPrime + 1;
    while (!isPrime(nextPrime)) {
        nextPrime++;
    }

    return nextPrime;
}

unsigned gcd(unsigned a, unsigned b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

void printGcd(unsigned a, unsigned b, bool newline) {
    printf("gcd(%d, %d) = %d", a, b, gcd(a, b));
    if (newline) {
        printf("\n");
    }
}
