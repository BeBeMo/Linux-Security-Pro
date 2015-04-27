#!/bin/bash

echo $1 | sudo -S echo ""
sudo chpasswd < passwd1.txt
