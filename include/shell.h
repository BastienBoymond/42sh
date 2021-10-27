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
#include <stdbool.h>
#include <dirent.h>
#include <glob.h>
#include <time.h>
#include <termios.h>
#include <ncurses.h>
#include <limits.h>
#include "variables.h"

#define POS 9
#define B_PATH "/usr/local/sbin:\
/usr/local/bin:/usr/sbin:/usr/bin:\
/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"

#define CT 27
#define ALT 91
#define ARROW_LEFT 68
#define ARROW_RIGHT 67
#define ARROW_UP 65
#define ARROW_DOWN 66
#define BACKSPACE 127
#define TAB 9

typedef enum type_s
{
    EXEC,
    COMMA,
    PIPE,
    L_REDIRECT,
    R_REDIRECT,
    DL_REDIRECT,
    DR_REDIRECT,
    AND_AND,
    PIPE_PIPE,
    BACKTICK
} type_t;

typedef struct shell_s
{
    int good_exec;
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

typedef struct local_s
{
    char *name;
    char *value;
    struct local_s *next;
} local_t;

typedef struct sh_s
{
    variables_t **var;
    local_t **local;
    env_t *envi;
    int sep;
} sh_t;

typedef struct sep_s
{
    type_t *type;
    void (*exec)(shell_t *shell, char **env, sh_t *sh);
}sep_t;

typedef struct histo_list_s {
    char *command;
    struct histo_list_s *next;
    struct histo_list_s *prev;
}histo_list_t;

// struct termios config
typedef struct termios term_t;

typedef struct my_termios_s {
    term_t term;
    int count;
    char *cmd;
    int type;
    char input;
    int cursor_pos;
    int arrow_pos;
} my_termios_t;

// typedef struct

typedef struct arr_s {
    int type;
    void (*ptr)(my_termios_t *c);
} arr_t;

//fonction for run

void exec_up(my_termios_t *c);
void exec_down(my_termios_t *c);
void exec_left(my_termios_t *c);
void exec_right(my_termios_t *c);

void exec_backspace(my_termios_t *c);

static const arr_t func[] = {
    {ARROW_UP, exec_up},
    {ARROW_DOWN, exec_down},
    {ARROW_RIGHT, exec_right},
    {ARROW_LEFT, exec_left},
};

char **check_non_var(char **arr);

char *change_tab_var(char *str);

void change_cmd(my_termios_t *c, char *new_cmd);

char **my_str_wordarr_delim(char *str, char *delim);

char *my_itoa(int number);

char *check_var(char *word, variables_t **var, env_t *env);

int exec_if(char **tab, char **env, int *pip, sh_t *sh);

char *tabcat(char **tab);

int order(shell_t *shell, char **env, sh_t *sh);

int exec(shell_t *shell, char **env, sh_t *sh);

int run(char *buffer, char **env, int *pip, sh_t *sh);

void comma(shell_t *shell, char **env, sh_t *sh);

void my_pipe(shell_t *shell, char **env, sh_t *sh);

char **get_true_path(char **path);

void backstick(shell_t *shell, char **env, sh_t *sh);

void l_redirect(shell_t *shell, char **env, sh_t *sh);

void print_prompt(env_t *envi);

void r_redirect(shell_t *shell, char **env, sh_t *sh);

void dl_redirect(shell_t *shell, char **env, sh_t *sh);

variables_t **create_variables(void);

sh_t create_sh(char **env, int argc);

void run_precmd(char **env, int *pip, sh_t *sh);

int redirect_fourth(ld_t *red, shell_t *shell, char **env, sh_t *sh);

void dr_redirect(shell_t *shell, char **env, sh_t *sh);

int no_sep(char *cmd, sh_t *sh);

char **checker(char **tab, env_t *envi, char ** path);

char **check_alias(char **tmp, char **tab, env_t *envi);

char *parsing_left(char *cmd, int total);

char *parsing_right(char *cmd, int start, int total);

int my_alias(env_t *env, char **tab, int *pip, variables_t **var);

int error_handing_red(shell_t *shell);

shell_t *fill_nodes(char *buffer);

void parse_cmd(parsing_t *pars, char *cmd);

// fonct with execve

int executation(char **path, char **tab, char **env, int *pip);

// fonct for env

env_t *int_list_push_back(env_t *env, char *varenv);

env_t *int_list_destroy(env_t *env, char *str);

int my_setenv(env_t *envi, char **tab, int *pip);

int my_unsetenv(env_t *envi, char **tab, int *pip);

env_t *pop_front(env_t *dest);

int print_env(env_t *env, int *pip);


//fonction for cd

int my_cd(char **tab, env_t *envi, int *pip);

int get_direct(char *str);

int my_exit(int *pip);

//fonction for pwd gestion

env_t *changepwd(env_t *envi);

//fonction for path

char **get_path(env_t *envi);

type_t *biggest_sep(char *cmd);

env_t *init(env_t *envi, char **env, int argc);

void sig_catch(int sig);

void verify_tty(sh_t *sh);

void error_handing(char **tab, int error, int *pip);

int my_echo(char **tab, int *pip);

int my_echo_two(char **tab);

int valid_cmd(char **path, char **tab);

void double_pipe(shell_t *shell, char **env, sh_t *sh);

void and_and(shell_t *shell, char **env, sh_t *sh);

char **my_arraycat(char **tmp, char **tab, int len);

char **checker(char **tab, env_t *envi, char **path);

char **check_inhib(char **tab);

char **my_globing(char **tab);

void history(char *buffer);

int print_history(int pip[2]);

char **search_history(char *cmd);

int valid_glob(char *str);

char *concatenate(char *dest, char *src);

int tab_len(char **tab);

void print_tree(shell_t *binary_tree);

int find_some_where(char **tab, char **path, int *pip);

int repeater(char **tab, char **env, int *pip, sh_t *sh);

int set_local_var(sh_t *sh, char *cmd);

void parsing(char *cmd, shell_t *tree, sh_t *sh);

int unset_local_var(sh_t *sh, char *cmd);

char **check_local_var(sh_t *sh, char **tab);

int check_sep(char *cmd, sh_t *sh);

char get_char(char c);