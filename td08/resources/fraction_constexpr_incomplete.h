/*!
 * \file fraction_constexpr_incomplete.h
 *
 * \brief Définition de la classe nvs::Fraction ainsi que d'un
 *        type (nvs::Fraction::Form) et de fonctions associées.
 */
#ifndef FRACTION_CONSTEXPR_INCOMPLETE_H
#define FRACTION_CONSTEXPR_INCOMPLETE_H

#include <string>
#include <ostream>
#include <tuple>

// TODO include manquants

#include "sign_incomplete.h"

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 */
namespace nvs {

/*!
 * \brief Classe représentant une [fraction]
 * (https://fr.wikipedia.org/wiki/Fraction_(math%C3%A9matiques)).
 *
 * Comme caractéristique principale, indiquons la sauvegarde du
 * signe sous la forme d'un nvs::Sign tandis que les numérateur
 * et dénominateur sont stockés sous une forme non signée.
 *
 * Par ailleurs, toute fraction est toujours stockée sous forme
 * simplifiée, c'est-à-dire comme une [fraction irréductible]
 * (https://fr.wikipedia.org/wiki/Fraction_irr%C3%A9ductible).
 *
 * Outre les méthodes de la classe Fraction, il existe de
 * multiples fonctions pour les utiliser. Elles sont définies
 * dans l'espace de nom \ref nvs dans le fichier fraction_constexpr.h.
 *
 */
    class Fraction {
        /*!
         * \brief [Signe]
         *        (https://fr.wikipedia.org/wiki/Signe_(arithm%C3%A9tique))
         *        de la fraction.
         */
        const Sign sign_;

        /*!
         * \brief [Valeur absolue]
         *        (https://fr.wikipedia.org/wiki/Valeur_absolue) du
         *        [numérateur]
         *        (https://fr.wikipedia.org/wiki/Num%C3%A9rateur)
         *        obtenu après [réduction de la fraction]
         * (https://fr.wikipedia.org/wiki/Plus_grand_commun_diviseur_de_nombres_entiers#Simplification_de_fractions).
         *
         * Dans la suite, on appelle ce numérateur _numérateur réduit_
         * ou simplement _numérateur_.
         */
        const unsigned numerator_;

        /*!
         * \brief [Valeur absolue]
         *        (https://fr.wikipedia.org/wiki/Valeur_absolue) du
         *        [dénominateur]
         *        (https://fr.wikipedia.org/wiki/D%C3%A9nominateur)
         *        obtenu après [réduction de la fraction]
         * (https://fr.wikipedia.org/wiki/Plus_grand_commun_diviseur_de_nombres_entiers#Simplification_de_fractions).
         *
         * Dans la suite, on appelle ce dénominateur
         * _dénominateur réduit_ ou simplement _dénominateur_.
         */
        const unsigned denominator_;

    public:

        /*!
         * \brief Constructeur avec déduction du signe.
         *
         * Les arguments du constructeur sont ici dénommés numérateur et
         * dénominateur _bruts_.
         *
         * Les attributs \ref numerator_ et \ref denominator_
         * sont obtenus après [réduction]
         * (https://fr.wikipedia.org/wiki/Plus_grand_commun_diviseur_de_nombres_entiers#Simplification_de_fractions)
         * de la fraction brute. L'attribut \ref sign_ est également
         * calculé.
         *
         * Si le dénominateur est nul, une exception
         * std::invalid_argument est levée.
         *
         * Par convention, la fraction correspondant à la valeur zéro,
         * c'est-à-dire de numérateur nul et dénominateur non nul, est
         * représentée avec :
         *   + \ref sign_ égal à Sign::ZERO ;
         *   + \ref numerator_ égal à 0 ;
         *   + \ref denominator_ égal à 1.
         *
         * \param numerator numérateur brut.
         * \param denominator dénominateur brut.
         *
         * \throw std::invalid_argument si `denominator` est nul.
         */
        inline constexpr Fraction(int numerator = 0, int denominator = 1);

