#!/bin/bash
#杀死僵尸进程
#sleep 2
num=$(ps -ef | grep defunct | grep -v grep | wc -l)

#如果个数为0
if [ $num -eq 0 ]
then
	echo "系统中目前不存在僵尸进程"
#如果个数不为0
else
	#ps -A -o stat,ppid,pid,cmd | grep -e '^[Zz]' | awk '{print $2}' | xargs kill -9
	echo "已杀死 $num 个僵尸进程"
fi
