#ifndef DEV3_SLNODE_H
#define DEV3_SLNODE_H

#include "value_t.h"

#include "value_t.h"

/*!
 * \brief Valeurs d'erreurs associées à un élément de liste.
 */
enum SLNError {
    /*!
     * \brief Erreur lors d'une allocation mémoire d'un élément de
     *        liste.
     */
    ESLNMEMORYFAIL = 50
};

/*!
 * \brief Structure représentant le type d'un élément d'une
 *        liste simplement chaînée ([linked list]
 * (https://en.wikipedia.org/wiki/Linked_data_structure#Linked_lists)).
 */
struct SLNode {
    /*!
     * \brief Adresse de l'élément suivant dans la liste.
     *
     * S'il n'y a pas d'élément suivant, `next` vaut `NULL`.
     */
    struct SLNode *next;

    /*!
     * \brief Valeur conservée par l'élément de la liste.
     */
    value_t value;
};

/*!
 * \brief Création d'une instance de struct SLNode.
 *
 * L'élément de liste créé est dans un état valide : il ne possède
 * pas de suivant.
 *
 * Il est alloué dynamiquement et doit donc être détruit quand
 * son usage n'est plus requis.
 *
 * Si l'allocation mémoire échoue :
 *   + `errno` est mis à ::ESLNMEMORYFAIL ;
 *   + `NULL` est retourné.
 *
 * \param value la valeur contenue dans le struct SLNode.
 *
 * \return l'adresse du struct SLNode créé.
 */
struct SLNode *newSLN(value_t value);

/*!
 * \brief Destruction d'une instance de struct SLNode.
 *
 * Le struct SLNode pointé par le pointeur de struct SLNode
 * dont l'adresse est fournie est détruit. Ensuite, ce
 * pointeur de struct SLNode est mis à `NULL`.
 *
 * Aucun maillage n'est modifié par la fonction !
 *
 * Si `adpSLN` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param adpSLN adresse d'un pointeur de struct SLNode vers le
 *               struct SLNode à détruire.
 */
void deleteSLN(struct SLNode **adpSLN);

/*!
 * \brief Accès en lecture à l'élément suivant de la liste.
 *
 * Si `pSLN` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLN adresse du struct SLNode dont on désire connaître le
 *             suivant.
 *
 * \return Adresse du struct SLNode suivant celui pointé par `pSLN`.
 */
struct SLNode *nextSLN(const struct SLNode *pSLN);

/*!
 * \brief Accès en écriture à l'élément suivant de la liste.
 *
 * Seul le maillage du struct SLNode pointé par `pSLN` est modifié
 * par cette fonction. La
 * mémoire n'est pas gérée ici.
 *
 * Si `pSLN` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLN adresse du struct SLNode dont on désire modifier le
 *             suivant.
 * \param pNewNext adresse du nouveau struct SLNode suivant celui
 *                 pointé par `pSLN`.
 */
void setNextSLN(struct SLNode *pSLN, struct SLNode *pNewNext);

/*!
 * \brief Accès en lecture à la valeur stockée dans l'élément de liste.
 *
 * Si `pSLN` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLN adresse du struct DLNode dont on désire connaître la
 *             valeur qu'il contient.
 *
 * \return valeur contenue dans le struct DLNode pointé par `pSLN`.
 */
value_t valueSLN(const struct SLNode *pSLN);

/*!
 * \brief Accès en écriture à la valeur contenue dans l'élément de
 *        liste.
 *
 * Si `pSLN` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLN adresse du struct SLNode dont on désire modifier la
 *             valeur.
 * \param newValue nouvelle valeur à conserver dans le struct SLNode
 *                 pointé par `pSLN`.
 */
void setValueSLN(struct SLNode *pSLN, value_t newValue);


#endif //DEV3_SLNODE_H
