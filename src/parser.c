/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

static type_t *find_sep_two(char *cmd, type_t *sep, int i)
{
    if (cmd[i] == '>' && cmd[i + 1] != '>' && cmd[i - 1] != '>' && sep != COMMA
    && sep != DR_REDIRECT  && sep != BACKTICK)
        return (R_REDIRECT);
    if (cmd[i] == '<' && cmd[i + 1] != '<' && cmd[i - 1] != '<' && sep != COMMA
    && sep != R_REDIRECT && sep != DR_REDIRECT  && sep != BACKTICK)
        return (L_REDIRECT);
    if (cmd[i] == '<' && cmd[i + 1] != '<' && sep != COMMA
    && sep != R_REDIRECT && sep != DR_REDIRECT && sep != DL_REDIRECT  \
    && sep != BACKTICK)
        return (DL_REDIRECT);
    if (cmd[i] == '|' && cmd[i + 1] == '|' && sep != COMMA &&
    sep != R_REDIRECT && sep != L_REDIRECT && sep != DR_REDIRECT)
        return (PIPE_PIPE);
    if (cmd[i] == '&' && cmd[i + 1] == '&' && sep != COMMA &&
    sep != R_REDIRECT && sep != L_REDIRECT && sep != DR_REDIRECT)
        return (AND_AND);
    else
        return (sep);
}

static type_t *find_sep(char *cmd, type_t *sep, int i)
{
    if (cmd[i] == ';')
        return (COMMA);
    if (cmd[i] == '`'  && (cmd[i - 1] == ' ' || i == 0))
        return (BACKTICK);
    if (cmd[i] == '|'  && cmd[i + 1] != '|' && cmd[i - 1] != '|' && \
    sep != COMMA && sep != R_REDIRECT && sep != DR_REDIRECT\
    && sep != DL_REDIRECT && sep != L_REDIRECT && sep != BACKTICK)
        return (PIPE);
    if (cmd[i] == '>' && cmd[i + 1] == '>' && sep != COMMA
    && sep != R_REDIRECT  && sep != BACKTICK)
        return (DR_REDIRECT);
    return (find_sep_two(cmd, sep, i));
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

void parsing(char *cmd, shell_t *tree, sh_t *sh)
{
    parsing_t *pars = malloc(sizeof(parsing_t));

    if (check_sep(cmd, sh) == 1) {
        tree->command = cmd;
        tree->type = EXEC;
        return;
    }
    parse_cmd(pars, cmd);
    tree->type = pars->type;
    tree->right = fill_nodes(pars->right);
    tree->left = fill_nodes(pars->left);
    parsing(tree->right->command, tree->right, sh);
    parsing(tree->left->command, tree->left, sh);
}