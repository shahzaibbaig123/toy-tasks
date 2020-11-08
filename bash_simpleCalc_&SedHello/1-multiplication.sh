#Script to display a multiplication table n times
echo "Enter the value for m and n"
read k l
for((i=1;i<=l;i++))
do
 echo $i '*' $k = `expr $i \* $k`
done



