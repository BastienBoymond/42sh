/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** utilites
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

int get_arr_size(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    for (; arr[i]; i++);
    return (i);
}