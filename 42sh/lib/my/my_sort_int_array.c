/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Displays the alphabet
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < (size - 1); i = i + 1) {
        if (array[i] > array[i + 1]) {
            my_swap(&array[i], &array[i + 1]);
            i = -1;
        }
    }
}