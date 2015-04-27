#!/bin/bash 

#通过dmidecode 命令查看电脑硬件信息

#电脑概述*****************************************************
if [ $2 -eq 1 ]
then
	Manufacturer=`echo $1 | sudo -S dmidecode -t system | grep "Manufacturer:"| awk -F: '{print $2}'` 
	ProductName=`echo $1 | sudo -S dmidecode -t system | grep "Product Name:"| awk -F: '{print $2}'` 
	Version=`echo $1 | sudo -S dmidecode -t system | grep "Version:"| awk -F: '{print $2}'`
	Time=`cat /proc/uptime| awk -F. '{run_hour=($1 % 86400)/3600;run_minute=($1 % 3600)/60;printf("%d时%d分",run_hour,run_minute)}'`
	SerialNumber=`echo $1 | sudo -S dmidecode -t system | grep "Serial Number:"| awk -F: '{print $2}'`
	HostName=`hostname`
	PlatForm=`uname -a | awk '{print $1,$3}'`
	Machine=`uname -m`
	                           
	echo -e " 制造商 :                        $Manufacturer\n"
	echo -e " 电脑型号 :                   $ProductName\n"
	echo -e " 电脑版本 :         	     $Version\n"
	echo -e " 持续运行时间:             $Time\n"
	echo -e " 序列号 :                        $SerialNumber\n"
	echo -e " 主机名 :	                        $HostName\n"
	echo -e " 操作系统版本 : 	      $PlatForm\n"
	echo -e " 内核架构 :	      $Machine"
fi


#cpu信息*****************************************************
if [ $2 -eq 2 ] 
then 
	CpuVersion=`echo $1 | sudo -S dmidecode -t processor | grep "Version:" | awk -F: '{print $2}'`
	CpuManufacturer=`echo $1 | sudo -S dmidecode -t processor | grep "Manufacturer:" | awk -F: '{print $2}'`
	CpuSocketDesignation=`echo $1 | sudo -S dmidecode -t processor | grep "Socket Designation:" | awk -F: '{print $2}'`
	CpuMaxSpeed=`echo $1 | sudo -S dmidecode -t processor | grep "Max Speed:" | awk -F: '{print $2}'`
	CpuCurrentSpeed=`echo $1 | sudo -S dmidecode -t processor | grep "Current Speed:" | awk -F: '{print $2}'`
	Cpucores=`cat /proc/cpuinfo  | grep "cpu cores"  | awk -F: NR==1'{print $2}'`
	Cpusiblings=`cat /proc/cpuinfo  | grep "siblings" |  awk -F: NR==1'{print $2}'`
	Cpucache1=`cat /proc/cpuinfo  | grep "clflush size" | awk -F: NR==1'{print $2}'`
	Cpucache2=`cat /proc/cpuinfo  | grep "cache size" | awk -F: NR==1'{print $2}'`
	
	echo -e " 处理器 :	         $CpuVersion\n"	
	echo -e " 制造商 :           $CpuManufacturer\n"	
	echo -e " 插座/插槽 :     $CpuSocketDesignation\n"	
	echo -e " 最大主频 :       $CpuMaxSpeed\n"
	echo -e " 当前主频 :       $CpuCurrentSpeed\n"	
	echo -e " 核心数目 :       $Cpucores核/$Cpusiblings线程\n"	
	echo -e " 一级缓存 :       $Cpucache1 KB\n"
	echo -e " 二级缓存 :       $Cpucache2\n"
fi


#主板信息***********************************************************
if [ $2 -eq 3 ]
then 
	BProductName=`echo $1 | sudo -S dmidecode -t baseboard | grep "Product Name:" | awk -F: '{print $2}'`
	BManufacturer=`echo $1 | sudo -S dmidecode -t baseboard | grep "Manufacturer:" | awk -F: '{print $2}'`
	BSerialNumber=`echo $1 | sudo -S dmidecode -t baseboard | grep "Serial Number:" | awk -F: '{print $2}'`
	
	echo -e " 主板型号 :	       $BProductName\n" 
	echo -e " 主板厂商 :	       $BManufacturer\n"
	echo -e " 序列号 :		       $BSerialNumber\n\n"
	
	BVendor=`echo $1 | sudo -S dmidecode -t bios | grep "Vendor:" | awk -F: '{print $2}'`
	BVersion=`echo $1 | sudo -S dmidecode -t bios | grep "Version:" | awk -F: '{print $2}'`
	BReleaseDate=`echo $1 | sudo -S dmidecode -t bios | grep "Release Date:" | awk -F: '{print $2}'`
	
	echo -e " BIOS产商 :	       $BVendor\n"
	echo -e " BIOS版本 :	       $BVersion\n"
	echo -e " 发布日期 :	       $BReleaseDate\n"		
fi


#内存信息*********************************************************
#free -m命令查看内存信息
if [ $2 -eq 4 ]
then
	Total=`free -m | awk NR==2'{print $2}'`
	Used=`free -m | awk NR==2'{print $3}'`
	Free=`free -m | awk NR==2'{print $4}'`
	Shared=`free -m | awk NR==2'{print $5}'`
	Buffer=`free -m | awk NR==2'{print $6}'`
	Cached=`free -m | awk NR==2'{print $7}'`
	BFUsed=`free -m | awk NR==3'{print $3}'`
	BFFree=`free -m | awk NR==3'{print $4}'`

	echo -e " 内存大小 : 		$Total MB\n"
	echo -e " 已用内存 :  		$Used MB\n"
	echo -e " 剩余内存： 		$Free MB\n"
	echo -e " 共享内存 : 		$Shared MB\n"
	echo -e " 缓冲区 :			$Buffer MB\n"
	echo -e " 高速缓存 :		$Cached MB\n"
	echo -e " 应用程序已使用内存:            $BFUsed MB\n"
	echo -e " 应用程序可使用内存:            $BFFree MB"  	 	
fi


