/*!
 * \file lotto_incomplete.h
 *
 * \brief Définition de la classe nvs::lotto::Lotto ainsi que
 *        de fonctions associées.
 */
#ifndef LOTTO_INCOMPLETE_H
#define LOTTO_INCOMPLETE_H

#include "parameter.h"
#include "pronostic.h"
#include "draw.h"

#include <vector>
#include <optional>
#include <string>
#include <ostream>

// TODO : ajouter d'éventuels include


/*!
 * \brief Espace de nom du projet Lotto de Nicolas Vansteenkiste.
 */
namespace nvs::lotto {

/*!
 * \brief Classe gérant un jeu de lotto.
 *
 * À sa création, on spécifie les valeurs minimale et maximale
 * de la grille et le nombre de valeurs d'un tirage / d'un
 * pronostic.
 *
 * Ensuite on enregistre les pronostics.
 *
 * Puis le tirage au sort des la combinaison gagnante est
 * réalisé.
 *
 * Enfin, on peut déterminer les gagants.
 */
class Lotto {
  /*!
   * \brief Paramétrage du lotto : valeurs minimale et maximale
   *        et nombre de valeurs d'un tirage / pronostic.
   */
  const Parameter parameter_;

  /*!
   * \brief Ensemble des pronostics de ce jeu de lotto.
   */
  std::vector<Pronostic> pronostics_;

  /*!
   * \brief Tirage de ce jeu de lotto.
   */
  std::optional<Draw> draw_;

 public:

  /*!
   * \brief Constructeur.
   *
   * Le paramétrage de lotto est construit. Davantage de
   * détail dans le constructeur de Parameter
   * Parameter::Parameter().
   *
   * Le lotto est construit sans pronostic et sans tirage.
   *
   * \param length nombre de valeurs à prédire.
   * \param maximum valeur minimale des valeurs à prédire,
   *                cette valeur incluse.
   * \param minimum valeur maximale des valeurs à prédire,
   *                cette valeur incluse.
   *
   * \throw std::invalid_argument si :
   *          + `maximum` est strictement inférieur à `minimum` ;
   *          + `lenght` vaut zéro ou dépasse le nombre de
   *            valeurs comprises entre `minimum` et `maximum`,
   *            ces valeurs incluses.
   *
   * \see Parameter::Parameter()
   */
  inline explicit Lotto(unsigned length = Parameter::LENGTH_DEFAULT_,
                        unsigned maximum = Parameter::MAXIMUM_DEFAULT_,
                        unsigned minimum = Parameter::MINIMUM_DEFAULT_);

  /*!
   * \brief Accesseur en lecture des paramètres de la grille de
   *        lotto.
   *
   * \return paramètres de lotto associée à ce jeu de lotto.
   */
  inline const Parameter &parameter() const;

  /*!
   * \brief Accesseur en lecture de l'ensemble des pronostics
   *        réalisés.
   *
   * \return ensemble des pronostics.
   */
  inline const std::vector<Pronostic> &pronostics() const;

  /*!
   * \brief Accesseur en écriture d'un pronostic.
   *
   * Le pronostic est associé aux paramètres du jeu de lotto. Il
   * est construit à l'aide du constructeur
   * Pronostic::Pronostic(const std::string &, const Container &, const Parameter &).
   *
   * Il est interdit d'ajouter un pronostic _après_ le tirage.
   *
   * \param owner propriétaire du pronostic.
   * \param values valeurs du pronostic.
   *
   * \return le jeu de lotto.
   *
   * \throw std::logic_error si le tirage a déjà été réalisé.
   *
   * \throw std::invalid_argument si
   *          + le nombre de valeurs fournies via `values` ne
   *            correspond pas au nombre de valeurs à prédire
   *            selon les paramètres de la grille du lotto ;
   *          + les valeurs fournies via `values` ne sont pas
   *            dans l'intervalle des valeurs acceptables selon
   *            les paramètres de la grille du lotto.
   *
   * \see Pronostic::Pronostic(const std::string &, const Container &, const Parameter &)
   */
  template<typename Container>
  inline Lotto &add(std::string owner, const Container &values);

  // rnvs : alternative avec initializer_list nécessaire ou pas ?

