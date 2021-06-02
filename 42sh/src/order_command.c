/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

static sep_t sep[] = {
    {COMMA, comma},
    {PIPE, my_pipe},
    {R_REDIRECT, r_redirect},
    {L_REDIRECT, l_redirect},
    {DL_REDIRECT, dl_redirect},
    {DR_REDIRECT, dr_redirect},
    {AND_AND, and_and},
    {PIPE_PIPE, double_pipe},
    {BACKTICK, backstick}
};

int order(shell_t *shell, char **env, sh_t *sh)
{
    for (int i = 0; i < POS; i++) {
        if (shell->type == sep[i].type) {
            sep[i].exec(shell, env, sh);
        }
    }
    if (shell->type == EXEC) {
        return (exec(shell, env, sh));
    }
}