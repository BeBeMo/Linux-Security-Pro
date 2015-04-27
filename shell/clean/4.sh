#!/bin/bash
#最近使用文档记录
size4=$(du -b ~/.local/share/recently-used.xbel | awk '{print $1}')
echo $size4
