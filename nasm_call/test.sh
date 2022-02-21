#!/bin/sh
I=1
while IFS=% read -r source stdres; do
        res=$(echo $source | ./$1)
        res=$(echo "$stdres" | tail -n +1)
        if [ x"$stdres" != x"$res" ]; then
                echo TEST $I '('$source')' FAILED: expexted "$stdres", got "$res"
        else
                echo TEST $I PASSED
        fi
        I=$((I+1))
done <<END
        1 2 3 4%1... 2... 3... 4... I love marine corps!
        8 3 2 5%8... 3... 2... 5... I love marine corps!
        -12 0 123 432%-12... 0... 123... 432... I love marine corps!
        -2 -23456 1 0%-2... -23456... 1... 0... I love marine corps!
END
