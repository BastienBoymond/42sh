/*
** EPITECH PROJECT, 2021
** lld
** File description:
** lld
*/

#include "../include/my.h"
#include "../include/shell.h"

void push_double_front(histo_list_t **list, char *value)
{
    histo_list_t *new = malloc(sizeof(histo_list_t));

    new->command = strdup(value);
    new->next = (*list);
    new->prev = NULL;

    if ((*list) != NULL)
        (*list)->prev = new;
    (*list) = new;
}

void push_double_back(histo_list_t *list, char *value)
{
    histo_list_t *new = malloc(sizeof(histo_list_t));

    new->command = strdup(value);
    new->next = list->next;
    list->next = new;
    new->prev = list;
    if (new->next != NULL)
        new->next->prev = new;
}