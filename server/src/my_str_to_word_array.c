/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** my_str_to_word_arary
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int is_alphanumeric(char c, char *separator)
{
    int i = 0;
    size_t size = strlen(separator);
    size_t count = 0;

    while (separator[i] != '\0') {
        if ((c != separator[i]))
            count++;
        i++;
    }
    if (count == size && c != '\0')
        return (1);
    return (0);
}

int count_word(char const *str, char *c)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (is_alphanumeric(str[i], c) && !is_alphanumeric(str[i + 1], c)) {
            counter += 1;
        }
        i += 1;
    }
    return (counter);
}

char *save_word(char const *str, int *i, char *separator)
{
    char *tmp = NULL;
    int min = *i;
    int max = *i;
    int j = 0;

    while (is_alphanumeric(str[*i], separator)) {
        max += 1;
        *i += 1;
    }
    tmp = malloc(sizeof(char) * ((max - min) + 1));
    if (str[*i] == '\0')
        *i -= 1;
    while (min < max) {
        tmp[j] = str[min];
        min += 1;
        j += 1;
    }
    tmp[j] = '\0';
    return (tmp);
}

char **my_str_to_word_array(char const *str, char *separator)
{
    int i = 0;
    int index = 0;
    char **tab = NULL;
    int size = 0;

    if (str == NULL)
        return (NULL);
    size = count_word(str, separator);
    tab = malloc(sizeof(char *) * (size + 1));
    if (tab == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (is_alphanumeric(str[i], separator)) {
            tab[index] = save_word(str, &i, separator);
            index += 1;
        }
        i += 1;
    }
    tab[size] = NULL;
    return (tab);
}
