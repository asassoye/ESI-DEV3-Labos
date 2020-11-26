/*!
 * \file slcircularlist.h
 *
 * \brief Définition d'un type représentant une liste circulaire
 *        simplement chaînée.
 */
#ifndef DEV3_SLCIRCULARLIST_H
#define DEV3_SLCIRCULARLIST_H

#include <stdbool.h>
#include <stddef.h>

#include "slnode.h"

/*!
 * \brief Valeurs d'erreurs associées à une liste.
 */
enum SLLError {
    /*!
     * \brief Erreur lors d'une allocation mémoire d'une liste ou
     *        d'un de ses éléments.
     */
    ESLLMEMORYFAIL = 60,

    /*!
     * \brief Opération interdite car la liste est vide.
     */
    ESLLEMPTY
};

/*!
 * \brief Structure représentant une liste circulaire simplement
 *        chaînée ([circular linked list]
 *  (https://en.wikipedia.org/wiki/Linked_list#Circular_linked_list)).
 */
struct SLCircularList {
    /*!
     * \brief Entrée dans la liste circulaire.
     */
    struct SLNode *entry;
};

/*!
 * \brief Création d'une liste circulaire simplement chaînée.
 *
 * La liste est créée vide, c'est-à-dire que son champ `entry`
 * est mis à `NULL`.
 *
 * Si l'allocation dynamique échoue :
 *   + `errno` est mis à ::ESLLMEMORYFAIL ;
 *   + `NULL` est retourné.
 *
 * \return adresse de la struct SLCircularList créée.
 */
struct SLCircularList *newSLCL(void);

/*!
 * \brief Destruction d'une liste circulaire simplement chaînée.
 *
 * La struct SLCircularList pointée par le pointeur de
 * struct SLCircularList
 * dont l'adresse est fournie est détruite. Ensuite, ce
 * pointeur de struct SLCircularList est mis à `NULL`.
 *
 * La destruction de la liste implique la destruction de tous
 * ses éléments.
 *
 * Si `adpSLCL` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param adpSLCL adresse d'un pointeur de struct SLCircularList
 *                vers la struct SLCircularList à détruire.
 */
void deleteSLCL(struct SLCircularList **adpSLCL);

/*!
 * \brief Destruction du contenu de la liste.
 *
 * Tous les struct SLNode qui constituent la liste sont détruits,
 * mais pas la liste elle-même. En fin de fonction, la liste est
 * vide, donc son champ `entry` est mis à `NULL`.
 *
 * Si `pSLCL` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la struct SLCircularList dont on désire
 *              détruite les éléments.
 */
void clearSLCL(struct SLCircularList *pSLCL);

/*!
 * \brief Accès en lecture de l'élément d'entrée de liste.
 *
 * Si la liste pointée par `pSLCL` est vide, `NULL` est retourné.
 *
 * Si `pSLCL` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la struct SLCircularList dont on désire
 *              connaître le struct SLNode d'entrée.
 *
 * \return adresse du struct SLNode en tête de la liste pointée
 *         par `pSLCL`.
 */
struct SLNode *entrySLCL(const struct SLCircularList *pSLCL);

/*!
 * \brief Accès en lecture de la nature vide ou non de la liste.
 *
 * Si `pSLCL` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la struct SLCircularList dont on désire
 *              savoir si elle est vide ou non.
 *
 * \return `true` si la liste pointée par `pSLCL` ne contient aucun
 *         struct SLNode, `false` sinon.
 */
bool emptySLCL(const struct SLCircularList *pSLCL);

/*!
 * \brief Insertion d'un élément en entrée de liste.
 *
 * Si l'instanciation du struct SLNode destiné à être la
 * nouvelle tête de liste échoue :
 *   + la liste est laissée telle quelle ;
 *   + `errno` est mis à ::ESLLMEMORYFAIL.
 *
 * Si `pSLCL` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la liste dont on veut modifier
 *              l'élément d'entrée.
 * \param value valeur que doit contenir l'élément en entrée
 *              de liste.
 *
 * \return adresse de la nouvelle entrée de liste... ou
 *         l'ancienne en cas d'échec.
 */
