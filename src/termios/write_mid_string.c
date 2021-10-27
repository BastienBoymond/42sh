/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** write_mid_string
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

void type_mid_string_two(my_termios_t *c, int len)
{
    for (int i = len - c->cursor_pos; i > 0; i--)
        write(1, "\033[1D", 4);
    c->cursor_pos++;
    write(1, "\033[1C", 4);
}

void type_mid_string(my_termios_t *c)
{
    char *next = NULL;
    char *temp = malloc(sizeof(char) * 2);
    char *temp_char = malloc(sizeof(char) * 2);
    int len = 0;

    if (c->cursor_pos <= 0)
        return;
    memset(temp, '\0', 2);
    memset(temp_char, '\0', 2);
    temp_char[0] = c->input;
    next = strdup(c->cmd + c->cursor_pos);
    temp[0] = c->cmd[c->cursor_pos];
    c->cmd[c->cursor_pos] = '\0';
    write(1, "\0338", 2);
    write(1, "\033[0K", 4);
    c->cmd = my_strcat(c->cmd, temp_char);
    c->cmd = my_strcat(c->cmd, next);
    dprintf(1, "%s", c->cmd);
    len = strlen(c->cmd);
    type_mid_string_two(c, len);
}