/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** reproduce my_strncmp
*/

#include "my.h"
#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    if (s1 == NULL || s2 == NULL)
        return (0);
    if (n == 0)
        return (0);
    for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1; i++);
    if (s1[i] > s2[i])
        return (1);
    else if (s1[i] < s2[i])
        return (-1);
    else
        return (0);
}