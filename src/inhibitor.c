/*
** EPITECH PROJECT, 2020
** 42
** File description:
** inhibitor.c
*/

#include "../include/my.h"
#include "../include/shell.h"

char get_char(char c)
{
    switch (c) {
        case 't':
            return ('\t');
        case 'b':
            return ('\b');
        case 'a':
            return ('\a');
        case 'n':
            return ('\n');
        case 'v':
            return ('\v');
        case 'r':
            return ('\r');
        case 'f':
            return ('\f');
    }
    return (' ');
}

char *check_backslash(char *tab)
{
    char *result = malloc(sizeof(char) * (strlen(tab) + 1));
    int str_index = 0;

    for (int i = 0; i <= strlen(tab); result[i] = '\0', i++);
    for (int i = 0, j = 0; tab[j] != NULL; i++, j++) {
        if (tab[j] == '\'' || tab[j] == '\"') {
            str_index++;
            j++;
        }
        if (tab[j] == '\\')
            result[i] = str_index % 2 ? get_char(tab[j++ + 1]) : tab[j++ + 1];
        else
            result[i] = tab[j];
    }
    return (result);
}

char **check_inhib(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        tab[i] = check_backslash(tab[i]);
    return (tab);
}