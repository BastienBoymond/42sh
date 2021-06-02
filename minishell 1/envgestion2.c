/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** execution.c
*/

#include "include/my.h"
#include "include/shell.h"

env_t *pop_front(env_t *dest) 
{
    env_t *tmp;
    if (dest != NULL) {
        tmp = dest->next;
        dest = tmp;
    }
    return (dest);
}

void print_env(env_t *env)
{
    env_t *node = env;
    for (int i = 0; node != NULL; node = node->next)
            my_printf("%s\n", node->env);
}