/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void comma(shell_t *shell, char **env, sh_t *sh)
{
    if (shell->left->command != NULL)
        order(shell->left, env, sh);
    if (shell->right->command != NULL)
        order(shell->right, env, sh);
}