        /*!
         * \brief Constructeur avec signe explicite.
         *
         * Les arguments de construction sont le signe et les valeurs
         * absolues des numérateur et dénominateur _bruts_.
         *
         * Les attributs \ref numerator_ et \ref denominator_
         * sont obtenus après [réduction]
         * (https://fr.wikipedia.org/wiki/Plus_grand_commun_diviseur_de_nombres_entiers#Simplification_de_fractions)
         * de la fraction brute.
         *
         * Si le dénominateur est nul, une exception
         * std::invalid_argument est levée.
         *
         * Une exception std::invalid_argument est également levée si
         * le signe fourni est Sign::ZERO alors que la fraction,
         * plus précisément le numérateur, n'est pas nulle. Par
         * contre, si le numérateur fourni est nul, l'attribut
         * \ref sign_ est mis à Sign::ZERO, quelle que soit la valeur
         * du paramètre `sign`.
         *
         * Par convention, la fraction correspondant à la valeur zéro,
         * c'est-à-dire de numérateur nul et dénominateur non nul, est
         * représentée avec :
         *   + \ref sign_ égal à Sign::ZERO ;
         *   + \ref numerator_ égal à 0 ;
         *   + \ref denominator_ égal à 1.
         *
         * \param sign signe de la fraction à construire.
         * \param numerator valeur absolue du numérateur brut.
         * \param denominator valeur absolue du dénominateur brut.
         *
         * \throw std::invalid_argument si
         *      + `denominator` est nul ;
         *      + `sign` est Sign::ZERO alors que `numerator` n'est pas
         *        nul.
         */
        inline constexpr Fraction(Sign sign, unsigned numerator = 0,
                                  unsigned denominator = 1);

        /*!
         * \brief Accesseur en lecture du signe.
         *
         * \return le signe de la fraction.
         */
        inline constexpr Sign sign() const;

        /*!
         * \brief Accesseur en lecture du numérateur.
         *
         * Le numérateur retourné est toujours le numérateur réduit.
         *
         * \return le numérateur réduit de la fraction.
         */
        inline constexpr unsigned numerator() const;

        /*!
         * \brief Accesseur en lecture du dénominateur.
         *
         * Le dénominateur retourné est toujours le dénominateur réduit.
         *
         * \return le dénominateur réduit de la fraction.
         */
        inline constexpr unsigned denominator() const;

