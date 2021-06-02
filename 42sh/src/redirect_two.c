/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int error_handing_red(shell_t *shell)
{
    if (shell->right->command == NULL) {
        my_printf("Missing name for redirect.\n");
        return (0);
    }
    if (shell->left->command == NULL) {
        my_printf("Invalid null command.\n");
        return (0);
    }
    return (1);
}

void redirect_two(shell_t *shell, char **env, int *pip, sh_t *sh)
{
    dup2(pip[0], 0);
    close(pip[1]);
    order(shell->left, env, sh);
}

void redirect_three(shell_t *shell, char **env, env_t *envi, int *pip)
{
    close(pip[1]);
    close(pip[0]);
    dup2(dup(1), 1);
    dup2(dup(0), 0);
}

int redirect_fourth(ld_t *red, shell_t *shell, char **env, sh_t *sh)
{
    if (!my_strcmp(red->str, red->buffer)) {
        red->pid = fork();
        if (red->pid == 0) {
            dup2(red->pip[1], 1);
            my_printf("%s", red->total);
            exit(0);
        } else {
            red->pid = fork();
            if (red->pid == 0) {
                redirect_two(shell, env, red->pip, sh);
                wait(&red->status);
                exit(0);
            } else {
                redirect_three(shell, env, sh->envi, red->pip);
                wait(&red->status);
            }
        }
        wait(&red->status);
        return (1);
    }
    return (0);
}