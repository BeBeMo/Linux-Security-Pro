#!/bin/bash
#回收站垃圾文件大小

size1=$(($(du -sh -b ~/.local/share/Trash/files | awk '{print $1}')-4096))
echo $size1
