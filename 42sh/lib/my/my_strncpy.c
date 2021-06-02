/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** header
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest , char const *src , int n)
{
    for (int t = 0; n > t; t++)
        dest[t] = src[t];
    return (dest);
}
