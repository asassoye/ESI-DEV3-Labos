/*!
 * \file data_fraction.h
 *
 * \brief Fonctions pour la génération de données de création de
 *        fractions.
 */
#ifndef DATA_FRACTION_H
#define DATA_FRACTION_H

#include <vector>
#include <utility>
#include <tuple>

namespace nvs {

/*!
 * \brief Énumération fortement typée pour choisir le type de
 *        comportement aléatoire.
 */
    enum class Random {
        /*!
         * \brief Constante d'énumération destinée à représenter un
         *        comportement aléatoire reproductible d'une exécution
         *        l'autre.
         */
        REPRODUCTIBLE,

        /*!
         * \brief Constante d'énumération destinée à représenter un
         *        comportement aléatoire _non_ reproductible
         *        d'une exécution l'autre.
         */
        UNIQUE
    };

/*!
 * \brief Fonction pour la génération de fraction avec deux entiers
 *        signés en argument.
 *
 * Le premier attribut de chaque std::pair sert de numérateur,
 * le second de dénominateur.
 *
 * Il peut y avoir des valeurs de dénominateur nulles.
 *
 * \param size le nombre de std::pair à produire.
 * \param type le type de comportement aléatoire attendu.
 *
 * \return std::vector de `size` std::pair.
 */
    std::vector<std::pair<int, int>>
    data_signed(unsigned size = 1'000'000, Random type = Random::UNIQUE);

/*!
 * \brief Fonction pour la génération de fraction avec un signe et
 *       deux entiers non signés en argument.
 *
 * Le premier champ de chaque std::tuple sert de signe,
 * le deuxième de numérateur,
 * le troisième de dénominateur.
 *
 * L'`int` prend ses valeurs parmi { -1, 0, 1 }, conformément aux
 * valeurs de l'enum class nvs::Sign.
 *
 * Il peut y avoir des valeurs de signe nulles alors que le premier
 * `ùnsigned` n'est pas nul, ou des valeurs de dénominateur nulles.
 *
 * \param size le nombre de std::tuple à produire.
 * \param type le type de comportement aléatoire attendu.
 *
 * \return std::vector de `size` std::tuple.
 */
    std::vector<std::tuple<int, unsigned, unsigned>>
    data_unsigned(unsigned size = 1'000'000, Random type = Random::UNIQUE);

}

#endif // DATA_FRACTION_H
