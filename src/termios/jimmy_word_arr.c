/*
** EPITECH PROJECT, 2021
** ouhouh basiten wordarr pue
** File description:
** null 20
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"

int is_sep(char c, char *delim)
{
    for (int i = 0; delim[i] != 0; i++) {
        if (c == delim[i] || c == '\0') {
            return (1);
        }
    }
    return (0);
}

int get_word_nb(char *str, char *delim)
{
    int word_nb = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (is_sep(str[i], delim) == 0 && is_sep(str[i + 1], delim) == 1) {
            word_nb += 1;
        }
    }
    return (word_nb);
}

int get_word_len(char *str, char *delim, int i)
{
    int len = 0;

    for ( ; str[i] != 0 && is_sep(str[i], delim) == 0; i++)
        len++;
    return (len);
}

char **my_str_wordarr_delim(char *str, char *delim)
{
    int nb_word = get_word_nb(str, delim);
    int index = 0;
    int word_len = 0;
    char **arr = malloc(sizeof(char *) * (nb_word + 1));

    for (int i = 0; str[i]; i++) {
        for ( ; str[i] != 0 && is_sep(str[i], delim) == 1; i++);
        word_len = get_word_len(str, delim, i);
        arr[index] = malloc(sizeof(char) * (word_len + 1));
        my_strncpy(arr[index], str + i, word_len);
        arr[index][word_len] = '\0';
        i += word_len;
        index++;
        if (str[i] == 0)
            break;
    }
    arr[nb_word] = NULL;
    return (arr);
}