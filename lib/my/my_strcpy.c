/*
** EPITECH PROJECT, 2020
** strcpy
** File description:
** headerc
*/

#include <stdlib.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    dest = malloc(sizeof(char) * my_strlen(src)+ 1);

    if (src == NULL)
        return (NULL);
    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return (dest);
}
