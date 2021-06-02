/*
** EPITECH PROJECT, 2020
** DAY03
** File description:
** Put the number
*/

#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        nb = -nb;
        write (1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return (0);
}
