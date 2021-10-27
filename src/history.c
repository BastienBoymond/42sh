/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** execution.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int tab_len(char **tab)
{
    int i = 0;
    if (tab == NULL)
        return (0);
    for (; tab[i]; i++);
    return (i);
}

void printing_search(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (tab[i + 1] == NULL)
            my_printf("%s", tab[i]);
        else
            my_printf("%s ", tab[i]);
    }
    my_printf("\n");
}

char **search_history(char *cmd)
{
    char *file = open_file("../.42shrc_history");
    char **line = my_str_to_word_array(file, "\n");
    char **command = NULL;
    char **tab = NULL;
    int k = 0;
    cmd = cmd + 1;
    if (my_str_isnum(cmd) == 0)
        k = 2;
    for (int i = 0; line[i]; i++) {
        command = my_str_to_word_array(line[i], "\t");
        if (!my_strncmp(cmd, command[k], my_strlen(cmd)) && command[2] != NULL)
            tab = my_str_to_word_array(command[2], " \t\n");
    }
    if (tab == NULL) {
        my_printf("%s: Event not found.\n", cmd);
        return (NULL);
    }
    printing_search(tab);
    return (tab);
}

int print_history(int pip[2])
{
    char *file = open_file("../.42shrc_history");

    dup2(pip[0], 0);
    dup2(pip[1], 1);
    my_printf("%s", file);
    return (0);
}

void history(char *buffer)
{
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int fd = open("../.42shrc_history", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd <= 0 || open_file("../.42shrc_history") == NULL)
        return;
    char **file = my_str_to_word_array(open_file("../.42shrc_history"), "\n");
    if (file == NULL)
        return;
    int i = tab_len(file) + 1;
    int hour = tm_struct->tm_hour;
    int min = tm_struct->tm_min;

    if (buffer == NULL)
        return;
    dprintf(fd, "\t%d\t%d:%d\t%s\n", i, hour, min, buffer);
    close(fd);
}