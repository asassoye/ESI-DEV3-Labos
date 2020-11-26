/*!
 * \file slnode_utility.h
 *
 * \brief Définition de fonctions d'aide à l'utilisation de
 *        struct SLNode.
 */
#ifndef DEV3_SLNODE_UTILITY_H
#define DEV3_SLNODE_UTILITY_H

#include <stddef.h>

#include "slnode.h"

/*!
 * \brief Accès à un élément suivant en position donnée.
 *
 * \param pSLN adresse du struct SLNode dont on désire accèder à
 *             un suivant.
 * \param distance position de l'élément désiré.
 *
 * \return adresse de l'élément `distance` positions après celui
 *         d'adresse `pSLN` ou `NULL` s'il n'y en a pas.
 */
struct SLNode *forwardSLN(struct SLNode *pSLN, size_t distance);

#endif
