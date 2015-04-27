#!/bin/bash

echo $1 | sudo -S userdel -r $2
