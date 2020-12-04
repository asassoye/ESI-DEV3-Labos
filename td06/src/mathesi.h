#ifndef DEV3_MATHESI_H
#define DEV3_MATHESI_H

#include <vector>

bool isPrime(unsigned number);

unsigned nextPrime(unsigned actualPrime);

std::vector<unsigned> primeList(unsigned min, unsigned max);

std::pair<int, int> euclideanDivision(int dividend, int divisor);

#endif //DEV3_MATHESI_H
