/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** A program that counts the numbers of characters
*/

#include "stdlib.h"

int my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