  /*!
   * \brief Accesseur en écriture d'un pronostic.
   *
   * Alternative à la méthode add(std::string, const Container &)
   * avec un vieux tableau du C (ou une liste d'initialisation)
   * pour fournir les valeurs.
   *
   * Le pronostic est associé aux paramètres de la grille du jeu
   * de lotto. Il
   * est construit à l'aide du constructeur
   * Pronostic::Pronostic(const std::string &, const T (&) [N], const Parameter &).
   *
   * Il est interdit d'ajouter un pronostic _après_ le tirage.
   *
   * \param owner propriétaire du pronostic.
   * \param values valeurs du pronostic.
   *
   * \return le jeu de lotto.
   *
   * \throw std::logic_error si le tirage a déjà été réalisé.
   *
   * \throw std::invalid_argument si
   *          + le nombre de valeurs fournies via `values` ne
   *            correspond pas au nombre de valeurs à prédire
   *            selon les paramètres de la grille du lotto ;
   *          + les valeurs fournies via `values` ne sont pas
   *            dans l'intervalle des valeurs acceptables selon
   *            les paramètres de la grille du lotto.
   *
   * \see Pronostic::Pronostic(const std::string &, const T (&) [N], const Parameter &)
   */
  template<typename T, std::size_t N>
  inline Lotto &add(std::string owner, const T (&values)[N]);

  /*!
   * \brief Accesseur en écriture d'un pronostic.
   *
   * Le pronostic doit être associé au même paramétrage que celui
   * du jeu de lotto.
   *
   * Il est interdit d'ajouter un pronostic _après_ le tirage.
   *
   * \param pronostic pronostic à ajouter à l'ensemble des
   *        pronostics.
   *
   * \return le jeu de lotto.
   *
   * \throw std::logic_error si le tirage a déjà été réalisé.
   *
   * \throw std::invalid_argument si le paramétrage de la grille
   *                              du pronostic n'est
   *                              pas celui du lotto.
   */
  inline Lotto &add(const Pronostic &pronostic);

  /*!
   * \brief Opérateur pour l'accès en écriture d'un pronostic.
   *
   * Le pronostic doit être associé au même paramétrage que celui
   * du jeu de lotto.
   *
   * Il est interdit d'ajouter un pronostic _après_ le tirage.
   *
   * \param pronostic pronostic à ajouter à l'ensemble des
   *        pronostics.
   *
   * \return le jeu de lotto.
   *
   * \throw std::logic_error si le tirage a déjà été réalisé.
   *
   * \throw std::invalid_argument si le paramétrage de la grille
   *                              du pronostic n'est
   *                              pas celui du lotto.
   *
   * \see add(const Pronostic &)
   */
  inline Lotto &operator+=(const Pronostic &pronostic);

  /*!
   * \brief Accesseur en lecture pour savoir si le tirage a eu
   *        lieu.
   *
   * \return `false` si le tirage n'a pas eu lieu, `true` à
   *         partir du moment où il a eu lieu.
   */
  inline bool has_draw() const;

  /*!
   * \brief Accesseur en écriture pour réaliser le tirage.
   *
   * Le tirage correspond évidemment aux paramètres du lotto.
   * Il ne peut y avoir qu'un seul tirage.
   *
   * \throw std::logic_error si le tirage a déjà eu lieu.
   */
  inline void set_draw();

  /*!
   * \brief Accesseur en lecture du tirage.
   *
   * \return un clone du tirage, s'il a eu lieu.
   *
   * \throw std::logic_error si le tirage n'a pas déjà été
   *        réalisé.
   */
  inline Draw draw() const;

  /*!
   * \brief Énumération fortement typée pour indiquer le type
   *        de l'égalité à utiliser par la méthode
   *        winner().
   */
  enum class Equality {
    /*! Pour indiquer l'égalité stricte. */
    STRICT,
    /*! Pour indiquer l'égalité inclusive. */
    INCLUSIVE
  };

  /*!
   * \brief Accesseur en lecture des pronostics gagnants.
   *
   * Cette méthode ne peut être invoquée qu'après le
   * tirage réalisé.
   *
   * Elle retourne l'ensemble des pronostics
   * comportant :
   *
   *  + _exactement_ `predicted_length` chiffres présents
   *    dans le tirage lorsque la valeur de `type` est
   *    Equality::STRICT ;
   *  + _au moins_ `predicted_length` chiffres présents dans
   *    le tirage lorsque la valeur de `type` est
   *    Equality::INCLUSIVE.
   *
   * \param predicted_length le nombre de chiffres du tirage
   *                         présents dans le pronostic.
   * \param type le type d'égalité utilisée (voir ci-dessus).
   *
   * \return ensemble des pronostics répondant aux paramètres.
   *
   * \throw std::logic_error si le tirage n'a pas encore eu lieu.
   *
   * \throw std::invalid_argument si `predicted_length` est nul
   *          ou strictement supérieur au nombre de valeurs du
   *          tirage.
   */
  inline std::vector<Pronostic>
  winner(unsigned predicted_length,
         Equality type = Equality::STRICT) const;

