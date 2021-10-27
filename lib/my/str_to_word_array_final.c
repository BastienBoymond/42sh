/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** str_to_word_array_final.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int check_next_sep(char const *sep, char c);
int get_nb_space(char const *str, char const *sep);
char *my_strncpy(char *dest, char const *src, int n);
int norme(char const *str, char const *sep, int a, int i);

int get_nb_words(const char *str, const char *separator)
{
    int count = 1;
    int i = 0;
    int a = 0;
    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++) {
        for (; separator[a] != '\0'; a++) {
            count += norme(str, separator, a, i);
        }
        a = 0;
    }
    return (count);
}

int get_space(char c, const char *sep)
{
    for (int a = 0; sep[a] != '\0'; a++) {
        if (sep[a] == c) {
            return (1);
        }
    }
    return (0);
}

int get_size(char const *str, const char *sep, int index)
{
    for (int i = 0; sep[i] != '\0'; i++) {
        if (str[index] == sep[i] && str[index + 1] != '\0' && \
        check_next_sep(sep, str[index + 1]) == 1) {
            return (1);
        }
        if (str[index + 1] == '\0' && str[index] != sep[i]) {
            return (1);
        }
    }
    return (0);
}

int *get_size_word(char const *str, const char *sep, int nb_word)
{
    int *sizes = malloc(sizeof(int) * ((nb_word * 2) + 1));
    int space = 0;
    int tab = 0;
    int size = 1;
    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++, size++) {
        space += get_space(str[i], sep);
        if (get_size(str, sep, i) == 1) {
            sizes[tab] = size - space;
            tab++;
            sizes[tab] = space;
            size = 0;
            space = 0;
            tab++;
        }
    }
    sizes[tab] = '\0';
    return (sizes);
}

char **my_str_to_word_array(char const *str, const char *sep)
{
    int start_space = get_nb_space(str, sep);
    int nb_word = get_nb_words(str + start_space, sep);
    char **array = malloc(sizeof(char *) * (nb_word + 1));
    int len = start_space;
    int *size_words = get_size_word(str + start_space, sep, nb_word);
    if (str == NULL)
        return (NULL);
    for (int a = 0, b = 0; a < nb_word; a++, b++) {
        array[a] = malloc(sizeof(char) * (size_words[b]) + 1);
        my_strncpy(array[a], str + len, size_words[b]);
        array[a][size_words[b]] = '\0';
        len += size_words[b + 1] + size_words[b];
        b++;
    }
    free(size_words);
    array[nb_word] = NULL;
    return (array);
}