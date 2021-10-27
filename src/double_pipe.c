/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void double_pipe(shell_t *shell, char **env, sh_t *sh)
{
    int i = 0;

    if (shell->left->command != NULL)
        i = order(shell->left, env, sh);
    if (shell->right->command != NULL && i != 0)
        order(shell->right, env, sh);
}