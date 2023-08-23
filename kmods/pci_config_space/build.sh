#!/bin/bash

echo "Building NVIDIA kernel module..."

make clean

cmake3 . && make || exit 1

rmmod kmod_nvidia
insmod kmod_nvidia.ko

echo "Listing module kmod_nvidia"
lsmod | grep "kmod_nvidia"