        /*!
         * \brief Accesseur en lecture sous la forme _unité_ +
         *        _partie fractionnaire_.
         *
         * Le premier champ du std::tuple retourné est le signe de
         * la fraction.
         *
         * Par exemple :
         *    + pour la fraction 5 / 6, ce premier champ vaut
         *      Sign::PLUS car 5 / 6 > 0 ;
         *    + pour la fraction 15 / 6, ce premier champ vaut
         *      Sign::PLUS car 15 / 6 > 0 ;
         *    + pour la fraction 0 / 6, ce premier champ vaut
         *      Sign::ZERO car 0 / 6 = 0 ;
         *    + pour la fraction - 18 / 6, ce premier champ vaut
         *      Sign::MINUS car - 18 / 6 < 0 ;
         *    + pour la fraction - 23 / 6, ce premier champ vaut
         *      Sign::MINUS car - 23 / 6 < 0.
         *
         * Le deuxième champ du std::tuple retourné est le nombre
         * d'unités de la valeur absolue de la fraction. Plus
         * précisément, c'est le plus grand naturel
         * inférieur ou égal à la valeur absolue de la fraction.
         *
         * Par exemple :
         *    + pour la fraction 5 / 6, ce deuxième champ vaut 0
         *      car 0 <= 5 / 6 < 1 ;
         *    + pour la fraction 15 / 6, ce deuxième champ vaut 2
         *      car 2 <= 15 / 6 < 3 ;
         *    + pour la fraction 0 / 6, ce deuxième champ vaut 0
         *      car 0 <= 0 / 6 < 1 ;
         *    + pour la fraction - 18 / 6, ce deuxième champ vaut 3
         *      car 3 <= 18 / 6 < 4 ;
         *    + pour la fraction - 23 / 6, ce deuxième champ vaut 3
         *      car 3 <= 23 / 6 < 4.
         *
         * Le troisième champ du std::tuple retourné est le numérateur
         * de la fraction réduite obtenue lorsqu'on soustrait le nombre
         * d'unités, c'est-à-dire le deuxième champ, de la valeur absolue
         * de la fraction de départ.
         *
         * Par exemple :
         *    + pour la fraction 5 / 6, ce troisième champ vaut 5 car
         *      5 / 6 - 0 = 5 / 6 ;
         *    + pour la fraction 15 / 6, ce troisième champ vaut 1 car
         *      15 / 6 - 2 = 1 / 2 ;
         *    + pour la fraction 0 / 6, ce troisième champ vaut 0 car
         *      0 / 6 - 0 = 0 ;
         *    + pour la fraction - 18 / 6, ce troisième champ vaut 0 car
         *      18 / 6 - 3 = 0 ;
         *    + pour la fraction - 23 / 6, ce troisième champ vaut 5 car
         *      23 / 6 - 3 = 5 / 6.
         *
         * Le quatrième champ du std::tuple retourné est le dénominateur
         * de la fraction réduite obtenue lorsqu'on soustrait le nombre
         * d'unités, c'est-à-dire le deuxième champ, de la valeur absolue
         * de la fraction de départ.
         *
         * Par exemple :
         *    + pour la fraction 5 / 6, ce quatrième champ vaut 6 car
         *      5 / 6 - 0 = 5 / 6 ;
         *    + pour la fraction 15 / 6, ce quatrième champ vaut 2 car
         *      15 / 6 - 2 = 1 / 2 ;
         *    + pour la fraction 0 / 6, ce quatrième champ vaut 1 car
         *      0 / 6 - 0 = 0 / 1 ;
         *    + pour la fraction - 18 / 6, ce quatrième champ vaut 1 car
         *      18 / 6 - 3 = 0 / 1 ;
         *    + pour la fraction - 23 / 6, ce quatrième champ vaut 6 car
         *      23 / 6 - 3 = 5 / 6.
         *
         * En résumé et par exemple :
         *    + pour la fraction 5 / 6, le std::tuple retourné vaut
         *      <Sign::PLUS, 0, 5, 6> ;
         *    + pour la fraction 15 / 6, le std::tuple retourné vaut
         *      <Sign::PLUS, 2, 1, 2> ;
         *    + pour la fraction 0 / 6, le std::tuple retourné vaut
         *      <Sign::ZERO, 0, 0, 1> ;
         *    + pour la fraction - 18 / 6, le std::tuple retourné vaut
         *      <Sign::MINUS, 3, 0, 1> ;
         *    + pour la fraction - 23 / 6, le std::tuple retourné vaut
         *      <Sign::MINUS, 3, 5, 6>.
         *
         * \return un std::tuple représentant la fraction sous la
         *         forme <signe, unités, numérateur, dénominateur>
         *         tel que décrit ci-dessus.
         *
         * \see unit_form(const Fraction &).
         */
        inline constexpr std::tuple<Sign, unsigned, unsigned, unsigned>
        unit_form() const;

        /*!
         * \brief Conversion d'une Fraction en std::string.
         *
         * Si le dénominateur vaut 1, il n'est pas utilisé. Par exemple,
         * la fraction « - 2 / 1 » est représentée par la std::string
         * « - 2 ».
         *
         * \return une std::string représentant la fraction.
         *
         * \see to_string(const Fraction &).
         */
        inline std::string to_string() const;

