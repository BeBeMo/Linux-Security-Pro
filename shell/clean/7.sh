#!/bin/bash
#缩略图
size3=$(($(du -sh -b ~/.cache/thumbnails | awk '{print $1}')-4096))
echo $size3
rm -rf ~/.cache/thumbnails/*
