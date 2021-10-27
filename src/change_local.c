/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** change_local.c
*/

#include "../include/my.h"
#include "../include/shell.h"

static char *get_local_var(sh_t *sh, char *name)
{
    for (local_t *temp = *sh->local; temp != NULL; temp = temp->next) {
        if (!my_strcmp(temp->name, name))
            return (temp->value);
    }
    return (NULL);
}

static char *change_local_var(sh_t *sh, char *word, int i)
{
    char *value = get_local_var(sh, &word[i + 1]);

    if (value == NULL)
        return (word);
    word[i] = '\0';
    word = my_strcat(word, value);
    return (word);
}

static char *parcours_word(sh_t *sh, char *word)
{
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == '$') {
            word = change_local_var(sh, word, i);
        }
    }
    return (word);
}

char **check_local_var(sh_t *sh, char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i] = parcours_word(sh, tab[i]);
    }
    return (tab);
}