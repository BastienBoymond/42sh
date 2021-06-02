/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "my.h"
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

char *fill_buffer(char *buffer, int fd, int size)
{
    int r = 0;

    r = read(fd, buffer, size);
    if (r == -1) {
        return (NULL);
    }
    if (buffer[0] == '\0') {
        return (NULL);
    }
    return (buffer);
}

char *open_file(char *file)
{
    struct stat buff;
    int fd = open(file, O_RDONLY | O_CREAT, 0666);
    char *buffer = NULL;
    int ret = 0;
    int size = 0;

    if (fd < 0)
        return (NULL);
    ret = stat(file, &buff);
    if (ret == -1)
        return (NULL);
    size = buff.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    buffer = fill_buffer(buffer, fd, size);
    if (buffer == NULL)
        return (NULL);
    close(fd);
    return (buffer);
}
