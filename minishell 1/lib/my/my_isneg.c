/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** Display N or P
*/

int my_putchar(char);

int my_isneg(int n)
{
    if (n >= 0){
        my_putchar('P');
    }
    else{
        my_putchar('N');
    }
    return (0);
}
