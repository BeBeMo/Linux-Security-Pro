a=$(grep $2 ../pathresult1)
b=${a/S/K}
#echo $a
#echo $b
echo $1 | sudo -S mv $a $b
