/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** arrow_right
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

void exec_right(my_termios_t *c)
{
    if (c->cursor_pos >= my_strlen(c->cmd))
        return;
    write(1, "\033[1C", 4);
    c->cursor_pos++;
}