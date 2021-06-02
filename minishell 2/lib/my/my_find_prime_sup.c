/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** find prime
*/

int my_putchar(void);

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1) {
        return (nb);
    } else {
        return (my_find_prime_sup(nb + 1));
    }
}
