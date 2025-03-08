/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_
    #include "game.h"

/**
 * @brief Create a thystame object
 * @param map : the map data structure
 * @param size : the size of the map
 * @retval : 0 if the object is created otherwise 84
 */
int spawn_thystame(map_t *map, int size);
/**
 * @brief Create a phiras object
 * @param map : the map data structure
 * @param size : the size of the map
 * @retval : 0 if the object is created otherwise 84
 */
int spawn_phiras(map_t *map, int size);
/**
 * @brief Create a mendiane object
 * @param map : the map data structure
 * @param size : the size of the map
 * @retval : 0 if the object is created otherwise 84
 */
int spawn_mendiane(map_t *map, int size);
/**
 * @brief Create a sibur object
 * @param map : the map data structure
 * @param size : the size of the map
 * @retval : 0 if the object is created otherwise 84
 */
int spawn_sibur(map_t *map, int size);
/**
 * @brief Create a deraumere object
 * @param map : the map data structure
 * @param size : the size of the map
 * @retval : 0 if the object is created otherwise 84
 */
int spawn_deraumere(map_t* map, int size);

/**
 * @brief get amount of linemate object
 * @param map : the map data structure
 * @param size : the size of the map
 * @return : the amount of linemate object
 */
int get_nb_thystame(map_t* map);
/**
 * @brief get amount of phiras object
 * @param map : the map data structure
 * @param size : the size of the map
 * @return : the amount of phiras object
 */
int get_nb_phiras(map_t* map);
/**
 * @brief get amount of mendiane object
 * @param map : the map data structure
 * @param size : the size of the map
 * @return : the amount of mendiane object
 */
int get_nb_mendiane(map_t* map);
/**
 * @brief get amount of sibur object
 * @param map : the map data structure
 * @param size : the size of the map
 * @return : the amount of sibur object
 */
int get_nb_sibur(map_t* map);
/**
 * @brief get amount of deraumere object
 * @param map : the map data structure
 * @param size : the size of the map
 * @return : the amount of deraumere object
 */
int get_nb_deraumere(map_t* map);
/**
 * @brief get amount of food object
 * @param map : the map data structure
 * @param size : the size of the map
 * @return : the amount of food object
 */
int get_nb_food(map_t* map);
/**
 * @brief get amount of linemate object
 * @param map : the map data structure
 * @param size : the size of the map
 * @return : the amount of linemate object
 */
int get_nb_linemate(map_t* map);


#endif /* !MAP_H_ */
