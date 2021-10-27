/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** local_var.c
*/

#include "../include/my.h"
#include "../include/shell.h"

sh_t create_sh(char **env, int argc)
{
    sh_t sh;

    sh.envi = malloc(sizeof(env_t));
    sh.var = malloc(sizeof(variables_t *));
    sh.envi = init(sh.envi, env, argc);
    sh.local = malloc(sizeof(local_t));
    return (sh);
}

int set_local_var(sh_t *sh, char *cmd)
{
    char **ar = my_str_to_word_array(cmd, "=");
    local_t *temp = *sh->local;
    local_t *tmp = malloc(sizeof(variables_t));
    if (ar[1] == NULL)
        return (0);
    tmp->name = strdup(ar[0]);
    tmp->value = strdup(ar[1]);
    tmp->next = NULL;
    if (temp == NULL) {
        *sh->local = tmp;
        return (0);
    }
    for (; temp->next != NULL; temp = temp->next) {
        if (!my_strcmp(ar[0], temp->name)) {
            temp->value = strdup(ar[1]);
            return (0);
        }
    }
    temp->next = tmp;
    return (0);
}

static void delete_node(sh_t *sh, int index)
{
    local_t *temp = *sh->local;

    if (index == 0) {
        sh->local = &((*sh->local)->next);
        return;
    }
    for (int i = 0; temp != NULL; temp = temp->next) {
        if (i == index - 1) {
            temp->next = temp->next->next;
        }
    }
}

int unset_local_var(sh_t *sh, char *cmd)
{
    local_t *temp = *sh->local;

    if (temp == NULL)
        return (0);
    for (int i = 0; temp != NULL; temp = temp->next, i++) {
        if (!my_strcmp(temp->name, cmd)) {
            delete_node(sh, i);
        }
    }
    return (0);
}
