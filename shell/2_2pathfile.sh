#!/bin/bash

filelist=`echo $1 |sudo -S find /etc -name "rc2.d"`
for file in $filelist
do
	find $file -name "K*" >> ./myopenres2
#	echo $file |awk -F "/" '{print $4}' >> ./myopenres1
done

sort -u ./myopenres2 > ../pathresult2
rm ./myopenres2
#cat ./myopenres2

