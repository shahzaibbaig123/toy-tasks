for file in *.txt
do
	sed -i -e 's/[A-Z]/\L&/g' -e 's/<[^>]*>//g' $file
done
