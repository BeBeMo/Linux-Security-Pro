#! /bin/bash
#清除缓存
#sleep 2
sync  #将系统缓存区中的脏数据写入磁盘中，包括已修改的i-node、已延迟的块I/O和读写映射文件
echo 3 > /proc/sys/vm/drop_caches   #默认0—不释放，1—释放pagecache，2—释放dentries和inodes，3—释放所有缓存
echo "已清理"
