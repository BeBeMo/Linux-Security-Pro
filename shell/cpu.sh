#!/bin/bash
#CPU使用情况

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
Disp_SYS_Rate=$(expr "scale=2; $SYS_Rate/1" |bc)
echo "CPU已使用$Disp_SYS_Rate%"

