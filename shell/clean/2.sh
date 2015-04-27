#!/bin/bash
#包临时文件
size2=$(($(du -sh -b /var/cache/apt/archives/partial | awk '{print $1}')-4096))
echo $size2
