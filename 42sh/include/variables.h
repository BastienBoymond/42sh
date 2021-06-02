/*
** EPITECH PROJECT, 2020
** 42
** File description:
** variables.h
*/

#ifndef __VAR_H__
#define __VAR_H__

typedef struct variables_s
{
    char *name;
    char *value;
    struct variables_s *next;
} variables_t;

#endif