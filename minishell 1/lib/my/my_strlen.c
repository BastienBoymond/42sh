/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** A program that counts the numbers of characters
*/

int my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
