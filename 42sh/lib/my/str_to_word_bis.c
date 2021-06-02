/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** str_to_word_bis.c
*/

#include <stdlib.h>

int check_next_sep(char const *sep, char c)
{
    for (int u = 0; sep[u] != '\0'; u++) {
        if (sep[u] == c) {
            return (0);
        }
    }
    return (1);
}

int norme(char const *str, char const *sep, int a, int i)
{
    if (str[i] == sep[a] && str[i + 1] != '\0' && \
    check_next_sep(sep, str[i + 1]) == 1) {
        return (1);
    } else {
        return (0);
    }
}

int get_nb_space(char const *str, char const *sep)
{
    int count = 0;
    int first_letter = 0;
    int space_tt = 0;
    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0' && first_letter == 0; i++) {
        for (int u = 0; sep[u] != '\0'; u++) {
            if (str[i] == sep[u]) {
                count++;
            }
        }
        if (count == 0) {
            first_letter = 1;
        } else {
            space_tt += count;
        }
        count = 0;
    }
    return (space_tt);
}