        /*!
         * \brief Conversion d'une Fraction en double.
         */
        inline constexpr explicit operator double() const;
    };

// prototypes

/*!
 * \brief Calcul de la [valeur absolue]
 *        (https://fr.wikipedia.org/wiki/Valeur_absolue)
 *        d'une fraction.
 *
 * \param fraction fraction dont on désire connaitre la valeur
 *        absolue.
 *
 * \return la valeur absolue de `fraction`.
 */
    constexpr Fraction abs(const Fraction &fraction);

/*!
 * \brief Expression d'une fraction sous la forme _unité_ +
 *        _partie fractionnaire_.
 *
 * Le premier champ du std::tuple retourné est le signe de
 * la fraction.
 *
 * Par exemple :
 *    + pour la fraction 5 / 6, ce premier champ vaut
 *      Sign::PLUS car 5 / 6 > 0 ;
 *    + pour la fraction 15 / 6, ce premier champ vaut
 *      Sign::PLUS car 15 / 6 > 0 ;
 *    + pour la fraction 0 / 6, ce premier champ vaut
 *      Sign::ZERO car 0 / 6 = 0 ;
 *    + pour la fraction - 18 / 6, ce premier champ vaut
 *      Sign::MINUS car - 18 / 6 < 0 ;
 *    + pour la fraction - 23 / 6, ce premier champ vaut
 *      Sign::MINUS car - 23 / 6 < 0.
 *
 * Le deuxième champ du std::tuple retourné est le nombre
 * d'unités de la valeur absolue de la fraction. Plus
 * précisément, c'est le plus grand naturel
 * inférieur ou égal à la valeur absolue de la fraction.
 *
 * Par exemple :
 *    + pour la fraction 5 / 6, ce deuxième champ vaut 0
 *      car 0 <= 5 / 6 > 1 ;
 *    + pour la fraction 15 / 6, ce deuxième champ vaut 2
 *      car 2 <= 15 / 6 < 3 ;
 *    + pour la fraction 0 / 6, ce deuxième champ vaut 0
 *      car 0 <= 0 / 6 < 1 ;
 *    + pour la fraction - 18 / 6, ce deuxième champ vaut 3
 *      car 3 <= 18 / 6 < 4 ;
 *    + pour la fraction - 23 / 6, ce deuxième champ vaut 3
 *      car 3 <= 23 / 6 < 4.
 *
 * Le troisième champ du std::tuple retourné est le numérateur
 * de la fraction réduite obtenue lorsqu'on soustrait le nombre
 * d'unités, c'est-à-dire le deuxième champ, de la valeur absolue
 * de la fraction de départ.
 *
 * Par exemple :
 *    + pour la fraction 5 / 6, ce troisième champ vaut 5 car
 *      5 / 6 - 0 = 5 / 6 ;
 *    + pour la fraction 15 / 6, ce troisième champ vaut 1 car
 *      15 / 6 - 2 = 1 / 2 ;
 *    + pour la fraction 0 / 6, ce troisième champ vaut 0 car
 *      0 / 6 - 0 = 0 ;
 *    + pour la fraction - 18 / 6, ce troisième champ vaut 0 car
 *      18 / 6 - 3 = 0 ;
 *    + pour la fraction - 23 / 6, ce troisième champ vaut 5 car
 *      23 / 6 - 3 = 5 / 6.
 *
 * Le quatrième champ du std::tuple retourné est le dénominateur
 * de la fraction réduite obtenue lorsqu'on soustrait le nombre
 * d'unités, c'est-à-dire le deuxième champ, de la valeur absolue
 * de la fraction de départ.
 *
 * Par exemple :
 *    + pour la fraction 5 / 6, ce quatrième champ vaut 6 car
 *      5 / 6 - 0 = 5 / 6 ;
 *    + pour la fraction 15 / 6, ce quatrième champ vaut 2 car
 *      15 / 6 - 2 = 1 / 2 ;
 *    + pour la fraction 0 / 6, ce quatrième champ vaut 1 car
 *      0 / 6 - 0 = 0 / 1 ;
 *    + pour la fraction - 18 / 6, ce quatrième champ vaut 1 car
 *      18 / 6 - 3 = 0 / 1 ;
 *    + pour la fraction - 23 / 6, ce quatrième champ vaut 6 car
 *      23 / 6 - 3 = 5 / 6.
 *
 * En résumé et par exemple :
 *    + pour la fraction 5 / 6, le std::tuple retourné vaut
 *      <Sign::PLUS, 0, 5, 6> ;
 *    + pour la fraction 15 / 6, le std::tuple retourné vaut
 *      <Sign::PLUS, 2, 1, 2> ;
 *    + pour la fraction 0 / 6, le std::tuple retourné vaut
 *      <Sign::ZERO, 0, 0, 1> ;
 *    + pour la fraction - 18 / 6, le std::tuple retourné vaut
 *      <Sign::MINUS, 3, 0, 1> ;
 *    + pour la fraction - 23 / 6, le std::tuple retourné vaut
 *      <Sign::MINUS, 3, 5, 6>.
 *
 * \param fraction fraction dont on désire la forme _unité_ +
 *                 _partie fractionnaire_.
 *
 * \return un std::tuple représentant la fraction sous la
 *         forme <signe, unités, numérateur, dénominateur>
 *         tel que décrit ci-dessus.
 *
 * \see Fraction::unit_form().
 */
    constexpr std::tuple<Sign, unsigned, unsigned, unsigned>
    unit_form(const Fraction &fraction);

/*!
 * \brief Conversion d'une Fraction en std::string.
 *
 * Si le dénominateur vaut 1, il n'est pas utilisé. Par exemple,
 * la fraction « - 2 / 1 » est représentée par la std::string
 * « - 2 ».
 *
 * \param fraction fraction dont on désire la conversion en
 *                 std::string.
 *
 * \return une std::string représentant `fraction`.
 *
 * \see Fraction::to_string().
 */
    inline std::string to_string(const Fraction &fraction);

/*!
 * \brief Opérateur d'injection d'une Fraction dans un flux en
 *        sortie.
 *
 * \param out flux dans lequel l'injection est réalisée.
 * \param fraction fraction à injecter.
 *
 * \return le flux après injection.
 */
    inline std::ostream &operator<<(std::ostream &out,
                                    const Fraction &fraction);

/*!
 * \brief Opérateur de comparaison pour tester l'égalité de deux
 *        fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction
 *
 * \return `true` si `lhs` et `rhs` sont égales, `false` sinon.
 */
    inline constexpr bool operator==(const Fraction &lhs,
                                     const Fraction &rhs);

/*!
 * \brief Opérateur de comparaison pour tester la différence de deux
 *        fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction
 *
 * \return `true` si `lhs` et `rhs` sont différentes, `false` sinon.
 */
    inline constexpr bool operator!=(const Fraction &lhs,
                                     const Fraction &rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        strictement inférieur de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction
 *
 * \return `true` si `lhs` est strictement inférieure à `rhs`,
 *         `false` sinon.
 */
    inline constexpr bool operator<(const Fraction &lhs,
                                    const Fraction &rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        inférieur ou égal de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction
 *
 * \return `true` si `lhs` est inférieure ou égale à `rhs`,
 *         `false` sinon.
 */
    inline constexpr bool operator<=(const Fraction &lhs,
                                     const Fraction &rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        strictement supérieur de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction
 *
 * \return `true` si `lhs` est strictement supérieur à `rhs`,
 *         `false` sinon.
 */
    inline constexpr bool operator>(const Fraction &lhs,
                                    const Fraction &rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        supérieur ou égal de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction
 *
 * \return `true` si `lhs` est supérieur ou égal à `rhs`,
 *         `false` sinon.
 */
    inline constexpr bool operator>=(const Fraction &lhs,
                                     const Fraction &rhs);

/*!
 * \brief Opérateur unaire identique.
 *
 * \param fraction une fraction.
 *
 * \return `fraction`.
 */
    inline constexpr Fraction operator+(const Fraction &fraction);

/*!
 * \brief Opérateur unaire opposé.
 *
 * \param fraction une fraction.
 *
 * \return l'opposé de `fraction`.
 */
    inline constexpr Fraction operator-(const Fraction &fraction);

/*!
 * \brief Opérateur arithmétique d'[addition]
 *        (https://en.wikipedia.org/wiki/Fraction_(mathematics)#Addition)
 *        de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction.
 *
 * \return la fraction égale à la somme de `lhs` et `rhs`.
 */
    inline constexpr Fraction operator+(const Fraction &lhs,
                                        const Fraction &rhs);

/*!
 * \brief Opérateur arithmétique de [soustraction]
 *        (https://en.wikipedia.org/wiki/Fraction_(mathematics)#Subtraction)
 *        de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction.
 *
 * \return la fraction égale à la soustraction de `rhs` à `lhs`.
 */
    inline constexpr Fraction operator-(const Fraction &lhs,
                                        const Fraction &rhs);

/*!
 * \brief Opérateur arithmétique de [multiplication]
 *        (https://en.wikipedia.org/wiki/Fraction_(mathematics)#Multiplication)
 *        de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction.
 *
 * \return la fraction égale au produit de `lhs` par `rhs`.
 */
    inline constexpr Fraction operator*(const Fraction &lhs,
                                        const Fraction &rhs);

/*!
 * \brief Opérateur arithmétique de [division]
 *        (https://en.wikipedia.org/wiki/Fraction_(mathematics)#Division)
 *        de deux fractions.
 *
 * \param lhs une fraction.
 * \param rhs une fraction.
 *
 * \return la fraction égale à la division de `lhs` par `rhs`.
 *
 * \throw std::invalid_argument si `rhs` est nul.
 */
    inline constexpr Fraction operator/(const Fraction &lhs,
                                        const Fraction &rhs);

// implémentation de fonctions inline

    constexpr Fraction abs(const Fraction &fraction) {
        // TODO
        return {};
    }

    constexpr std::tuple<Sign, unsigned, unsigned, unsigned>
    unit_form(const Fraction &fraction) {
        // TODO
        return {};
    }

    std::string to_string(const Fraction &fraction) {
        // TODO
        return {};
    }

    std::ostream &operator<<(std::ostream &out,
                             const Fraction &fraction) {
        // TODO
        return out;
    }

    constexpr bool operator==(const Fraction &lhs,
                              const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr bool operator!=(const Fraction &lhs,
                              const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr bool operator<(const Fraction &lhs,
                             const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr bool operator<=(const Fraction &lhs,
                              const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr bool operator>(const Fraction &lhs,
                             const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr bool operator>=(const Fraction &lhs,
                              const Fraction &rhs) {
        // TODO
        return {};
    }

    inline constexpr Fraction operator+(const Fraction &fraction) {
        // TODO
        return {};
    }

    inline constexpr Fraction operator-(const Fraction &fraction) {
        // TODO
        return {};
    }

    constexpr Fraction operator+(const Fraction &lhs,
                                 const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr Fraction operator-(const Fraction &lhs,
                                 const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr Fraction operator*(const Fraction &lhs,
                                 const Fraction &rhs) {
        // TODO
        return {};
    }

    constexpr Fraction operator/(const Fraction &lhs,
                                 const Fraction &rhs) {
        // TODO
        return {};
    }

// implémentation de méthodes inline

    constexpr Fraction::Fraction(int numerator, int denominator) :
    // TODO
            sign_{},
            numerator_{},
            denominator_{} {}

    constexpr Fraction::Fraction(Sign sign, unsigned numerator,
                                 unsigned denominator) :
    // TODO
            sign_{},
            numerator_{},
            denominator_{} {}

    constexpr Sign Fraction::sign() const {
        // TODO
        return {};
    }

    constexpr unsigned Fraction::numerator() const {
        // TODO
        return {};
    }

    constexpr unsigned Fraction::denominator() const {
        // TODO
        return {};
    }

    constexpr std::tuple<Sign, unsigned, unsigned, unsigned>
    Fraction::unit_form() const {
        // TODO
        return {};
    }

    std::string Fraction::to_string() const {
        // TODO
        return {};
    }

    constexpr Fraction::operator double() const {
        // TODO
        return {};
    }

} // namespace nvs

#endif // FRACTION_CONSTEXPR_INCOMPLETE_H
