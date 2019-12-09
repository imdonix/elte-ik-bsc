#!/bin/sh

odd_odd="0"
odd_even="0"
even_odd="0"
even_even="0"

line_c="1"
while read line
do
    words=`echo $line | wc -w`
    for i in `seq $words`
    do
        num=`echo $line | cut -f$i -d' '`

        if [ `expr $line_c % 2` -eq "1" ]
        then
            if [ `expr $num % 2` -eq "1" ]
            then
                odd_odd=`expr $odd_odd + $num`
            else
                odd_even=`expr $odd_even + $num`
            fi
        else
            if [ `expr $num % 2` -eq "1" ]
            then
                even_odd=`expr $even_odd + $num`
            else
                even_even=`expr $even_even + $num`
            fi
        fi
    done
    line_c=`expr $line_c + 1`
done < $1

echo "Páratlan sorok, páratlan összege: $odd_odd"
echo "Páratlan sorok, páros összege: $odd_even"
echo "Páros sorok, páratlan összege: $even_odd"
echo "Páros sorok, páros összege: $even_even"