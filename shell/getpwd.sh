#!/bin/bash

#判断密码是否一致
echo $1 |sudo -S echo > /dev/null

if [ $? == 0 ];then
	echo "1";
else
	echo "2";
fi
