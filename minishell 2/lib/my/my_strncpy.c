/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** header
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest , char const *src , int n)
{
    int i = 0;
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > my_strlen(src))
        dest[i] = '\0';

    return (dest);
}
