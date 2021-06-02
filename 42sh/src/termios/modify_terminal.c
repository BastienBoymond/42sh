/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** catch_inputs
*/

#include "../include/shell.h"
#include "../include/my_termios.h"

my_termios_t *init_shell_config(void)
{
    my_termios_t *c = malloc(sizeof(my_termios_t));

    c->cmd = malloc(sizeof(char) * 5);
    memset(c->cmd, '\0', 4);
    c->input = 0;
    c->count = 0;
    c->cursor_pos = 0;
    c->arrow_pos = 0;
    return (c);
}

void change_terminal_settings(my_termios_t *c, int fd)
{
    static struct termios oldtio, newtio;

    if (fd == 1) {
        tcgetattr(STDIN_FILENO, &oldtio);
        newtio = oldtio;
        newtio.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &newtio);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldtio);
    }
}