/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

typedef struct parsed_info_s {
    char* port;
    char* width;
    char* height;
    char **names;
    char* clients_nb;
    char* freq;
} parsed_info_t;

/**
 * @brief Parse all arguments sent to the program
 * @param argv : the arguments
 * @return : the parsed arguments
 */
parsed_info_t* parse_args(char** argv);
/**
 * @brief Free the parsed arguments
 * @param info : the parsed arguments
 */
void free_parsing(parsed_info_t *info);
/**
 * @brief Check if the arguments are valid
 * @param infos : the parsed arguments
 * @retval 0 if the arguments are valid otherwise 84
 */
int check_parsing(parsed_info_t* infos);

#endif /* !PARSING_H_ */
