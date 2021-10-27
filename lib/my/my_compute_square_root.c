/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** racine carré
*/

int my_putchar(char);

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 0) {
        return (0);
    }
    while (i <= nb/2) {
        i++;
        if (i * i == nb) {
            return (i);
        }
    }
    return (0);
}
