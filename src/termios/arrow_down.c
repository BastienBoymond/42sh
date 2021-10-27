/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** arrow_down
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

void exec_down(my_termios_t *c)
{
    char *file = open_file("../.42shrc_history");
    char **arr = NULL;
    char **tmp = NULL;
    int i = 0;

    if (file == NULL)
        return;
    if (c->arrow_pos == 0)
        return;
    arr = my_str_wordarr_delim(file, "\n");
    write(1, "\0338", 2);
    write(1, "\033[0K", 4);
    for (; arr[i + c->arrow_pos]; i++);
    tmp = my_str_wordarr_delim(arr[i], "\t");
    c->arrow_pos -= 1;
    if (get_arr_size(tmp) > 2)
        change_cmd(c, tmp[2]);
}