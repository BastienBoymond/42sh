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

Test(parsing_left, test_left_error, .init = redirect_all_stdt)
{
    int i = 0;
    char *cmd = "Coucou";
    char *result = parsing_left(cmd, i);
    cr_assert_eq(result, NULL);
}

Test(parsing_right, test_right, .init = redirect_all_stdt)
{
    int i = 6;
    char *cmd = "Coucou;bien";
    int j = my_strlen(cmd);
    char *result = parsing_right(cmd, i + 1, j);
    cr_assert_str_eq(result, "bien");
}

Test(parsing_right, test_right_error, .init = redirect_all_stdt)
{
    int i = 0;
    char *cmd = "Coucou;bien";
    int j = 0;
    char *result = parsing_right(cmd, i, j);
    cr_assert_eq(result, NULL);
}

Test(check_sep, test_check_sep_NULL, .init = redirect_all_stdt)
{
    char *cmd = NULL;
    sh_t sh = create_sh(__environ, 1);
    int result = check_sep(cmd, &sh);
    cr_assert_eq(result, 1);
}

Test(check_sep, test_check_sep_Nosep, .init = redirect_all_stdt)
{
    char *cmd = "ls";
    sh_t sh = create_sh(__environ, 1);
    int result = check_sep(cmd, &sh);
    cr_assert_eq(result, 1);
}

Test(check_sep, test_check_sep_with_sep, .init = redirect_all_stdt)
{
    char *cmd = "ls | cat -e";
    sh_t sh = create_sh(__environ, 1);
    int result = check_sep(cmd, &sh);
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

Test(biggest_sep, test_find_sep_and, .init = redirect_all_stdt)
{
    char *cmd = "ls && ls";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 7);
}

Test(biggest_sep, test_find_sep_dpipe, .init = redirect_all_stdt)
{
    char *cmd = "ls || ls";
    int result = biggest_sep(cmd);
    cr_assert_eq(result, 8);
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

Test(my_echo, test_echo, .init = redirect_all_stdt)
{
    char **tab = my_str_to_word_array("echo", "\n\t ");
    int pip[2];
    my_echo(tab, pip);
    cr_assert_stdout_eq_str("\n");
}

Test(my_echo, test_echo_one_args, .init = redirect_all_stdt)
{
    char **tab = my_str_to_word_array("echo patate", "\n\t ");
    int pip[2];
    my_echo(tab, pip);
    cr_assert_stdout_eq_str("patate\n");
}

Test(my_echo, test_echo_mult_args, .init = redirect_all_stdt)
{
    char **tab = my_str_to_word_array("echo patate la zone", "\n\t ");
    int pip[2];
    my_echo(tab, pip);
    cr_assert_stdout_eq_str("patate la zone\n");
}

Test(valid_cmd, test_bad_cmd, .init = redirect_all_stdt)
{
    char **path = my_str_to_word_array("azazert", "\n\t");
    char **tab = my_str_to_word_array("lazerfg", "\n\t ");
    int i = valid_cmd(path, tab);
    cr_assert_eq(i, 1);
}

Test(valid_cmd, test_good_cmd, .init = redirect_all_stdt)
{
    char **path = my_str_to_word_array("/usr/local/sbin:/usr/local/bin:\
/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", ":");
    char **tab = my_str_to_word_array("ls", "\n\t ");
    int i = valid_cmd(path, tab);
    cr_assert_eq(i, 0);
}

Test(executation, exec, .init = redirect_all_stdt)
{
    char **path = my_str_to_word_array("/usr/local/sbin:/usr/local/bin\
:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", ":");
    char **tab = my_str_to_word_array("ls", "\n\t ");
    int pip[2];
    char **env = __environ;
    int i = executation(path, tab, env, pip);
    cr_assert_eq(i, 0);
}

Test(valid_glob, was_a_good_glob, .init = redirect_all_stdt)
{
    int i = valid_glob("ls *");
    cr_assert_eq(i, 0);
}

Test(valid_glob, was_a_bad_glob, .init = redirect_all_stdt)
{
    int i = valid_glob("ls");
    cr_assert_eq(i, 1);
}

Test(concatenate, do_concatenate, .init = redirect_all_stdt)
{
    char *str = concatenate("ls|", "ls");
    cr_assert_str_eq(str, "ls|ls|");
}

Test(tab_len, do_tab_error, .init = redirect_all_stdt)
{
    char **tab = NULL;
    int i = tab_len(tab);
    cr_assert_eq(i, 0);
}

Test(tab_len, do_tab_arg, .init = redirect_all_stdt)
{
    char *tab[3] = {"ls", "-l", NULL};
    int i = tab_len(tab);
    cr_assert_eq(i, 2);
}

Test(envgestion, do_the_env_gestion)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls | ls ; ls | ls && ls || ls > ls < ls >> ls << ls";
    parsing(buffer, shell, &head);
}

Test(all, do_all_exec)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls | cat -e ; ls | wc -l";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_two)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls > file";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_three)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls < file";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_five)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls >> file";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_six)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "exit";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}


Test(all, do_all_exec_seven)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "setenv";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_eight)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "unsetenv";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_nine)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "unsetenv PATH";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "setenv PATH";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_one)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "env";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_two)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "history";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_three)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "alias";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_four)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "alias ls ls -l";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_five)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "cd";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_eight)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "cd ../";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_nine)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls | cat -e";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls && ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_one)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls || ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_two)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "setenv yo lerap";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_three)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "!ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_four)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "zert";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_e)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "which ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}


Test(all, do_all_exec_ten_ten_five)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "where ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_six)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "where gg";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_seven)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "which ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_eight)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "which echo";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_nine)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "where echo";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "where";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_one)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "repeat";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_five)
{
    char *tab[4] = {"ls", "-l", "include", NULL};
    char *str = tabcat(tab);
}

Test(all, do_all_exec_ten_ten_ten_eight)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "if bougn == cendre ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_nine)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "if bougn != cendre ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "if";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_one)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "if ls == rs";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_two)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "`echo patate`";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_three)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "`ls`";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_seven)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "set bite ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_eight)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "set bite ls\nbite";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_nine)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "alias ls ls --color=auto\nls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_ten)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls\n!ls";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_ten_one)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "history";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_ten_two)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "!monkeyss";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

Test(all, do_all_exec_ten_ten_ten_ten_ten_three)
{
    shell_t *shell = malloc(sizeof(shell_t));
    sh_t head = create_sh(__environ, 1);
    char *buffer = "ls \t";

    parsing(buffer, shell, &head);
    order(shell, __environ, &head);
}

// Test(all, get_char)
// {
//     get_char('n');
//     get_char('t');
//     get_char('b');
//     get_char('a');
//     get_char('v');
//     get_char('r');
//     get_char('f');
// }

// Test(all, do_all_exec_ten_ten_ten_ten_ten_four)
// {
//     shell_t *shell = malloc(sizeof(shell_t));
//     sh_t head = create_sh(__environ, 1);
//     char *buffer = "";

//     parsing(buffer, shell, &head);
//     order(shell, __environ, &head);
// }