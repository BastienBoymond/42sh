/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** header
*/

int my_strlen(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_revstr(char *str)
{
    int i = 0;
    int l = my_strlen(str);
    unsigned char c;

    while (i < l / 2) {
        c = str[i];
        str[i] = str[l - 1 - i];
        str[l - 1 - i] = c;
        i++;
    }
    return (str);
}
