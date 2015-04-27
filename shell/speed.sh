#!/bin/bash

 ethtool wlan0 | grep "Link detected: yes" > /dev/null #判断是否是无线网

	if [ $? -eq 0 ] #判断网卡
	then
		eth=wlan0
	else
		eth=eth0
   	 fi
        #求出一秒前后流量的差值,作为这一秒的下载网速, 从/proc/net/dev文件中.
	RXpre=$(cat /proc/net/dev | grep $eth | tr : " " | awk '{print $2}')
	TXpre=$(cat /proc/net/dev | grep $eth | tr : " " | awk '{print $10}')
	
	sleep 1

	
	RXnext=$(cat /proc/net/dev | grep $eth | tr : " " | awk '{print $2}')
	TXnext=$(cat /proc/net/dev | grep $eth | tr : " " | awk '{print $10}')

	RX=$((${RXnext}-${RXpre}))
	TX=$((${TXnext}-${TXpre}))

	 #流量单位转换
	if [[ $RX -lt 1048576 ]];then
	RX=$(echo $RX | awk '{printf "%.1f",$1/1024}'  | awk '{print $1 "KB/s"}')

	else
	RX=$(echo $RX | awk '{printf "%.1f",$1/1048576}'  | awk '{print $1 "MB/s"}')
	fi	
	
	if [[ $TX -lt 1048576 ]];then
	TX=$(echo $TX | awk '{printf "%.1f",$1/1024}'  | awk '{print $1 "KB/s"}')

	else
	TX=$(echo $TX | awk '{printf "%.1f",$1/1048576}'  | awk '{print $1 "MB/s"}')
	fi	

        #输出下载速度
	echo "系统当前占用的网速为 $RX "

