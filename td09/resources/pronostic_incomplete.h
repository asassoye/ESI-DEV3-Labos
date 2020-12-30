/*!
 * \file pronostic_incomplete.h
 *
 * \brief Définition de la classe nvs::lotto::Pronostic.
 */
#ifndef PRONOSTIC_INCOMPLETE_H
#define PRONOSTIC_INCOMPLETE_H

#include "item.h"
#include "parameter.h"

#include <string>
#include <initializer_list>
#include <set>

/*!
 * \brief Espace de nom du projet Lotto de Nicolas Vansteenkiste.
 */
namespace nvs::lotto {

/*!
 * \brief Classe représentant un pronostic de jeu de lotto.
 */
class Pronostic : public Item {
  /*!
   * \brief Nom / identifiant de l'auteur / propriétaire
   *        du pronostic.
   */
  const std::string owner_;

 public:

  /*!
   * \brief Constructeur générique.
   *
   * À part pour ce qui concerne le propriétaire du pronostic,
   * qui peut être transmis à l'aide d'une valeur temporaire
   * car sa valeur est clonée dans l'attribut \ref owner_,
   * tout a été dit dans la description du constructeur de
   * Item Item::Item().
   *
   * Un appel correct est :
   *
   *     Pronostic { "owner", std::vector<unsigned> { 4, 6, 15, 12 }, parameter }
   *
   * \param owner nom / identifiant du propriétaire du pronostic.
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
   * \see Item::Item()
   */
  template<typename Container>
  explicit inline Pronostic(const std::string &owner,
                            const Container &values,
                            const Parameter &parameter);

  /*!
   * \brief Constructeur générique avec une
   *        liste d'initialisation en argument.
   *
   * Il s'agit d'une alternative pour permettre la création
   * d'un pronostic avec une liste d'initialisation pour
   * renseigner les valeurs.
   *
   * Voici un appel correct :
   *
   *     Pronostic { "owner", { 4, 6, 15, 12 }, parameter }
   *
   * \param owner nom / identifiant du propriétaire du pronostic.
   * \param values liste d'initialisation avec les valeurs.
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
   * \see Pronostic::Pronostic(const std::string &, const Container &, const Parameter &)
   */
  template<typename T>
  explicit inline Pronostic(const std::string &owner,
                            const std::initializer_list<T> &values,
                            const Parameter &parameter);

  /*!
   * \brief Constructeur générique avec un
   *        vieux tableau du C en argument.
   *
   * Il s'agit d'une alternative pour permettre la création
   * d'un pronostic avec un vieux tableau pour
   * renseigner les valeurs.
   *
   * Voici un appel correct :
   *
   *     int t [] = { 4, 6, 15, 12 };
   *     Pronostic { "owner", t, parameter }
   *
   * \param owner nom / identifiant du propriétaire du pronostic.
   * \param values vieux tableau avec les valeurs.
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
   * \see Pronostic::Pronostic(const std::string &, const Container &, const Parameter &)
   */
  template<typename T, std::size_t N>
  explicit inline Pronostic(const std::string &owner,
                            const T (&values)[N],
                            const Parameter &parameter);

  /*!
   * \brief Constructeur virtuel par défaut.
   */
  virtual ~Pronostic() override = default;

  /*!
   * \brief Accesseur en lecture du propriétaire du pronostic.
   *
   * \return propriétaire du pronostic.
   */
  inline const std::string &owner() const;

  /*!
   * \brief Conversion d'un Pronostic en std::string.
   *
   * Le propriétaire, les paramètres de la grille et les valeurs
   * du pronostic sont mis en forme et convertis en std::string.
   *
   * \return représentation du Pronostic sous la forme d'une
   *         std::string.
   *
   * \see to_string(const Pronostic &)
   */
  inline std::string to_string() const override;
};

// implémentation méthodes inline

template<typename Container>
Pronostic::Pronostic(const std::string &owner,
                     const Container &values,
                     const Parameter &parameter) :
// TODO
{}

template<typename T>
Pronostic::Pronostic(const std::string &owner,
                     const std::initializer_list<T> &values,
                     const Parameter &parameter) :
    Pronostic{owner,
              std::set<unsigned>{cbegin(values),
                                 cend(values)}, parameter} {}

template<typename T, std::size_t N>
Pronostic::Pronostic(const std::string &owner,
                     const T (&values)[N],
                     const Parameter &parameter) :
    Pronostic{owner,
              std::set<unsigned>{std::cbegin(values),
                                 std::cend(values)}, parameter} {}

const std::string &Pronostic::owner() const {
  return owner_;
}

std::string Pronostic::to_string() const {
  return Item::to_string().append(" ::: ").append(owner_);
}

}   // namespace nvs::lotto

#endif // PRONOSTIC_INCOMPLETE_H
