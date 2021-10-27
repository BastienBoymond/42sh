/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int my_exit(int *pip)
{
    dup2(pip[0], 0);
    dup2(pip[1], 1);
    if (isatty(STDIN_FILENO))
        exit(my_putstr("exit\n"));
    else
        exit(0);
    return (0);
}