#!/bin/bash
#获得电脑开机时间

#/proc/uptime中存放已运行时间,转换成标准格式输出
cat /proc/uptime | awk -F. '{run_days=$1 / 86400;run_hour=($1 % 86400)/3600;run_minute=($1 % 3600)/60;run_second=$1 % 60;printf("已开机：%d天%d时%d分%d秒\n",run_days,run_hour,run_minute,run_second)}'
