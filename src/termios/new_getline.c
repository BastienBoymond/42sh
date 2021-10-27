/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** new_getline
*/

#include "../include/shell.h"
#include "../include/my_termios.h"
#include "../../include/my.h"
#include <curses.h>

char **init_getline(my_termios_t *c)
{
    c->count = 0;
    c->input = 0;
    write(1, "\0337", 2);
    c->cmd = malloc(sizeof(char) * 5);
    memset(c->cmd, '\0', 5);
    change_terminal_settings(c, 1);
    return (init_completion_array());
}

void fill_cmd(my_termios_t *c)
{
    if (c->cursor_pos == my_strlen(c->cmd)) {
        write(1, &c->input, 1);
        char newput[1];
        newput[0] = c->input;
        newput[1] = '\0';
        c->cmd = my_strcat(c->cmd, newput);
        c->cursor_pos++;
    } else
        type_mid_string(c);
}

void events_two(my_termios_t *c)
{
    if (c->input == BACKSPACE) {
        exec_backspace(c);
        return;
    } else {
        fill_cmd(c);
    }
}

void ct_events_or_type(my_termios_t *c)
{
    if (c->input == CT)
        catch_inputs(c);
    else if (c->count == 0 && c->input != '\n' && c->input != TAB) {
        events_two(c);
    }
}

char *new_getline(my_termios_t *c)
{
    char **completion_arr = init_getline(c);

    while (c->input != '\n') {
        c->count = 0;
        c->input = getchar();
        if (new_line(c))
            return (c->cmd);
        ct_events_or_type(c);
        c->cmd = do_auto_completion(completion_arr, c->cmd, c);
    }
    c->input = -1;
    write(1, "\n", 1);
    change_terminal_settings(c, 0);
    if (c->cmd == NULL)
        return ("\n\0");
    return (c->cmd);
}