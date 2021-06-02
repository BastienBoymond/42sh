/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** arrow_left
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

void exec_left(my_termios_t *c)
{
    if (c->cursor_pos <= 0)
        return;
    write(1, "\033[1D", 4);
    c->cursor_pos--;
}