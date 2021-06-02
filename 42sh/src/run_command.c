/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int valid_cmd(char **path, char **tab)
{
    char *printable = NULL;

    if (access(tab[0], F_OK) == 0) {
        return (0);
    }
    if (path != NULL) {
        for (int i = 0; path[i] != NULL; i++) {
            printable = my_strcat(path[i], "/");
            printable = my_strcat(printable, tab[0]);
            if (access(printable, F_OK) == 0 && my_strcmp(path[i], "/")) {
                return (0);
            }
        }
    }
    my_printf("%s: Command not found.\n", tab[0]);
    return (1);
}

int exec(shell_t *shell, char **env, sh_t *sh)
{
    char **tab;
    char *result;
    int r = 0;
    char *temp_cmd = strdup(shell->command);
    int get_return = 0;
    temp_cmd[strlen(temp_cmd)] = '\0';
    temp_cmd = change_tab_var(temp_cmd);
    tab = my_str_to_word_array(temp_cmd, " \t\n");
    result = malloc(sizeof(char) * (r + 1));
    if (my_strcmp(tab[0], "alias"))
        for (int i = 0; tab[i] != NULL; i++)
            tab[i] = check_var(tab[i], sh->var, sh->envi);
    for (int i = 0; i < r + 1; result[i] = '\0', i++);
    for (int i = 0; tab[i] != NULL; i++) {
        result = my_strcat(result, tab[i]);
        result = my_strcat(result, " ");
    }
    get_return = run(result, env, shell->pip, sh);
    run_precmd(env, shell->pip, sh);
    return (get_return);
}
int run_three(char **tab, char **env, int *pip, sh_t *sh)
{
    char **path = get_path(sh->envi);

    if (!my_strcmp(tab[0], "if"))
        return (exec_if(tab, env, pip, sh));
    if (!my_strcmp(tab[0], "which") || !my_strcmp(tab[0], "where"))
        return (find_some_where(tab, path, pip));
    if (!my_strcmp(tab[0], "repeat")) {
        return (repeater(tab, env, pip, sh));
    } else
        return (executation(path, get_true_path(tab), env, pip));
}

int run_two(char **tab, char **env, int *pip, sh_t *sh)
{
    char **path = get_path(sh->envi);

    if (!my_strcmp(tab[0], "setenv"))
        return (my_setenv(sh->envi, tab, pip));
    if (!my_strcmp(tab[0], "unsetenv"))
        return (my_unsetenv(sh->envi, tab, pip));
    if (!my_strcmp(tab[0], "alias"))
        return (my_alias(sh->envi, &tab[1], pip, sh->var));
    if (!my_strcmp(tab[0], "history"))
        return (print_history(pip));
    if (!my_strcmp(tab[0], "set"))
        return (set_local_var(sh, tab[1]));
    if (!my_strcmp(tab[0], "unset"))
        return (unset_local_var(sh, tab[1]));
    return (run_three(tab, env, pip, sh));
}

int run(char *buffer, char **env, int *pip, sh_t *sh)
{
    char **tab = my_str_to_word_array(buffer, " \t\n");
    char **path = get_path(sh->envi);
    if (tab[0] == NULL || nocaracter(tab[0]) == 1)
        return (1);
    tab = check_inhib(checker(tab, sh->envi, path));
    tab = check_non_var(check_local_var(sh, tab));
    if (!my_strncmp(tab[0], "!", 1)) {
        tab = search_history(tab[0]);
        if (tab == NULL)
            return (1);
    }
    if (!my_strcmp(tab[0], "exit"))
        return (my_exit(pip));
    if (!my_strcmp(tab[0], "cd"))
        return (my_cd(tab, sh->envi, pip));
    if (!my_strcmp(tab[0], "echo"))
        return (my_echo(tab, pip));
    if (!my_strcmp(tab[0], "env"))
        return (print_env(sh->envi, pip));
    return (run_two(tab, env, pip, sh));
}