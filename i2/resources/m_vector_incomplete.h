/*!
 * \file m_vector.h
 *
 * \brief Définition de la classe m_vector.
 */
#ifndef M_VECTOR_H
#define M_VECTOR_H

#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <ostream>

// TODO : éventuellement ajouter include

namespace he2b::nvs {

/*!
 * \brief Classe représentant un
 *        [vecteur] (https://fr.wikipedia.org/wiki/Vecteur)
 *        au sens mathématique.
 *
 * Dans la documentation, le terme _vecteur_ fait toujours référence
 * à un vecteur au sens mathématique. Pour parler du conteneur standard
 * std::vector, les termes _std::vector_ sont utilisés.
 *
 * Le _nombre_ de [composantes]
 * (https://fr.wikipedia.org/wiki/Composantes_d%27un_vecteur) du vecteur
 * doit au moins être égal à un. Il n'a pas de limite supérieure.
 * Il est fixé à la création du vecteur et ne change jamais.
 * Il est stocké dans l'attribut \ref size_.
 *
 * Les _valeurs_ des composantes du vecteur sont stockées dans un
 * std::vector de `double`s.
 * Elles se trouvent dans l'attribut \ref data_.
 *
 * Pour ce qui concerne le calcul du produit scalaire
 * (voir operator *(const m_vector &, const m_vector &)) et de la norme
 * (voir norm(const m_vector &) et m_vector::operator double()),
 * on considère que les composantes sont données dans une base
 * orthonormée.
 *
 * Par exemple, dans un espace à 3 dimensions, donc à 3 composantes,
 * le vecteur :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      -1.2 \\
 *                      8.34 \\
 *                      4.1
 *                \end{pmatrix}
 * \f]
 *
 * est ici représenté par un objet dont :
 *
 * + l'attribut \ref size_ est égal à 3 ;
 * + l'attribut \ref data_ est le std::vector de contenu
 *   { -1.2, 8.34, 4.1 }.
 */
class m_vector {
  /*!
   * \brief Nombre de composantes du vecteur.
   *
   * Ce nombre est immuable.
   */
  const std::size_t size_;

  /*!
   * \brief Valeurs des composantes du vecteur.
   *
   * Le nombre de composantes est stocké dans \ref size_. Il y a
   * redondance avec la valeur retournée par std::vector::size().
   */
  std::vector<double> data_;

  /*!
   * \brief Validation d'une valeur d'index.
   *
   * Si la valeur d'index est strictement inférieure à \ref size_,
   * rien ne se passe, la fonction retourne simplement. Dans
   * le cas contraire une exception de type std::invalid_argument
   * est levée avec un message renseignant la valeur de l'index
   * erroné et la valeur de \ref size_.
   *
   * \param index index à tester.
   *
   * \throw std::invalid_argument si l'index égale ou excède
   *        le nombre de composantes du vecteur.
   */
  inline void validate_index(std::size_t index) const;

 public:

  /*!
   * \brief Constructeur.
   *
   * Seul le nombre de composantes est renseigné. Toutes les
   * composantes sont mises à zéro.
   *
   * Le nombre de composantes ne peut être nul.
   *
   * \param size nombre de composantes du vecteur.
   *
   * \throw std::invalid_argument si `size` est nul.
   */
  inline explicit m_vector(std::size_t size);

  /*!
   * \brief Constructeur.
   *
   * Le nombre de composantes et la valeur de celles-ci, identiques
   * pour toutes les composantes, sont fournis.
   *
   * Le nombre de composantes ne peut être nul.
   *
   * \param size nombre de composantes du vecteur.
   * \param value valeur (unique et identique) des composantes du
   *        vecteur.
   *
   * \throw std::invalid_argument si `size` est nul.
   */
  inline m_vector(std::size_t size, double value);

  /*!
   * \brief Constructeur.
   *
   * Les valeurs des composantes sont fournies via une
   * std::initializer_list de `double`s. Le nombre de composantes
   * en est déduit.
   *
   * Le nombre de composantes ne peut être nul.
   *
   * \param data liste des composantes du vecteur. Elle ne peut être
   *        vide.
   *
   * \throw std::invalid_argument si `data` est vide.
   */
  inline m_vector(std::initializer_list<double> data);

