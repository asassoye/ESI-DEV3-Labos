/**
 * @file mathesi.h
 * @author Andrew SASSOYE
 */
#ifndef TD01_MATHESI_H
#define TD01_MATHESI_H

#include <stdbool.h>

/**
 * Verify if number is prime
 *
 * @param number Number to verify
 * @return true if number is prime
 * @return false if number is not prime
 */
bool isPrime(unsigned int number);

/**
 * Print a Prime table between two numbers
 *
 * @param min minimum of table
 * @param max maximum of table
 */
void printPrimeTable(int min, int max);

/**
 * Print a decomposition of a number in a product of prime numbers
 *
 * @param number Number to decompose
 * @param showPower show or not duplicate primes as power
 */
void printPrimeFactor(unsigned int number, bool showPower);

/**
 * Returns the prime after given number
 *
 * @param actualPrime start number
 * @return prime after actualPrime
 */
int nextPrime(int actualPrime);

/**
 * Returns greatest common divisor of two numbers
 *
 * @param a first number
 * @param b second number
 * @return gcd(a, b)
 */
unsigned gcd(unsigned a, unsigned b);

/**
 * Print greatest common divisor of two numbers
 *
 * @param a first number
 * @param b second number
 * @param newline new line after printing gcd
 */
void printGcd(unsigned a, unsigned b, bool newline);

#endif
