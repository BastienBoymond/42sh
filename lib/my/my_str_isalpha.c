/*
** EPITECH PROJECT, 2020
** is alpha
** File description:
** is alpha
*/

#include <stdio.h>

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            i++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            i++;
        } else
            return (0);
    }
    return (1);
}