#!/bin/bash
#回收站
size1=$(($(du -sh -b ~/.local/share/Trash/files | awk '{print $1}')-4096))

#包临时文件
size2=$(($(du -sh -b /var/cache/apt/archives/partial | awk '{print $1}')-4096))

#缩略图
size3=$(($(du -sh -b ~/.cache/thumbnails | awk '{print $1}')-4096))

#最近使用文档记录
size4=$(du -b ~/.local/share/recently-used.xbel | awk '{print $1}')

#总大小
size=$(($size1+$size2+$size3+$size4))
echo "$(printf "%0.2f\n" `echo "scale=5; $size / 1024 " | bc`)k"
