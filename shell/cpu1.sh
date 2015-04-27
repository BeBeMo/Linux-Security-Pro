#!/bin/bash

#CPU时间 cpu=user+system+nice+idle+iowait+irq+softirq
#CPU利用率的计算方法：
#可以使用取两个采样点，计算其差值的办法，(idle2-idle1)/(cpu2-cpu1)

CPULOG_1=$(cat /proc/stat | awk '/cpu /{print $2" "$3" "$4" "$5" "$6" "$7" "$8" "$9" "$10" "$11}')
SYS_IDLE_1=$(echo $CPULOG_1 | awk '{print $4}')
Total_1=$(echo $CPULOG_1 | awk '{print $1+$2+$3+$4+$5+$6+$7+$8+$9+$10}')

sleep 1

CPULOG_2=$(cat /proc/stat | awk '/cpu /{print $2" "$3" "$4" "$5" "$6" "$7" "$8" "$9" "$10" "$11}')
SYS_IDLE_2=$(echo $CPULOG_2 | awk '{print $4}')
Total_2=$(echo $CPULOG_2 | awk '{print $1+$2+$3+$4+$5+$6+$7+$8+$9+$10}')

SYS_IDLE=$(expr $SYS_IDLE_2 - $SYS_IDLE_1)
Total=$(expr $Total_2 - $Total_1)

tmp_rate=$(expr 1-$SYS_IDLE/$Total | bc -l)
SYS_Rate=$(expr $tmp_rate*100 | bc -l)

#display
Disp_SYS_Rate=$(expr "scale=0; $SYS_Rate/1" |bc)

echo $Disp_SYS_Rate%
