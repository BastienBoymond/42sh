/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** if prime put 1 if not put 0
*/

int my_putchar(char);

int my_is_prime(int nb)
{
    int i = 0;
    int d = 0;

    while (i < nb) {
        i++;
        if (nb % i == 0) {
            d++;
        }
    }
    if (d == 2) {
        return (1);
    } else {
        return (0);
    }
}
