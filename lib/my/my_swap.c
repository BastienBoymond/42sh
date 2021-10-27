/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** A program that swaps the content of two integers
*/
#include <stddef.h>

int my_putchar(char c);

void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
