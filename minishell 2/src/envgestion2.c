/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** execution.c
*/

#include "../include/my.h"
#include "../include/shell.h"

env_t *pop_front(env_t *dest)
{
    env_t *tmp;
    if (dest != NULL) {
        tmp = dest->next;
        dest = tmp;
    }
    return (dest);
}

void print_env(env_t *env, int *pip)
{
    env_t *node = env;
    dup2(pip[0], 0);
    dup2(pip[1], 1);
    for (int i = 0; node != NULL; node = node->next)
            my_printf("%s\n", node->env);
}

shell_t *fill_nodes(char *cmd)
{
    shell_t *tree = malloc(sizeof(shell_t));

    tree->type = malloc(sizeof(type_t));
    tree->type = EXEC;
    tree->pip[0] = 0;
    tree->pip[1] = 1;
    tree->command = my_strcpy(tree->command, cmd);
    tree->left = NULL;
    tree->right = NULL;
    return (tree);
}

env_t *init(env_t *envi, char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        envi = int_list_push_back(envi, env[i]);
    envi = envi->next;
    return (envi);
};