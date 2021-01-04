/*!
 * \file sign.h
 *
 * \brief Définition de l'énumération fortement typée nvs::Sign
 *        et de fonctions associées.
 */
#ifndef DEV3_SIGN_H
#define DEV3_SIGN_H

#include <string>
#include <ostream>

/*!
 * \brief Sign namespace.
 */
namespace g54327 {

/*!
 * \brief Énumération fortement typée représentant un [signe]
 *        (https://fr.wikipedia.org/wiki/Signe_(arithm%C3%A9tique))
 *        au sens mathématique.
 */
enum class Sign {
  /*!
   * \brief Constante d'énumération destinée à représenter le
   *        signe « plus » (+), c'est-à-dire celui d'un
   *        [nombre (strictement) positif]
   *        (https://fr.wikipedia.org/wiki/Nombre_positif).
   *
   * Lorsqu'on transtype Sign::PLUS en entier, on obtient la
   * valeur +1.
   */
  PLUS = +1,

  /*!
   * \brief Constante d'énumération destinée à représenter le
   *        signe « moins » (-), c'est-à-dire celui d'un
   *        [nombre (strictement) négatif]
   *        (https://fr.wikipedia.org/wiki/Nombre_n%C3%A9gatif).
   *
   * Lorsqu'on transtype Sign::MINUS en entier, on obtient la
   * valeur -1.
   */
  MINUS = -1,

