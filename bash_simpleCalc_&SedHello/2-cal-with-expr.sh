echo "Please enter the expression with spaces, for multiplication use x (small) not * as it is a special char in unix, ctr-c to exit"
while :
do
    
   
    read n s m
    if [ $s == 'x' ];
    then
       echo $n '*' $m = $(expr "$n" \* "$m")
    elif [ $s == '/' ];
    then
       echo $n '/' $m = `expr $n / $m`
    elif [ $s == '+' ];
    then
       echo $n '+' $m = $(expr "$n" + "$m")
    elif [ $s == '-' ];
    then
       echo $n '-' $m = `expr $n - $m`
    else
       echo "Wrong input"
    fi
    

done

