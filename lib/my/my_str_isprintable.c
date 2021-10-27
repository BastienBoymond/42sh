/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** isprintable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 0 && str[i] <= 31)
            return (0);
        i++;
    }
    return (1);
}