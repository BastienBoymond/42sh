/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int builtin_command(char *cmd, int k)
{
    char *builtin[12] = {"cd", "echo", "setenv", "unsetenv", "history",
    "which", "where", "exit", "env", "alias", "repeat", NULL};

    for (int i = 0; builtin[i]; i++) {
        if (!my_strcmp(cmd, builtin[i]) && k == 0) {
            printf("%s: shell built-in command.\n");
            return (1);
        }
        if (!my_strcmp(cmd, builtin[i]) && k == 1) {
            printf("%s is a shell built-in\n");
            return (1);
        }
    }
    return (0);
}

int find_ndarg(char *cmd, char **path, int k)
{
    int result = 0;
    char *printable = NULL;

    if (result += builtin_command(cmd, k) == 1 && k == 0)
        return (result);
    for (int i = 0; path[i]; i++) {
        printable = my_strcat(path[i], "/");
        printable = my_strcat(printable, cmd);
        if (access(printable, F_OK) == 0 && my_strcmp(path[i], "/")) {
            printf("%s\n", printable);
            result++;
            if (k == 0)
                break;
        }
    }
    return (result);
}

int find_some_where(char **tab, char **path, int *pip)
{
    int result = 0;
    dup2(pip[0], 0);
    dup2(pip[1], 1);
    if (tab[1] == NULL)
        return (0);
    if (!my_strcmp(tab[0], "which")) {
        result = find_ndarg(tab[1], path, 0);
        if (result == 0)
            printf("%s: Command not found.\n", tab[1]);
    }
    if (!my_strcmp(tab[0], "where"))
        find_ndarg(tab[1], path, 1);
}