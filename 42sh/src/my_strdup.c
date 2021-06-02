/*
** EPITECH PROJECT, 2020
** 42
** File description:
** my_strdup.c
*/

char *my_strdup(char *str)
{
    char *res = malloc(sizeof(char) * (strlen(str) + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        res[i] = str[i];
    }
    res[strlen(str)] = '\0';
    return (res);
}