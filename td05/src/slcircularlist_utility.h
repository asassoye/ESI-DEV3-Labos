/*!
 * \file slcircularlist_utility.h
 *
 * \brief Définition de fonctions d'aide à l'utilisation de
 *        struct SLCircularList.
 */
#ifndef DEV3_SLCIRCULARLIST_UTILITY_H
#define DEV3_SLCIRCULARLIST_UTILITY_H

#include "slcircularlist.h"

/*!
 * \brief Accès en lecture de la taille de la liste.
 *
 * La taille de la liste est le nombre de struct SLNode qui la
 * constituent. Une liste vide est donc de taille nulle.
 *
 * Si `pSLCL` est `NULL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la struct SLCircularList dont on désire
 *              connaître la taille.
 *
 * \return nombre d'éléments de la liste pointée par `pSLCL`.
 */
size_t sizeSLCL(const struct SLCircularList *pSLCL);

/*!
 * \brief Élément précédant celui fourni.
 *
 * Retourne l'élément de la liste `pSLCL` précédant `pSLN`
 * ou `NULL` si la liste est vide.
 *
 * Si `pSLCL` est `NULL`, si `pSLN` est `NULL` sans que `pSLCL`
 * ne soit vide ou si `pSLN` ne pointe pas sur un élément de la
 * liste pointée par `pSLCL`, le comportement de la fonction est
 * indéterminé.
 *
 * \param pSLCL adresse de la liste où rechercher le précédant.
 * \param pSLN adresse de l'élément dont on désire le précédant.
 *
 * \return adresse de l'élément précédant `pSLN` ou `NULL` si
 *         `pSLCL` est vide.
 */
struct SLNode *previousSLCL(const struct SLCircularList *pSLCL,
                            const struct SLNode *pSLN);


#endif //DEV3_SLCIRCULARLIST_UTILITY_H
