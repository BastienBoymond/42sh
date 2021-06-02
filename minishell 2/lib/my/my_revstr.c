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
    int len = my_strlen(str);
    unsigned char c;

    while (i < len / 2) {
        c = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = c;
        i++;
    }
    return (str);
}
