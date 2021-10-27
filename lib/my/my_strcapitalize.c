/*
** EPITECH PROJECT, 2020
** my_strcapitalize.c
** File description:
** str capitalize
*/

#include <stdio.h>

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' &&
        str[i - 1] >= 32 && str[i - 1] <= 47)
            str[i] -= 32;
        if (str[i] >= 'A' && str[i] <= 'Z'
        && str[i - 1] >= 48 && str[i - 1] <= 122)
            str[i] += 32;
        i++;
    }
    return (str);
}