/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

char **my_arraycat(char **tmp, char **tab, int len)
{
    char *str = NULL;
    char **final = NULL;
    for (int i = 0; tmp[i]; i++) {
        str = my_strcat(str, tmp[i]);
        str = my_strcat(str, "|");
        len += my_strlen(tmp[i]);
    }
    for (int i = 1; tab[i]; i++) {
        str = my_strcat(str, tab[i]);
        str = my_strcat(str, "|");
        len += my_strlen(tab[i]);
    }
    str[len - 1] = '\0';
    final = my_str_to_word_array(str, "| ");
    return (final);
}

char **check_alias(char **tmp, char **tab, env_t *envi)
{
    if (!my_strcmp(tmp[0], tab[0]))
        tab = my_arraycat(&tmp[1], tab, strlen(tmp[0]));
    return (tab);
}

char **checker(char **tab, env_t *envi, char **path)
{
    char *str = open_file("../.42shrc");
    char **shrc = my_str_to_word_array(str, "\n");
    char **tmp = NULL;
    char *waiting = NULL;

    if (shrc == NULL)
        return (tab);
    for (int i = 0; shrc[i]; i++) {
        tmp = my_str_to_word_array(shrc[i], " '\n");
        if (!my_strcmp(tmp[0], "alias")) {
            waiting = my_strcpy(waiting, tmp[1]);
            tmp[1] = malloc(sizeof(char) * my_strlen(waiting));
            tmp[1][my_strlen(waiting)] = '\0';
            tmp[1] = my_strncpy(tmp[1], waiting, strlen(waiting));
            tab = check_alias(&tmp[1], tab, envi);
        }
        free(tmp);
    }
    return (tab);
}