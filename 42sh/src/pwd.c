/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

env_t *changepwd(env_t *envi)
{
    env_t *temp = envi;
    char *str = malloc(sizeof(char) * 1000);
    char *str2 = malloc(sizeof(char) * 1000);
    int k = 0;
    for (;my_strncmp("PWD=", temp->env, 4); temp = temp->next);
    str = my_strcpy(str, "OLD");
    str = my_strcat(str, temp->env);
    getcwd(str2, 1000);
    temp->env = my_strcpy(temp->env, "PWD=");
    temp->env = my_strcat(temp->env, str2);
    for (;temp->next != NULL; temp = temp->next) {
        if (!my_strncmp("OLDPWD=", temp->next->env, 7)) {
            k++;
            temp->next->env = my_strcpy(temp->env, str);
        }
    }
    if (k == 0 && temp->next == NULL)
        temp = int_list_push_back(temp, str);
    return (envi);
}