#!/bin/sh

power()
{
    product=1
    for i in `seq $2`
    do
        product=`expr $product \* $1`
    done
    echo $product
}

while read line
do
    from=`echo $line | cut -f1 -d','`
    to=`echo $line | cut -f2 -d','`

    echo "$from -> $to - alakitott szamok":


    p=3
    while [ `echo $line | cut -f$p -d','` ]
    do
        decimal=0
        toconvert=`echo $line | cut -f$p -d','`
        splitted=`echo $toconvert | sed -e 's/\(.\)/\1\n/g'`
        len=`echo $splitted | wc -w`
        
        ## Convert to decimal
        for i in $splitted
        do
            len=`expr $len - 1`
            ph=`power $from $len`
            add=`expr $ph \* $i`
            decimal=`expr $add + $decimal`
        done
        
        ## Convert to Output
        out=""
        while [ $decimal != 0 ]
        do
            rem=`expr $decimal % $to`
            out=`echo $out$rem-`
            decimal=`expr $decimal / $to`
        done

        ## Reverse string
        rev=`echo $out | sed "s/-/\n/g" | tac | sed ':a;N;$!ba;s/\n//g'`

        echo "($toconvert) => $rev"


        p=`expr $p + 1`
    done
done < $1



