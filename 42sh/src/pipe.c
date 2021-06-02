/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void my_pipe(shell_t *shell, char **env, sh_t *sh)
{
    int status = 0;
    int pip[2];
    pid_t pid = 0;
    shell->left->pip[0] = shell->pip[0];
    shell->right->pip[1] = shell->pip[1];
    pipe(pip);
    shell->left->pip[1] = pip[1];
    shell->right->pip[0] = pip[0];
    if (shell->left->command == NULL || shell->right->command == NULL)
        return (my_printf("Invalid null command.\n"));
    pid = fork();
    if (pid == 0) {
        close(pip[0]);
        order(shell->left, env, sh);
        close(pip[1]);
        exit(0);
    } else {
        close(pip[1]);
        order(shell->right, env, sh);
        wait(&status);
    }
}