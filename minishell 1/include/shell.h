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

typedef struct env_s
{
    char *env;
    struct env_s *next;
}env_t;

// fonct with execve

void executation(char **path, char **tab, char **env);

// fonct for env

env_t *int_list_push_back(env_t *env, char *varenv);

env_t *int_list_destroy(env_t *env, char *str);

env_t *my_setenv(env_t *envi, char **tab);

env_t *my_unsetenv(env_t *envi, char **tab);

env_t *pop_front(env_t *dest);

void print_env(env_t *env);

//fonction for cd

env_t *my_cd(char **tab, env_t *envi);

//fonction for pwd gestion

env_t *changepwd(env_t *envi);

//fonction for path

char **get_path(env_t *envi);