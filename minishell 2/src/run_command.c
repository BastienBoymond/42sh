/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int valid_cmd(char **path, char **tab)
{
    char *printable = NULL;

    if (access(tab[0], F_OK) == 0) {
        return (0);
    }
    for (int i = 0; path[i] != NULL; i++) {
        printable = my_strcat(path[i], "/");
        printable = my_strcat(printable, tab[0]);
        if (access(printable, F_OK) == 0) {
            return (0);
        }
    }
    my_printf("%s: Command not found.\n", tab[0]);
    return (1);
}

void exec(shell_t *shell, char **env, env_t *envi)
{
    run(shell->command, env, envi, shell->pip);
}

void run(char *buffer, char **env, env_t *envi, int *pip)
{
    char **tab = my_str_to_word_array(buffer, " \t\n");
    char **path = NULL;

    if (tab[0] == NULL || nocaracter(tab[0]) == 1)
        return;
    if (!my_strcmp(tab[0], "exit"))
        return (my_exit(pip));
    if (!my_strcmp(tab[0], "cd"))
        return (my_cd(tab, envi, pip));
    if (!my_strcmp(tab[0], "env"))
        return (print_env(envi, pip));
    if (!my_strcmp(tab[0], "setenv"))
        return (my_setenv(envi, tab, pip));
    if (!my_strcmp(tab[0], "unsetenv")) {
        return (my_unsetenv(envi, tab, pip));
    } else {
        path = get_path(envi);
        return (executation(path, tab, env, pip));
    }
}