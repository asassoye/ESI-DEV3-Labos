/**
* @file pronostic.h
* @brief Définition de la classe nvs::lotto::Draw.
*
* @author Andrew SASSOYE <andrew@sasoye.be>
* @copyright Copyright © 2020 Andrew SASSOYE. This project is released under the MIT License.
*/
#ifndef DRAW_H
#define DRAW_H

#include "item.h"
#include "parameter.h"

#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

#include "random/random.hpp"

/*!
 * \brief Espace de nom du projet Lotto de Nicolas Vansteenkiste.
 */
namespace g54327::lotto {

/*!
 * \brief Classe représentant un tirage de numéros de lotto.
 */
class Draw : public Item {
  /*!
   * \brief Méthode réalisant le tirage.
   *
   * Le std::set d'`unsigned` retourné respecte en taille
   * et valeurs les paramètres du jeu de lotto fournis via
   * l'argument `parameter`.
   *
   * \param parameter paramètres du jeu de lotto.
   *
   * \return tirage valide pour le lotto paramétré par `parameter`.
   */
  inline std::set<unsigned> draw(const Parameter &parameter) const;

 public:

  /*!
   * \brief Constructeur d'un tirage au sort de numéros de lotto.
   *
   * La méthode privée draw() fait la boulot dans le respect
   * des paramètres du lotto.
   *
   * \param parameter paramètres du jeu de lotto.
   *
   * \see draw()
   */
  inline explicit Draw(const Parameter &parameter);

  /*!
   * \brief Constructeur virtuel par défaut.
   */
  virtual ~Draw() override = default;
};

// implémentation méthodes inline

Draw::Draw(const Parameter &parameter) :
    Item{draw(parameter), parameter}
// rem. : on doit fournir parameter à draw car au moment de
//        l'appel de draw l'attribut parameter_ n'est
//        (peut-être) pas encore construit
{}

std::set<unsigned> Draw::draw(const Parameter &parameter) const {
  using namespace std;
  vector<unsigned> universe(parameter.maximum() -
      parameter.minimum() + 1);
  iota(begin(universe), end(universe), parameter.minimum());
  shuffle(begin(universe), end(universe), nvs::urng());
  return {cbegin(universe), cbegin(universe) +
      parameter.length()};
}

}   // namespace nvs::lotto

#endif // DRAW_H
