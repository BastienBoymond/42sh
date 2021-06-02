/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int valid_glob(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '*' || str[i] == '?'
        || str[i] == '[' || str[i] == ']')
            return (0);
    }
    return (1);
}

char *concatenate(char *dest, char *src)
{
    dest = my_strcat(dest, src);
    dest = my_strcat(dest, "|");
    return (dest);
}

char **my_globing(char **tab)
{
    glob_t globing;
    char *str = NULL;
    int len = 0;
    for (int i = 0; tab[i]; i++) {
        globing.gl_offs = 0;
        if (valid_glob(tab[i]) == 0) {
            if (glob(tab[i], GLOB_DOOFFS, NULL, &globing) == GLOB_NOMATCH) {
                printf("%s%s\n", tab[0], ": No match.");
                exit(84);
            }
            for (int j = 0; globing.gl_pathv[j]; j++) {
                str = concatenate(str, globing.gl_pathv[j]);
                len += strlen(globing.gl_pathv[j]) + 1;
            }
        } else {
            str = concatenate(str, tab[i]);
            len += strlen(tab[i]) + 1;
        }
    }
    str[len - 1] = '\0';
    return (my_str_to_word_array(str, "|"));
}