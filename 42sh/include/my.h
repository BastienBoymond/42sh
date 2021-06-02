/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** describe all fonction
*/

#include <stdarg.h>

#define EXIT_SUCCESS    0
#define EXIT_ERROR      84
#define ARRAY_SIZE      3

typedef struct my_printf_s
{
    char c;
    void (*str)(va_list);
}my_printf_t;

/*
my_putchar put a character
*/

void my_putchar(char);

/*
my_putstr put a str
*/

int my_putstr(char const *str);

/*
my_strlen calculate lenght of str
*/

int my_strlen(char const *str);

/*
my_strcmp compare different char
if return 0 it same char
else we got a difference
*/

int my_strcmp(char const *s1, char const *s2);

/*
my_strncmp is my_strcmp but with n char
*/

int my_strncmp(char const *s1, char const *s2, int n);

/*
my_strstr find a str in another str
*/

char *my_strstr(char *str, char const *to_find);

/*
my_strcat concatenate 2 str
*/

char *my_strcat(char *s1, char *s2);

/*
my_compute_power_rec is recursive power
*/

int my_compute_power_rec(int nb, int p);

/*
my_compute_square_rec_root do square
*/

int my_compute_square_root(int nb);

/*
my_find_prime_sup find prime number
*/

int my_find_prime_sup(int nb);

/*
my_get number is use to get number
*/

int my_getnbr(char const *str);

/*
my_isneg put P if positive and N if negative
*/

int my_isneg(int n);

/*
my_is_prime find if number was prime or not
*/

int my_is_prime(int nb);

/*
my_put_nbr put number
*/

int my_put_nbr(int nb);

/*
my_revstr reverse a str
*/

char *my_revstr(char *str);

/*
my_showmem not exist
*/

int my_showmem(char const *str, int size);

/*
my_showstr not exist
*/

int my_showstr(char const *str);

/*
my_sort_int_array not exist
*/

void my_sort_int_array(int *tab, int size);

/*
my_strcapitalize not exist
*/

char *my_strcapitalize(char *str);

/*
my_strcpy copy str
*/

char *my_strcpy(char *dest, char const *src);

/*
my_str_isapha define if str was alpha or not
*/

int my_str_isalpha(char const *str);

/*
my_str_islower define if was lower
*/

int my_str_islower(char const *str);

/*
my_str_isnum define if number into str
*/

int my_str_isnum(char const *str);

/*
my_str_isprintable not exist
*/

int my_str_isprintable(char const *str);

/*
my_str_isupper  not exist
*/

int my_str_isupper(char const *str);

/*
my_strlowcase put all up in low
*/

char *my_strlowcase(char *str);

/*
my_strncat not exist
*/

char *my_strncat(char *dest, char const *src, int nb);

/*
my_strncpy copy n str
*/

char *my_strncpy(char *dest, char const *src, int n);

/*
my_strupcase put down in up
*/

char *my_strupcase(char *str);

/*
my_swap
*/

void my_swap(int *a, int *b);

//is my_printf

int my_printf(char *str, ...);

//my_str_to_word_array

int get_nb_words(const char *str, const char *separator);

char **my_str_to_word_array(char const *str, const char *sep);

//all this file was here for printf

void flag_nbr(va_list ap);

void flag_char(va_list ap);

void flag_str(va_list ap);

int nocaracter(char *str);

int onlyalphanum(char *str);

char *open_file(char *file);