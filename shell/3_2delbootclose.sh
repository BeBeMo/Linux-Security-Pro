a=$(grep $2 ../pathresult2)
b=${a/K/S}
#echo $a
#echo $b
echo $1 | sudo -S mv $a $b
