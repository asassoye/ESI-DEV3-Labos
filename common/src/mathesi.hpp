#ifndef DEV3_MATHESI_HPP
#define DEV3_MATHESI_HPP

#include <vector>

namespace dev3::math {
    bool isPrime(unsigned number);

    unsigned nextPrime(unsigned actualPrime);

    std::vector<unsigned> primeList(unsigned min, unsigned max);

    std::pair<int, int> euclideanDivision(int dividend, int divisor);
}

#endif //DEV3_MATHESI_HPP
