/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void comma(shell_t *shell, char **env, env_t *envi)
{
    if (shell->left->command != NULL)
        order(shell->left, env, envi);
    if (shell->right->command != NULL)
        order(shell->right, env, envi);
}