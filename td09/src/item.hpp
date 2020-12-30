/**
 * @file item.h
 * @brief Définition de la classe g54327::lotto::Item ainsi que
 *        de fonctions associées.
 *
 * @author Andrew SASSOYE <andrew@sasoye.be>
 * @copyright Copyright © 2020 Andrew SASSOYE. This project is released under the MIT License.
 */
#ifndef ITEM_H
#define ITEM_H

#include <set>
#include <string>
#include <ostream>
#include <stdexcept>

#include "parameter.hpp"

/*!
 * \brief Espace de nom du projet Lotto de Nicolas Vansteenkiste.
 */
namespace g54327::lotto {

/*!
 * \brief Classe mère des pronostics et tirage d'un jeu de lotto.
 *
 * Il s'agit d'une classe abstraite.
 *
 * Son destructeur est virtuel
 * pur. Cependant, comme ses classes filles auront à utiliser ce
 * destructeur, il doit être implémenté. Vous trouverez davantage
 * d'informations sur les méthodes virtuelles pures _avec_ une
 * implémentation dans le [GotW #31](http://www.gotw.ca/gotw/031.htm).
 * Sa section 2.1 se penche spécifiquement sur le cas des
 * destructeurs virtuels purs.
 */
class Item {
  /*!
   * \brief Référence vers un paramétrage de grille de lotto.
   */
  const Parameter &parameter_;

  /*!
   * \brief Ensemble de valeurs prédites (dans le cas d'un
   *        pronostic) ou tirées aléatoirement (dans le cas d'un
   *        tirage).
   *
   * Comme il s'agit d'un std::set, chaque valeur y est unique.
   */
  const std::set<unsigned> values_;

  /*!
   * \brief Vérification de tailles.
   *
   * Lors de la création d'un Item, il faut vérifier que le
   * nombre de valeurs du pronostic, c'est-à-dire le nombre de
   * valeurs dans \ref values_, correspond bien au paramétrage
   * du lotto, spécifié via \ref parameter_.
   *
   * \throw std::invalid_argument si le nombre de valeurs
   *          fournies à la construction ne correspond pas au
   *          nombre de valeurs à prédire pour ce lotto.
   *
   * \see Item()
   */
  inline void checkLengths() const;

  /*!
   * \brief Vérification de valeurs.
   *
   * Lors de la création d'un Item, il faut vérifier que
   * les valeurs du pronostic, c'est-à-dire les valeurs
   * présentes dans \ref values_, correspondent bien au paramétrage
   * du lotto, spécifié via \ref parameter_.
   *
   * \throw std::invalid_argument si les valeurs fournies
   *          à la construction ne sont pas dans l'intervalle
   *          des valeurs acceptées pour ce lotto.
   *
   * \see Item()
   */
  inline void checkValues() const;

 public:

  /*!
   * \brief Constructeur générique.
   *
   * La référence `parameter` sert à initialiser l'attribut
   * \ref parameter_,
   * lui-même référence de Parameter. L'argument doit donc faire
   * référence à une Parameter qui survit à l'appel du
   * constructeur.
   * Dès lors, proscrire un appel comme :
   *
   *     Item(values, Parameter { });
   *
   * Tout le contenu du conteneur values est utilisé pour
   * initialiser l'attribut \ref values_. À cette fin, le type
   * Container doit disposer _dans son espace de nom_ de fonction
   * nommées `cbegin()` et `cend()`. La première retourne un
   * itérateur de valeurs constantes sur son premier élément.
   * La seconde un itérateur passé son dernier élément. Par
   * ailleurs, comme \ref values_ est un
   * std::set<unsigned>,  `values` peut ne pas survire à l'appel
   * du constructeur et son contenu doit pouvoir être
   * transtypé en `unsigned`. Voici un appel valide :
   *
   *     Item(std::vector<double> { 7.7, 2.3, 43 }, parameter);
   *
   * Les méthodes checkLengths() et checkValues() sont
   * appelées pour vérifier que les données fournies via
   * `values` respectent bien les paramètres de `parameter`.
   *
   * \param values conteneur quelconque de valeurs.
   * \param parameter paramétrage de lotto.
   *
   * \throw std::invalid_argument si
   *          + le nombre de valeurs fournies via `values` ne
   *            correspond pas au nombre de valeurs à prédire
   *            selon `parameter` ;
   *          + les valeurs fournies via `values` ne sont pas
   *            dans l'intervalle des valeurs acceptables selon
   *            `parameter`.
   *
   * \see checkLengths(), checkValues()
   */
  template<typename Container>
  inline explicit Item(const Container &values,
                       const Parameter &parameter);

