/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** 42_termios
*/

#ifndef MY_TERMIOS_H
#define MY_TERMIOS_H

void inputs(void);
char *new_getline(my_termios_t *c);
my_termios_t *init_shell_config(void);
void type_mid_string(my_termios_t *c);
void change_terminal_settings(my_termios_t *c, int fd);
char **init_completion_array(void);
char *do_auto_completion(char **completion_arr, char *cmd, my_termios_t *c);
int get_arr_size(char **arr);
int new_line(my_termios_t *c);
int catch_inputs(my_termios_t *c);

//completion
char *get_next_words(char *cmd, int index, int end);
char *get_current_words(char *cmd, int index, int end);
char *get_prev_word(char *cmd, int index);
int get_index_begining(char *cmd, char *seps, my_termios_t *c, int *end);
int get_index_sep(char cmd, char *seps);

#endif /* !MY_TERMIOS_H */
