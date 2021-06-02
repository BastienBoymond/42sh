/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** describe all fonction
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <dirent.h>

#define POS 7

typedef enum type_s
{
    EXEC,
    COMMA,
    PIPE,
    L_REDIRECT,
    R_REDIRECT,
    DL_REDIRECT,
    DR_REDIRECT
}type_t;

typedef struct shell_s
{
    int pip[2];
    type_t *type;
    char *command;
    struct shell_s *right;
    struct shell_s *left;
}shell_t;

typedef struct ld_s
{
    int pip[2];
    pid_t pid;
    int status;
    char *str;
    char *buffer;
    char *total;
    size_t len;
}ld_t;

typedef struct parsing_s
{
    type_t *type;
    char *left;
    char *right;
}parsing_t;

typedef struct env_s
{
    char *env;
    struct env_s *next;
}env_t;

typedef struct sep_s
{
    type_t *type;
    void (*exec)(shell_t *shell, char **env, env_t *envi);
}sep_t;

//fonction for run

void order(shell_t *shell, char **env, env_t *envi);

void exec(shell_t *shell, char **env, env_t *envi);

void run(char *buffer, char **env, env_t *envi, int *pip);

void comma(shell_t *shell, char **env, env_t *envi);

void my_pipe(shell_t *shell, char **env, env_t *envi);

void l_redirect(shell_t *shell, char **env, env_t *envi);

void r_redirect(shell_t *shell, char **env, env_t *envi);

void dl_redirect(shell_t *shell, char **env, env_t *envi);

int redirect_fourth(ld_t *red, shell_t *shell, char **env, env_t *envi);

void dr_redirect(shell_t *shell, char **env, env_t *envi);

void parsing(char *cmd, shell_t *tree);

char *parsing_left(char *cmd, int total);

char *parsing_right(char *cmd, int start, int total);

int error_handing_red(shell_t *shell);

shell_t *fill_nodes(char *buffer);

// fonct with execve

void executation(char **path, char **tab, char **env, int *pip);

// fonct for env

env_t *int_list_push_back(env_t *env, char *varenv);

env_t *int_list_destroy(env_t *env, char *str);

void my_setenv(env_t *envi, char **tab, int *pip);

void my_unsetenv(env_t *envi, char **tab, int *pip);

env_t *pop_front(env_t *dest);

void print_env(env_t *env, int *pip);


//fonction for cd

void my_cd(char **tab, env_t *envi, int *pip);

int get_direct(char *str);

void my_exit(int *pip);

//fonction for pwd gestion

env_t *changepwd(env_t *envi);

//fonction for path

char **get_path(env_t *envi);

int check_sep(char *cmd);

type_t *biggest_sep(char *cmd);

env_t *init(env_t *envi, char **env);

void sig_catch(int sig);

void error_handing(char **tab, int error, int *pip);