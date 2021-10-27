/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** execution.c
*/

#include "../include/my.h"
#include "../include/shell.h"

void error_handing(char **tab, int error, int *pip)
{
    my_printf("%s: %s.", tab[0], strerror(error));
    if (error == ENOEXEC)
        my_printf(" Wrong Architecture.\n");
    else
        my_printf("\n");
}

void exec2(char **path, char **tab, char **env, int *pip)
{
    char *printable = NULL;
    dup2(pip[0], 0);
    dup2(pip[1], 1);
    if (access(tab[0], F_OK) == 0) {
        execve(tab[0], tab, env);
        error_handing(tab, errno, pip);
        exit(0);
    }
    for (int i = 0; path[i] != NULL; i++) {
        printable = my_strcat(path[i], "/");
        printable = my_strcat(printable, tab[0]);
        if (access(printable, F_OK) == 0 && my_strcmp(path[i], "/")) {
            execve(printable, tab, env);
            error_handing(tab, errno, pip);
            exit(0);
        }
    }
    my_printf("%s: Command not found.\n", tab[0]);
    exit(0);
}

void sig_catch(int sig)
{
    int term = 0;

    if (WIFSIGNALED(sig)) {
        term = WTERMSIG(sig);
        if (term == SIGSEGV)
            write (2, strsignal(term), my_strlen(strsignal(term)));
        if (term == SIGFPE)
            write(2, "Floating exception", 18);
        if (WCOREDUMP(sig))
            write(2, " (core dumped)\n", 15);
        else
            write(2, "\n", 1);
    }
}

char **get_path(env_t *envi)
{
    char *env = my_strcpy(env, B_PATH);
    char **path = NULL;
    int i = 0;

    for (; envi != NULL; envi = envi->next) {
        if (envi->env[0] == 'P' && envi->env[1] == 'A' \
        && envi->env[2] == 'T' && envi->env[3] == 'H' && envi->env[4] == '=') {
            path = my_str_to_word_array(&envi->env[5], ":");
            i += 1;
        }
    }
    if (i == 0)
        path = my_str_to_word_array(&env[5], ":");
    return (path);
}

int executation(char **path, char **tab, char **env, int *pip)
{
    pid_t pid;
    int status = 0;
    if (valid_cmd(path, tab) == 1)
        return (1);
    pid = fork();
    if (pid == -1) {
        perror(NULL);
        exit (84);
    } else if (pid == 0) {
        tab = my_globing(tab);
        exec2(path, tab, env, pip);
    } else {
        waitpid(pid, &status, 0);
        dup2(dup(1), 1);
        dup2(dup(0), 0);
        sig_catch(status);
    }
    return (0);
}