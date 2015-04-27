#!/bin/bash

filelist=`echo $1 |sudo -S find /etc -name "rc2.d"`
for file in $filelist
do
	find $file -name "S*" >> ./myopenres1
#	echo $file |awk -F "/" '{print $4}' >> ./myopenres1
done

sort -u ./myopenres1 > ../pathresult1
rm ./myopenres1
#cat ./myopenres2

