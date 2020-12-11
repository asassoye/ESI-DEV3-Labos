#include <cmath>
#include <stdexcept>
#include "mathesi.h"

bool isPrime(unsigned number) {
    int max = (int) sqrt(number);

    if (number <= 1) {
        return false;
    }

    if (number != 2 && number % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= max; ++(++i)) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

unsigned nextPrime(unsigned actualPrime) {
    unsigned nextPrime = actualPrime + 1;
    while (!isPrime(nextPrime)) {
        nextPrime++;
    }

    return nextPrime;
}

std::vector<unsigned> primeList(unsigned min, unsigned max) {
    std::vector<unsigned> list;

    for (unsigned i = min; i < max; ++i) {
        if (isPrime(i)) {
            list.push_back(i);
        }
    }

    list.shrink_to_fit();
    return list;
}

std::pair<int, int> euclideanDivision(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::domain_error("Impossible to divide by zero.");
    }

    std::pair result{dividend / divisor, dividend % divisor};
    return result;
}