  /*!
   * \brief Constructeur.
   *
   * Les valeurs des composantes sont fournies via un
   * std::vector de `double`s. Le nombre de composantes
   * en est déduit.
   *
   * Le nombre de composantes ne peut être nul.
   *
   * \param data std::vector des composantes du vecteur. Il ne peut être
   *        vide.
   *
   * \throw std::invalid_argument si `data` est vide.
   */
  inline m_vector(std::vector<double> data);

  /*!
   * \brief Accesseur en lecture du nombre de composantes.
   *
   * \return nombre de composantes du vecteur.
   */
  inline std::size_t size() const;

  /*!
   * \brief Méthode de comparaison du nombre de composantes.
   *
   * \param v vecteur à comparer au vecteur courant.
   *
   * \return `true` si `v` possède le même nombre de composantes
   *         que le vecteur courant, `false` sinon.
   */
  inline bool equal_size(const m_vector &v) const;

  /*!
   * \brief Accesseur en lecture des valeurs des composantes.
   *
   * \return valeurs des composantes du vecteur.
   */
  inline const std::vector<double> &data() const;

  /*!
   * \brief Accesseur en écriture des valeurs des composantes.
   *
   * Le nombre de nouvelles composantes doit exactement être
   * égal au nombre de composantes du vecteur courant. Si ce n'est pas
   * le cas, les valeurs des composantes ne sont pas modifiées
   * et une exception de type std::invalid_argument est levée
   * avec un message renseignant le nombre de valeurs de `new_data`
   * et celui du vecteur courant.
   *
   * \param new_data nouvelles valeurs des composantes.
   *
   * \throw std::invalid_argument si le nombre de composantes
   *        de `new_data` et du vecteur courant ne sont pas égaux.
   *
   * \see m_vector::equal_size().
   * \see validate_size(const m_vector &, const m_vector &).
   */
  inline void data(const std::vector<double> &new_data);

  /*!
   * \brief Accesseur en lecture d'une composante du vecteur.
   *
   * La première composante est d'index 0. La dernière d'index
   * \ref size_ - 1.
   *
   * Si `index` est supérieur ou égal à \ref size_, le comportement
   * de la méthode est indéterminé.
   *
   * \param index index de la composante voulue.
   *
   * \return valeur de la composante d'index `index`.
   */
  inline double operator[](std::size_t index) const;

  /*!
   * \brief Accesseur en écriture d'une composante du vecteur.
   *
   * La première composante est d'index 0. La dernière d'index
   * \ref size_ - 1.
   *
   * Si `index` est supérieur ou égal à \ref size_, le comportement
   * de la méthode est indéterminé.
   *
   * \param index index de la composante voulue.
   *
   * \return référence vers la valeur de la composante d'index `index`.
   */
  inline double &operator[](std::size_t index);

  /*!
   * \brief Accesseur en lecture d'une composante du vecteur.
   *
   * La première composante est d'index 0. La dernière d'index
   * \ref size_ - 1.
   *
   * Si `index` est supérieur ou égal à \ref size_, une exception
   * de type std::invalid_argument est levée avec un message
   * renseignant la valeur de l'index erroné et la valeur de
   * \ref size_.
   *
   * \param index index de la composante voulue.
   *
   * \return valeur de la composante d'index `index`.
   *
   * \throw std::invalid_argument si l'index égale ou excède
   *        le nombre de composantes du vecteur.
   *
   * \see m_vector::validate_index().
   */
  inline double at(std::size_t index) const;

  /*!
   * \brief Accesseur en écriture d'une composante du vecteur.
   *
   * La première composante est d'index 0. La dernière d'index
   * \ref size_ - 1.
   *
   * Si `index` est supérieur ou égal à \ref size_, une exception
   * de type std::invalid_argument est levée avec un message
   * renseignant la valeur de l'index erroné et la valeur de
   * \ref size_.
   *
   * \param index index de la composante voulue.
   *
   * \return référence vers la valeur de la composante d'index `index`.
   *
   * \throw std::invalid_argument si l'index égale ou excède
   *        le nombre de composantes du vecteur.
   *
   * \see m_vector::validate_index().
   */
  inline double &at(std::size_t index);

