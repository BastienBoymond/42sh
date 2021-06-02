/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** execution.c
*/

#include "../include/my.h"
#include "../include/shell.h"

env_t *int_list_push_back(env_t *env, char *varenv)
{
    env_t *node = malloc(sizeof(env_t));
    env_t *bef = NULL;

    if (env == NULL || node == NULL)
        return;
    node->env = varenv;
    node->next = NULL;
    if (env == NULL) {
        env = node;
    } else {
        for (bef = env; bef->next != NULL; bef = bef->next);
        bef->next = node;
        bef->next->next = NULL;
    }
    return (env);
}

env_t *int_list_destroy(env_t *env, char *str)
{
    env_t *dest = env;

    if (dest == NULL)
        return (env);
    if (!my_strncmp(str, dest->env, my_strlen(str))) {
        dest = pop_front(dest);
        return (dest);
    }
    for (; dest->next != NULL ; dest = dest->next) {
        if (!my_strncmp(str, dest->next->env, my_strlen(str))) {
            dest->next = dest->next->next;
            return (env);
        }
    }
    return (env);
}

int my_setenv(env_t *envi, char **tab, int *pip)
{
    char *str = tab[1];
    dup2(pip[0], 0);
    dup2(pip[1], 1);
    if (tab[1] == NULL) {
        print_env(envi, pip);
        return (0);
    }
    if (onlyalphanum(str) == 0) {
        my_printf("%s: Variable name must contain \
alphanumeric characters.\n", tab[0]);
        return (1);
    }
    str = my_strcat(str, "=");
    if (tab[2] == NULL) {
        envi = int_list_push_back(envi, str);
    } else {
        str = my_strcat(str, tab[2]);
        envi = int_list_push_back(envi, str);
    }
    return (0);
}

int my_unsetenv(env_t *envi, char **tab, int *pip)
{
    char *str = tab[1];

    dup2(pip[0], 0);
    dup2(pip[1], 1);
    if (tab[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return (1);
    }
    str = my_strcat(str, "=");
    envi = int_list_destroy(envi, str);
    return (0);
}