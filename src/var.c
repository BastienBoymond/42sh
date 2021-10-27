/*
** EPITECH PROJECT, 2021
** bastien le nullos
** File description:
** il check pas null
*/

#include "../include/my.h"
#include "../include/shell.h"

static int var_exist(char *word, variables_t **var)
{
    variables_t *temp = *var;

    for (; temp != NULL; temp = temp->next) {
        if (!my_strcmp(temp->name, word)) {
            return (1);
        }
    }
    return (0);
}

char *check_var(char *word, variables_t **var, env_t *env)
{
    variables_t *temp = *var;

    for (; temp != NULL; temp = temp->next) {
        if (!my_strcmp(word, temp->name) && var_exist(temp->value + 1, var))
            return (check_var(temp->value + 1, var, env));
        if (!my_strcmp(word, temp->name))
            return (temp->value);
    }
    for (env_t *t_env = env; t_env != NULL; t_env = t_env->next) {
        if (!my_strcmp(my_str_to_word_array(t_env->env, "=")[0], word + 1)) {
            word = my_str_to_word_array(t_env->env, "=")[1];
        }
    }
    if (var_exist(word, var))
        return (check_var(word, var, env));
    return (word);
}

char **get_true_path(char **path)
{
    for (int i = 0; path[i] != NULL; i++)
        if (path[i][0] == '\0')
            path[i + 1] = my_strcat(" ", path[i + 1]);
    return (path);
}
