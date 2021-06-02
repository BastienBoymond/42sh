/*
** EPITECH PROJECT, 2021
** e
** File description:
** e
*/

#include <stdlib.h>

char *my_itoa(int number)
{
    char *str = malloc(sizeof(char) * 15);

    if (number < 0)
        number = -number;
    str = str + sizeof(str);
    *--str = '\0';
    while (number >= 10) {
        *--str = '0' + number % 10;
        number /= 10;
    }
    *--str = '0' + number;
    if (number < 0)
        *--str = '-';
    return (str);
}