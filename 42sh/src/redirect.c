/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void l_redirect(shell_t *shell, char **env, sh_t *sh)
{
    int fd = 0;
    int status = 0;
    pid_t pid = 0;
    char **redirect = NULL;
    if (error_handing_red(shell) == 0)
        return;
    redirect = my_str_to_word_array(shell->right->command, " \t\n");
    if ((fd = open(redirect[0], O_RDONLY)) == -1)
        return (my_printf("%s: %s.\n", redirect[0], strerror(errno)));
    else {
        shell->left->pip[0] = fd;
        shell->left->pip[1] = shell->pip[1];
        order(shell->left, env, sh);
        close(fd);
    }
}

void r_redirect(shell_t *shell, char **env, sh_t *sh)
{
    int fd = 0;
    int status = 0;
    pid_t pid = 0;
    char **redirect = NULL;
    if (error_handing_red(shell) == 0)
        return;
    redirect = my_str_to_word_array(shell->right->command, " \t\n");
    if ((fd = open(redirect[0], O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
        return (my_printf("%s: %s.\n", redirect[0], strerror(errno)));
    else {
        shell->left->pip[1] = fd;
        shell->left->pip[0] = shell->pip[0];
        order(shell->left, env, sh);
        close(fd);
    }
}

ld_t *init_red(shell_t *shell)
{
    ld_t *red = malloc(sizeof(ld_t));

    red->pip[2];
    red->pid = 0;
    red->status = 0;
    red->str = my_strcpy(red->str, shell->right->command);
    red->buffer = NULL;
    red->total = NULL;
    red->len = 0;
    return (red);
}

void dl_redirect(shell_t *shell, char **env, sh_t *sh)
{
    ld_t *red = malloc(sizeof(ld_t));

    red = init_red(shell);
    pipe(red->pip);
    if (isatty(STDIN_FILENO) == 1)
        my_printf("heredoc> ");
    while (getline(&red->buffer, &red->len, stdin) != -1) {
        if (redirect_fourth(red, shell, env, sh) == 1)
            return;
        if (isatty(STDIN_FILENO) == 1)
            my_printf("heredoc> ");
        red->total = my_strcat(red->total, red->buffer);
    }
}

void dr_redirect(shell_t *shell, char **env, sh_t *sh)
{
    int fd = 0;
    int status = 0;
    pid_t pid = 0;
    char **redirect = NULL;
    if (error_handing_red(shell) == 0)
        return;
    redirect = my_str_to_word_array(shell->right->command, " \t\n");
    if ((fd = open(redirect[0], O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
        return (my_printf("%s: %s.\n", redirect[0], strerror(errno)));
    else {
        shell->left->pip[1] = fd;
        shell->left->pip[0] = shell->pip[0];
        if (shell->left->command[0] == '(') {
            printf("parenthese\n");
        } else {
            order(shell->left, env, sh);
        }
        close(fd);
    }
}