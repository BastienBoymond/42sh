/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Displays the alphabet
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *s1, char *s2)
{
    char *result = malloc(sizeof(char) * my_strlen(s1) + my_strlen(s2) + 1);
    int c = 0;
    if (s1 != NULL) {
        for (int i = 0 ; s1[i] != '\0' ; i++, c++) {
            result[c] = s1[i];
        }
    }
    for (int j = 0 ; s2[j] != '\0' ; j++, c++) {
        result[c] = s2[j];
    }
    result[c] = '\0';
    return (result);
}