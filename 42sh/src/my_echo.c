/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int my_echo_two(char **tab)
{
    for (int i = 1 ; tab[i]; i++) {
        if (tab[i + 1] == NULL)
            my_printf("%s\n", tab[i]);
        else
            my_printf("%s ", tab[i]);
    }
}

int my_echo(char **tab, int *pip)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == 0) {
        dup2(pip[0], 0);
        dup2(pip[1], 1);
        if (tab[1] == NULL)
            my_printf("\n");
        else
            my_echo_two(tab);
        exit(0);
    } else {
        waitpid(pid, status, 0);
        dup2(dup(0), 0);
        dup2(dup(1), 1);
    }
    return (0);
}