struct SLNode *pushSLCL(struct SLCircularList *pSLCL,
                        value_t value);

/*!
 * \brief Insertion d'une nouvelle valeur dans la liste à
 *        l'emplacement préalable d'un élément spécifié.
 *
 * Si l'instanciation du struct SLNode destiné à être inséré dans
 * la liste échoue :
 *   + la liste est laissée telle quelle ;
 *   + `errno` est mis à ::ESLLMEMORYFAIL.
 *
 * Après insertion, l'élément pointé par `pSLN` devient le suivant
 * de celui nouvellement inséré. En d'autres termes, l'élément
 * fraichement inséré prend la place de celui pointé par `pSLN`,
 * tandis que ce dernier vient se placer à sa suite.
 *
 * En toute généralité :
 *
 *      insertSLCL(pSLCL, getEntrySLCL(pSLCL), value);
 *
 * est équivalent à :
 *
 *      pushSLCL(pSLCL, value);
 *
 * En particulier, si `pSLCL` pointe sur une liste vide :
 *
 *      insertSLCL(pSLCL, NULL, value);
 *
 * est équivalent à :
 *
 *      pushSLCL(pSLCL, value);
 *
 * Si `pSLCL` est `NULL`, si `pSLN` est `NULL` sans que `pSLCL`
 * ne soit vide ou si `pSLN` ne pointe pas sur un élément de la
 * liste pointée par `pSLCL`, le comportement de la fonction est
 * indéterminé.
 *
 * Remarque : il est impossible avec cette fonction d'insérer un
 * élément entre l'entrée et l'élément précédant l'entrée sans que
 * le nouvel élément ne devienne la nouvelle entrée de liste.
 *
 * \param pSLCL adresse de la liste dans laquelle on désire insérer
 *              un nouvel élément.
 * \param pSLN adresse de l'élément de la liste où
 *             l'insertion doit avoir lieu.
 * \param value valeur du nouvel élément à insérer.
 *
 * \return adresse du nouvel élément inséré... ou `pSLN`
 *         en cas d'échec.
 */
struct SLNode *insertSLCL(struct SLCircularList *pSLCL,
                          struct SLNode *pSLN,
                          value_t value);

/*!
 * \brief Suppression de l'élément en entrée de liste.
 *
 * L'élément supprimé est détruit.
 *
 * Si la liste pointée par `pSLCL` est initialement vide :
 *   + la liste est laissée telle quelle ;
 *   + `errno` est mis à ::ESLLEMPTY ;
 *   + `NULL` est retourné.
 *
 * Si `pSLCL` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la liste dont on veut ôter
 *              l'élément d'entrée.
 *
 * \return adresse de la nouvelle entrée de liste ou
 *         `NULL` si elle est désormais vide.
 */
struct SLNode *popSLCL(struct SLCircularList *pSLCL);

/*!
 * \brief Suppression d'un élément de la liste.
 *
 * L'élément supprimé est détruit.
 *
 * Si la liste pointée par `pSLCL` est initialement vide, rien
 * ne se passe.
 *
 * Si `pSLCL` est `NULL`, si `pSLN` est `NULL` alors que la liste
 * n'est pas vide ou si `pSLN` ne pointe pas sur un élément de la
 * liste pointée par `pSLCL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la liste dont on désire supprimer
 *              un élément.
 * \param pSLN adresse de l'élément à supprimer.
 *
 * \return adresse de l'élément de la liste qui se trouve, après
 *         suppression, en même position que l'élément qui a été
 *         supprimé, c'est-à-dire `NULL` si la liste est finalement
 *         vide ou l'adresse de l'élément suivant l'élément
 *         qui a été supprimé.
 */
struct SLNode *eraseSLCL(struct SLCircularList *pSLCL,
                         struct SLNode *pSLN);

#endif // SLCIRCULARLIST_H