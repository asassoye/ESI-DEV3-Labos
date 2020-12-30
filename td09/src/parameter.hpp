/**
 * @file parameter.h
 *
 * @author Andrew SASSOYE <andrew@sasoye.be>
 * @copyright Copyright © 2020 Andrew SASSOYE. This project is released under the MIT License.
 */
#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include <ostream>
#include <stdexcept>

/*!
 * @brief Espace de nom du projet Lotto de Nicolas Vansteenkiste.
 */
namespace g54327::lotto
    {

/*!
 * \brief Classe de paramétrage d'un jeu de lotto.
 *
 * La grille du jeu de lotto est caractérisée par
 * trois paramètres :
 *
 *    + la valeur minimale entière positive des valeurs à prédire ;
 *    + la valeur maximale entière positive des valeurs à prédire ;
 *    + le nombre maximal de valeurs à prédire.
 *
 * Les valeurs à prédire sont à choisir parmi tous les entiers
 * compris entre les valeurs minimale et maximale, ces valeurs
 * incluses.
 *
 * Par exemple, avec :
 *
 *    + valeur minimale égale à 6 ;
 *    + valeur maximale égale à 21 ;
 *    + nombre de valeurs à prédire égal à 4 ;
 *
 * il faut prédire 4 valeurs parmi les entiers entre 6 et 21, ces
 * valeurs comprises.
 */
        class Parameter
    {
      public:

      // à partir de c++17, les attributs static peuvent être inline
      // par ailleurs constexpr implique inline dans ce cas.
      // voir les liens suivants :
      // https://stackoverflow.com/a/39653928
      // http://www.nuonsoft.com/blog/2017/08/28/c17-inline-variables/
      /*!
       * \brief Valeur minimale par défaut des chiffres à prédire.
       */
      static constexpr unsigned MINIMUM_DEFAULT_{1};

      /*!
       * \brief Valeur maximale par défaut des chiffres à prédire.
       */
      static constexpr unsigned MAXIMUM_DEFAULT_{50};

      /*!
       * \brief Valeur par défaut du nombre de chiffres à prédire.
       */
      static constexpr unsigned LENGTH_DEFAULT_{8};

      private:

      /*!
       * \brief Valeur minimale des chiffres à prédire.
       *
       * Cette valeur est incluse dans les chiffres à prédire.
       */
      const unsigned minimum_;

      /*!
       * \brief Valeur maximale des chiffres à prédire.
       *
       * Cette valeur est incluse dans les chiffres à prédire.
       * Elle doit être au moins égale à \ref minimum_.
       */
      const unsigned maximum_;

      /*!
       * \brief Nombre de chiffres à prédire.
       *
       * Cette valeur doit se trouver dans l'intervalle
       * [ 1, \ref maximum_ - \ref minimum_ + 1 ] :
       *
       *    + elle ne peut être nulle ;
       *    + elle ne peut être supérieure au nombre de chifres
       *      compris entre les valeurs minimale et maximale.
       */
      const unsigned length_;

      public:

      /*!
       * \brief Constructeur.
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
       */
      constexpr
      explicit Parameter(unsigned length = LENGTH_DEFAULT_,
                         unsigned maximum = MAXIMUM_DEFAULT_,
                         unsigned minimum = MINIMUM_DEFAULT_);

      /*!
       * \brief Accesseur en lecture du minimum des valeurs à prédire.
       *
       * \return minimum des valeurs à prédire.
       */
      constexpr
      unsigned minimum() const;

      /*!
       * \brief Accesseur en lecture du maximum des valeurs à prédire.
       *
       * \return maximum des valeurs à prédire.
       */
      constexpr
      unsigned maximum() const;

      /*!
       * \brief Accesseur en lecture du nombre de valeurs à prédire.
       *
       * \return nombre de valeurs à prédire.
       */
      constexpr
      unsigned length() const;

      /*!
       * \brief Conversion d'un Parameter en std::string.
       *
       * Les valeurs minimale et maximale des valeurs à prédire ainsi
       * que le nombre de valeurs à prédire sont mis en forme
       * et convertis en std::string.
       *
       * \return représentation du Parameter sous la forme d'une
       *         std::string.
       *
       * \see to_string(const Parameter &)
       */
      inline std::string to_string() const;
    };

// prototypes

/*!
 * \brief Conversion d'un Parameter en std::string.
 *
 * Les valeurs minimale et maximale des valeurs à prédire ainsi
 * que le nombre de valeurs à prédire de `parameter` sont mis
 * en forme et convertis en std::string.
 *
 * \param parameter Parameter à convertir.
 *
 * \return représentation de `parameter` sous la forme d'une
 *         std::string.
 *
 * \see Parameter::to_string()
 */
    inline std::string to_string(const Parameter & parameter);

/*!
 * \brief Opérateur d'injection d'un Parameter dans un flux en
 *        sortie.
 *
 * Les valeurs minimale et maximale des valeurs à prédire ainsi
 * que le nombre de valeurs à prédire de `parameter` sont mis en
 * forme et injectés dans `out`.
 *
 * \param out flux dans lequel injecter `parameter`.
 * \param parameter Parameter à injecter.
 *
 * \return flux après injection.
 *
 * \see Parameter::to_string()
 */
    inline std::ostream & operator<<(std::ostream & out,
    const Parameter & parameter);

// implémentation méthodes inline

    constexpr Parameter::Parameter(unsigned length, unsigned maximum,
    unsigned minimum) :
    minimum_ { minimum },
    maximum_ {
      maximum < minimum_ ?
      throw std::invalid_argument
      { "maximum < minimum_" } :
      maximum
    },
    length_ {
      length == 0 ?
      throw std::invalid_argument
      { "length == 0" } :
      maximum_ - minimum_ + 1 < length ?
      throw std::invalid_argument
      {
        "maximum_ - minimum_ + 1 "
        "< length"
      } :
      length
    }
    {}

    constexpr unsigned Parameter::minimum() const
    {
      return minimum_;
    }

    constexpr unsigned Parameter::maximum() const
    {
      return maximum_;
    }

    constexpr unsigned Parameter::length() const
    {
      return length_;
    }

    std::string Parameter::to_string() const
    {
      return std::to_string(length_)
          .append(" : [")
          .append(std::to_string(minimum_))
          .append("..")
          .append(std::to_string((maximum_)))
          .append("]");
    }

// implémentation fonctions inline

    std::string to_string(const Parameter & parameter)
    {
      return parameter.to_string();
    }

    std::ostream & operator<<(std::ostream & out,
    const Parameter & parameter)
    {
      return out << parameter.to_string();
    }

    }

#endif // PARAMETER_H
