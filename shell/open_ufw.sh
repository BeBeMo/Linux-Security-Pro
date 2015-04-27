#!/bin/bash
#ufw防火墙
#sleep 2
pwd=cc21176
#查看状态
s=$(echo $pwd | sudo -S ufw status | awk -F ： '{print $2}')
#echo $s

#如果状态是不活动
if [ "$s" == "不活动" ]
then
	#开启防火墙
	echo $pwd | sudo -S ufw enable
else
	#显示防火墙状态
	echo "防火墙已开启"
fi

#关闭防火墙
#sudo ufw disable

