/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "include/my.h"
#include "include/shell.h"

env_t *init(env_t *envi, char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        envi = int_list_push_back(envi, env[i]);
    envi = envi->next;
}

env_t *run2(char **tab, char **env, env_t *envi)
{
    char **path = NULL;
    if (!my_strcmp(tab[0], "setenv")) {
        envi = my_setenv(envi, tab);
        return (envi);
    }
    if (!my_strcmp(tab[0], "unsetenv")) {
        envi = my_unsetenv(envi, tab);
        return (envi);
    } else {
        path = get_path(envi);
        executation(path, tab, env);
        return (envi);
    }
}

env_t *run(char *buffer, char **env, env_t *envi)
{
    char **tab = my_str_to_word_array(buffer, " \t\n");
    int j = 1;
    if (tab[0] == NULL || nocaracter(tab[0]) == 1)
        return (envi);
    if (!my_strcmp(tab[0], "exit")) {
        my_putstr("exit\n");
        exit(0);
    }
    if (!my_strcmp(tab[0], "cd")) {
        envi = my_cd(tab, envi);
        return (envi);
    }
    if (!my_strcmp(tab[0], "env")) {
        print_env(envi);
        return (envi);
    }
    return (envi = run2(tab, env, envi));
}

int main(int argc, char *argv[], char *env[])
{
    char *buffer = NULL;
    int j = 0;
    size_t len = 0;
    env_t *envi = malloc(sizeof(env_t));
    envi = init(envi, env);

    if (argc != 1)
        return (84);
    if (isatty(STDIN_FILENO) == 1)
            my_printf("$> ");
    while (getline(&buffer, &len, stdin) != -1) {
        envi = run(buffer, env, envi);
        if (isatty(STDIN_FILENO) == 1)
            my_printf("$> ");
    }
    return (0);
}