  /*!
  * \brief Représentation d'un vecteur sous la forme d'une chaîne
  *        de caractères.
  *
  * Le nombre de composantes puis les valeurs de chancune d'elles
  * sont convertis en chaîne de caractères bien mise en forme.
  *
  * \return std::string représentant le vecteur courant.
  */
  inline std::string to_string() const;

  /*!
   * \brief Conversion du vecteur en `double`.
   *
   * La valeur retournée est celle de la norme du vecteur.
   *
   * \see norm(const m_vector &).
   */
  inline explicit operator double() const;
};

// prototypes

/*!
 * \brief Opérateur d'injection d'un vecteur dans un flux en sortie.
 *
 * Le nombre de composantes puis les valeurs de chancune d'elles,
 * bien mis en forme, sont injectés dans le flux.
 *
 * \param out flux dans lequel le vecteur est injecté.
 * \param v vecteur à injecter.
 *
 * \return flux après injection.
 *
 * \see m_vector::to_string().
 */
inline std::ostream &operator<<(std::ostream &out,
                                const m_vector &v);

/*!
 * \brief Représentation d'un vecteur sous la forme d'une chaîne
 *        de caractères.
 *
 * Le nombre de composantes de `v` puis les valeurs de chancune d'elles
 * sont convertis en chaîne de caractères bien mise en forme.
 *
 * \param v vecteur à convertir en chaîne de caractères.
 *
 * \return std::string représentant `v`.
 *
 * \see m_vector::to_string().
 */
inline std::string to_string(const m_vector &v);

/*!
 * \brief Test de l'égalité du nombre de composantes de deux vecteurs.
 *
 * \param lhs premier vecteur.
 * \param rhs second vecteur.
 *
 * \return `true` si `lhs` et `rhs` ont même nombre de composantes.
 *
 * \see m_vector::equal_size().
 */
inline bool equal_size(const m_vector &lhs, const m_vector &rhs);

/*!
 * \brief Validation de l'égalité du nombre de composantes de deux
 *        vecteurs.
 *
 * Si le nombre de composantes de `lhs` et de `rhs` sont égaux,
 * rien ne se passe, la fonction retourne simplement. Dans
 * le cas contraire une exception de type std::invalid_argument
 * est levée avec un message renseignant le nombre de composantes
 * de `lhs` et celui de `rhs`.
 *
 * \param lhs premier vecteur.
 * \param rhs second vecteur.
 *
 * \throw std::invalid_argument si le nombre de composantes de `lhs`
 *        diffère de celui de `rhs`.
 *
 * \see equal_size(const m_vector &, const m_vector &).
 */
inline void validate_size(const m_vector &lhs, const m_vector &rhs);

/*!
 * \brief Multiplication d'un vecteur par un nombre.
 *
 * Cet opérateur retourne le vecteur obtenu en multipliant le vecteur
 * `v` par le `double` `d`.
 *
 * En toute généralité, si `d` a pour valeur \f$ d \f$ et le vecteur
 * représenté par `v` est \f$ \vec{v} \f$ qui possède \f$ n \f$
 * composantes :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      v_0 \\
 *                      v_1 \\
 *                      \ldots \\
 *                      v_n
 *                \end{pmatrix}
 * \f]
 *
 * alors le vecteur retourné a pour composantes celles de
 * \f$ d \, \vec{v} \f$ :
 *
 * \f[
 *      d \, \vec{v} = \begin{pmatrix}
 *                      d \, v_0 \\
 *                      d \, v_1 \\
 *                      \ldots \\
 *                      d \, v_n
 *                  \end{pmatrix}
 * \f]
 *
 * Par exemple, si `d` vaut 3.1 et le vecteur représenté par `v` est
 * \f$ \vec{v} \f$ de composantes :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      4.5 \\
 *                      8.1 \\
 *                      -2.6
 *                \end{pmatrix}
 * \f]
 *
 * alors le vecteur retourné est celui de composantes :
 *
 * \f[
 *      d \, \vec{v} = \begin{pmatrix}
 *                      3.1 \times 4.5 \\
 *                      3.1 \times 8.1 \\
 *                      3.1 \times -2.6
 *                  \end{pmatrix}
 *                 = \begin{pmatrix}
 *                      13.95 \\
 *                      25.11 \\
 *                      -8.06
 *                  \end{pmatrix}
 * \f]
 *
 * \param d nombre.
 * \param v vecteur.
 *
 * \return vecteur obtenu en multipliant `v` par `d`.
 *
 * \see operator*(const m_vector &, double).
 */
inline m_vector operator*(double d, const m_vector &v);

/*!
 * \brief Multiplication d'un vecteur par un nombre.
 *
 * \param v vecteur.
 * \param d nombre.
 *
 * \return vecteur obtenu en multipliant `v` par `d`.
 *
 * \see operator*(double, const m_vector &).
 */
inline m_vector operator*(const m_vector &v, double d);

/*!
 * \brief Produit scalaire de vecteurs.
 *
 * Si le nombre de composantes des vecteurs représentés par `lhs` et
 * `rhs` ne sont pas égaux, une exception de type std::invalid_argument
 * est levée avec un message renseignant le nombre de composantes
 * de `lhs` et celui de `rhs`.
 *
 * Dans le cas contraire, si `lhs` et `lhs` ont même nombre de
 * composantes, la suite s'applique.
 *
 * On considère que les composantes du vecteur sont relatives
 * à une [base orthonormée]
 * (https://fr.wikipedia.org/wiki/Base_orthonorm%C3%A9e).
 *
 * Dans une telle base, avec \f$ \vec{v} \f$ le vecteur représenté par
 * `lhs` :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      v_0 \\
 *                      v_1 \\
 *                      \ldots \\
 *                      v_n
 *                \end{pmatrix}
 * \f]
 *
 * et \f$ \vec{r} \f$ le vecteur représenté par `rhs` :
 *
 * \f[
 *      \vec{r} = \begin{pmatrix}
 *                      r_0 \\
 *                      r_1 \\
 *                      \ldots \\
 *                      r_n
 *                \end{pmatrix}
 * \f]
 *
 * le [produit scalaire]
 * (https://fr.wikipedia.org/wiki/Produit_scalaire#Base_orthonormale)
 * \f$ \vec{v} \cdot \vec{r} \f$ est le nombre égal à :
 *
 * \f[
 *  \vec{v} \cdot \vec{r} = \begin{pmatrix}
 *                              v_0 \\
 *                              v_1 \\
 *                              \ldots \\
 *                              v_n
 *                          \end{pmatrix}
 *                          \cdot
 *                          \begin{pmatrix}
 *                              r_0 \\
 *                              r_1 \\
 *                              \ldots \\
 *                              r_n
 *                          \end{pmatrix}
 *                        = v_0 \, r_0 + v_1 \, r_1 + \ldots + v_n \, r_n
 *                        = \sum_{i = 0}^{n} v_i \, r_i
 * \f]
 *
 * Par exemple, si le vecteur représenté par `lhs` est \f$ \vec{v} \f$
 * et a pour composantes :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      4.5 \\
 *                      8.1 \\
 *                      -2.6
 *                \end{pmatrix}
 * \f]
 *
 * et `rhs` représente \f$ \vec{r} \f$ de composantes :
 *
 * \f[
 *      \vec{r} = \begin{pmatrix}
 *                      -1.6 \\
 *                      0.0 \\
 *                      -2.7
 *                \end{pmatrix}
 * \f]
 *
 * alors le produit scalaire \f$ \vec{v} \cdot \vec{r} \f$ retourné est
 * égal à :
 *
 * \f[
 *      \vec{v} \cdot \vec{r} = \begin{pmatrix}
 *                                  4.5 \\
 *                                  8.1 \\
 *                                  -2.6
 *                              \end{pmatrix}
 *                              \cdot
 *                              \begin{pmatrix}
 *                                  -1.6 \\
 *                                  0.0 \\
 *                                  -2.7
 *                              \end{pmatrix}
 *                            = 4.5 \times -1.6 + 8.1 \times 0.0 +
 *                                      -2.6 \times -2.7
 *                            = -7.2 + 0.0 + 7.02
 *                            = -0.18
 * \f]
 *
 * \param lhs vecteur.
 * \param rhs vecteur.
 *
 * \return produit scalaire des vecteurs représentés par `lhs` et `rhs`.
 *
 * \throw std::invalid_argument si le nombre de composantes de `lhs`
 *        diffère de celui de `rhs`.
 *
 * \see validate_size(const m_vector &, const m_vector &).
 */
inline double operator*(const m_vector &lhs, const m_vector &rhs);

/*!
 * \brief Norme d'un vecteur.
 *
 * On considère que les composantes du vecteur sont relatives
 * à une [base orthonormée]
 * (https://fr.wikipedia.org/wiki/Base_orthonorm%C3%A9e).
 *
 * La [norme (euclidienne)]
 * (https://fr.wikipedia.org/wiki/Produit_scalaire#D%C3%A9finitions_et_premi%C3%A8res_propri%C3%A9t%C3%A9s)
 * d'un vecteur est égale à la racine carrée du produit scalaire
 * de ce vecteur avec lui-même.
 *
 * Dans une base orthonormée, avec \f$ \vec{v} \f$ le vecteur représenté
 * par `v` :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      v_0 \\
 *                      v_1 \\
 *                      \ldots \\
 *                      v_n
 *                \end{pmatrix}
 * \f]
 *
 * sa norme \f$ \| \vec{v} \| \f$  est égale à :
 *
 * \f[
 *  \| \vec{v} \| = \sqrt{\vec{v} \cdot \vec{v}}
 *                = \sqrt{\begin{pmatrix}
 *                              v_0 \\
 *                              v_1 \\
 *                              \ldots \\
 *                              v_n
 *                        \end{pmatrix}
 *                        \cdot
 *                        \begin{pmatrix}
 *                              v_0 \\
 *                              v_1 \\
 *                              \ldots \\
 *                              v_n
 *                        \end{pmatrix}}
 *                = \sqrt{v_0 \, v_0 + v_1 \, v_1 + \ldots + v_n \, v_n}
 *                = \sqrt{\sum_{i = 0}^{n} v_i^2}
 * \f]
 *
 * Par exemple, si le vecteur représenté par `v` est \f$ \vec{v} \f$
 * et a pour composantes :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      4.5 \\
 *                      8.1 \\
 *                      -2.6
 *                \end{pmatrix}
 * \f]
 *
 * alors la norme retourné est égale à :
 *
 * \f[
 *      \sqrt{\vec{v} \cdot \vec{v}} = \sqrt{\begin{pmatrix}
 *                                              4.5 \\
 *                                              8.1 \\
 *                                              -2.6
 *                                           \end{pmatrix}
 *                                           \cdot
 *                                           \begin{pmatrix}
 *                                              4.5 \\
 *                                              8.1 \\
 *                                              -2.6
 *                                           \end{pmatrix}}
 *                                  = \sqrt{4.5 \times 4.5 +
 *                                          8.1 \times 8.1 +
 *                                          -2.6 \times -2.6}
 *                                  = \sqrt{20.25 + 65.61 + 6.76}
 *                                  = \sqrt{92.62}
 *                                  = 9,623929\!\ldots
 * \f]
 *
 * \param v vecteur.
 *
 * \return norme de `v`.
 *
 * \see operator*(const m_vector &, const m_vector &).
 */
inline double norm(const m_vector &v);

/*!
 * \brief Ordre strictement inférieur.
 *
 * On considère que les composantes du vecteur sont relatives
 * à une [base orthonormée]
 * (https://fr.wikipedia.org/wiki/Base_orthonorm%C3%A9e).
 *
 * L'ordre est obtenu :
 *
 *  + _en majeur_ sur le nombre de composantes des
 *    vecteurs comparer ;
 *  + _en mineur_ sur leurs normes.
 *
 * Dans les deux cas,
 * c'est l'ordre strictement croissant qui est utilisé.
 *
 * En toute généralité, si le vecteur représenté par `lhs` est
 * \f$ \vec{v} \f$ et possède \f$ n \f$ composantes :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      v_0 \\
 *                      v_1 \\
 *                      \ldots \\
 *                      v_n
 *                \end{pmatrix}
 * \f]
 *
 * et `rhs` représente le vecteur \f$ r \f$ de \f$ m \f$ composantes :
 *
 * \f[
 *      \vec{r} = \begin{pmatrix}
 *                      r_0 \\
 *                      r_1 \\
 *                      \ldots \\
 *                      r_m
 *                \end{pmatrix}
 * \f]
 *
 * alors on compare d'abord \f$ n \f$ et \f$ m \f$ et, s'ils sont égaux,
 * on compare les normes \f$ \| \vec{v} \| \f$ et \f$ \| \vec{r} \| \f$.
 *
 * Par exemple, si le vecteur représenté par `lhs` est \f$ \vec{v} \f$
 * et a pour composantes :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      4.5 \\
 *                      8.1 \\
 *                      -2.6
 *                \end{pmatrix}
 * \f]
 *
 * et `rhs` représente \f$ \vec{r} \f$ de composantes :
 *
 * \f[
 *      \vec{r} = \begin{pmatrix}
 *                      -1.6 \\
 *                      0.0
 *                \end{pmatrix}
 * \f]
 *
 * alors la valeur retournée est `false` car le nombre de composantes
 * de \f$ \vec{v} \f$, 3, n'est pas strictement inférieur à celui
 * de \f$ \vec{r} \f$, 2.
 *
 * En guise d'autre exemple, si le vecteur représenté par `lhs` est
 * \f$ \vec{v} \f$ dont les composantes sont :
 *
 * \f[
 *      \vec{v} = \begin{pmatrix}
 *                      4.5 \\
 *                      8.1 \\
 *                      -2.6
 *                \end{pmatrix}
 * \f]
 *
 * et `rhs` représente \f$ \vec{r} \f$ de composantes :
 *
 * \f[
 *      \vec{r} = \begin{pmatrix}
 *                      -1.6 \\
 *                      0.0 \\
 *                      -2.7
 *                \end{pmatrix}
 * \f]
 *
 * alors la valeur retournée est `false` car la norme de \f$ \vec{v} \f$,
 * \f$ \| \vec{v} \| = 9,623929\!\ldots \f$, n'est pas strictement
 * inférieure à celle de \f$ \vec{r} \f$,
 * \f$ \| \vec{r} \| = 3,138471\!\ldots \f$.
 *
 * \param lhs vecteur.
 * \param rhs vecteur.
 *
 * \return `true` ou `false` selon les modalités décrites ci-dessus.
 *
 * \see m_vector::size().
 * \see norm(const m_vector &).
 */
inline bool operator<(const m_vector &lhs, const m_vector &rhs);

// implémentations des méthodes inline

void m_vector::validate_index(std::size_t index) const {
  // TODO : compléter / modifier
}

m_vector::m_vector(std::size_t size) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

m_vector::m_vector(std::size_t size, double value) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

m_vector::m_vector(std::initializer_list<double> data) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

m_vector::m_vector(std::vector<double> data) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

std::size_t m_vector::size() const {
  // TODO : compléter / modifier
  return {};
}

bool m_vector::equal_size(const m_vector &v) const {
  // TODO : compléter / modifier
  return {};
}

const std::vector<double> &m_vector::data() const {
  // TODO : compléter / modifier
  return {};
}

void m_vector::data(const std::vector<double> &new_data) {
  // TODO : compléter / modifier
}

double m_vector::operator[](std::size_t index) const {
  // TODO : compléter / modifier
  return {};
}

double &m_vector::operator[](std::size_t index) {
  // TODO : compléter / modifier
  // FIXME : erreur de compilation ici
  return {};
}

double m_vector::at(std::size_t index) const {
  // TODO : compléter / modifier
  return {};
}

double &m_vector::at(std::size_t index) {
  // TODO : compléter / modifier
  // FIXME : erreur de compilation ici
  return {};
}

std::string m_vector::to_string() const {
  // TODO : compléter / modifier
  return {};
}

m_vector::operator double() const {
  // TODO : compléter / modifier
  return {};
}

// implémentations des fonctions inline

std::ostream &operator<<(std::ostream &out, const m_vector &v) {
  // TODO : compléter / modifier
  // FIXME : erreur de compilation ici
  return {};
}

std::string to_string(const m_vector &v) {
  // TODO : compléter / modifier
  return {};
}

bool equal_size(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
  return {};
}

inline void validate_size(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
}

m_vector operator*(double d, const m_vector &v) {
  // TODO : compléter / modifier
  return {};
}

m_vector operator*(const m_vector &v, double d) {
  // TODO : compléter / modifier
  return {};
}

double operator*(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
  return {};
}

double norm(const m_vector &v) {
  // TODO : compléter / modifier
  return {};
}

bool operator<(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
  return {};
}

} // namespace he2b::nvs

#endif // M_VECTOR_H
