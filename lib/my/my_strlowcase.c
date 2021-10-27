/*
** EPITECH PROJECT, 2020
** my_strlowcase.c
** File description:
** put letter in lowercase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
    return (str);
}