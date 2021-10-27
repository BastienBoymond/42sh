/*
** EPITECH PROJECT, 2021
** diogo le dog
** File description:
** wouf wouf
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../include/my.h"

char *remove_parenthesis(char *str)
{
    char new[255] = {0};
    int index = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != '(' && str[i] != ')') {
            new[index] = str[i];
            index++;
        }
    }
    return (strdup(new));
}

bool is_number(char *str)
{
    int neg_nb = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        if (str[i] == '-')
            neg_nb++;
    }
    if (neg_nb > 1)
        return (false);
    return (true);
}

int verif_equal_statement(char **tab, char **env, int *pip, sh_t *sh)
{
    if ((is_number(tab[1]) && !is_number(tab[3])) ||
    (!is_number(tab[1]) && is_number(tab[3])))
        return (0);
    if (is_number(tab[1])) {
        if (atoi(tab[1]) == atoi(tab[3])) {
            return (run(tabcat(tab + 4), env, pip, sh));
        }
    }
    if (strcmp(tab[1], tab[3]) == 0) {
        return (run(tabcat(tab + 4), env, pip, sh));
    }
    return (0);
}

int verif_not_equal_statement(char **tab, char **env, int *pip, sh_t *sh)
{
    if ((is_number(tab[1]) && !is_number(tab[3])) ||
    (!is_number(tab[1]) && is_number(tab[3])))
        return (0);
    if (is_number(tab[1])) {
        if (atoi(tab[1]) != atoi(tab[3])) {
            return (run(tabcat(tab + 4), env, pip, sh));
        }
    }
    if (strcmp(tab[1], tab[3]) != 0)
        return (run(tabcat(tab + 4), env, pip, sh));
    return (0);
}

int exec_if(char **tab, char **env, int *pip, sh_t *sh)
{
    if (get_arr_size(tab) <= 4 ||
    (!strcmp(tab[2], "==") && !strcmp(tab[2], "!=")))
        return (0);
    tab[1] = remove_parenthesis(tab[1]);
    tab[3] = remove_parenthesis(tab[3]);
    if (tab[2][0] == '=')
        return (verif_equal_statement(tab, env, pip, sh));
    return (verif_not_equal_statement(tab, env, pip, sh));
}