/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** utilities
*/

#include "../include/my.h"
#include "../include/shell.h"
#include "../include/my_termios.h"

void print_prompt(env_t *envi)
{
    env_t *dest = envi;
    char **pars = NULL;
    int i = 0;

    for (;my_strncmp("PWD=", dest->env, 4); dest = dest->next);
    pars = my_str_to_word_array(dest->env, "/");
    for (; pars[i]; i++);
    i--;
    my_printf("\033[0;34m");
    my_printf("%s", pars[i]);
    my_printf("\033[0;36m");
    my_printf(" $> ");
    my_printf("\033[0m");
}

void verify_tty(sh_t *sh)
{
    if (isatty(STDIN_FILENO) == 1)
        print_prompt(sh->envi);
}