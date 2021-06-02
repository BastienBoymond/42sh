/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** parse_cmd.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int parse_backstick(parsing_t *pars, char *cmd, int cmd_s, int i)
{
    if ((pars->type == BACKTICK && cmd[i] == '`' && (cmd[i - 1] == ' ' || \
    i == 0)) && cmd[i + 1] != '\0') {
        pars->left = parsing_left(cmd, i);
        pars->right = parsing_right(cmd, i + 1, cmd_s);
        return (1);
    }
    return (0);
}

int parse_cmd_bis(parsing_t *pars, char *cmd, int cmd_s, int i)
{
    if ((pars->type == PIPE && cmd[i] == '|') || (pars->type == COMMA
    && cmd[i] == ';') || (pars->type == R_REDIRECT && cmd[i] == '>')
    || (pars->type == L_REDIRECT && cmd[i] == '<')) {
        pars->left = parsing_left(cmd, i);
        pars->right = parsing_right(cmd, i + 1, cmd_s + 1);
        return (1);
    } else if ((pars->type == DR_REDIRECT && cmd[i] == '>'
    && cmd[i - 1] == '>') || (pars->type == DL_REDIRECT
    && cmd[i] == '<' && cmd[i - 1] == '<') ||\
    (pars->type == PIPE_PIPE && cmd[i] == '|' && cmd[i - 1] == '|')
    || (pars->type == AND_AND && cmd[i] == '&' && cmd[i - 1] == '&')) {
        pars->left = parsing_left(cmd, i - 1);
        pars->right = parsing_right(cmd, i + 2, cmd_s + 2);
        return (1);
    } else {
        if (parse_backstick(pars, cmd, cmd_s, i) == 1)
            return (1);
    }
    return (0);
}

void parse_cmd(parsing_t *pars, char *cmd)
{
    int cmd_s = my_strlen(cmd) - 1;

    pars->type = malloc(sizeof(type_t));
    pars->type = biggest_sep(cmd);
    for (int i = cmd_s; i >= 0; i--) {
        if (parse_cmd_bis(pars, cmd, cmd_s, i) == 1)
            return;
    }
}