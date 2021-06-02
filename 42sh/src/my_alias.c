/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void parser_alias(char **files)
{
    printf("%s\t", files[0]);
    for (int i = 1; files[i]; i++) {
        if (files[i + 1] == NULL)
            printf("%s", files[i]);
        else
            printf("%s ", files[i]);
    }
    printf("\n");
}

void print_alias(variables_t **var)
{
    variables_t *temp = *var;

    for (; temp != NULL; temp = temp->next) {
        printf("%s\t%s\n", temp->name, temp->value);
    }
}

static variables_t *create_tmp(char **tab)
{
    variables_t *tmp = malloc(sizeof(variables_t));

    tmp->name = strdup(tab[0]);
    tmp->value = "";
    for (int i = 1; tab[i] != NULL; i++)
        tmp->value = my_strcat(tmp->value, my_strcat(" ", tab[i]));
    tmp->next = NULL;
    return (tmp);
}

void change_alias(char **tab, variables_t **var)
{
    variables_t *temp = *var;
    variables_t *tmp = create_tmp(tab);

    if (temp == NULL) {
        *var = tmp;
        return;
    }
    for (; temp->next != NULL; temp = temp->next) {
        if (!my_strcmp(tab[0], temp->name)) {
            temp->value = strdup(tab[1]);
            return;
        }
    }
    if (!my_strcmp(tab[0], temp->name)) {
        temp->value = strdup(tab[1]);
        return;
    }
    temp->next = tmp;
}

int my_alias(env_t *env, char **tab, int *pip, variables_t **var)
{
    int fd = 0;

    if (tab[1] == NULL) {
        print_alias(var);
    } else {
        change_alias(tab, var);
    }
    return (0);
}