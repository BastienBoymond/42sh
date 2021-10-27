/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Displays the alphabet
*/

#include <stdio.h>
#include "my.h"
#include <unistd.h>

int count_minus(char const c)
{
    int minus_counter = 0;

    if (c == '-') {
        minus_counter += 1;
    }
    return (minus_counter);
}

int is_nbr(char const c)
{
    for (int nb = '0'; nb <= '9'; nb += 1) {
        if (nb == c) {
            return (1);
        }
    }
    return (0);
}

int convert(char c)
{
    for (int nb = '0'; nb <= '9'; nb += 1) {
        if (nb == c) {
            c -= 48;
            return (c);
        }
    }
    return (0);
}

int error(int r, int m)
{
    if (r >= 2147483647 || r <= -2147483647) {
        return (0);
    }
    if (m % 2 == 1) {
        r *= -1;
        return (r);
    }
    return (r);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int get_minus = 0;
    int already_got_nbr = 0;

    for (int i = 0; str[i] != 0; i += 1) {
        if (already_got_nbr == 0) {
            get_minus += count_minus(str[i]);
        }
        if (is_nbr(str[i])) {
            already_got_nbr += 1;
            result = (10 * result) + convert(str[i]);
        }
        if (already_got_nbr != 0 && !is_nbr(str[i])) {
            result = error(result, get_minus);
            return (result);
        }
    }
    result = error(result, get_minus);
    return (result);
}