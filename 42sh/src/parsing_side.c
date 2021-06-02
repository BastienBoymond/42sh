/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

char *parsing_left(char *cmd, int total)
{
    char *result = malloc(sizeof(char) * (total + 1));

    if (total == 0)
        return (NULL);
    result[total] = '\0';
    for (int i = 0; i < total; i++) {
        result[i] = cmd[i];
    }
    return (result);
}

char *parsing_right(char *cmd, int start, int total)
{
    int all = total - start;
    char *result = malloc(sizeof(char) * (all + 1));

    if (all == 0)
        return (NULL);
    result[all] = '\0';
    for (int i = start, j = 0; i < total; i++, j++) {
        result[j] = cmd[i];
    }
    return (result);
}

int no_sep(char *cmd, sh_t *sh)
{
    sh->sep = 0;
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '|' || cmd[i] == '>' || cmd[i] == '<' || cmd[i] == ';'
        || cmd[i] == '&') {
            sh->sep = 1;
            return (1);
        }
    }
    return (0);
}

int check_sep(char *cmd, sh_t *sh)
{
    if (cmd == NULL)
        return (1);
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '|' || cmd[i] == '>' || cmd[i] == '<' || cmd[i] == ';'
        || cmd[i] == '&' || (cmd[i] == '`' && sh->sep == 0))
            return (0);
    }
    return (1);
}