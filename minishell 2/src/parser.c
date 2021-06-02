/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

static type_t *find_sep(char *cmd, type_t *sep, int i)
{
    if (cmd[i] == ';')
        return (COMMA);
    if (cmd[i] == '|' &&  sep != COMMA && sep != R_REDIRECT
    && sep != DR_REDIRECT && sep != DL_REDIRECT && sep != L_REDIRECT)
        return (PIPE);
    if (cmd[i] == '>' && cmd[i + 1] == '>' && sep != COMMA
    && sep != R_REDIRECT)
        return (DR_REDIRECT);
    if (cmd[i] == '>' && cmd[i + 1] != '>' && cmd[i - 1] != '>' && sep != COMMA
    && sep != DR_REDIRECT)
        return (R_REDIRECT);
    if (cmd[i] == '<' && cmd[i + 1] != '<' && cmd[i - 1] != '<' && sep != COMMA
    && sep != R_REDIRECT && sep != DR_REDIRECT)
        return (L_REDIRECT);
    if (cmd[i] == '<' && cmd[i + 1] != '<' && sep != COMMA
    && sep != R_REDIRECT && sep != DR_REDIRECT && sep != DL_REDIRECT)
        return (DL_REDIRECT);
    else
        return (sep);
}

type_t *biggest_sep(char *cmd)
{
    type_t *sep = malloc(sizeof(type_t));

    sep = EXEC;
    for (int i = 0; cmd[i]; i++) {
        sep = find_sep(cmd, sep, i);
    }
    return (sep);
}

void parse_cmd(parsing_t *pars, char *cmd)
{
    int cmd_s = my_strlen(cmd) - 1;
    char **test = NULL;
    char **second = NULL;

    pars->type = malloc(sizeof(type_t));
    pars->type = biggest_sep(cmd);
    for (int i = cmd_s; i >= 0; i--) {
        if ((pars->type == PIPE && cmd[i] == '|') || (pars->type == COMMA
        && cmd[i] == ';') || (pars->type == R_REDIRECT && cmd[i] == '>')
        || (pars->type == L_REDIRECT && cmd[i] == '<')) {
            pars->left = parsing_left(cmd, i);
            pars->right = parsing_right(cmd, i + 1, cmd_s + 1);
            return;
        } else if ((pars->type == DR_REDIRECT && cmd[i] == '>'
        && cmd[i - 1] == '>') || (pars->type == DL_REDIRECT
        && cmd[i] == '<' && cmd[i - 1] == '<')) {
            pars->left = parsing_left(cmd, i - 1);
            pars->right = parsing_right(cmd, i + 2, cmd_s + 2);
            return;
        }
    }
}

int check_sep(char *cmd)
{
    if (cmd == NULL)
        return (1);
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '|' || cmd[i] == '>' || cmd[i] == '<' || cmd[i] == ';')
            return (0);
    }
    return (1);
}

void parsing(char *cmd, shell_t *tree)
{
    parsing_t *pars = malloc(sizeof(parsing_t));

    if (check_sep(cmd) == 1) {
        tree->command = cmd;
        tree->type = EXEC;
        return;
    }
    parse_cmd(pars, cmd);
    tree->type = pars->type;
    tree->right = fill_nodes(pars->right);
    tree->left = fill_nodes(pars->left);
    parsing(tree->right->command, tree->right);
    parsing(tree->left->command, tree->left);
}