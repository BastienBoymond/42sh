/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** execution.c
*/

#include "include/my.h"
#include "include/shell.h"

void error_handing(char **tab, int error)
{
    my_printf("%s: %s.", tab[0], strerror(errno));
    if (errno == ENOEXEC)
        my_printf(" Wrong Architecture.\n");
    else 
        my_printf("\n");
}

void exec2(char **path, char **tab, char **env)
{
    char *printable = NULL;

    if (access(tab[0], F_OK) == 0) {
        execve(tab[0], tab, env);
        error_handing(tab, errno);
        exit(0);
    }
    for (int i = 0; path[i] != NULL; i++) {
        printable = my_strcat(path[i], "/");
        printable = my_strcat(printable, tab[0]);
        if (access(printable, F_OK) == 0) {
            execve(printable, tab, env);
            error_handing(tab, errno);
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
    char **path = NULL;

    for (; envi != NULL; envi = envi->next) {
        if (envi->env[0] == 'P' && envi->env[1] == 'A' \
        && envi->env[2] == 'T' && envi->env[3] == 'H' && envi->env[4] == '=') {
            path = my_str_to_word_array(&envi->env[5], ":");
        }
    }
    return (path);
}

void executation(char **path, char **tab, char **env)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1) {
        perror(NULL);
        exit (84);
    } else if (pid == 0) {
        exec2(path, tab, env);
    } else {
        waitpid(pid, &status, 0);
        sig_catch(status);
    }
}