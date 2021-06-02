/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** was flag_nbr of printf
*/

#include "my.h"
#include <stdarg.h>

void flag_nbr(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void flag_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void flag_str(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}