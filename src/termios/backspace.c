/*
** EPITECH PROJECT, 2021
** shell
** File description:
** shell
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

void exec_backspace(my_termios_t *c)
{
    char *next = NULL;
    int len = 0;

    if (c->cursor_pos <= 0)
        return;
    next = c->cmd + c->cursor_pos;
    write(1, "\0338", 2);
    write(1, "\033[0K", 4);
    c->cursor_pos -= 1;
    c->cmd[c->cursor_pos] = '\0';
    c->cmd = my_strcat(c->cmd, next);
    dprintf(1, "%s", c->cmd);
    len = strlen(c->cmd);
    for (int i = len - c->cursor_pos; i > 0; i--)
        write(1, "\033[1D", 4);
}