  /*!
   * \brief Constante d'énumération destinée à représenter le
   *        signe du nombre [zéro]
   *        (https://fr.wikipedia.org/wiki/Z%C3%A9ro).
   *
   * Lorsqu'on transtype Sign::ZERO en entier, on obtient la
   * valeur 0.
   */
  ZERO = 0
};

// prototypes (pas vraiment nécesssaire si fonction inline)

/*!
 * \brief Fonction retournant le signe d'un entier donné.
 *
 * \param value l'entier dont on désire le signe.
 *
 * \return le signe de `value`.
 */
constexpr Sign sign(int value);

/*!
 * \brief Fonction retournant le signe opposé d'un signe donné.
 *
 * On a :
 *
 * |    sign     | opposite(sign) |
 * |:-----------:|:--------------:|
 * | Form::PLUS  |  Form::MINUS   |
 * | Form::MINUS |  Form::PLUS    |
 * | Form::ZERO  |  Form::ZERO    |
 *
 * \param sign signe dont on désire obtenir l'opposé.
 *
 * \return le signe opposé de `sign`.
 *
 * \see operator-(Sign).
 */
constexpr Sign opposite(Sign sign);

/*!
 * \brief Opérateur retournant le signe opposé d'un signe donné.
 *
 * On a :
 *
 * |    sign     |     - sign    |
 * |:-----------:|:-------------:|
 * | Form::PLUS  |  Form::MINUS  |
 * | Form::MINUS |  Form::PLUS   |
 * | Form::ZERO  |  Form::ZERO   |
 *
 * \param sign signe dont on désire obtenir l'opposé.
 *
 * \return le signe opposé de `sign`.
 *
 * \see opposite(Sign).
 */
constexpr Sign operator-(Sign sign);

/*!
 * \brief Fonction retournant le signe produit de deux nvs::Sign.
 *
 * La [règle des signes]
 * (https://fr.wikipedia.org/wiki/Signe_(arithm%C3%A9tique)#R%C3%A8gle_des_signes)
 * est étendue pour prendre en compte le signe de zéro :
 *
 * |     lhs     |     rhs     | product(lhs, rhs) |
 * |:-----------:|:-----------:|:-----------------:|
 * | Form::PLUS  | Form::PLUS  |     Form::PLUS    |
 * | Form::PLUS  | Form::MINUS |     Form::MINUS   |
 * | Form::PLUS  | Form::ZERO  |     Form::ZERO    |
 * | Form::MINUS | Form::PLUS  |     Form::MINUS   |
 * | Form::MINUS | Form::MINUS |     Form::PLUS    |
 * | Form::MINUS | Form::ZERO  |     Form::ZERO    |
 * | Form::ZERO  | Form::PLUS  |     Form::ZERO    |
 * | Form::ZERO  | Form::MINUS |     Form::ZERO    |
 * | Form::ZERO  | Form::ZERO  |     Form::ZERO    |
 *
 * \param lhs un premier Sign.
 * \param rhs un second Sign.
 *
 * \return le signe produit de `lhs` et `rhs` comme dans le tableau
 *         ci-dessus.
 *
 * \see operator*(Sign, Sign).
 */
constexpr Sign product(Sign lhs, Sign rhs);

/*!
 * \brief Opérateur retournant le signe produit de deux nvs::Sign.
 *
 * La [règle des signes]
 * (https://fr.wikipedia.org/wiki/Signe_(arithm%C3%A9tique)#R%C3%A8gle_des_signes)
 * est étendue pour prendre en compte le signe de zéro :
 *
 * |     lhs     |     rhs     |    lhs * rhs   |
 * |:-----------:|:-----------:|:--------------:|
 * | Form::PLUS  | Form::PLUS  |   Form::PLUS   |
 * | Form::PLUS  | Form::MINUS |   Form::MINUS  |
 * | Form::PLUS  | Form::ZERO  |   Form::ZERO   |
 * | Form::MINUS | Form::PLUS  |   Form::MINUS  |
 * | Form::MINUS | Form::MINUS |   Form::PLUS   |
 * | Form::MINUS | Form::ZERO  |   Form::ZERO   |
 * | Form::ZERO  | Form::PLUS  |   Form::ZERO   |
 * | Form::ZERO  | Form::MINUS |   Form::ZERO   |
 * | Form::ZERO  | Form::ZERO  |   Form::ZERO   |
 *
 * \param lhs un premier Sign.
 * \param rhs un second Sign.
 *
 * \return le signe produit de `lhs` et `rhs` comme dans le tableau
 *         ci-dessus.
 *
 * \see product(Sign, Sign).
 */
constexpr Sign operator*(Sign lhs, Sign rhs);

/*!
 * \brief Fonction de conversion d'un nvs::Sign en std::string.
 *
 * \param sign le signe à convertir.
 *
 * \return une std::string représentant `sign`.
 */
inline std::string to_string(Sign sign);

/*!
 * \brief Opérateur d'injection d'un nvs::Sign dans un flux en
 *        sortie.
 *
 * \param out le flux dans lequel l'injection est réalisée.
 * \param sign le signe à injecter.
 *
 * \return le flux après injection.
 */
inline std::ostream &operator<<(std::ostream &out, Sign sign);

constexpr Sign sign(int value) {
  if (value < 0)
    return Sign::MINUS;
  if (value > 0) {
    return Sign::PLUS;
  }
  return Sign::ZERO;
}

constexpr Sign opposite(Sign sign) {
  switch (sign) {
    case Sign::PLUS:return Sign::MINUS;
    case Sign::MINUS:return Sign::PLUS;
    case Sign::ZERO:
    default:return Sign::ZERO;
  }
}

constexpr Sign operator-(Sign sign) {
  return opposite(sign);
}

constexpr Sign product(Sign lhs, Sign rhs) {
  if (lhs == Sign::ZERO || rhs == Sign::ZERO)
    return Sign::ZERO;
  if (opposite(lhs) == rhs) {
    return Sign::MINUS;
  }
  return Sign::PLUS;
}

constexpr Sign operator*(Sign lhs, Sign rhs) {
  return product(lhs, rhs);
}

constexpr bool operator<(Sign lhs, Sign rhs) {
  return (lhs == Sign::MINUS && rhs != Sign::MINUS) || (lhs == Sign::ZERO && rhs == Sign::PLUS);
}

inline std::string to_string(Sign sign) {
  switch (sign) {
    case Sign::MINUS:return "MINUS (-)";
    case Sign::PLUS:return "PLUS (+)";
    case Sign::ZERO:
    default:return "ZERO (0)";
  }
}

inline std::ostream &operator<<(std::ostream &out, Sign sign) {
  out << to_string(sign);
  return out;
}
}

#endif // DEV3_SIGN_H
