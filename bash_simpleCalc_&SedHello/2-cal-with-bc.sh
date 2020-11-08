

echo "Please tell scale (floating point precision)"
read p
echo "Please enter the expression with spaces, for multiplication use x (small) not * as it is a special char in unix, ctr-c to exit"

while :
do
    
   
    read n s m
    if [ $s == 'x' ];
    then
       echo -n "$n x $m" =
       echo "scale=$p; $n * $m " | bc
    elif [ $s == '/' ];
    then
       echo -n "$n / $m" =
       echo "scale=$p; $n / $m " | bc
    elif [ $s == '+' ];
    then
       echo -n "$n + $m" =
       echo "scale=$p; $n + $m " | bc
    elif [ $s == '-' ];
    then
       echo -n "$n - $m" =
       echo "scale=$p; $n - $m " | bc
    else
       echo "Wrong input"
    fi
    

done


