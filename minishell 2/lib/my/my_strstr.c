/*
** EPITECH PROJECT, 2020
** strstr
** File description:
** str into a other str
*/

#include "my.h"
#include <stdlib.h>

int my_strncmp( char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find)
{
    int lenght = my_strlen(to_find);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[0] && my_strncmp(str, to_find, lenght) == 0)
            return (&str[i]);
        i++;
    }
    return (NULL);
}