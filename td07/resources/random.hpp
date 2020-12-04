/*!
 * \file random.hpp
 * \brief Définitions de fonctions conviviales pour générer des
 *        séquences pseudo-aléatoires.
 */
#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <utility>
#include <limits>

#ifdef _WIN32
#include <ctime>
#endif

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 *
 */
namespace nvs {

// fonctions

/*!
 * \brief Un générateur de nombres uniformément aléatoires.
 *
 * Cette fonction produit et partage un unique
 * générateur de nombres uniformément aléatoires
 * (_Uniform Random Number Generator_).
 * Elle est issue de Random Number Generation in C++11
 * ([WG21 N3551]
 * (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3551.pdf)),
 * par Walter E. Brown.
 *
 * _Remarque_ : Sous Windows, c'est un std::mt19937 qui est
 * retourné, sous les autres systèmes d'exploitation c'est
 * un std::default_random_engine. La raison en est qu'avec
 * gcc sous Windows, la première valeur retournée par
 * un std::default_random_engine change peu en fonction de la
 * graine plantée avec nvs::randomize. Pour s'en convaincre,
 * exécuter nvs::random_value(1, 100000) par des instances
 * successives d'un même programme...
 *
 * \return un générateur de nombres uniformément aléatoires.
 */
    inline auto &urng() {
#ifdef _WIN32
        static std::mt19937 u {};
        // https://stackoverflow.com/a/32731387
        // dans le lien précédent : Linux   <-> gcc
        //                       et Windows <-> msvc
#else
        static std::default_random_engine u{};
#endif
        return u;
    }

/*!
 * \brief Un peu de bruit.
 *
 * Cette fonction met le générateur de nombres uniformément
 * aléatoires partagé par nvs::urng() dans un état aléatoire.
 * Elle est issue de Random Number Generation in C++11
 * ([WG21 N3551]
 * (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3551.pdf)),
 * par Walter E. Brown.
 */
    inline void randomize() {
#ifdef _WIN32
        urng().seed(std::time(nullptr));
        // https://stackoverflow.com/a/18908041
#else
        static std::random_device rd{};
        urng().seed(rd());
#endif
    }

/*!
 * \brief Générateur de flottants aléatoires.
 *
 * Les flottants produits se distribuent uniformément entre
 * `min` et `max`, la valeur minimale comprise, la maximale non.
 *
 * Si `max` est strictement inférieur à `min`, les contenus de ces
 * variables sont permutés.
 *
 * Cette fonction est largement inspirée par Random Number
 * Generation in C++11 ([WG21 N3551]
 * (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3551.pdf)),
 * par Walter E. Brown.
 *
 * _Remarque_ : Par rapport au modèle de fonction
 * nvs::random_value<T> produisant des entiers aléatoires, les
 * arguments `min` et `max` sont inversés de sorte à avoir la
 * valeur nulle (0) comme borne (minimale ou maximale) si la
 * fonction est appelée avec un seul argument. Notez que cela n'a
 * pas de réelle incidence sur la signification des paramètres
 * puisque leurs contenus sont permutés si nécessaire.
 *
 * \param max borne supérieure (ou inférieure) de l'intervalle
 *            dans lequel les flottants sont générés.
 * \param min borne inférieure (ou supérieure) de l'intervalle
 *            dans lequel les flottants sont générés.
 *
 * \return un flottant dans l'intervalle semi-ouvert à droite
 *         [`min`, `max`[ (ou [`max`, `min`[ si `max` < `min`).
 */
    inline double random_value(double max = 1., double min = 0.) {
        static std::uniform_real_distribution<double> d{};

        if (max < min) std::swap(min, max);

        return d(urng(), decltype(d)::param_type{min, max});
    }

// fonctions template

/*!
 * \brief Générateur d'entiers aléatoires.
 *
 * Les entiers produits se distribuent uniformément entre
 * `min` et `max`, ces valeurs incluses.
 *
 * The effect is undefined if T is not one of : short, int, long,
 * long long, unsigned short, unsigned int, unsigned long, or
 * unsigned long long.
 *
 * Si `max` est strictement inférieur à `min`, les contenus de ces
 * variables sont permutés.
 *
 * Cette fonction est largement inspirée par Random Number
 * Generation in C++11 ([WG21 N3551]
 * (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3551.pdf)),
 * par Walter E. Brown.
 *
 * \param min valeur minimale (ou maximale) pouvant être retournée.
 * \param max valeur maximale (ou minimale) pouvant être retournée.
 *
 * \return un entier entre `min` et `max`.
 */
    template<typename T = int>
    inline T random_value(T min = std::numeric_limits<T>::min(),
                          T max = std::numeric_limits<T>::max()) {
        static std::uniform_int_distribution<T> d{};

        if (max < min) std::swap(min, max);

        return d(urng(), typename decltype(d)::param_type{min, max});
    }

} // namespace nvs

#endif // RANDOM_HPP
