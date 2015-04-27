#!/bin/bash
myPath="filenum.sh"
if [ ! -f "$myPath" ];then
	echo 0
else
#英文系统下获取文件修改时间
	res=$(stat filenum.sh | grep Modify | awk '{print $2}') 2>/dev/null
	if [ ! -n "$res" ];then
	#中文系统下获取文件修改时间
		res1=$(stat filenum.sh | awk '{print $1}' | sed -n "6,1p" | awk -F "：" '{print $2}') 2>/dev/null
		echo $res1
	fi
fi