  /*!
   * \brief Conversion d'un Lotto en std::string.
   *
   * Les paramètres de la grille (minimum, maximum et taille)
   * sont toujours convertis en std::string.
   *
   * Si le tirage a eu lieu, son résultat et l'ensemble des
   * pronostics sont convertis. Sinon, un message indiquant
   * que le tirage n'a pas encore eu lieu est ajouté à la
   * std::string.
   *
   * \return représentation du Lotto sous la forme d'une
   *         std::string.
   *
   * \see to_string(const Lotto &)
   */
  inline std::string to_string() const;
};

// prototypes

/*!
 * \brief Conversion d'un Lotto en std::string.
 *
 * Les paramètres de la grille (minimum, maximum et taille) de
 * `lotto` sont toujours convertis en std::string.
 *
 * Si le tirage de `lotto` a eu lieu, son résultat et l'ensemble de
 * ses pronostics sont convertis. Sinon, un message indiquant
 * que le tirage n'a pas encore eu lieu est ajouté à la
 * std::string.
 *
 * \param lotto Lotto à convertir.
 *
 * \return représentation de `lotto` sous la forme d'une
 *         std::string.
 *
 * \see Lotto::to_string()
 */
inline std::string to_string(const Lotto &lotto);

/*!
 * \brief Opérateur d'injection d'un Lotto dans un flux en sortie.
 *
 * Les paramètres de la grille (minimum, maximum et taille) de
 * `lotto` sont toujours injectés dans `out`.
 *
 * Si le tirage de `lotto` a eu lieu, son résultat et l'ensemble de
 * ses pronostics sont injectés. Sinon, un message indiquant
 * que le tirage n'a pas encore eu lieu est injectés dans `out`.
 *
 * \param out flux dans lequel injecter `lotto`.
 * \param lotto Lotto à injecter.
 *
 * \return flux après injection.
 *
 * \see Lotto::to_string()
 */
inline std::ostream &operator<<(std::ostream &out,
                                const Lotto &lotto);

// implémentation méthodes inline

Lotto::Lotto(unsigned length, unsigned maximum, unsigned minimum) :
// TODO {}

const Parameter &Lotto::parameter() const {
  return parameter_;
}

const std::vector<Pronostic> &Lotto::pronostics() const {
  return pronostics_;
}

template<typename Container>
inline Lotto &Lotto::add(std::string owner,
                         const Container &values) {
  return add(Pronostic{owner, values, parameter_});
}

template<typename T, std::size_t N>
Lotto &Lotto::add(std::string owner, const T (&values)[N]) {
  return add(Pronostic{owner, values, parameter_});
}

Lotto &Lotto::add(const Pronostic &pronostic) {
  // TODO
}

Lotto &Lotto::operator+=(const Pronostic &pronostic) {
  return add(pronostic);
}

bool Lotto::has_draw() const {
  // TODO
}

void Lotto::set_draw() {
  // TODO
}

Draw Lotto::draw() const {
  // TODO
}

std::vector<Pronostic>
Lotto::winner(unsigned predicted_length, Equality type) const {
  // TODO
}

std::string Lotto::to_string() const {
  std::string result{"{ g } "};
  result
      .append(parameter_.to_string())
      .append("\n");

  if (has_draw()) {
    // ici tirage a eu lieu
    result
        .append("{ d } ")
        .append(draw_->to_string())
        .append("\n");

    result
        .append("{ p } ")
        .append(std::to_string(pronostics_.size()))
        .append("\n");
    for (const auto &e : pronostics_) {
      result
          .append("      ")
          .append(e.to_string())
          .append("\n");
    }
  } else {
    // ici pas encore de tirage
    result.append("no draw yet");
  }

  return result;
}

// implémentation fonctions inline

std::string to_string(const Lotto &lotto) {
  return lotto.to_string();
}

std::ostream &operator<<(std::ostream &out, const Lotto &lotto) {
  return out << lotto.to_string();
}

}   // namespace nvs::lotto

#endif // LOTTO_INCOMPLETE_H
