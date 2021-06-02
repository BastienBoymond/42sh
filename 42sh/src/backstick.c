/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-bastien.boymond
** File description:
** backstick.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

char **get_cmd(FILE *fp)
{
    int i = 0;
    char **array = malloc(sizeof(char *) * 1000);
    char path[PATH_MAX];

    array[0] = NULL;
    while (fgets(path, PATH_MAX, fp) != NULL) {
        array[i] = strdup(path);
        i++;
    }
    array[i] = NULL;
    return (array);
}

void backstick(shell_t *shell, char **env, sh_t *sh)
{
    FILE *fp;
    char *cmd = NULL;
    char **array = NULL;

    fp = popen(shell->right->command, "r");
    array = get_cmd(fp);
    if (shell->left->command != NULL) {
        cmd = shell->left->command;
        for (int a = 0; array[a]; a++) {
            cmd = strcat(cmd, " ");
            cmd = strcat(cmd, array[a]);
        }
        run(cmd, env, shell->pip, sh);
    } else {
        run(array[0], env, shell->pip, sh);
    }
    pclose(fp);
    free_array(array);
}