#!/bin/bash
#最近使用文档记录
size4=$(du -b ~/.local/share/recently-used.xbel | awk '{print $1}')
echo $size4
rm -f ~/.local/share/recently-used.xbel
touch ~/.local/share/recently-used.xbel
