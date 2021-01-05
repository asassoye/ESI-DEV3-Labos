/*!
 * \file data.h
 *
 * \brief Prototypes d'une fonction et définition d'une énumération
 *        pour la génération de données.
 */
#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <tuple>

/*!
 * \brief Espace de nommage de la [HE2B](https://www.he2b.be/).
 *
 */
namespace he2b {

/*!
 * \brief Espace de nommage de Nicolas Vansteenkiste.
 *
 */
namespace nvs {

/*!
 * \brief Énumération fortement typée pour contrôler le caractère
 *        reproductible ou non du comportement des fonctions
 *        pour la génération des données.
 */
enum class Randomness {
  /*!
   * \brief Pour indiquer qu'on désire un comportement _différent_
   *        des fonctions pour la génération des données
   *        d'une exécution à l'autre du programme qui l'utilise.
   */
  NON_REPRODUCTIBLE,

  /*!
   * \brief Pour indiquer qu'on désire un comportement _identique_
   *        des fonctions pour la génération des données
   *        d'une exécution à l'autre du programme qui l'utilise.
   */
  REPRODUCTIBLE
};

/*!
 * \brief Fonction de production de données.
 *
 * Les données produites servent à la production de vecteurs (au sens
 * mathématique) tels que modélisés par la classe m_vector.
 *
 * Pour chaque std::tuple du std::vector retourné, le champ d'index :
 *
 *  + 0 : correspond au nombre de composantes du vecteur ;
 *  + 1 : correspond aux valeurs des composantes du vecteur.
 *
 * Idéalement, chaque std::tupe sert à produire un vecteur, mais il
 * peut y avoir des erreurs :
 *
 *  + la std::string retournée dans le premier champ du std::tuple
 *    peut ne pas représenter un entier non signé, comme par exemple
 *    les chaînes `"12e"`, `"1e2"` ou `"e12"` ;
 *  + le nombre de composantes indiqué dans le premier champ peut être
 *    nul, c'est-à-dire égal à zéro, ce qui est exclu dans m_vector ;
 *  + le nombre de composantes renseigné dans le premier champ peut être
 *    différent du nombre d'éléments du std::vector en second index
 *    du std::tuple.
 *
 * _Remarque_ : si le paramètre `reproductible` est mis à
 * Randomness::NON_REPRODUCTIBLE, cela rend non reproductible
 * d'une exécution à l'autre cet appel de fonction,
 * mais également celui de toutes les fonctions avec un argument
 * de type \ref Randomness appelées utlérieurement, car les
 * fonctions de random.hpp utilisent toutes _le même_ générateur
 * aléatoire.
 *
 * \param size pour contrôler le nombre d'élements du std::vector
 *             retourné.
 * \param reproductible pour contrôler la nature reproductible ou
 *                      non de la fonction.
 *
 * \return données brutes telles que décrites ci-dessus.
 */
std::vector<std::tuple<std::string, std::vector<double>>>
data(std::size_t size = 1'000'000,
     Randomness reproductible = Randomness::NON_REPRODUCTIBLE);

} // namespace he2b::nvs

} // namespace he2b

#endif // DATA_H
