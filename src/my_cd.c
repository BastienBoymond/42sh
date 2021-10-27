/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void get_home(env_t *envi)
{
    char *path = NULL;
    env_t *node = envi;

    for (; node->next != NULL; node = node->next) {
        if (!my_strncmp("HOME=", node->next->env, 5))
            path = my_strcpy(path, &node->next->env[5]);
    }
    chdir(path);
}

int get_back(env_t *envi)
{
    char *path = NULL;
    env_t *node = envi;

    for (; node->next != NULL; node = node->next) {
        if (!my_strncmp("OLDPWD=", node->next->env, 7))
            path = my_strcpy(path, &node->next->env[7]);
    }
    if (chdir(path) == -1) {
        my_printf(": No such file or directory.\n");
        return (1);
    }
    return (0);
}

int get_direct(char *str)
{
    if (chdir(str) == -1) {
        my_printf("%s: %s.\n", str, strerror(errno));
        return (1);
    }
    return (0);
}

int get_indirect(char *str)
{
    if (chdir(str) == -1) {
        my_printf("%s: %s.\n", str, strerror(errno));
        return (1);
    }
    return (0);
}

int my_cd(char **tab, env_t *envi, int *pip)
{
    dup2(pip[1], 1);
    if (tab[1] == NULL || my_strcmp(tab[1], "~") == 0) {
        get_home(envi);
    } else if (my_strcmp(tab[1], "-") == 0) {
        if (get_back(envi) == 1)
            return (1);
    } else if (tab[1][0] == '/') {
        if (get_direct(tab[1]) == 1)
            return (1);
    } else {
        if (get_indirect(tab[1]) == 1)
            return (1);
    }
    envi = changepwd(envi);
    return (0);
}