  /*!
   * \brief Destructeur virtuel pur.
   *
   * Comme la classe est destinée à être héritée, son destructeur
   * doit être [virtuel]
   * (https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors).
   *
   * L'utilisation de la classe n'a de sens qu'à travers une
   * classe dérivée. Il s'agit donc d'une [classe abstraite]
   * (https://en.cppreference.com/w/cpp/language/abstract_class).
   * Le choix de la méthode virtuelle pure, pour obtenir une
   * classe abstraite, s'est porté sur le destructeur.
   *
   * Cependant, les classes filles vont implicitement utiliser
   * le destructeur de la classe mère. Le destructeur virtuel
   * pur requiert donc une implémentation. On trouve plus
   * d'informations sur les méthodes virtuelles pures dotées
   * d'une implémentation dans le [GotW #31]
   * (http://www.gotw.ca/gotw/031.htm). L'implémentation
   * du [destructeur](https://en.cppreference.com/w/cpp/language/destructor)
   * par défaut fait ici très bien l'affaire.
   *
   * Finalement, il est étiqueté [`inline`]
   * (https://stackoverflow.com/a/1759575) pour ne pas violer
   * la [One Definition Rule]
   * (https://en.wikipedia.org/wiki/One_Definition_Rule).
   *
   * \see https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
   * \see https://en.cppreference.com/w/cpp/language/abstract_class
   * \see http://www.gotw.ca/gotw/031.htm
   * \see https://en.cppreference.com/w/cpp/language/destructor
   * \see https://stackoverflow.com/a/1759575
   * \see https://en.wikipedia.org/wiki/One_Definition_Rule
   */
  inline virtual ~Item() = 0;

  /*!
   * \brief Constructeur par recopie par défaut.
   *
   * Le destructeur virtuel par défaut a des effets en cascade.
   *
   * \see https://stackoverflow.com/q/33957037
   * \see https://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
   * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
   */
  Item(const Item &) = default;

  /*!
   * \brief Constructeur par déplacement par défaut.
   *
   * Le destructeur virtuel par défaut a des effets en cascade.
   *
   * \see https://stackoverflow.com/q/33957037
   * \see https://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
   * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
   */
  Item(Item &&) = default;

  /*!
   * \brief Accesseur en lecture des paramètres de la grille de
   *        lotto.
   *
   * \return paramètres de la grille de lotto associée à cet
   *         élément de lotto.
   */
  inline const Parameter &parameter() const;

  /*!
   * \brief Accesseur en lecture des valeurs.
   *
   * Il s'agit des valeurs pronostiquées ou tirées au sort
   * selon la nature de l'instance.
   *
   * \return les valeurs de cet élément de lotto.
   */
  inline const std::set<unsigned> &values() const;

  /*!
   * \brief Conversion d'un Item en std::string.
   *
   * Les paramètres de la grille et les valeurs de l'élément
   * de lotto sont mis en forme et convertis en std::string.
   *
   * \return représentation du Item sous la forme d'une
   *         std::string.
   *
   * \see to_string(const Item &)
   */
  inline virtual std::string to_string() const;
};

// prototypes

/*!
 * \brief Conversion d'un Item en std::string.
 *
 * Les paramètres de la grille et les valeurs de l'élément
 * de lotto `item` sont mis en forme et convertis en
 * std::string.
 *
 * Pour obtenir un comportement polymorphique sur l'_argument_
 * `item`, la méthode Item::to_string() est utilisée.
 *
 * \param item Item à convertir.
 *
 * \return représentation de `item` sous la forme
 *         d'une std::string.
 *
 * \see Item::to_string()
 */
inline std::string to_string(const Item &item);

/*!
 * \brief Opérateur d'injection d'un Item dans un flux en
 *        sortie.
 *
 * Les paramètres de la grille et les valeurs de l'élément
 * de lotto `item` sont mis en forme et injectés dans `out`.
 *
 * Pour obtenir un comportement polymorphique sur l'_argument_
 * `item`, la méthode Item::to_string() est utilisée.
 *
 * \param out flux dans lequel injecter `item`.
 * \param item Item à injecter.
 *
 * \return flux après injection.
 *
 * \see Item::to_string()
 */
inline std::ostream &operator<<(std::ostream &out,
                                const Item &item);

// implémentation méthodes inline

void Item::checkLengths() const {
  if (parameter_.length() != values_.size()) {
    throw std::invalid_argument{"size error"};
  }
}

void Item::checkValues() const {
  for (auto value : values_) {
    if (value < parameter_.minimum() || value > parameter_.maximum()) {
      throw std::invalid_argument{"value error"};
    }
  }
}

template<typename Container>
Item::Item(const Container &values, const Parameter &parameter) :
    parameter_{parameter},
    values_{cbegin(values), cend(values)}
// ici cbegin et cend recherchés dans namespace de container
// car ADL : https://en.cppreference.com/w/cpp/language/adl
{
  checkLengths();
  checkValues();
}

// https://stackoverflow.com/a/11494673
// http://www.gotw.ca/gotw/031.htm
Item::~Item() = default;

const Parameter &Item::parameter() const {
  return parameter_;
}

const std::set<unsigned> &Item::values() const {
  return values_;
}

std::string Item::to_string() const {
  std::string result{parameter_.to_string()};
  result.append(" :: { ");
  for (auto e : values_) {
    result.append(std::to_string(e)).append(" ");
  }
  return result.append("}");
}

// implémentation fonctions inline

std::string to_string(const Item &item) {
  return item.to_string();
}

std::ostream &operator<<(std::ostream &out,
                         const Item &item) {
  return out << item.to_string();
}

}

#endif // ITEM_H
