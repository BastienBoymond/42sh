/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

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

int main(int argc, char *argv[], char *env[])
{
    char *buffer = NULL;
    size_t len = 0;
    env_t *envi = malloc(sizeof(env_t));
    shell_t *shell = malloc(sizeof(shell_t));

    envi = init(envi, env);
    if (argc != 1)
        return (84);
    if (isatty(STDIN_FILENO) == 1)
        print_prompt(envi);
    while (getline(&buffer, &len, stdin) != -1) {
        shell = fill_nodes(buffer);
        parsing(buffer, shell);
        order(shell, env, envi);
        if (isatty(STDIN_FILENO) == 1)
            print_prompt(envi);
    }
    return (0);
}