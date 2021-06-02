/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** get nb of word
*/

int get_nb_words(const char *str, const char *separator)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; separator[j] != '\0'; j++) {
            count = (str[i] == separator[j]) ? count + 1: count;
        }
    }
    return (count);
}