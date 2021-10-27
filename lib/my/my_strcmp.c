/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** reproduce the behavior of strcmp
*/

#include <stdio.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    if (s1 == NULL || s2 == NULL) {
        return (-1);
    }
    while (s1[i] == s2[i] && s1[i] && s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}