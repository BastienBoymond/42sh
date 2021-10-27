/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** new_getline_events
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

void catch_arrows(my_termios_t *c)
{
    char input = getchar();

    if (input != ALT)
        return;
    input = getchar();
    if (input >= 65 && input <= 68)
        func[input - 65].ptr(c);
}

int catch_inputs(my_termios_t *c)
{
    if (c->input == CT) {
        catch_arrows(c);
        c->count++;
        return (1);
    }
    return (0);
}

int new_line(my_termios_t *c)
{
    if (c->input == '\n') {
        printf("\n");
        c->cursor_pos = 0;
        c->arrow_pos = 0;
        return (1);
    }
    return (0);
}