/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"
#include "../include/my_termios.h"

void print_tree(shell_t *binary_tree)
{
    if (binary_tree == NULL)
        return;
    my_printf("%s\n", binary_tree->command);
    print_tree(binary_tree->left);
    print_tree(binary_tree->right);
}

void init_command_history(histo_list_t *list)
{
    char *file = open_file("../.42shrc_history");
    char **arr = my_str_to_word_array(file, "\n");
    char **tmp = NULL;

    for (int i = 0; arr[i]; i++) {
        tmp = my_str_to_word_array(arr[i], "\t");
        if (get_arr_size(tmp) > 3) {
            printf("puhsing %s\n", tmp[4]);
            push_double_front(&list, tmp[4]);
        }
    }
}

int main(int argc, char *argv[], char *env[])
{
    char *buffer = NULL;
    size_t len = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    my_termios_t *config = init_shell_config();
    sh_t sh = create_sh(env, argc);

    verify_tty(&sh);
    while (1) {
        if (isatty(STDIN_FILENO) == 1) {
            buffer = new_getline(config);
        } else if (getline(&buffer, &len, stdin) == -1)
            exit(0);
        history(buffer);
        shell = fill_nodes(buffer);
        no_sep(buffer, &sh);
        parsing(buffer, shell, &sh);
        order(shell, env, &sh);
        verify_tty(&sh);
    }
    return (0);
}