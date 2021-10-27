/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** parse_wods_completion
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

int get_index_sep(char cmd, char *seps)
{
    for (int i = 0; i < 3; i++) {
        if (cmd == seps[i])
            return (1);
    }
    return (-1);
}

int get_index_begining(char *cmd, char *seps, my_termios_t *c, int *end)
{
    char *words = NULL;
    int len = my_strlen(cmd);
    int index = c->cursor_pos;

    if (len <= c->cursor_pos)
        for (; len <= index; index--)
    *end = index;
    for (; index >= 0; index--) {
        if (get_index_sep(cmd[index], seps) == 1)
            break;
    }
    index++;
    return (index);
}

char *get_prev_word(char *cmd, int index)
{
    char *prev = strndup(cmd, index);

    if (strcmp(prev, "") == 0)
        return (NULL);
    return (prev);
}

char *get_current_words(char *cmd, int index, int end)
{
    char *temp = NULL;
    if (my_strlen(cmd) == 0)
        return (NULL);
    temp = strdup(cmd + index);
    char *next = strndup(temp, end);

    return (next);
}

char *get_next_words(char *cmd, int index, int end)
{
    char *next = NULL;

    if (end + index >= my_strlen(cmd))
        return (NULL);
    strdup(cmd + end + index);
    return (next);
}