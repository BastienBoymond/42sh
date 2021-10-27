/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

char *tabcat(char **tab)
{
    int len = 0;
    char *cmd = NULL;
    for (int i = 0; tab[i]; i++) {
        cmd = my_strcat(cmd, tab[i]);
        if (tab[i + 1] != NULL)
            cmd = my_strcat(cmd, " ");
    }
    return (cmd);
}

int repeater(char **tab, char **env, int *pip, sh_t *sh)
{
    int nb = 0;
    char *cmd = NULL;
    if (tab[1] == NULL || tab[2] == NULL) {
        printf("%s: Too few arguments.\n", tab[0]);
        return (1);
    }
    if (my_str_isnum(tab[1])) {
        nb = atoi(tab[1]);
        cmd = tabcat(&tab[2]);
        for (int i = 0; i < nb; i++) {
            run(cmd, env, pip, sh);
        }
    } else {
        printf("%s: Badly formed number.\n", tab[0]);
        return (1);
    }

}