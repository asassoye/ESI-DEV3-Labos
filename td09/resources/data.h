/*!
 * \file data.h
 * \brief Définition d'une fonction pour la production de
 *        pronostics de lotto.
 */
#ifndef DATA_H
#define DATA_H

#include <vector>
#include <utility>
#include <string>

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 */
namespace nvs {

/*!
 * \brief Espace de nom du projet _Lotto_.
 */
namespace lotto {

/*!
 * \brief Fonction qui retourne des valeurs pour produire des
 *        pronostics pour un jeu de lotto.
 *
 * Dans le retour :
 *
 *    + la partie std::string peut servir à représenter le
 *      propriétaire d'un pronostic ;
 *    + la partie std::vector<unsigned> peut servir à représenter
 *      les valeurs d'un pronostic.
 *
 * \param pronostic_count nombre de pronostics désirés.
 * \param grid_length nombre de valeurs dans un pronostic.
 * \param grid_maximum valeur maximale possible des valeurs du
 *                     pronostic.
 * \param grid_minimum valeur minimale possible des valeurs du
 *                     pronostic.
 *
 * \return des données pour produire les parties «propriétaire »
 *         et « valeurs » d'un pronostics de lotto de paramétrage
 *         donné en argument.
 *
 * \throw std::invalid_argument dans les trois cas suivants :
 *
 *  + le nombre de valeurs d'un pronostic est nul ;
 *  + la valeur maximale possible d'un pronostic est strictement
 *    inférieure à sa valeur minimale possible ;
 *  + le nombre de valeurs d'un pronostic dépasse le nombre de
 *    valeurs de l'intervalle des valeurs acceptables.
 */
std::vector<std::pair<std::string, std::vector<unsigned>>>
data(unsigned pronostic_count, unsigned grid_length,
     unsigned grid_maximum, unsigned grid_minimum);

} // namespace lotto

} // namespace nvs

#endif // DATA_H
