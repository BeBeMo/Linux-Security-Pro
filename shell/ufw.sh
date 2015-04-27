#!/bin/bash
#ufw防火墙
#sleep 2
psw=$1
#查看状态
s=$(echo $psw | sudo -S ufw status | awk -F ： '{print $2}')
echo $s

#如果状态是不活动
#if [ "$s" = "不活动" ]
#then
	#开启防火墙
#	sudo ufw enable
#fi

#关闭防火墙
#sudo ufw disable

