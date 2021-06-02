/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

static sep_t sep[] = {
    {EXEC, exec},
    {COMMA, comma},
    {PIPE, my_pipe},
    {R_REDIRECT, r_redirect},
    {L_REDIRECT, l_redirect},
    {DL_REDIRECT, dl_redirect},
    {DR_REDIRECT, dr_redirect},
};

void order(shell_t *shell, char **env, env_t *envi)
{
    for (int i = 0; i < POS; i++) {
        if (shell->type == sep[i].type) {
            sep[i].exec(shell, env, envi);
        }
    }
}