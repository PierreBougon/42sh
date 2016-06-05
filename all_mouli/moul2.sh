#!/bin/bash
## 
## 
## Moulinette from http://pastebin.com/1hMX0NDu

mysh=./42sh

fail()
{
    echo "$1"
}

start()
{
    touch .tmp_a .tmp_b
}

end()
{
    rm -f .tmp_a .tmp_b
}

# Check if $mysh is present
test0()
{
    if [ ! -x $mysh ]
    then
	echo "Please compile. Moulitest need your binary"
	exit
    fi
}

# START OF BASIC

test1()
{
    start
    echo "ls -l > .tmp_a" | $mysh > /dev/null 2>&1
    echo "ls -l > .tmp_b" | tcsh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test2()
{
    start
    echo "touch .tmp_a; mkdir .tmp; cd .tmp; ls .. | wc > .tmp_b; cd -; ls | wc > .tmp_a;" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp/.tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    rm -rf .tmp/
    end
}

test3()
{
    start
    echo "cat > .tmp_a < $mysh" | $mysh > /dev/null 2>&1
    echo "cat < $mysh > .tmp_b" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a $mysh)
    res2=$(diff .tmp_b $mysh)
    if [ "$res" = "" -a "$res2" = "" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test4()
{
    start
    echo "cat $mysh | sort | head > .tmp_a" | $mysh > /dev/null 2>&1
    echo "cat $mysh | sort | head > .tmp_b" | tcsh > /dev/null 2>&1
    res=$(diff .tmp_b .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test5()
{
    start
    echo "cat < $mysh | cat > .tmp_a" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a $mysh)
    if [ "$res" = "" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test6()
{
    start
    echo "cat $mysh | cat | cat | cat -e | wc > .tmp_a" | $mysh > /dev/null 2>&1
    echo "cat $mysh | cat -e | wc > .tmp_b" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test7()
{
    start
    echo "cat < $mysh | cat > .tmp_a; ls >> .tmp_a" | $mysh > /dev/null 2>&1
    echo "cat < $mysh | cat > .tmp_b; ls >> .tmp_b" | tcsh > /dev/null 2>&1
    res=$(diff -a .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test21()
{
    start
    echo "setenv PSU 7credits; env | grep PSU= > .tmp_a" | $mysh > /dev/null 2>&1
    echo "setenv PSU 7credits; env | grep PSU= > .tmp_b" | tcsh > /dev/null 2>&1
    res=$(diff -a .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test26()
{
    echo "azertyuiop>.tmp_a" | $mysh > /dev/null 2>&1
    secure=`cat .tmp_a`
    if [ -e ".tmp_a" -a ! -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

# END OF BASIC

# START OF MEDIUM

test8()
{
    start
    echo "<$mysh cat>.tmp_a" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a $mysh)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test9()
{
    start
    echo "<$mysh cat    >.tmp_a ; >   .tmp_b cat $mysh " | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test10()
{
    start
    echo ">    .tmp_a cat   $mysh;;   >>   .tmp_a ls" | $mysh > /dev/null 2>&1
    echo ">    .tmp_b cat   $mysh;;   >>   .tmp_b ls" | tcsh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

# END OF MEDIUM

# START OF HARD

test23()
{
    start
    echo ">.tmp_a cat $mysh; cat .tmp_a | cat > .tmp_a; ls >> .tmp_a; ls > .tmp_b" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test24()
{
    start
    echo "<$mysh cat>.tmp_a; <.tmp_a cat| cat >> .tmp_b;" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

# Won't work without /bin in $PATH
# Won't work if you don't use 'isatty' to display your prompt
test27()
{
    start
    echo "echo ls | $mysh > .tmp_a; echo ls | tcsh > .tmp_b" | $mysh > /dev/null 2>&1
    res=$(diff .tmp_a .tmp_b)
    secure=`cat .tmp_a`
    if [ "$res" = "" -a -n "$secure" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

# END OF HARD

# START OF ERROR

test11()
{
    echo "cat $mysh > .tmp_a | ls" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test12()
{
    echo "|ls > .tmp_a" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test13()
{
    echo "ls > .tmp_a > .tmp_a" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test14()
{
    echo "ls > .tmp_a < $mysh | ls" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test15()
{
    echo "ls > .tmp_a < $mysh ; ls" | $mysh > /dev/null 2>&1
    if [ -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test16()
{
    echo "ls    >>>    .tmp_a" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test17()
{
    echo ">.tmp_a" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test18()
{
    echo "<>><<<<>>>><>>>>>><<<>>><<>><<<>>>>>.tmp_a" | $mysh > /dev/null 2>&1 #Cool huh?
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test19()
{
    echo "ls | cat < $mysh; touch .tmp_a" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test20()
{
    echo "cat $mysh | | touch .tmp_a" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test22()
{
    echo "cat $mysh >.tmp_a ; ls | cat < $mysh" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

test25()
{
    echo "<mysh>.tmp_a" | $mysh > /dev/null 2>&1
    if [ ! -e ".tmp_a" ]
    then
	echo "OK"
    else
	echo "KO"
    fi
    end
}

# END OF ERROR

tests_passed=0
tests_total=27

test0
echo "*** Basic test ***"
for i in $(seq 1 7) 21 26
do
    out=$(test$i)
    echo "Test $i: $out"
    [ "$out" = "OK" ] && let tests_passed++
done

echo -e "\n*** Medium test ***"
for i in 8 9 10
do
    out=$(test$i)
    echo "Test $i: $out"
    [ "$out" = "OK" ] && let tests_passed++
done

echo -e "\n*** Hard test ***"
for i in 23 24 27
do
    out=$(test$i)
    echo "Test $i: $out"
    [ "$out" = "OK" ] && let tests_passed++
done

echo -e "\n*** Error test ***"
for i in $(seq 11 20) 22 25
do
    out=$(test$i)
    echo "Test $i: $out"
    [ "$out" = "OK" ] && let tests_passed++
done

echo -e "\nTests passed: $tests_passed/$tests_total ($(($tests_passed * 100 / $tests_total))%)"
