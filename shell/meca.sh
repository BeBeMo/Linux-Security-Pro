#!/bin/bash
#内存/缓存使用情况
#sleep 2
#查看内存使用率
#已使用内存
used=$(free | awk 'NR==2{print $3}')
#空闲内存
free=$(free | awk 'NR==2{print $4}')
#总内存
total=$(free | awk 'NR==2{print $2}')
#已用内存率（小数点后保留4位）
ut=$(printf "%0.4f\n" ` echo "scale=5; $used / $total " | bc `)
#空余内存率（小数点后保留4位）
ft=$(printf "%0.4f\n" ` echo "scale=5; $free / $total " | bc `)
#echo "查看内存/缓存使用情况"
#已用内存百分比（小数点后保留2位）
echo "已用内存：$(printf "%0.2f\n" `echo "sclae=4; $ut * 100" | bc`)%"
#空闲内存百分比（小数点后保留2位）
#echo "空闲内存：$(printf "%0.2f\n" `echo "sclae=2; $ft * 100" | bc`)%"

####################################################################

#查看缓存使用率
#已使用缓存
used=$(free | awk 'NR==3{print $3}')
#空闲缓存
free=$(free | awk 'NR==3{print $4}')
#总缓存
total=$(($used+$free))
#已用缓存率（小数点后保留4位）
ut=$(printf "%0.4f\n" ` echo "scale=5; $used / $total " | bc `)
#空余缓存率（小数点后保留4位）
ft=$(printf "%0.4f\n" ` echo "scale=5; $free / $total " | bc `)
#echo "查看缓存使用情况"
#已用缓存百分比（小数点后保留2位）
echo "已用缓存：$(printf "%0.2f\n" `echo "sclae=4; $ut * 100" | bc`)%"
#空闲缓存百分比（小数点后保留2位）
#echo "空闲缓存：$(printf "%0.2f\n" `echo "sclae=2; $ft * 100" | bc`)%"
