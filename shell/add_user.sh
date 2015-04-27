#!/bin/bash
echo $1 | sudo -S useradd $2 
sudo chpasswd < passwd.txt
