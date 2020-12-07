/**
 * @file td07.h
 * @author Andrew SASSOYE
 */
#ifndef DEV3_TD07_H
#define DEV3_TD07_H

#include <cstddef>
#include <array>

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

template<size_t N>
std::array<std::pair<unsigned, double>, N> test_nvs_random(unsigned times) {
    std::array<std::pair<unsigned, double>, N> array{};
    size_t randomValue;

    for (size_t i = 0; i < times; ++i) {
        randomValue = nvs::random_value(0, array.size());
        (array[randomValue].first)++;
    }

    for (size_t i = 0; i < array.size(); ++i) {
        array[i].second = static_cast<double>(array[i].first) / times;
    }

    return array;
}

#endif //DEV3_TD07_H
