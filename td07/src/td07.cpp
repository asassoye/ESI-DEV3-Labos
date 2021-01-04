/**
 * @file td07.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include <exception>
#include "td07.hpp"
#include "../resources/mathesicpp.hpp"

void print(const std::vector<int> &data) {
    std::cout << "{";
    for (size_t i = 0; i < data.size(); ++i) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << data[i];
    }
    std::cout << "}" << std::endl;
}

void sort(std::vector<int> &data, bool ascending) {
    int c;
    for (size_t j = 1; j <= data.size(); j++)
        for (size_t i = 0; i < data.size() - 1; i++)
            if (ascending ? data[i] > data[i + 1] : data[i] < data[i + 1]) {
                c = data[i];
                data[i] = data[i + 1];
                data[i + 1] = c;
            }
}

unsigned primeFactor(std::map<unsigned, unsigned> &result, unsigned value) {
    if (!result.empty()) {
        result.clear();
    }

    if (g54327::math::isPrime(value)) {
      result.insert(std::pair<unsigned, unsigned>(value, 1));
      return 1;
    }

    unsigned count = 0;
    unsigned prime = 2;
    unsigned power = 0;
    while (value > 1) {
        while (value % prime == 0) {
            value /= prime;
            ++power;
        }
        if (power > 0) {
            result.insert(std::pair<unsigned, unsigned>(prime, power));
            power = 0;
            ++count;
        }

        if (prime == 2) {
            prime++;
        } else {
            prime += 2;
        }
    }

    return count;
}

void printPrimeFactor(unsigned value, std::map<unsigned, unsigned> &decomposition) {
    std::cout << value << " = ";
    if (value <= 1) {
        std::cout << value;
        return;
    }

    for (auto i = decomposition.begin(); i != decomposition.end(); ++i) {
        if (i->second != 0) {
            if (i != decomposition.begin()) {
                std::cout << " * ";
            }
            std::cout << i->first << (i->second != 1 ? "^" : "") << (i->second != 1 ? std::to_string(i->second) : "");
        }
    }

    std::cout << std::endl;
}
