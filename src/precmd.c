/*
** EPITECH PROJECT, 2020
** 42
** File description:
** precmd.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void run_precmd(char **env, int *pip, sh_t *sh)
{
    variables_t *temp = *sh->var;

    for (; temp != NULL; temp = temp->next) {
        if (!my_strcmp(temp->name, "precmd") && temp->value[0] != '\0') {
            run(temp->value, env, pip, sh);
        }
    }
}