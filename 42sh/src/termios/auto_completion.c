/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** auto_completion
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

int get_dir_size(void)
{
    DIR *dir;
    struct dirent *directory;
    int nb = 0;

    dir = opendir(".");
    if (dir) {
        while ((directory = readdir(dir)) != NULL) {
            nb++;
        }
        closedir(dir);
    }
    return (nb);
}

char **init_completion_array(void)
{
    int files_nb = get_dir_size();
    int index = 0;
    DIR *dir;
    struct dirent *directory;
    char **completion_arr = malloc(sizeof(char *) * (files_nb + 1));

    if (files_nb <= 0)
        return (NULL);
    dir = opendir(".");
    if (dir) {
        while ((directory = readdir(dir)) != NULL) {
            completion_arr[index] = strdup(directory->d_name);
            index++;
        }
        closedir(dir);
    }
    return (completion_arr);
}

char *autocomplete(char *current, char **arr, my_termios_t *c, int index)
{
    int files_nb = get_dir_size();
    if (current == NULL)
        return (NULL);
    for (int i = 0; i < files_nb; i++) {
        if (strncmp(arr[i], current, strlen(current)) == 0) {
            write(1, "\0338", 2);
            write(1, "\033[0K", 4);
            current = strdup(arr[i]);
            return (current);
        }
    }
    return (NULL);
}

char *concat_words(char *cmd, char *next, char *prev, char *word)
{
    if (cmd == NULL)
        return (NULL);
    if (prev != NULL)
        cmd = my_strcat(prev, cmd);
    if (next != NULL)
        cmd = my_strcat(word, next);
    if (cmd != NULL) {
        dprintf(1, "%s", cmd);
    }
    return (cmd);
}

char *do_auto_completion(char **completion_arr, char *cmd, my_termios_t *c)
{
    int index = 0;
    int end = 0;
    char *prev = NULL;
    char *next = NULL;
    char *word = NULL;

    if (c->input != TAB)
        return (cmd);
    index = get_index_begining(cmd, "\t\n ", c, &end);
    prev = get_prev_word(cmd, index);
    next = get_next_words(cmd, index, end);
    word = get_current_words(cmd, index, end);
    cmd = autocomplete(word, completion_arr, c, index);
    cmd = concat_words(cmd, next, prev, word);
    if (cmd != NULL) {
        c->cursor_pos = my_strlen(cmd);
        return (cmd);
    }
    c->cursor_pos = my_strlen(c->cmd);
    return (c->cmd);
}