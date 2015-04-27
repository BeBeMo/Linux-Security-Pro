#!/bin/bash
#统计僵尸进程个数
#sleep 2
#得到僵尸进程个数
num=$(ps -ef | grep defunct | grep -v grep | wc -l)

#如果个数为0
if [ $num -eq 0 ]
then
	echo "系统中目前不存在僵尸进程"
#如果个数不为0
else
	echo "系统中目前存在 $num 个僵尸进程"
fi
