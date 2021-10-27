#!/bin/bash

rougefonce='\e[0;31m'
vertfonce='\e[0;32m'
bleufonce='\e[0;33m'
neutre='\e[0;m'

nb=0

print_perc() {
    SIZE1=$(stat -c%s ${1})
    SIZE2=$(stat -c%s ${2})
    PERC=$(bc <<< "scale=2; ($SIZE2 - $SIZE1)/$SIZE1 * 100")
    echo "with $PERC % compression"
}

make_test() {
    echo -ne "${1}" | ../../.././42sh &> ../res_mysh
    echo -ne "${1}" | tcsh &> ../res_tcsh
    sort ../res_mysh > ../res_mysh2
    sort ../res_tcsh > ../res_tcsh2
    Test=$(diff ../res_mysh2 ../res_tcsh2)
    if [ "$Test" = "" ]
            then
                echo -ne "${vertfonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${vertfonce} OK${neutre}\n"
            else
                echo -ne "${rougefonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${rougefonce} KO${neutre}\n"
            fi
    let 'nb=nb+1'
    rm ../.42shrc
}

#make && make clean

echo -e "${bleufonce}1 - MINISHELL1${neutre}\n"
make_test "\n"
make_test "exit"
make_test "../my_segfault"
make_test "ls"
make_test "azedc"
make_test "pwd"
make_test "ls -l"
make_test "./mysh"
make_test "setenv patate"
make_test "setenv patate pat"
make_test "setenv patate\nunsetenv patate"
make_test "unsetenv pwd"
make_test "setenv coucou="
make_test "setenv hey_"
make_test "cd\npwd"
make_test "cd/npwd"
make_test "cd zesdrfgthvf"
make_test "cd main.c"
make_test "cd include"
make_test " ls\t\t-l"
make_test "\t\tpwd\n \t\tcd\npwd"
make_test "  \tpwd\t \ncd\t    \n ls"
make_test "pwd\t\tcd      pwd\t\n"
make_test "ls -l"
make_test "./scan_build"
make_test "./prog_with_divZero"
make_test "../directory"
make_test "./thbv"
make_test "cd ../\n cd ../\n cd -\n"

echo -e "\n${bleufonce}2 - MINISHELL2${neutre}\n"
make_test "ls ; ls"
make_test "ls ; pwd ; grep main"
make_test "cd / ; pwd ; ls"
make_test "pwd ; cd ; pwd ; cd - ; pwd"
make_test "\t\t ls ; \t    cd   ; \t\tpwd"
make_test "\t\tls > yo\n    \tcat -e      yo ; grep sh"
make_test "\t\tls     >   \t  yo  \n \t ; cat -e < yo\n cat -e yo"
make_test "\tls >> yo\npwd\t >> yo"
make_test "ls | grep lib"
make_test "ls | grep lib | grep l"
make_test "ls | grep lib ; ls -la > yo"
make_test "pwd ; cd .. ; ls | cat -e > file ; cd - ; cat ../file"
make_test "ls -l; ls -l | wc -l"
make_test "ls | ls"
make_test "   ls; pwd; ls -l | wc - c"
make_test "ls;pwd"
make_test "ls|cat -e;pwd"
make_test "ls\t|cat -e > yolo"
make_test "ls -l |grep 1"
make_test "ls > yolo ; cat -e < yolo"
make_test "|"
make_test "ls|cat -e"
make_test "< yo"
make_test "> yo"
make_test ">> yo"
make_test "ls >"
make_test "cat -e <"
make_test "ls >>"
make_test "cat -e < my_test.sh"
make_test "grep make < my_test.sh"
make_test "ls -l|grep d|grep s|cat -e"
make_test "ls -l \t | grep d | cat -e | wc -c"
make_test "cd | ls"
make_test "cd ../| wc -c"
make_test "cd / | pwd"
make_test "ls > test62"
make_test "cat -e < azerfg"
make_test "ls > test64\ncat -e < test64"
make_test "ls|ls|ls|ls|ls|ls|"
make_test "ls|ls|ls|ls|ls|ls|ls"
make_test "ls > test67; chmod 000 test67 ; ls >> test67 ; rm -f test67"
make_test "env | grep PATH"
make_test "ls | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e"
make_test "ls | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e"
make_test "ls | grep l | cat -e | wc -c | cat -e"
make_test "setenv patate | env | grep patate"-
make_test "setenv patate | grep patate"
make_test "ls|grep -e;cd>>trfc"
make_test "ls ; ls; cd \t\t\n ls|cat -e > file"
make_test "pwd\t   ; cat -e \n ls | wc -l"
make_test "ls | wc -l | cat -e | wc -c"
make_test "env | cat -e | ls"
make_test "ls | grp"
make_test "ls | grep s | s"
make_test "ls | s | grep s"
make_test ";"
make_test "ls | cd"
make_test "ls | cat -e | wc -c"
make_test "ls | cat -e | wc -c | cat -e | wc -c | cat -e"
make_test "env | cd\n ls"
make_test "grp | ls | s"
make_test "grp | cat -e"

echo -e "\n${bleufonce}3 - 42sh${neutre}\n"

make_test "ls && ls"
make_test "ls || ls"
make_test "ert || ls"
make_test "zert && sdfg && qsdfg && lsdfg"
make_test "ls || ls && ls && ls"
make_test "ls && azer"
make_test "zsedrf && ls"
make_test "ls *"
make_test "ls -l *"
make_test "ls -la *.c"
make_test "cd ../../../src ; ls -l *.c"
make_test "alias ls 'ls --color=auto'\nls"
make_test "alias patate 'ls'\npatate"
make_test "ls \n"
make_test "echo \t"
make_test "echo \l"
make_test "which ls"
make_test "where ls"
make_test "which echo"
make_test "where echo"
make_test "ls `echo -e /bin`"
make_test "cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo 'OK'"
make_test "`echo ls`"
make_test "repeat"
make_test "repeat 5 ls"
make_test "repeat 5 ls -l"
make_test "repeat ls"
make_test "repeat 5"
make_test "repeat zerf azert"
make_test "repeat 5"
make_test "repeat 5 ls"
make_test "repeat 5 ls -l"
make_test "repeat 5 ls ls"
make_test "echo `ls \| cat -e \| wc -c`"
make_test "if 1 == 1 ls"
make_test "if 1 != 2 ls"
make_test "if 1 == 3 ls"
make_test "if 1 != 1 ls"