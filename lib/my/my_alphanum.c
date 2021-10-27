/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** power but recusive
*/

int nocaracter(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            return (0);
        if (str[i] >= 'A' && str[i] <= 'Z')
            return (0);
        if (str[i] >= '0' && str[i] <= '9')
            return (0);
    }
    return (1);
}

int onlyalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 0 && str[i] <= 47)
            return (0);
        if (str[i] >= 58 && str[i] <= 64)
            return (0);
        if (str[i] >= 91 && str[i] <= 94)
            return (0);
        if (str[i] == 96)
            return (0);
        if (str[i] >= 123 && str[i] <= 127)
            return (0);
    }
    return (1);
}