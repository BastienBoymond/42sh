/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** Recopy
*/

#include "my.h"
#include <stdarg.h>

static my_printf_t func[] = {
    {'d', flag_nbr},
    {'c', flag_char},
    {'s', flag_str},
};

int verification(va_list ap, int i, char *str)
{
    for (int a = 0; a < ARRAY_SIZE; a++) {
        if (str[i] == func[a].c)
            func[a].str(ap);
    }
    return (0);
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list ap;
    va_start(ap, str);

    while (str[i] != '\0') {
        if (str[i] == '%' && str[i + 1] != '\0') {
            i++;
            verification(ap, i, str);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(ap);
    return (EXIT_SUCCESS);
}