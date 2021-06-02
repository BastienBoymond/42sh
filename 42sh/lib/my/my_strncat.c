/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Displays the alphabet
*/

#include <stdlib.h>
#include "my.h"
#include <unistd.h>

char *error(void);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    for (i = 0; i < nb; i = i + 1) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return (dest);
}