/*
** EPITECH PROJECT, 2020
** mini_shell
** File description:
** execution.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/shell.h"

void redirect_all_stdt(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_direct, test_cd_direct_work, .init = redirect_all_stdt)
{
    int i =  get_direct("../");
    cr_assert_eq(i, 0);
}

Test(get_direct, test_cd_direct_error, .init = redirect_all_stdt)
{
    int i =  get_direct("/root");
    cr_assert_eq(i, 1);
}

Test(get_indirect, test_cd_indirect_error, .init = redirect_all_stdt)
{
    int i =  get_indirect("Makefile");
    cr_assert_eq(i, 1);
}

Test(get_indirect, test_cd_indirect, .init = redirect_all_stdt)
{
    int i =  get_indirect("include");
    cr_assert_eq(i, 0);
}

Test(my_exit, test_exit, .init = redirect_all_stdt)
{
    int pip[2];
    my_exit(pip);
    cr_assert_stdout_eq_str("exit");
}

Test(parsing_left, test_left, .init = redirect_all_stdt)
{
    int i = 6;
    char *cmd = "Coucou;bien";
    char *result = parsing_left(cmd, i);
    cr_assert_str_eq(result, "Coucou");
}

Test(parsing_right, test_right, .init = redirect_all_stdt)
{
    int i = 6;
    char *cmd = "Coucou;bien";
    int j = my_strlen(cmd);
    char *result = parsing_right(cmd, i + 1, j);
    cr_assert_str_eq(result, "bien");
}

Test(check_sep, test_check_sep_NULL, .init = redirect_all_stdt)
{
    char *cmd = NULL;
    int result = check_sep(cmd);
    cr_assert_eq(result, 1);
}

Test(check_sep, test_check_sep_Nosep, .init = redirect_all_stdt)
{
    char *cmd = "ls";
    int result = check_sep(cmd);
    cr_assert_eq(result, 1);
}

Test(check_sep, test_check_sep_with_sep, .init = redirect_all_stdt)
{
    char *cmd = "ls | cat -e";
    int result = check_sep(cmd);
    cr_assert_eq(result, 0);
}

Test(biggest_sep, test_find_sep_comma, .init = redirect_all_stdt)
{
    char *cmd = "ls ; cat -e";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 1);
}

Test(biggest_sep, test_find_sep_pipe, .init = redirect_all_stdt)
{
    char *cmd = "ls | cat -e";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 2);
}

Test(biggest_sep, test_find_sep_lr, .init = redirect_all_stdt)
{
    char *cmd = "ls < cat -e";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 3);
}

Test(biggest_sep, test_find_sep_rr, .init = redirect_all_stdt)
{
    char *cmd = "ls > cat -e";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 4);
}

Test(biggest_sep, test_find_sep_dlr, .init = redirect_all_stdt)
{
    char *cmd = "ls << cat -e";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 5);
}

Test(biggest_sep, test_find_sep_drr, .init = redirect_all_stdt)
{
    char *cmd = "ls >> cat -e";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 6);
}

Test(biggest_sep, test_find_sep_NULL, .init = redirect_all_stdt)
{
    char *cmd = "ls";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 0);
}

Test(sig_catch, test_signal_catch_seg, .init = redirect_all_stdt)
{
    int sig = 11;
    sig_catch(sig);
    cr_assert_stderr_eq_str("Segmentation fault\n");
}

Test(sig_catch, test_signal_catch_float, .init = redirect_all_stdt)
{
    int sig = 8;
    sig_catch(sig);
    cr_assert_stderr_eq_str("Floating exception\n");
}

Test(error_handing, error_handing, .init = redirect_all_stdt)
{
    char *tab[2] = {"patate", NULL};
    int err = EACCES;
    int pip[2];
    error_handing(tab, err, pip);
    cr_assert_stdout_eq_str("patate: Permission denied.\n");
}

Test(error_handing, error_handing2, .init = redirect_all_stdt)
{
    char *tab[2] = {"patate", NULL};
    int err = ENOEXEC;
    int pip[2];
    error_handing(tab, err, pip);
    cr_assert_stdout_eq_str("patate: Exec format error. Wrong Architecture.\n");
}