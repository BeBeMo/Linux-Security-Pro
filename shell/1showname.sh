#!/bin/bash
#提取etc/rc2.d名称

i=0
long=$(ls /etc/rc2.d)
#echo $long

for sname in $long
do
	#echo ${sname:0:1}
	if [ ${sname:0:1} = 'S' ]
	then
		#echo $sname
		name[${i}]=${sname:3}
	fi
	(( ++i ))
done

name=${name[@]}
echo $name | sed 's/ /\n/g ' > result1
