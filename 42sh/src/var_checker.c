/*
** EPITECH PROJECT, 2020
** 42
** File description:
** var_checker.c
*/

#include "../include/my.h"
#include "../include/shell.h"

char *change_tab_var(char *str)
{
    char *res = malloc(sizeof(char) * (strlen(str) + 1));
    int quote = 0;

    for (int i = 0; i < strlen(str) + 1; res[i] = '\0', i++)
    for (int i = 0, j = 0; str[j] != '\0'; i++, j++) {
        if (str[j] == '\'')
            quote++;
        if (str[j] == '$' && quote % 2)
            res[i] = 1;
        else
            res[i] = str[j];
    }
    return (res);
}

char **check_non_var(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            arr[i][j] = arr[i][j] == 1 ? '$' : arr[i][j];
        }
    }
    return (arr);
}
