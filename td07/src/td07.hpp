/**
 * @file td07.h
 * @author Andrew SASSOYE
 */
#ifndef DEV3_TD07_HPP
#define DEV3_TD07_HPP

#include <cstddef>
#include <array>
#include <map>

#include "../resources/random.hpp"

/**
 * Retourne un resultat statistique
 *
 * @tparam N taille de l'array
 * @param times nombre de fois ou on teste la fonction de randomisation
 * @return resultat statistique
 */
template<size_t N>
std::array<std::pair<unsigned, double>, N> test_nvs_random(unsigned times);

/**
 * Affiche le contenu d'un vector de int en console
 *
 * @param data vecteur
 */
void print(const std::vector<int> &data);

/**
 * Sort a vector of integers
 *
 * @param data vector to sort
 * @param ascending sort ascending if true
 */
void sort(std::vector<int> &data, bool ascending);

unsigned primeFactor(std::map<unsigned, unsigned> &result, unsigned value);

void printPrimeFactor(unsigned value, std::map<unsigned, unsigned> &decomposition);

template<size_t N>
std::array<std::pair<unsigned, double>, N> test_nvs_random(unsigned times) {
    std::array<std::pair<unsigned, double>, N> array{};
    size_t arraySize = array.size();
    size_t randomValue;

    nvs::randomize();

    for (size_t i = 0; i < times; ++i) {
        randomValue = nvs::random_value(0, arraySize);
        (array[randomValue].first)++;
    }

    for (size_t i = 0; i < arraySize; ++i) {
        array[i].second = static_cast<double>(array[i].first) / times;
    }

    return array;
}

#endif //DEV3_TD07_HPP
